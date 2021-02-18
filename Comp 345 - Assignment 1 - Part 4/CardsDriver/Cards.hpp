//
//  Cards.hpp
//  CardsDriver
//
//  Created by Adrien Tosti on 2021-02-17.
//

#ifndef Cards_hpp
#define Cards_hpp
#include <string>
#include <vector>
using namespace std;


#include <stdio.h>
class Cards {
public:
    string cardName;
    string cardGoods;
    string cardAction;
    Cards();
    Cards(string name, string goods, string action);
};


class Deck {
public:
    int numOfPlayers;
    vector<Cards> vectorDeck;
    
    Deck(){};
    
    Deck(int numOfPlayers);
    
    Cards draw();
    
};

class Hand {
public:
    int numOfCards;
    vector<Cards> hand;
    
    Hand();
    
    Cards exchange(int index);
};


#endif /* Cards_hpp */
