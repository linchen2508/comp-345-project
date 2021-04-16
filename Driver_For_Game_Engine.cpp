/***** Memory Leak Check *****/
#define _DEBUG
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#define _CRTDBG_MAP_ALLOC
#include <memory>
/****************************/
#include "Cards.h"
#include "Player.h"
#include "Map.h"
#include "MapLoader.h"
#include "GameEngine.h"
#include <string>

using namespace std;

int main() {

	GameEngine *gamebot = new GameEngine();

	//Comment out for debug

	//GOOD FOR USE
	gamebot->setPlayers();
	gamebot->setMap();
	gamebot->setStartRegoin();
	gamebot->setNonPlayerArmy();


	gamebot->setDeck();
	

	gamebot->setHand();
	
	gamebot->gameloop();

	gamebot->computeScord();

	return 0;
}