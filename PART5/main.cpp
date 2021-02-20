#include <iostream>
#include <string>
#include "BiddingFacility.h"
#include <vector>
using namespace std;

int main() 
{
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


}
