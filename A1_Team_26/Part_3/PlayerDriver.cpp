#include "Player.h";

/***** Memory Leak Check *****/
#define _DEBUG
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
#define _CRTDBG_MAP_ALLOC
#include <memory>
/****************************/

using namespace std;

int main() {


	//**check for memory leaks**//
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<Territory*> t;
	vector<Cards*> h;
	BiddingFacility* b = new BiddingFacility ("seven", 100, 11);

	Player* de = new Player("seven",7,18, t, h, b);

	Territory* t1 = new Territory("t1", "c1",0,0,false,"", false, 0);
	Territory* t2 = new Territory("t2", "c1", 0, 0, false, "", false, 0);
	Territory* t3 = new Territory("t2", "c2", 0, 0, false, "", false, 0);

	cout << "\ntest paycoin method -- paycoin(2) \n" << endl;
	cout << *de;
	de->PayCoin(2);
	cout << *de;
	
	cout << "\ntest placenewarmies -- placenewarmies(t1, 4)\n" << endl;
	cout << *t1;
	de->PlaceNewArmies(t1, 4);
	cout << *t1;
	cout << *de;

	cout << "\ntest movearmies -- movearmies(t1, t2, 2)\n" << endl;
	cout << *t2;
	de->MoveArmies(t1, t2, 2);
	cout << *t1;
	cout << *t2;

	cout << "\ntest moveoverland -- moveoverland(t1, t3, 1)" << endl;
	cout << *de;
	de->MoveOverLand(t1, t2, 1);
	de->MoveOverLand(t1, t3, 1);
	cout << *de;

	cout<<"\ntest buildcity -- buildcity(t2)\n"<<endl;
	cout << *t2;
	de->BuildCity(t2);
	cout << *t2;
	cout << *de;

	cout<< "\ntest destroyarmy -- destroyarmy(t1, 1)\n"<<endl;
	cout << *t1;
	de->DestroyArmy(t1, 1);
	cout << *t1;
	
	cout << "\ntest territory vector\n";
	de->printTerritory();

	cout << "\ntest memeory leak\n";

	delete de;
	de = nullptr;

	t.clear();
	h.clear();

	return 0;
}
