#pragma once
#include <string>
#include <array>
using namespace std;
class BiddingFacility
{
private:
	//Name of the player
	string name;
	//The current amount of money the player has
	int money;
	//The bid the player makes
	int bid;

public:
	//Default constructor of the class
	BiddingFacility();

	//Constructor with 3 parameters
	BiddingFacility(string a, int b, int c);
	
	//Copy construcotr
	BiddingFacility(const BiddingFacility& object);

	//Assignment Operator
	BiddingFacility& operator = (const BiddingFacility&);

	//function to set the bid
	void setBid();

	//Getter for attribute bid
	int getBid();

	//Reveal the bid of the player
	void revealBid();

	//compare the bid to decide which player will go first
	static void compareBid(BiddingFacility a[]);
};

