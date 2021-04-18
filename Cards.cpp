#include <iostream>
#include <string>
#include <algorithm>
#include "Cards.h"
#include "Player.h"

using namespace std;

/****** Card Class ******/

//Default Constructor
Cards::Cards() {
    cardName = "";
    cardGoods = "";
    cardAction = "";
}
//Constructor with parameter
Cards::Cards(string name, string goods, string action) {
    cardName = name;
    cardGoods = goods;
    cardAction = action;
}
//Copy Constructor
Cards::Cards(const Cards& object) {
    this->cardName = object.cardName;
    this->cardGoods = object.cardGoods;
    this->cardAction = object.cardAction;

}
//Assignment Operator
Cards& Cards::operator = (const Cards& object) {
    this->cardName = object.cardName;
    this->cardGoods = object.cardGoods;
    this->cardAction = object.cardAction;
    return *this;
}
//Destructor
Cards::~Cards() {};
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Cards& object) {
    return output << "Card Name: < " << object.cardName << " > Card Goods: < " << object.cardGoods << " > Card Action: < " << object.cardAction <<" >"<< endl;
}
//Get Method
string Cards::getCardName() {
   //Remove whiteSpace
   //cardName.erase(remove(cardName.begin(),cardName.end(),' '),cardName.end());
   return cardName;
}
string Cards::getCardAction()
{
    return cardAction;
}


//part 6 by nian
string Cards::getGoodName() {
    return cardGoods;
}
void Cards::Ancient(CardScord* csd)
{
    csd->cs["Ancient"] += 1;
    string h = this->getCardName();
    if (h == "Ancient Sage") {
        csd->cs["Ancient Sage"] += 1;
        return;
    }
    string s = this->getGoodName();
    if (s.find("Flying") != -1) {
        csd->cs["Flying"] += 1;
        return;
    }
    if (s.find("elixir") != -1) {
        char c = s.at(0);
        int n = c - '0';//char to int
        csd->cs["elixir"] += n;
        return;
    }

}
void Cards::Cursed(CardScord* csd)
{
    csd->cs["Cursed"] += 1;
    string h = this->getCardName();
    if (h == "Cursed Tower") {
        csd->cs["Cursed Tower"] += 1;
        return;
    }
    string s = this->getGoodName();
    if (s.find("Flying") != -1) {
        csd->cs["Flying"] += 1;
        return;
    }
    if (s.find("elixir") != -1) {
        char c = s.at(0);
        int n = c - '0';//char to int
        csd->cs["elixir"] += n;
        return;
    }

}
void Cards::Dire(CardScord* csd)
{
    csd->cs["Dire"] += 1;
    string h = this->getCardName();
    if (h == "Dire Ogre") {
        csd->cs["Dire Ogre"] += 1;
        return;
    }
    string s = this->getGoodName();
    if (s.find("Flying") != -1) {
        csd->cs["Flying"] += 1;
        return;
    }
    if (s.find("elixir") != -1) {
        char c = s.at(0);
        int n = c - '0';//char to int
        csd->cs["elixir"] += n;
        return;
    }

}
void Cards::Forest(CardScord* csd)
{
    csd->cs["Forest"] += 1;

    string s = this->getGoodName();

    if (s.find("elixir") != -1) {
        char c = s.at(0);
        int n = c - '0';//char to int
        csd->cs["elixir"] += n;
        return;
    }

}
void Cards::Noble(CardScord* csd)
{
    csd->cs["Noble"] += 1;
    string h = this->getCardName();
    if (h == "Noble Hills") {
        csd->cs["Noble Hills"] += 1;
        return;
    }

}
void Cards::Night(CardScord* csd)
{
    csd->cs["Night"] += 1;
    string h = this->getCardName();
    if (h == "Night Wizard") {
        csd->cs["Night Wizard"] += 1;
        return;
    }

}
/****** END ******/


/****** Deck Class ******/
//Default Constructor
Deck::Deck() {
    vector<Cards*> vectorDeck;
}
//Copy Constructor
Deck::Deck(const Deck& object) {

    for (int i = 0; i < object.vectorDeck.size(); i++) {
        this->vectorDeck[i] = new Cards(*object.vectorDeck[i]);
    }

}
//Assignment Operator
Deck& Deck::operator=(const Deck& object) {

    for (int i = 0; i < object.vectorDeck.size(); i++) {
        this->vectorDeck[i] = new Cards(*object.vectorDeck[i]);
    }
    return *this;
}
//Destructor
Deck::~Deck() {
    for (int i = 0; i < vectorDeck.size(); i++) {
        delete vectorDeck[i];
        vectorDeck[i] = nullptr;
    }
}
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Deck& object) {
    output << "Number Of Cards In The Deck: ";
    output << object.vectorDeck.size() << endl;
    for (int i = 0; i < object.vectorDeck.size(); i++) {
        output << i + 1;
        output <<" -- " <<*(object.vectorDeck[i]);
    }
    output << endl;
    return output;
}
//Draw Method
Cards* Deck::draw() {
    Cards* tempcard = new Cards(*(this->vectorDeck.front()));
    delete this->vectorDeck.front();
    this->vectorDeck.front() = nullptr;
    this->vectorDeck.erase(this->vectorDeck.begin());
    return tempcard;
}
//Card Cost Methid
Deck* Deck::cardCost() {
    Deck* temp_deck = new Deck();
    vector<string> cost_name = { "Arcane Manticore","Arcane Sphinx","Arcane Temple","Mountain Dwarf","Mountain Treasury","Castle","","Castle 2" };
    for (int i = 0; i < cost_name.size(); i++) {
        for (int j = 0; j < this->vectorDeck.size(); j++) {
            if (this->vectorDeck[j]->getCardName().compare(cost_name[i]) == 0) {
                Cards* tempcard = new Cards(*(this->vectorDeck[j]));
                temp_deck->setDeck(tempcard);
                //Delete Card From Deck
                delete this->vectorDeck[j];
                this->vectorDeck[j] = nullptr;
                this->vectorDeck.erase(vectorDeck.begin()+j);
            }
        }
    }
    return temp_deck;
}

void Deck::shuffling() {
    //Set C time for different Random Number Sequence
    srand((unsigned int)time(NULL));
    for (int i = 0; i < this->vectorDeck.size(); i++) {

        int tempNum = rand() % vectorDeck.size();//Random Number from 0 to Deck size
        
        swap(vectorDeck.front(), vectorDeck[tempNum]);

    }
}
//Get Method
vector<Cards*> Deck::getDeck() {
    return vectorDeck;
}
//Set Method
void Deck::setDeck(Cards* object) {
    //Cards* temp = new Cards(*object);
    this->vectorDeck.push_back(object);
}
/****** END ******/


/****** Hand Class ******/

//Default Constructor
Hand::Hand() {
    vector<Cards*> hand;
}
//Copy Constructor
Hand::Hand(const Hand& object) {

    for (int i = 0; i < object.hand.size(); i++) {
        this->hand[i] = new Cards(*object.hand[i]);
    }

}
//Assignment Operator
Hand& Hand::operator=(const Hand& object) {

    for (int i = 0; i < object.hand.size(); i++) {
        this->hand[i] = new Cards(*(object.hand[i]));
    }
    return *this;
}
//Destructor
Hand::~Hand() {
    for (int i = 0; i < hand.size(); i++) {
        for (int i = 0; i < hand.size(); i++) {
            delete hand[i];
            hand[i] = nullptr;
        }
    }

}
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Hand& object) {
    output << "Hand Cards on the table: \n\n";
    for (int i = 0; i < object.hand.size(); i++) {
        output << i+1;
        output <<" -- "<<*(object.hand[i]);
    }
    output << endl;
    return output;
}
//Set Method
void Hand::setHand(Cards* object) {
    this->hand.push_back(object);
}

void Hand::exchange(int index, Player* player) {
    //For Cost
    int cost;
    if (index == 1) {
        cost = 0;
    }
    if (index == 2 || index == 3) {
        cost = 1;
    }
    if (index == 4 || index == 5) {
        cost = 2;
    }
    if (index == 6) {
        cost = 3;
    }
    while (player->getCoin() < cost) {
        cout << player->getName() << ": You do not have enough coin pay for card cost, please choose another card" << endl;
        cin >> index;
        if (index == 1) {
            cost = 0;
        }
        if (index == 2 || index == 3) {
            cost = 1;
        }
        if (index == 4 || index == 5) {
            cost = 2;
        }
        if (index == 6) {
            cost = 3;
        }
    }

    //For Pay
    player->setCoin(cost);

    //Add Card into Player's handcard
    Cards* temp = new Cards(*hand[index - 1]);
    player->setHandCard(temp);
    //cout << "\n"<<player->getName() << " has select " << *temp << endl;

    //Memory Leak Proctect
    delete hand[index - 1];
    hand[index - 1] = nullptr;
    hand.erase(this->hand.begin() + (index - 1));
    //delete temp;
    //temp = nullptr;

}
//Get Method
vector<Cards*> Hand::getHand() {
    return hand;
}
/****** END ******/