#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Territory;
class Cards;

class Player {

public:
	//Constructor
	Player();
	Player(string name,int coin,int move,vector<Territory*> territory,vector<Cards*> handCard);
	//Copy constructor
	Player(const Player& object);
	//Assignment Operator
	Player& operator = (const Player&);
	//Destructor
	~Player();

	//Method Required by Part 2
	void PayCoin(int coin);
	void PlaceNewArmies(Territory* territory,int army);
	void MoveArmies(Territory* A,Territory* B,int army);
	void MoveOverLand(Territory* A, Territory* B,int army);
	void BuildCity(Territory* territory);
	void DestroyArmy(Territory* territory,int army);

	//Get Method
	string getName();
	int getMove();
	vector<Territory*> getTerritory();
	//vector<Card*> get_handCard();

	//Set Method
	void setArmy(int army);
	void setMove(int move);

	//Service Method
	bool check_territory(Territory* object);
	void printTerritory();
	void toString();


private:
	string name;
	int coin,move,army,cityToken;
	vector<Territory*> territory;
	vector<Cards*> handCard;
};

//Territory Class For Debug
class Territory {

public:
	//Constructor
	Territory();
	Territory(string territoryName,string continentName,int tID,int continentID,bool connectedForeignContient,string player,bool build_city,int armyAmount);
	~Territory();

	//Get Method
	bool getBuildCity();
	string getPlayer();
	int getArmyNum();
	string getContinentName();
	
	//Set Method
	void setArmy(int);
	void setBuildCity();
	void setPlayer(string player);

	//Service Method
	void toString();
private:
	string tName, continentName, player;
	int tID,continentID;
	bool build_city;
	int armyNum;
	bool connectedForeignContinent;
};

//Card Class For Debug
class Cards {

public:
	Cards();
	Cards(string active);

private:
	string active;
};