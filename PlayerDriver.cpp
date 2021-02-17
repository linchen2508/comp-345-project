#include "Player.h";

using namespace std;

int main() {

	vector<Territory*> t;
	vector<Cards*> h;
	BiddingFacility b ("SEVEN", 100, 11);

	Player* de = new Player("SEVEN",7,18, t, h, b);
	Territory* t1 = new Territory("T1", "C1",0,0,false,"", false, 0);
	Territory* t2 = new Territory("T2", "C1", 0, 0, false, "", false, 0);
	Territory* t3 = new Territory("T2", "C2", 0, 0, false, "", false, 0);

	cout << "\nTEST PayCoin Method\n" << endl;
	cout << *de;
	de->PayCoin(2);
	cout << *de;
	
	cout << "\nTEST PlaceNewArmies\n" << endl;
	cout << *t1;
	de->PlaceNewArmies(t1, 4);
	cout << *t1;
	cout << *de;

	cout << "\nTEST MoveArmies\n" << endl;
	cout << *t2;
	de->MoveArmies(t1, t2, 2);
	cout << *t1;
	cout << *t2;

	cout << "\nTEST MoveOverLand" << endl;
	cout << *de;
	de->MoveOverLand(t1, t2, 1);
	de->MoveOverLand(t1, t3, 1);
	cout << *de;

	cout<<"\nTEST BuildCity\n"<<endl;
	cout << *t2;
	de->BuildCity(t2);
	cout << *t2;
	cout << *de;

	cout<< "\nTEST DestroyArmy\n"<<endl;
	cout << *t1;
	de->DestroyArmy(t1, 1);
	cout << *t1;
	
	cout << "\nTEST Territory Vector\n";
	de->printTerritory();

	cout << "\nTEST MEMEORY LEAK\n";

	delete de;
	de = NULL;
	delete t1;
	t1 = NULL;
	delete t2;
	t2 = NULL;
	delete t3;
	t3 = NULL;
	
	t.clear();
	h.clear();


	//_CrtDumpMemoryLeaks();
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}
