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
//    GameEngine* gamebot = new GameEngine();
//    StatisticsObserver* S1 = new StatisticsObserver(gamebot);
//
//    gamebot->setPlayers();
//    //Oberserver For Part 2
//    ActionObserver* A1 = new ActionObserver(gamebot->getPlayerVector()[0]);
//    ActionObserver* A2 = new ActionObserver(gamebot->getPlayerVector()[1]);
//    
//    gamebot->setDeck();
//    gamebot->setHand();
//    gamebot->setMap();
//    
//    gamebot->setStartRegoin();
//
//    //variable to keep track how many card each player has drawn
//    int numberOfCardEachPlayer = 0;
//
//    cout << "\n\n//***** ONLY FOR DEMO PART 2 and 3 with 4 Rounds and NOT USE GameEngine Loop *****//\n" << endl;
//
//    gamebot->gameLoopForDemo4();
//
//    delete gamebot;
//    gamebot = NULL;
//    delete A1;
//    A1 = NULL;
//    delete A2;
//    A2 = NULL;
//}