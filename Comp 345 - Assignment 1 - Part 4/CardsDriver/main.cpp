//
//  main.cpp
//  CardsDriver
//
//  Created by Adrien Tosti on 2021-02-17.
//

#include <iostream>
#include "Cards.hpp"
#include <string>
#include <random>
#include <algorithm>
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    // 2 players - 27 cards
    Cards card1("Ancient Phoenix", "Flying", "Move 5 armies");
    Cards card2("Ancient Sage", "+1 VP per Ancient Card", "Move 3 armies");
    Cards card3("Ancient Tree Spirit", "3 elixirs", "Place 4 armies");
    Cards card4("Ancient Woods", "1 new army", "Build a city AND place 1 army");
    Cards card5("Cursed Banshee", "2 elixirs", "Move 6 armies");
    Cards card6("Cursed Gargoyles", "Flying", "Move 5 armies");
    Cards card7("Cursed King", "1 elixir", "Place 3 armies OR Move 4 armies");
    Cards card8("Cursed Mausoleum", "Move 1 army", "Build a city");
    Cards card9("Cursed Tower", "+1 VP per flying", "Build a city");
    Cards card10("Dire Dragon", "Flying", "Move 3 armies AND Destroy army");
    Cards card11("Dire Eye", "Flying", "Place 4 armies");
    Cards card12("Dire Giant", "Immune to attack", "Place 3 armies AND Destroy army");
    Cards card13("Dire Goblin", "1 elixir", "Move 5 armies");
    Cards card14("Dire Ogre", "+1 VP per 3 coins", "Move 2 armies");
    Cards card15("Forest Elf", "1 army", "Place 3 armies OR Move 2 armies");
    Cards card16("Forest Gnome", "3 elixirs", "Move 2 armies");
    Cards card17("Forest Pixie", "1 army", "Move 4 armies");
    Cards card18("Forest Tree Town", "Move 1 army", "Build a city");
    Cards card19("Graveyard", "+1 VP per Cursed Card", "Place 2 armies");
    Cards card20("Lake", "+1 VP per Forest Card", "Place 2 armies OR Move 3 armies");
    Cards card21("Night Hydra", "1 army", "Move 5 armies AND Destroy army");
    Cards card22("Night Village", "1 army", "Build a city");
    Cards card23("Night Wizard", "+1 VP per Night Card", "Adrien");
    Cards card24("Noble Hills", "Three noble cards = 4VP", "Place 3 armies");
    Cards card25("Noble Knight", "Move 1 army", "Place 4 armies AND Destroy army");
    Cards card26("Noble Unicorn", "Move 1 army", "Move 4 armies AND Place 1 army");
    Cards card27("Stronghold", "+1 VP per Dire card", "Build a city");
    
    // 3 players - 32 cards
    Cards card28("Arcane Manticore", "Move 1 army", "Place 4 armies AND Destroy army");
    Cards card29("Arcane Sphinx", "Flying", "Place 3 armies OR Move 4 armies");
    Cards card30("Arcane Temple", "+1 VP per Arcane Card", "Move 3 armies");
    Cards card31("Mountain Dwarf", "+3 VP if you have two Mountain Cards", "Move 2 armies AND Destroy army");
    Cards card32("Mountain Treasury", "1 elixir and 2 coins", "Move 3 armies");
    
    // 4 players - 34 cards
    Cards card33("Castle", "1 elixir", "Place 3 armies OR Build a city");
    Cards card34("Castle 2", "1 elixir", "Move 3 armies AND Build a city");
    
    
    
    
    Cards cardPlaces[6];
    
    Cards dork[27];
    dork[0] = card1;
//    deck[1] = card2;
//    deck[2] = card3;
//    deck[3] = card4;
//    deck[4] = card5;
//    deck[5] = card6;
//    deck[6] = card7;
//    deck[7] = card8;
//    deck[8] = card9;
//    deck[9] = card10;
//    deck[10] = card11;
//    deck[11] = card12;
//    deck[12] = card13;
//    deck[13] = card14;
//    deck[14] = card15;
//    deck[15] = card16;
//    deck[16] = card17;
//    deck[17] = card18;
//    deck[18] = card19;
//    deck[19] = card20;
//    deck[20] = card21;
//    deck[21] = card22;
//    deck[22] = card23;
//    deck[23] = card24;
//    deck[24] = card25;
//    deck[25] = card26;
//    deck[26] = card27;
  
    Deck newDeck(2);
    
    
    
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card1);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card2);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card3);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card4);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card5);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card6);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card7);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card8);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card9);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card10);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card11);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card12);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card13);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card14);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card15);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card16);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card17);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card18);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card19);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card20);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card22);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card23);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card24);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card25);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card26);
    newDeck.vectorDeck.insert(newDeck.vectorDeck.begin(), card27);
    
    //Shuffling the deck
    random_device rd;
    auto rng = default_random_engine { rd() };
    shuffle(begin(newDeck.vectorDeck), end(newDeck.vectorDeck), rng);
//    random_shuffle(newDeck.vectorDeck.begin(), newDeck.vectorDeck.end());
    
    Hand newHand;
    
    for (int i = 0; i<6; i++) {
        newHand.hand.push_back(newDeck.draw());
    };
    
    Cards newCard1 = newDeck.draw();
    Cards newCard2 = newDeck.draw();

    
    
//    Cards newCardfromVector = newDeck.vectorDeck.front();
    
//    string name = newCardfromVector.cardName;
    


    cout << "Here's the first hand: \n";
    for (int x = 0; x<6; x++) {
        cout << "Card, " + newHand.hand[x].cardName + "\n";
    }
    cout << "\nLet's take the fourth card:\n\n\n";
    
    newHand.exchange(4);
    newHand.hand.push_back(newDeck.draw());
    
    cout << "\nHere's the second hand: \n";
    for (int x = 0; x<6; x++) {
        cout << "Card, " + newHand.hand[x].cardName + "\n";
    }
    
    
    
    
    return 0;
}
