//#include "Cards.h"
//#include "Player.h"
//#include "Map.h"
//#include "MapLoader.h"
//#include "GameEngine.h"
//#include <string>
//
//using namespace std;
//
//int main() {
//
//	GameEngine *gamebot = new GameEngine();
//
//	StatisticsObserver* S1 = new StatisticsObserver(gamebot);
//
//	
//	//Comment out for debug
//
//	//GOOD FOR USE
//	gamebot->setPlayers();
//	ActionObserver* A1 = new ActionObserver(gamebot->getPlayerVector()[0]);
//	ActionObserver* A2 = new ActionObserver(gamebot->getPlayerVector()[1]);
//
//	gamebot->setMap();
//	gamebot->setStartRegoin();
//	//gamebot->setNonPlayerArmy();
//
//
//	gamebot->setDeck();
//
//	gamebot->setHand();
//
//	gamebot->gameloop();
//
//	return 0;
//}