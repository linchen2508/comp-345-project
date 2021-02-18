//
//  Cards.cpp
//  CardsDriver
//
//  Created by Adrien Tosti on 2021-02-17.
//

#include <iostream>
#include <string>
#include "Cards.hpp"
using namespace std;


    Cards::Cards(){
        cardName = "";
        cardGoods = "";
        cardAction = "";
    }
    
    Cards::Cards(string name, string goods, string action){
        cardName = name;
        cardGoods = goods;
        cardAction = action;
    }

Deck::Deck(int numOfPlayers)  {
    vector<Cards> vectorDeck;
}

Hand::Hand(){
    numOfCards = 6;
    vector<Cards> hand;
    
}

Cards Deck::draw() {
    Cards tempcard = this->vectorDeck.front();
    this->vectorDeck.erase(this->vectorDeck.begin());
    return tempcard;
}

Cards Hand::exchange(int index) {
    int cost;
    Cards tempcard = this->hand[index -1];
    if (index == 1)
        cost = 0;
    if (index == 2)
        cost = 1;
    if (index == 3)
        cost = 1;
    if (index == 4)
        cost = 2;
    if (index == 5)
        cost = 2;
    if (index == 6)
        cost = 3;
    
    //Check if player has enough money
    this->hand.erase(this->hand.begin() + (index-1));
    
    return tempcard;
    
    
}


//    Cards draw(int index) {
//        this->deck = new Cards[28];
//    }

    
    


