#include "Player.h";
#include "BiddingFacility.h"

#include<sstream>

using namespace std;

//Default Construtor
Player::Player()
{
	name = "Default";
	move = 0;
	coin = 0;
	army = 0;
	cityToken = 0;
	vector<Territory*> territory;
	vector<Cards*> handCard;
	bid = new BiddingFacility();
}
//Constructor with Name
Player::Player(string name)
{
	this->name = name;
	this->move = 0;
	this->army = 0;
	this->coin = 0;
	this->cityToken = 0;
	vector<Territory*> territory;
	vector<Cards*> handCard;
	bid = new BiddingFacility();
}
//Construtor with parameter
Player::Player(string name, int coin, int move, vector<Territory*> territory, vector<Cards*> handCard, BiddingFacility* bid)
{
	this->name = name;
	this->coin = coin;
	this->move = move;
	this->army = 18;
	this->cityToken = 3;
	this->territory = territory;
	this->handCard = handCard;
	this->bid = bid;
}

//Copy Constructor
Player::Player(const Player& object) {
	this->name = object.name;
	this->coin = object.coin;
	this->move = object.move;
	this->army = object.army;
	this->cityToken = object.cityToken;
	for (int i = 0; i < object.territory.size(); i++) {
		this->territory[i] = new Territory(*object.territory[i]);
	}
	for (int i = 0; i < object.handCard.size(); i++) {
		this->handCard[i] = new Cards(*object.handCard[i]);
	}
	this->bid = new BiddingFacility(*(object.bid));
}

//Assignment Operator
Player& Player::operator=(const Player& object) {
	this->name = object.name;
	this->coin = object.coin;
	this->move = object.move;
	this->army = object.army;
	this->cityToken = object.cityToken;
	for (int i = 0; i < object.territory.size(); i++) {
		this->territory[i] = new Territory(*object.territory[i]);
	}
	for (int i = 0; i < object.handCard.size(); i++) {
		this->handCard[i] = new Cards(*object.handCard[i]);
	}
	this->bid = new BiddingFacility(*(object.bid));
	return *this;
}

//Destructor
Player::~Player() {
	name = "";
	coin = 0;
	move = 0;
	army = 0;
	cityToken = 0;

	for (int i = 0; i < handCard.size(); i++) {
		delete handCard[i];
		handCard[i] = nullptr;	
	}
	territory.clear();
	handCard.clear();

	delete bid;
	bid = nullptr;

};

//Method Required by Part 2
void Player::PayCoin(int coin) {
	this->coin = this->coin - coin;
}

//method to bulid a city
int Player::BuildCity(Territory* territory) {

	//terriory null mean that we can build a city in there
	if (territory == NULL)
		return 0;;

	//if the terriory have an object, then we can not build in there
	if (territory->getBuildCity()) {
		cout << "The city has been built" << endl;
		return 0;
	}

	//build a city 
	cout << "The success of city construction" << endl;
	territory->setBuildCity();
	if (!this->territory.empty()) {
		cityToken = cityToken - 1;
	}
	//A3 Action Observer
	this->active = 4;
	Notify();
	//A3 statistics observer
	this->change = 1;
	return 1;
}

//method to place new armies
int Player::PlaceNewArmies(Territory* A, int army) {

	// if the territory is empty 
	if (this->territory.empty()) {
		//Territory* A = new Territory(*territory);
		A->setPlayer(name);
		A->setArmy(army);
		setArmy(3);
		A->setBuildCity();
		this->territory.push_back(A);
	}

	//if the territory exist a city --> true 
	else if (A->getBuildCity() == true) {

		//place the army to the territory 
		A->setArmy(army);
		setArmy(army);

		//A3
		active = 1;
		Notify();

		cout << "Placement success" << endl;
	}
	else {
		cout << "You can not place new armies in the territory without a city." << endl;
		return 0;
	}
	return 1;
}

//Move army from point A to point B
int Player::MoveArmies(Territory* A, Territory* B, int army) {
	//Check point B whether occupied by player

	//if this place has no player
	if (B->getPlayer().empty()) {
		//Territory* BB = new Territory(*B);
		A->setArmy(-army);
		B->setArmy(army);
		B->setPlayer(getName());
		territory.push_back(B);
		//territory.push_back(new Territory(*B));
		setMove(-army);
		
		//A3 Action Observer
		this->active = 2;
		Notify();
		//A3 statistics observer
		this->change = 1;

		cout << "Mobile success" << endl;
	}

	//if the player is the same (same name) 
	//make sure the place has not been occupied by other players

	else if (B->getPlayer().compare(getName()) == 0) {
		A->setArmy(-army);
		B->setArmy(army);
		setMove(-army);

		//A3 Action Observer
		this->active = 2;
		Notify();
		//A3 statistics observer
		this->change = 1;
		cout << "Mobile success" << endl;
	}


	else {

		cout << "Your destination has been occupied by other players." << endl; return 0;
	}
	return 1;
}

//Move over land and/or water.
int Player::MoveOverLand(Territory* A, Territory* B, int army) {

	//if the continent name is not as same as the continent player wanna to move 
	if (A->getContinentName().compare(B->getContinentName()) != 0) {


		//if the move more than 3 then you can across the continent
		//
		if (getMove() > 3) {


			//if no player occupied the land, we can attack this land. 
			if (B->getPlayer().empty()) {
				//Territory* BB = new Territory(*B);

				//kill the army in territory A
				A->setArmy(-army);

				//set the army num 
				B->setArmy(army);

				//change the name 
				B->setPlayer(getName());
				territory.push_back(B);

				//move between the contentine, army num auto -3.
				setMove(-army - 3);
				cout << "Placement success" << endl;

				//A3 Action Observer
				this->active = 2;
				Notify();
				//A3 statistics observer
				this->change = 1;
				return 1;
			}

			//if the same player own this land .
			else if (B->getPlayer().compare(getName()) == 0) {

				//army move from a to b
				A->setArmy(-army);
				B->setArmy(army);

				//move between the contentine, army num auto -3.
				setMove(-army - 3);
				cout << "Placement success" << endl;

				//A3 Action Observer
				this->active = 2;
				Notify();
				//A3 statistics observer
				this->change = 1;

				return 1;
			}
			else {
				cout << "Your destination has been occupied by other players." << endl;
				return 0;
			}
		}
		else {

			cout << "You need more than three movement to cross continent." << endl;
			return 0;
		}
	}
	else {
		cout << "You destination is in the same continent." << endl;
		return 0;
	}
}

//method to destory army 
int Player::DestroyArmy(Territory* territory, int num) {
	territory->setArmy(-num);
	
	//A3 Action Observer
	this->active = 5;
	Notify();
	//A3 statistics observer
	this->change = 2;
	cout << "Successful destruction" << endl;
	return 1;
}

//Set Method
void Player::setArmy(int army) {
	this->army -= army;
}
void Player::setMove(int move) {
	this->move += move;
}
void Player::setCoin(int coin) {
	this->coin -= coin;
}
void Player::setHandCard(Cards* object) {
	this->handCard.push_back(object);
	//A3 - active
	active = 6;
	Notify();
}
void Player::setTerritory(Territory* object) {
	this->territory.push_back(object);
}
void Player::setCityToken(int token) {
	this->cityToken = token;
}
void Player::setBidding(BiddingFacility* object) {
	delete bid;
	bid = nullptr;
	this->bid = new BiddingFacility(*object);
	//this->bid = object;
}

//A3- set num
void Player::setNum(int num) {
	this->num = num;
};


//Get Method
string Player::getName() {
	return name;
}
int Player::getMove() {
	return move;
}
int Player::getCoin() {
	return coin;
}
int Player::getArmy() {
	return army;
}
int Player::getBidding() {
	return bid->getBid();
}

vector<Territory*> Player::getTerritory() {
	return territory;
}
vector<Cards*> Player::getHandCard() {
	return handCard;
}

Territory* Player::getTerritoryById(int tid)
{
	for (auto i = 0; i < territory.size(); i++) {
		if (territory[i]->getTID() == tid)
			return territory[i];
	}
	return nullptr;
}

//Service Method
bool Player::check_territory(Territory* object) {
	for (int i = 0; i < territory.size(); i++) {
		if (territory[i]->getPlayer().compare(object->getPlayer()) == 0) {
			return false;
		}
	}
	return true;
}
void Player::printTerritory(){
	for (int i = 0; i < territory.size(); i++) {
		cout << *territory[i];
	}
}
//Stream Insertion Operator
ostream& operator<< (ostream& output, const Player& object) {
	output << "Player Info --";
	output << " Name: << " << object.name << " >> Movement: << " << object.move << " >> Coin: << " << object.coin << " >>  Army: << " << object.army << " >> City Token: << " << object.cityToken<<" >>"<<endl;
	if (object.handCard.size() != 0) {
		output << "Player Hand Card : \n";
		for (int i = 0; i < object.handCard.size(); i++) {
			output << i + 1;
			output << " -- " << *(object.handCard[i]);
		}
	}
	if (object.territory.size() != 0) {
		output << "Player Territory : \n";
		for (int i = 0; i < object.territory.size(); i++) {
			output << i + 1;
			output << " -- " << *(object.territory[i]);
		}
	}
	return output;
}
//part 6 by nian
void Player::loadCardMap(CardScord* cs1)
{
	int n = this->getHandCard().size();
	for (int i = 0; i < n; i++) {
		if ((this->getHandCard())[i]->getCardName().find("Ancient") != -1) {
			(this->getHandCard())[i]->Ancient(cs1);
		}
		if ((this->getHandCard())[i]->getCardName().find("Cursed") != -1) {
			(this->getHandCard())[i]->Cursed(cs1);
		}
		if ((this->getHandCard())[i]->getCardName().find("Dire") != -1) {
			(this->getHandCard())[i]->Dire(cs1);
		}
		if ((this->getHandCard())[i]->getCardName().find("Forest") != -1) {
			(this->getHandCard())[i]->Forest(cs1);
		}
		if ((this->getHandCard())[i]->getCardName().find("Night") != -1) {
			(this->getHandCard())[i]->Night(cs1);
		}
		if ((this->getHandCard())[i]->getCardName().find("Noble") != -1) {
			(this->getHandCard())[i]->Noble(cs1);
		}
		if ((this->getHandCard())[i]->getCardName().find("Graveyard") != -1) {
			cs1->cs["Graveyard"] += 1;
		}
		if ((this->getHandCard())[i]->getCardName().find("Lake") != -1) {
			cs1->cs["Lake"] += 1;
		}
		if ((this->getHandCard())[i]->getCardName().find("Stronghold") != -1) {
			cs1->cs["Stronghold"] += 1;
		}

	}
}
int Player::calCS(CardScord* cs1)
{
	int score = 0;
	if (cs1->cs["Arcane Temple"] == 1) {
		score += cs1->cs["Arcane"];
	}
	if (cs1->cs["Ancient Sage"] == 1) {
		score += cs1->cs["Ancient"];
	}
	if (cs1->cs["Graveyard"] == 1) {
		score += cs1->cs["Cursed"];
	}
	if (cs1->cs["Cursed Tower"] == 1) {
		score += cs1->cs["Flying"];
	}
	if (cs1->cs["Stronghold"] == 1) {
		score += cs1->cs["Dire"];
	}
	if (cs1->cs["Lake"] == 1) {
		score += cs1->cs["Forest"];
	}
	if (cs1->cs["Night Wizard"] == 1) {
		score += cs1->cs["Night"];
	}
	if (cs1->cs["Noble Hills"] == 1 && cs1->cs["Noble"] == 3) {
		score += 4;
	}
	if (cs1->cs["Mountain Dwarf"] == 1 && cs1->cs["Mountain"] == 2) {
		score += 3;
	}
	if (cs1->cs["Dire Ogre"] == 1) {
		score += this->getCoin() / 3;
	}
	return score;

}





// And / or action 


//every player 6 cards
//AND 
//OR
//TWO ACTION CARDS

void Player::getNowHandAction(vector<int>& actionCode, vector<string>& actionsStr)
{
	//all action

// HAND CARD FROM CARD DECK
	Cards* now = handCard.back();

	//read the action from the card
	string cardAction = now->getCardAction();

	//if the card is AND card
	size_t And = cardAction.find("AND");

	//if the card is OR card
	size_t Or = cardAction.find("OR");
	string buf;
	int tmp = 0;
	int ch = 0;

	//include at least one "AND"
	if (And != string::npos) {

		//do the action before and
		actionsStr.push_back(cardAction.substr(0, And));

		//do the action after and
		actionsStr.push_back(cardAction.substr(And + string("AND ").size()));
	}

	//include at least one "OR"
	else if (Or != string::npos) {

		//make your choice
		cout << "1." << cardAction.substr(0, Or) << endl;
		cout << "2." << cardAction.substr(Or + string("OR ").size()) << endl;
		cout << "Enter the action of your choice:";
		cin >> ch;


		while (true) {
			if (ch == 1 || ch == 2)
				break;
			cout << "Please enter 1 or 2" << endl;
			cout << "Enter the action of your choice:";
		}

		//do the action before OR
		if (ch == 1) {
			actionsStr.push_back(cardAction.substr(0, Or));
		}
		else {

			//do the action after OR
			actionsStr.push_back(cardAction.substr(Or + string("OR ").size()));
		}
	}

	//no action, miss the choice
	else {
		actionsStr.push_back(cardAction);
	}


	/*
Place
Move
Build
Destroy
*/



// action cost 

	for (int i = 0; i < actionsStr.size(); i++) {
		stringstream ss(actionsStr[i]);
		tmp = 0;
		ss >> buf;
		if (buf.compare("Place") == 0) {
			ss >> tmp;
			tmp += 1000;
		}
		else if (buf.compare("Move") == 0) {
			ss >> tmp;
			tmp += 2000;
		}
		else if (buf.compare("Build") == 0) {
			tmp = 3000;
		}
		else if (buf.compare("Destroy") == 0) {
			tmp = 4000;
		}
		else {
			cout << "Unknown command��" << buf << endl;
		}
		ss.clear();
		actionCode.push_back(tmp);
	}
}


// main control stream

void Player::dealWithHand(vector<Player*> allPlayer, MapLoader* mapLoader)
{
	vector<int> code;
	vector<string> describe;
	int ch = 0;
	int tmp = 0;	//temp 
	int num = 0;	//action number

	//use money to move 
	int goldMove = 0;
	Territory* A = NULL;	//FROM A TO B 
	Territory* B = NULL;
	Player* obj = NULL;		//OBJ BEING ATTACK
	//code stands for the num of action 
	getNowHandAction(code, describe);

	//vaild card if code >0
	while (code.size() > 0) {
		cout << "=======================" << endl;
		for (int i = 0; i < describe.size(); i++) {
			cout << i + 1 << ". " << describe[i] << endl;
		}
		cout << "code 0 - The end of the action" << endl;
		cout << "Enter the action of your choice:";
		cin >> ch;
		while (true) {
			if (ch >= 0 && ch <= code.size())
				break;
			cout << "Please enter 0 -- " << code.size() << endl;
			cout << "Enter the action of your choice:";
		}
		if (ch == 0)
			break;
		ch--;
		cout << "=======================" << endl;





		//delete  this action
		tmp = code[ch];
		code[ch] = code.back();
		code.pop_back();
		describe[ch] = describe.back();
		describe.pop_back();

		switch (tmp / 1000)
		{
		case 1:
		{
			num = tmp % 1000;
			while (num > 0) {
				int j = 1;
				for (auto i = 0; i < territory.size(); i++) {
					if (territory[i]->getBuildCity() && territory[i]->getPlayer() == this->name) {
						cout << "code: " << j++ << endl;
						cout << *(territory[i]) << endl;
					}
				}
				cout << "code 0 - The end of the action" << endl;
				cout << "Enter the code of your choice:";
				cin >> ch;
				while (true) {
					if (ch >= 0 && ch < j)
						break;
					cout << "Please enter 0 -- " << territory.size() << endl;
					cout << "Enter the action of your choice:";
					cin >> ch;
				}
				if (ch == 0)
					break;
				j = 1;
				for (auto i = 0; i < territory.size(); i++) {
					if (territory[i]->getBuildCity() && territory[i]->getPlayer() == this->name && ch == j++) {

						A = getTerritoryById(territory[i]->getTID());
						int m;
						cout << "Place num:" << endl;
						cin >> m;
						if (m > num) {
							cout << "quantity not sufficient " << endl;
							break;
						}
						if (PlaceNewArmies(A, m) < 1) {
							break;
						}
						num -= m;
						;
					}
				}
			}
		}
		break;

		case 2:
		{
			move = tmp % 1000;
			while (move > 0) {
				int j = 1;
				//CHOOSE A 
				for (auto i = 0; i < territory.size(); i++) {
					cout << "code:" << j++ << endl;
					cout << *(territory[i]) << endl;
				}
				cout << "code 0 - The end of the action" << endl;
				cout << "Choose A point" << endl;
				cout << "Enter the code of your choice:";
				cin >> ch;
				while (true) {
					if (ch >= 0 && ch < j)
						break;
					cout << "Please enter 0 -- " << territory.size() << endl;
					cout << "Enter the action of your choice:";
					cin >> ch;
				}
				if (ch == 0)
					break;
				j = 1;
				for (auto i = 0; i < territory.size(); i++) {
					if (ch == j++) {
						A = territory[i];
						break;
					}
				}

				//CHOOSE B
				j = 1;
				for (auto i = 0; i < A->getAdjacentTerritoryInMap().size(); i++) {
					cout << "code:" << j++ << endl;
					cout << *(mapLoader->worldMap->getTerritoryById(A->getAdjacentTerritoryInMap()[i])) << endl;
				}
				cout << "code 0 - The end of the action" << endl;
				cout << "Choose B point" << endl;
				cout << "Enter the code of your choice:";
				cin >> ch;
				while (true) {
					if (ch >= 0 && ch < j)
						break;
					cout << "Please enter 0 -- " << A->getAdjacentTerritoryInMap().size() << endl;
					cout << "Enter the action of your choice:";
					cin >> ch;
				}
				if (ch == 0)
					break;
				j = 1;
				for (auto i = 0; i < A->getAdjacentTerritoryInMap().size(); i++) {
					if (ch == j++) {
						B = this->getTerritoryById(A->getAdjacentTerritoryInMap()[i]);
						if (B == NULL) {
							B = (mapLoader->worldMap->getTerritoryById(A->getAdjacentTerritoryInMap()[i]));
						}
						break;
					}
				}

				if (A && B) {
					int m;
					cout << "Move num:" << endl;
					cin >> m;
					goldMove = 0;
					if (A->continentID != B->continentID) {
						cout << "The voyage takes three steps(1.Yes  2.No)" << endl;
						cin >> goldMove;
						if (goldMove == 1) {
							goldMove = 3;
						}
						else {
							goldMove = 0;
							continue;
						}
					}

					if (m + goldMove > move) {
						cout << "quantity not sufficient " << endl;
					}
					else {
						if (goldMove)
							MoveOverLand(A, B, m);
						else
							MoveArmies(A, B, m);

						break;
					}
				}
				else {
					cout << "Not found" << endl;
				}

			}
			move = 0;

		}
		break;
		//Build City Function
		case 3:
		{
			num = 1;
			while (num > 0) {
				int j = 1;
				for (auto i = 0; i < territory.size(); i++) {
					if (!territory[i]->getBuildCity()) {
						cout << "code:" << j++ << endl;
						cout << *(territory[i]) << endl;
					}
				}
				cout << "code 0 - The end of the action" << endl;
				cout << "Enter the code of your choice:";
				cin >> ch;
				while (true) {
					if (ch >= 0 && ch < j)
						break;
					cout << "Please enter 0 -- " << territory.size() - 1 << endl;
					cout << "Enter the action of your choice:";
					cin >> ch;
				}
				if (ch == 0)
					break;
				j = 1;
				for (auto i = 0; i < territory.size(); i++) {
					if (!territory[i]->getBuildCity()) {
						A = getTerritoryById(territory[i]->getTID());

						if (BuildCity(A) < 1) {
							break;
						}
						num = 0;;
						break;
					}
				}
			}
		}
		break;
		case 4:
		{
			num = 1;
			while (num > 0) {
				int j = 1;
				for (auto i = 0; i < allPlayer.size(); i++) {
					if (allPlayer[i] != this) {
						cout << "code:" << j++ << endl;
						cout << *(allPlayer[i]) << endl;
					}
				}
				cout << "code 0 - The end of the action" << endl;
				cout << "Enter the code of your choice:";
				cin >> ch;
				while (true) {
					if (ch >= 0 && ch < j)
						break;
					cout << "Please enter 0 -- " << allPlayer.size() << endl;
					cout << "Enter the action of your choice:";
					cin >> ch;
				}
				if (ch == 0)
					break;
				j = 1;
				for (auto i = 0; i < allPlayer.size(); i++) {
					if (allPlayer[i] != this && ch == j++) {
						obj = allPlayer[i];
						break;
					}
				}
				j = 1;
				for (auto i = 0; i < obj->territory.size(); i++) {
					cout << "code:" << j++ << endl;
					cout << *(obj->territory[i]) << endl;
				}
				cout << "code 0 - The end of the action" << endl;
				cout << "Enter the code of your choice:";
				cin >> ch;
				while (true) {
					if (ch >= 0 && ch < j)
						break;
					cout << "Please enter 0 -- " << obj->territory.size() << endl;
					cout << "Enter the action of your choice:";
					cin >> ch;
				}
				if (ch == 0)
					break;
				j = 1;
				for (auto i = 0; i < obj->territory.size(); i++) {
					if (ch == j++) {
						obj->DestroyArmy(obj->territory[i], 1);
						num = 0;
						break;
					}
				}
			}
		}
		default:
			break;
		}
		cout << "=======================" << endl;

	}
}

void Player::fitMap(vector<Player*> allPlayer, MapLoader* mapLoader)
{

	//Delete the area where there is no army and the city is not used
	for (auto i = 0; i < allPlayer.size(); i++) {
		for (auto j = 0; j < allPlayer[i]->territory.size(); j++) {
			if (allPlayer[i]->territory[j]->getArmyNum() <= 0 && allPlayer[i]->territory[j]->getBuildCity() == false) {
				allPlayer[i]->territory.erase(allPlayer[i]->territory.begin() + j);
				j--;
			}
		}
	}
	//The player��s city occupation status is synchronized to the map 
	for (auto i = 0; i < allPlayer.size(); i++) {
		for (auto j = 0; j < allPlayer[i]->territory.size(); j++) {
			if (!allPlayer[i]->territory[j]->getPlayer().empty()) {
				Territory* p = mapLoader->worldMap->getTerritoryById(allPlayer[i]->territory[j]->getTID());
				if (p)
					p->setPlayer(allPlayer[i]->territory[j]->getPlayer());
			}
		}
	}
	//The city occupation of the map is synchronized to the player
	for (auto z = 0; z < mapLoader->worldMap->allTerritory.size(); z++) {
		for (auto i = 0; i < allPlayer.size(); i++) {
			Territory* p = allPlayer[i]->getTerritoryById(mapLoader->worldMap->allTerritory[z]->getTID());
			if (p)
				p->setPlayer(mapLoader->worldMap->allTerritory[z]->getPlayer());
		}
	}
}