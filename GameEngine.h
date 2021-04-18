#pragma once
#include "Player.h"
#include <vector>

class GameEngine : public GameSubject {

public:
	GameEngine();
	~GameEngine();

	//Set Method
	void setPlayers();
	void setMap(); 
	void setStartRegoin();
	void setNonPlayerArmy();
	void setDeck();
	void setHand();

	//Get Method
	Deck* getDeck() { return playingDeck; };
	Hand* getHand() { return hand; };
	vector<Player*> getPlayerVector() { return players; };
	MapLoader* getMapLoader() { return wml; };
	int getNum() { return num; };
	//For statistics Obeserver
	int getPlayerIndex() { return playerIndex; };
	string getPlayerContinent(Player* object);
	int getPlayerContinentNum(Player* object);
	int getVictoryPoint(Player* object);

	//Service Method
	void gameloop();
	void gameLoopForDemo4();
	void gameLoopTournament();
	void computeScord();

	
private:
	vector<Player*> players;
	Deck* playingDeck;
	Hand* hand;
	MapLoader* wml;
	string mode;

	//For Statistics Observer
	int num;
	int playerIndex;
};