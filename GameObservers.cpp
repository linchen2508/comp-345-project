
#include "Player.h"
#include <iostream>
#include <list>

using namespace std;


//***** Player Subject Class *****//
PlayerSubject::PlayerSubject() {
     _observers = new list<ActionObserver*>;
};
PlayerSubject::~PlayerSubject() {
     delete _observers;
};
void PlayerSubject::Attach(ActionObserver* o) {
    _observers->push_back(o);
};
void PlayerSubject::Detach(ActionObserver* o) {
    _observers->remove(o);
};
void PlayerSubject::Notify() {
    list<ActionObserver*>::iterator i = _observers->begin();
    for (; i != _observers->end(); ++i)
        (*i)->Update();
};


//***** Obeservers Class *****//
GameObserver::GameObserver() {
};
GameObserver::~GameObserver() {
};


//***** Action Obeservers Class *****//
ActionObserver::ActionObserver(Player* s) {
    _subject = s;
    _subject->Attach(this);
};
ActionObserver::~ActionObserver() {  
    _subject->Detach(this);
};
void ActionObserver::Update() {
    display();
};
void ActionObserver::display() {

    int action = _subject->getActive();
    int num = _subject->getNum();

    switch (action) {
    case 1: {
        cout << "Player - " << _subject->getName() << " Action: << Place New Armies >>. Current Armies Number : " << _subject->getArmy() << endl;
    }
        break;
    case 2: {
        cout << "Player - " << _subject->getName() << " Action: << Move Armies >>." << endl;
        cout << "Current Territory Occupied: " << endl;
        for (int i = 0; i < _subject->getTerritory().size(); i++) {
            cout << i + 1 <<" - "<< *_subject->getTerritory()[i] << endl;
        }
    }
        break;
    case 3: {
        int count = 0;
        for (int i = 0; i < _subject->getHandCard().size(); i++) {
            if (_subject->getHandCard()[i]->getGoodName() == "Flying") {
                count++;
            }
        }
        cout << "Player - " << _subject->getName() << " Action: << Move Over Land >>. Current Flying Goods: "<< count << endl; 
        
    }
        break;
    case 4: {
        cout << "Player - " << _subject->getName() << " Action: << Build City >>. Current City Token: " << _subject->getCityToken() << endl;
        cout << "Current City Occupied: " << endl;
        for (int i = 0; i < _subject->getTerritory().size(); i++) {
            if (_subject->getTerritory()[i]->getBuildCity() == true) {
                cout << i + 1 << " - " << *_subject->getTerritory()[i] << endl;
            }     
        }
    }
        break;
    case 5:
        cout << "Player - " << _subject->getName() << " Action: << Destroy Armies >>" << endl;
        break;
    case 6: {
        switch (num) {
        case 1: {
            cout << "\nPlayer - " << _subject->getName() << ": select the first card from the left, he would pay ZERO coin. Current Coin: "<< _subject->getCoin() << endl;
            cout << "Card Info -- " << *_subject->getHandCard()[_subject->getHandCard().size()-1]<< endl;
        }
            break;
        case 2: {
            cout << "\nPlayer - " << _subject->getName() << ": select the second card from the left, he would pay ONE coin. Current Coin: " << _subject->getCoin() << endl;
            cout << "Card Info -- " << *_subject->getHandCard()[_subject->getHandCard().size() - 1] << endl;
        }
            break;
        case 3: {
            cout << "\nPlayer - " << _subject->getName() << ": select the third card from the left, he would pay ONE coin. Current Coin: " << _subject->getCoin() << endl;
            cout << "Card Info -- " << *_subject->getHandCard()[_subject->getHandCard().size() - 1] << endl;
        }
            break;
        case 4: {
            cout << "\nPlayer - " << _subject->getName() << ": select the fourth card from the left, he would pay TWO coin. Current Coin: " << _subject->getCoin() << endl;
            cout << "Card Info -- " << *_subject->getHandCard()[_subject->getHandCard().size() - 1] << endl;
        }
            break;
        case 5: {
            cout << "\nPlayer - " << _subject->getName() << ": select the fifth card from the left, he would pay TWO coin. Current Coin: " << _subject->getCoin() << endl;
            cout << "Card Info -- " << *_subject->getHandCard()[_subject->getHandCard().size() - 1] << endl;
        }
            break;
        case 6: {
            cout << "\nPlayer - " << _subject->getName() << ": select the sixth card from the left, he would pay ThREE coin. Current Coin: " << _subject->getCoin() << endl;
            cout << "Card Info -- " << *_subject->getHandCard()[_subject->getHandCard().size() - 1] << endl;
        }
            break;
        }
    }
        break;
    }
};