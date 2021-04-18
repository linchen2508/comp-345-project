#include "Cards.h"
#include "Player.h"
#include "Map.h"
#include "MapLoader.h"
#include "GameEngine.h"
#include "PlayerStrategies.h"
#include <string>

using namespace std;

int main() {

	//create a new game engine
	GameEngine* gamebot = new GameEngine();
	//create a statistic observers
	StatisticsObserver* S1 = new StatisticsObserver(gamebot);
	//set name of the players
	gamebot->setPlayers();
	//create 2
	ActionObserver* A1 = new ActionObserver(gamebot->getPlayerVector()[0]);
	ActionObserver* A2 = new ActionObserver(gamebot->getPlayerVector()[1]);
	gamebot->setMap();
	gamebot->setStartRegoin();
	gamebot->setNonPlayerArmy();
	gamebot->setDeck();
	gamebot->setHand();


	int mode;
	cout << "Type 1 for tournament mode and 2 for single game mode: \n";
	cin >> mode;
	//tournament mode
	if (mode == 1) {
		gamebot->gameLoopTournament();
		//gamebot->computeScord();   
    }

	// 2 human player mode
	if (mode == 2) {
		gamebot->gameloop();
		//gamebot->computeScord();
	}
	return 0;
}
