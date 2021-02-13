#include "BiddingFacility.h"
#include <iostream>
#include <string>
using namespace std;


BiddingFacility::BiddingFacility(string a, int b, int c)
{
	name = a;
	money = b;
	bid = c;
}


void BiddingFacility::revealBid()
{
	cout << name << " bid " << bid;
}

void BiddingFacility::setBid() 
{
	cout << "Enter the amount you wanna bid: ";
	cin >> bid;
	while (bid < 0)
	{
		cout << "You can't bid less than 0";
		cin >> bid;
	}
}

int BiddingFacility::getBid()
{
	return bid;
}

void BiddingFacility::compareBid(BiddingFacility a[])
{
	int max = 0;
	string currentmaxname = "";
	for (int i = 0; i < sizeof(a); i++)
	{
		if (a[i].bid > max)
			max = a[i].bid;
	}

	for (int i = 0; i < sizeof(a); i++)
	{
		if (a[i].bid == max && a[i].name.compare(currentmaxname) > 0)
			currentmaxname = a[i].name;
	}
	cout << currentmaxname << " bids the most coins and will go first";
}
	//Some shitty ass functions for the winner to pay coin to the coin supply below
	//
	//........
	




