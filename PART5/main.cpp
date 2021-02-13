#include <iostream>
#include <string>
#include "BiddingFacility.cpp"
using namespace std;

int main() 
{
	BiddingFacility one("Lin", 100, 10);
	BiddingFacility two("Sin", 100, 10);
	BiddingFacility three("Seg", 100, 30);

	BiddingFacility testArray[] = { one, two, three };

	BiddingFacility::compareBid(testArray);
}