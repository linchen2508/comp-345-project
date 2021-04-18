#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Map.h"
#include "Cards.h"
#include "BiddingFacility.h"
#include "MapLoader.h"
#include "GameObservers.h"

using namespace std;


class Player : public PlayerSubject {

public:
	//Constructor
	Player();
	Player(string name);
	Player(string name,int coin,int move,vector<Territory*> territory,vector<Cards*> handCard, BiddingFacility* bid);
	//Copy constructor
	Player(const Player& object);
	//Assignment Operator
	Player& operator = (const Player&);
	//Destructor
	~Player();

	//Method Required by Part 2
	void PayCoin(int coin);

	//Active Observer int = 1	
	int PlaceNewArmies(Territory* territory, int army);	//Change to create a new one and then copy  2-part4 --- Can not Create new one, patern need to observer
	//Active Observer int = 2
	int MoveArmies(Territory* A, Territory* B, int army);//Change to create a new one and then copy  2-part4--- Can not Create new one  patern need to observer
	//Active Observer int = 3
	int MoveOverLand(Territory* A, Territory* B, int army);//Change to create a new one and then copy  2-part4--- Can not Create new one  patern need to observer
	//Active Observer int = 4
	int BuildCity(Territory* territory);
	//Active Observer int = 5
	int DestroyArmy(Territory* territory, int army);

	//Get Method
	string getName();
	int getMove();
	int getCoin();
	int getArmy();
	int getBidding();
	int getCityToken() { return cityToken; };//For A3
	int getActive() { return active; }; //For A3
	int getNum() { return num; }; //For A3
	int getChange() { return change; };//For A3
	int getTerritoryNum(){
		int count = 0;
		for (int i = 0; i < getTerritory().size(); i++) {
			if (getTerritory()[i]->getArmyNum() > getTerritory()[i]->getWhiteNum()) {
				count++;
			}
		}
		return count;
	};
	vector<Territory*> getTerritory();
	vector<Cards*> getHandCard();
	Territory* getTerritoryById(int tid);		//THROUGH tid TO GAIN OBJECT Territory  2-part4

	//Set Method
	void setArmy(int army);
	void setMove(int move);
	void setCoin(int coin);
	void setHandCard(Cards* object);
	void setCityToken(int token);
	void setBidding(BiddingFacility* object);
	void setTerritory(Territory* object);
	//A3 - Set Name
	void setName(string name) { this->name = name; };
	void setChange(int num) { this->change = num; };
	//A3- set num
	void setNum(int num);
	
	//Actions to deal with cards  2-part4
	void getNowHandAction(vector<int>& actionCode, vector<string>& actionsStr);		//According to the current card action Get the code representing the action (1 or 2 two actions) )  2-part4
	void dealWithHand(vector<Player*> allPlayer, MapLoader* mapLoader);	//Actions to deal with cards   2-part4

	//Keep the player in line with the map  2-part4
	void fitMap(vector<Player*> allPlayer, MapLoader* mapLoader);

	//Service Method
	bool check_territory(Territory* object);
	void printTerritory();

	//Stream Insertion Operator
	friend ostream& operator<<(ostream& output, const Player& object);

	//part 6 by nian
	void loadCardMap(CardScord* cs);
	int calCS(CardScord* cs);

private:
	string name;
	int coin,move,army,cityToken;
	vector<Territory*> territory;
	vector<Cards*> handCard;
	BiddingFacility* bid;


	//For A3 active observer
	int active;
	//For A3 statistic obeserver
	int change;
	int num;// player select card number

};

