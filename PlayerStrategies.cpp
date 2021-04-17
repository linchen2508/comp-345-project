//
// Created by Nian Liu on 2021-04-16.
//

#include "PlayerStrategies.h"

PlayerStrategies::~PlayerStrategies() {}

int PlayerStrategies::doSth(Hand *hand) {
    return 0;
}

Context::Context(PlayerStrategies *str){
    this->playerStrategies=str;
}

Context::~Context() {
    delete this->playerStrategies;
}

void Context::set_Strategy(PlayerStrategies *pstr) {
    delete this->playerStrategies;
    this->playerStrategies=pstr;
}

int Context::DoStrategy(Hand* hand) {
    int result=this->playerStrategies->doSth(hand);
    return result;
}

int GreedyPlayer::doSth(Hand *h) {
    vector<Cards*> hcs=h->getHand();
    int len= hcs.size();
    int result = 0;
    for(int i=0;i<len;i++){
        string ca=hcs[i]->getCardAction();
        if(ca.find("Build")!=ca.npos||ca.find("Destroy")!=ca.npos){
            return result=i+1;
        }
    }
    return result=(rand() % 6 + 1);

}

int ModeratePlayer::doSth(Hand *h) {
    vector<Cards*> hcs=h->getHand();
    int len= hcs.size();
    int result = 0;
    for(int i=0;i<len;i++){
        string ca=hcs[i]->getCardAction();
        if(ca.find("Move")!=ca.npos||ca.find("Place")!=ca.npos){
            return result=i+1;
        }
    }
    return result=(rand()%6+1);

}
