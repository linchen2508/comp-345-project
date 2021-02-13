#include "Player.h";

using namespace std;


int main() {

	vector<Territory*> t;
	vector<Cards*> h;

	Player* de = new Player("SEVEN",7,18, t, h);
	Territory* t1 = new Territory("T1", "C1",0,0,false," ", false, 0);
	Territory* t2 = new Territory("T2", "C1", 0, 0, false, "", false, 0);
	Territory* t3 = new Territory("T2", "C2", 0, 0, false, "", false, 0);

	cout << "\nTEST PayCoin Method\n" << endl;
	de->toString();
	de->PayCoin(2);
	de->toString();
	
	cout << "\nTEST PlaceNewArmies\n" << endl;
	t1->toString();
	de->PlaceNewArmies(t1, 4);
	t1->toString();
	de->toString();

	cout << "\nTEST MoveArmies\n" << endl;
	t2->toString();
	de->MoveArmies(t1, t2, 2);
	t1->toString();
	t2->toString();

	cout << "\nTEST MoveOverLand" << endl;
	de->toString();
	de->MoveOverLand(t1, t2, 1);
	de->MoveOverLand(t1, t3, 1);
	de->toString();

	cout<<"\nTEST BuildCity\n"<<endl;
	t2->toString();
	de->BuildCity(t2);
	t2->toString();
	de->toString();

	cout<< "\nTEST DestroyArmy\n"<<endl;
	t1->toString();
	de->DestroyArmy(t1, 1);
	t1->toString();
	
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
	
	_CrtDumpMemoryLeaks();

	return 0;
}
