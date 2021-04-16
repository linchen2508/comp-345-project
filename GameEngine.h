#pragma once
#include "Player.h"
#include <vector>

class GameEngine {

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

	//Service Method
	void gameloop();
	void computeScord();


private:
	vector<Player*> players;
	Deck* playingDeck;
	Hand* hand;
	MapLoader* wml;
	string mode;
};