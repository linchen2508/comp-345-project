/***** Memory Leak Check *****/
#define _DEBUG
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#define _CRTDBG_MAP_ALLOC
#include <memory>
/****************************/
#include "Player.h";
#include "MapLoader.h";
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	//**check for memory leaks**//
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	/********** PART 1 **********/
	cout << "/********** PART 1 **********/" << endl;

		Territory* t0 = new Territory("t0", "c0", 0, 0);
	    Territory* t1 = new Territory("t1", "c0", 1, 0);
	    Territory* t2 = new Territory("t2", "c1", 2, 1);
	    Territory* t3 = new Territory("t3", "c1", 3, 1);
	    Territory* t4 = new Territory("t4", "c2", 4, 2);
	    Territory* t5 = new Territory("t5", "c2", 5, 2);
	    Territory* t6 = new Territory("t6", "c2", 6, 2);
	
	    Continent* c0 = new Continent("c0", 0);
	    Continent* c1 = new Continent("c1", 1);
	    Continent* c2 = new Continent("c2", 2);
	
	    Map* m0 = new Map("BigMap", 7, 3);
	
	    m0->allTerritory.push_back(t0);
	    m0->allTerritory.push_back(t1);
	    m0->allTerritory.push_back(t2);
	    m0->allTerritory.push_back(t3);
	    m0->allTerritory.push_back(t4);
	    m0->allTerritory.push_back(t5);
	    m0->allTerritory.push_back(t6);
	    m0->allContinent.push_back(c0);
	    m0->allContinent.push_back(c1);
	    m0->allContinent.push_back(c2);
	
	    std::cout << m0->getNumOfAllContinent() << std::endl;
	    m0->printAllContinent();
	    m0->setMapName("BBigMap");
	
	    std::cout << m0->getMName() << std::endl;
	    std::cout << m0->getNumOfAllTerritory() << std::endl;
	    std::cout << t1->getContinentName() << std::endl;
	    //t1.setConnectedForeignContinent(true);//default false
	    t0->adjacentTerritoryInMap.push_back(0);
	    t0->adjacentTerritoryInMap.push_back(1);
	    t0->adjacentTerritoryInMap.push_back(2);
	    t0->adjacentTerritoryInSameContinent.push_back(1);
	
	    t1->adjacentTerritoryInMap.push_back(0);
	    t1->adjacentTerritoryInMap.push_back(1);
	    t1->adjacentTerritoryInSameContinent.push_back(0);
	
	    t2->adjacentTerritoryInMap.push_back(0);
	    t2->adjacentTerritoryInMap.push_back(2);
	    t2->adjacentTerritoryInMap.push_back(3);
	    t2->adjacentTerritoryInSameContinent.push_back(3);
	
	    t3->adjacentTerritoryInMap.push_back(2);
	    t3->adjacentTerritoryInMap.push_back(3);
	    t3->adjacentTerritoryInMap.push_back(5);
	    t3->adjacentTerritoryInSameContinent.push_back(2);
	
	    t4->adjacentTerritoryInMap.push_back(4);
	    t4->adjacentTerritoryInMap.push_back(5);
	    t4->adjacentTerritoryInMap.push_back(6);
	    t4->adjacentTerritoryInSameContinent.push_back(5);
	    t4->adjacentTerritoryInSameContinent.push_back(6);
	
	    t5->adjacentTerritoryInMap.push_back(3);
	    t5->adjacentTerritoryInMap.push_back(4);
	    t5->adjacentTerritoryInMap.push_back(5);
	    t5->adjacentTerritoryInSameContinent.push_back(4);
	
	    t6->adjacentTerritoryInMap.push_back(4);
	    t6->adjacentTerritoryInMap.push_back(6);
	    t6->adjacentTerritoryInSameContinent.push_back(4);
	
	
	    int tLen = m0->allTerritory.size();
	    for (int i = 0; i < tLen; i++) {
	        cout << "Territory name: " << m0->allTerritory[i]->getTName();
	        cout << " Territory adjacentInMap:";
	        m0->allTerritory[i]->printTerritoryVector(m0->allTerritory[i]->adjacentTerritoryInMap);
	        cout << " Territory adjacentInSameContinent:";
	        m0->allTerritory[i]->printTerritoryVector(m0->allTerritory[i]->adjacentTerritoryInSameContinent);
	        cout << endl;
	    }
	
	    c0->territoryMemberInContinent.push_back(t0);
	    c0->territoryMemberInContinent.push_back(t1);
	    c0->reachableForeignContinent.insert(1);
	    c1->territoryMemberInContinent.push_back(t2);
	    c1->territoryMemberInContinent.push_back(t3);// comment out any of these will break the continent subGraph
	    c1->reachableForeignContinent.insert(0);
	    c1->reachableForeignContinent.insert(2);
	    c2->territoryMemberInContinent.push_back(t4);
	    c2->territoryMemberInContinent.push_back(t5);
	    c2->territoryMemberInContinent.push_back(t6);
	    c2->reachableForeignContinent.insert(1);
	
	    bool check;
	    check = c0->checkSubGraph();
	    cout << "Continent0 subgraph is connected? " << check << endl;
	    check = c1->checkSubGraph();
	    cout << "Continent1 subgraph is connected? " << check << endl;
	    check = c2->checkSubGraph();
	    cout << "Continent2 subgraph is connected? " << check << endl;
	
	    m0->validate();
	
	    delete m0;
	    m0 = nullptr;
	    delete c0;
	    c0 = nullptr;
	    delete c1;
	    c1 = nullptr;
	    delete c2;
	    c2 = nullptr;
	    delete t0;
	    t0 = nullptr;
	    delete t1;
	    t1 = nullptr;
	    delete t2;
	    t2 = nullptr;
	    delete t3;
	    t3 = nullptr;
	    delete t4;
	    t4 = nullptr;
	    delete t5;
	    t5 = nullptr;
	    delete t6;
	    t6 = nullptr;

	/********** PART 2 **********/
	cout << "\n/********** PART 2 **********/\n" << endl;

		MapLoader* wml = new MapLoader();
		wml->setMapFile("map1.txt");
	    cout << wml->getMapFile() << endl;
	
	    wml->readMap();
	    wml->worldMap->printAllContinent();
	    wml->worldMap->printAllTerritory();
	
	    //print adjacent relation line by line
	    //each line represent each territory's adjacent relation with other t in map
	    for (int i = 0; i < wml->worldMap->getNumOfAllTerritory(); i++) {
	        for (int j : wml->worldMap->allTerritory[i]->adjacentTerritoryInMap) {
	            cout << j << " ";
	        }
	        cout << endl;
	    }
	
	    cout << "-------------------------continent set-----------------------------" << endl;
	    for (int i = 0; i < wml->worldMap->getNumOfAllContinent(); i++) {
	        for (int j : wml->worldMap->allContinent[i]->reachableForeignContinent) {
	            cout << j << " ";
	        }
	        cout << endl;
	    }
	    wml->worldMap->validate();

		delete wml;
		wml = nullptr;

	/********** PART 3 **********/
	cout << "\n/********** PART 3 **********/\n" << endl;

	vector<Territory*> t;
	vector<Cards*> h;
	BiddingFacility* bid = new BiddingFacility("seven", 100, 11);

	Player* de = new Player("seven", 7, 18, t, h, bid);

	Territory* t11 = new Territory("t1", "c1", 0, 0, false, "", false, 0);
	Territory* t12 = new Territory("t2", "c1", 0, 0, false, "", false, 0);
	Territory* t13 = new Territory("t2", "c2", 0, 0, false, "", false, 0);

	cout << "\nTest Paycoin Method -- PayCoin(2) \n" << endl;
	cout << *de;
	de->PayCoin(2);
	cout << *de;

	cout << "\nTest PlaceNewArmies -- PlaceNewArmies(t11, 4)\n" << endl;
	cout << *t11;
	de->PlaceNewArmies(t11, 4);
	cout << *t11;
	cout << *de;

	cout << "\nTest MoveArmies -- MoveArmies(t11, t12, 2)\n" << endl;
	cout << *t12;
	de->MoveArmies(t11, t12, 2);
	cout << *t11;
	cout << *t12;

	cout << "\nTest MoveOverLand -- MoveOverLand(t11, t13, 1)" << endl;
	cout << *de;
	de->MoveOverLand(t11, t12, 1);
	de->MoveOverLand(t11, t13, 1);
	cout << *de;

	cout << "\nTest BuildCity -- BuildCity(t12)\n" << endl;
	cout << *t12;
	de->BuildCity(t12);
	cout << *t12;
	cout << *de;

	cout << "\nTest DestroyArmy -- DestroyArmy(t1, 1)\n" << endl;
	cout << *t11;
	de->DestroyArmy(t11, 1);
	cout << *t11;

	cout << "\nTest Print Territory Vector\n";
	de->printTerritory();

	cout << "\nTest Memeory Leak\n";

	delete de;
	de = nullptr;

	t.clear();
	h.clear();

	/********** PART 4 **********/
	cout << "\n/********** PART 4 **********/\n" << endl;
	vector<Territory*> card_t;
	vector<Cards*> card_h;
	BiddingFacility* card_bid = new BiddingFacility("Eight", 100, 11);

	Player* card_play = new Player("Eight", 7, 18, card_t, card_h, card_bid);

	// 2 players - 27 cards
	Cards* card1 = new Cards("Ancient Phoenix", "Flying", "Move 5 armies");
	Cards* card2 = new Cards("Ancient Sage", "+1 VP per Ancient Card", "Move 3 armies");
	Cards* card3 = new Cards("Ancient Tree Spirit", "3 elixirs", "Place 4 armies");
	Cards* card4 = new Cards("Ancient Woods", "1 new army", "Build a city AND place 1 army");
	Cards* card5 = new Cards("Cursed Banshee", "2 elixirs", "Move 6 armies");
	Cards* card6 = new Cards("Cursed Gargoyles", "Flying", "Move 5 armies");
	Cards* card7 = new Cards("Cursed King", "1 elixir", "Place 3 armies OR Move 4 armies");
	Cards* card8 = new Cards("Cursed Mausoleum", "Move 1 army", "Build a city");
	Cards* card9 = new Cards("Cursed Tower", "+1 VP per flying", "Build a city");
	Cards* card10 = new Cards("Dire Dragon", "Flying", "Move 3 armies AND Destroy army");
	//Cards* card11 = new Cards("Dire Eye", "Flying", "Place 4 armies");
	//Cards* card12 = new Cards("Dire Giant", "Immune to attack", "Place 3 armies AND Destroy army");
	//Cards* card13 = new Cards("Dire Goblin", "1 elixir", "Move 5 armies");
	//Cards* card14 = new Cards("Dire Ogre", "+1 VP per 3 coins", "Move 2 armies");
	//Cards* card15 = new Cards("Forest Elf", "1 army", "Place 3 armies OR Move 2 armies");
	//Cards* card16 = new Cards("Forest Gnome", "3 elixirs", "Move 2 armies");
	//Cards* card17 = new Cards("Forest Pixie", "1 army", "Move 4 armies");
	//Cards* card18 = new Cards("Forest Tree Town", "Move 1 army", "Build a city");
	//Cards* card19 = new Cards("Graveyard", "+1 VP per Cursed Card", "Place 2 armies");
	//Cards* card20 = new Cards("Lake", "+1 VP per Forest Card", "Place 2 armies OR Move 3 armies");
	//Cards* card21 = new Cards("Night Hydra", "1 army", "Move 5 armies AND Destroy army");
	//Cards* card22 = new Cards("Night Village", "1 army", "Build a city");
	//Cards* card23 = new Cards("Night Wizard", "+1 VP per Night Card", "Adrien");
	//Cards* card24 = new Cards("Noble Hills", "Three noble cards = 4VP", "Place 3 armies");
	//Cards* card25 = new Cards("Noble Knight", "Move 1 army", "Place 4 armies AND Destroy army");
	//Cards* card26 = new Cards("Noble Unicorn", "Move 1 army", "Move 4 armies AND Place 1 army");
	//Cards* card27 = new Cards("Stronghold", "+1 VP per Dire card", "Build a city");

	//// 3 players - 32 cards
	//Cards* card28 = new Cards("Arcane Manticore", "Move 1 army", "Place 4 armies AND Destroy army");
	//Cards* card29 = new Cards("Arcane Sphinx", "Flying", "Place 3 armies OR Move 4 armies");
	//Cards* card30 = new Cards("Arcane Temple", "+1 VP per Arcane Card", "Move 3 armies");
	//Cards* card31 = new Cards("Mountain Dwarf", "+3 VP if you have two Mountain Cards", "Move 2 armies AND Destroy army");
	//Cards* card32 = new Cards("Mountain Treasury", "1 elixir and 2 coins", "Move 3 armies");

	//// 4 players - 34 cards
	//Cards* card33 = new Cards("Castle", "1 elixir", "Place 3 armies OR Build a city");
	//Cards* card34 = new Cards("Castle 2", "1 elixir", "Move 3 armies AND Build a city");


	Deck* newDeck = new Deck();

	newDeck->setDeck(card1);
	newDeck->setDeck(card2);
	newDeck->setDeck(card3);
	newDeck->setDeck(card4);
	newDeck->setDeck(card5);
	newDeck->setDeck(card6);
	newDeck->setDeck(card7);
	newDeck->setDeck(card8);
	newDeck->setDeck(card9);
	newDeck->setDeck(card10);

	cout << "/****** TEST Draw Method ******/\n" << endl;
	cout << "/****** Before Draw Method ******/" << endl;
	cout << *newDeck << endl;

	Hand* newHand = new Hand();

	for (int i = 0; i < 6; i++) {
		newHand->setHand(newDeck->draw());
	};

	cout << "/****** After Draw Method ******/" << endl;

	cout << *newDeck << endl;

	cout << "/****** TEST Exchange Method ******/\n" << endl;

	cout << "/****** Before Exchange Method ******/" << endl;

	cout << *newHand << endl;

	cout << "/****** After Draw Method <Index 4> ******/" << endl;

	newHand->exchange(4, card_play);

	cout << *newHand << endl;

	cout << "/******** Memory Leak Protect ********/" << endl;

	delete card_play;
	card_play = nullptr;
	delete newDeck;
	newDeck = nullptr;
	delete newHand;
	newHand = nullptr;

	card_t.clear();
	card_h.clear();
	/********** PART 5 **********/
	cout << "\n/********** PART 5 **********/\n" << endl;

		BiddingFacility a("Alex", 100, 20);
		BiddingFacility b("Bob", 120, 60);
		BiddingFacility c("Chad", 140, 40);
		BiddingFacility d("Dean", 160, 10);
	
		BiddingFacility* one = new BiddingFacility("Zin", 100, 50);
		BiddingFacility* two = new BiddingFacility("Lone", 100, 30);
		BiddingFacility* three = new BiddingFacility("Seg", 100, 0);
		BiddingFacility* four = new BiddingFacility("Ore", 100, 50);
	
		//Test the assignment operator
		BiddingFacility* AOTest;
		AOTest = three;
	
		cout << AOTest;
	
		//Test the copy constructor
		BiddingFacility* CCTest = four;
	
		//Test the stream insertion operator
		cout << four;
		cout << a;
		cout << b;
		cout << c;
		cout << d;
	
		vector<BiddingFacility*> testVector;
	
		testVector.push_back(one);
		testVector.push_back(two);
		testVector.push_back(three);
		testVector.push_back(four);
	
		//Test the function to see who goes first
		BiddingFacility::compareBid(testVector);
	
		//Destructor will automatically be called after execution finish
	
		//Memory Leak Delete
		for (int i = 0; i < testVector.size(); i++) {
			delete testVector.at(i);
			testVector[i] = nullptr;
		}
	
		testVector.clear();
	/********** END ************/

	return 0;
};