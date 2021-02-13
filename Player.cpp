#include "Player.h";

using namespace std;

//Default Construtor
Player::Player()
{
	name = "Default";
	move = 0;
	coin = 0;
	army = 18;
	cityToken = 3;
	vector<Territory*> territory;
	vector<Cards*> handCard;
}

//Construtor with parameter
Player::Player(string name,int coin,int move,vector<Territory*> territory,vector<Cards*> handCard)
{
	this->name = name;
	this->coin = coin;
	this->move = move;
	this->army = 18;
	this->cityToken = 3;
	this->territory = territory;
	this->handCard = handCard;
}

//Copy Constructor
Player::Player(const Player& object) {
	this->name = object.name;
	this->coin = object.coin;
	this->move = object.move;
	this->army = object.army;
	this->cityToken = object.cityToken;
	this->territory = object.territory;
	this->handCard = object.handCard;
}

//Assignment Operator
Player& Player::operator=(const Player& object) {
	this->name = object.name;
	this->coin = object.coin;
	this->move = object.move;
	this->army = object.army;
	this->cityToken = object.cityToken;
	this->territory = object.territory;
	this->handCard = object.handCard;
	return *this;
}

//Destructor
Player::~Player() {
	name = "";
	coin = 0;
	move = 0;
	army = 0;
	cityToken = 0;
	territory.clear();
	handCard.clear();
	vector<Territory*>().swap(territory);
	vector<Cards*>().swap(handCard);
};

//Method Required by Part 2
void Player::PayCoin(int coin) {
	this->coin = this->coin - coin;
}

void Player::BuildCity(Territory* territory) {
	territory->setBuildCity();
	cityToken = cityToken -1 ;
}

void Player::PlaceNewArmies(Territory* territory, int army) {
	if (this->territory.empty()) {
		territory->setPlayer(getName());
		territory->setArmy(army);
		setArmy(4);
		territory->setBuildCity();
		this->territory.push_back(territory);
	}
	else if (territory->getBuildCity() == true) {
		territory->setArmy(army);
	}
	else {
		cout << "You can not place new armies in the territory without a city." << endl;
	}
}

//Move army from point A to point B
void Player::MoveArmies(Territory* A,Territory* B,int army) {
	//Check point B whether occupied by player
	if (B->getPlayer().empty()) {
		A->setArmy(-army);
		B->setArmy(army);
		B->setPlayer(getName());	
		territory.push_back(B);
		setMove(-army);
	}
	else if (B->getPlayer().compare(getName()) == 0) {
		A->setArmy(-army);
		B->setArmy(army);
		setMove(-army);
	}
	else {
		cout << "Your destination has been occupied by other players." << endl;
	}
}

void Player::MoveOverLand(Territory* A, Territory* B, int army) {

	if (A->getContinentName().compare(B->getContinentName()) != 0) {

		if (getMove() > 3) {

			if (B->getPlayer().empty()) {
				A->setArmy(-army);
				B->setArmy(army);
				B->setPlayer(getName());
				territory.push_back(B);
				setMove(-army - 3);
			}
			else if (B->getPlayer().compare(getName()) == 0) {
				A->setArmy(-army);
				B->setArmy(army);
				setMove(-army - 3);
			}
			else {
				cout << "Your destination has been occupied by other players." << endl;
			}
		}
		else {
			cout << "You need more than three movement to cross continent." << endl;
		}
	}
	else {
		cout << "You destination is in the same continent." << endl;
	}
}

void Player::DestroyArmy(Territory* territory, int num) {
	territory->setArmy(-num);
}

//Set Method
void Player::setArmy(int army) {
	this->army -= army;
}
void Player::setMove(int move) {
	this->move += move;
}

//Get Method
string Player::getName() {
	return name;
}
int Player::getMove() {
	return move;
}
vector<Territory*> Player::getTerritory() {
	return territory;
}

//Service Method
void Player::toString() {
	cout << "Player Name: " << name << "\nMovement: " << move << "\nCoin: " << coin << "\nArmy: " << army << "\nCity Token: " << cityToken << endl;
}
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
		territory[i]->toString();
	}
}



/**** Territory Method *****/
Territory::Territory() {
	tName = "";
	continentName = "";
	player = "";
	tID = 0;
	continentID = 0;
	armyNum = 0;
	connectedForeignContinent = false;
	build_city = false;
}

Territory::Territory(string territoryName, string continentName, int tID, int continentID, bool connectedForeignContient, string player, bool build_city, int armyNum) {
	this->tName = tName;
	this->continentName = continentName;
	this->tID = tID;
	this->continentID = continentID;
	this->connectedForeignContinent = connectedForeignContient;
	this->player = player;
	this->armyNum = armyNum;
	this->build_city = build_city;
}
Territory::~Territory() {}

//Get Method
bool Territory::getBuildCity() {
	return build_city;
}
int Territory::getArmyNum() {
	return armyNum;
}
string Territory::getPlayer() {
	return player;
}
string Territory::getContinentName() {
	return continentName;
}

//Set Method
void Territory::setBuildCity() {
	build_city = true;
}
void Territory::setArmy(int army) {
	armyNum += army;
}

void Territory::setPlayer(string player) {
	this->player = player;
}

//Service Method
void Territory::toString() {
	string temp, place_hold;
	if (build_city == 0) {
		temp = "No";
	}
	else {
		temp = "Yes";
	}
	if (player.length() == 0) {
		place_hold = "None";
	}
	cout <<"Territory Name: "<< tName <<" Player: "<< player << place_hold<< 
		" Build City: "<<temp<<" Army: "<<armyNum<<endl;
}


/*** Card Method ***/
Cards::Cards() {
	active = "new";
}
Cards::Cards(string active) {
	this->active = active;
}