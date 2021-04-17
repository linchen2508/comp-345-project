//
// Created by Nian Liu on 2021-04-16.
//

#ifndef INC_345A3_PLAYERSTRATEGIES_H
#define INC_345A3_PLAYERSTRATEGIES_H


#include "Cards.h"

class PlayerStrategies {
public:
    virtual ~PlayerStrategies();
    virtual int doSth(Hand* hand);
};

class Context{
public:
    Context(PlayerStrategies* str);
    ~Context();
    void set_Strategy(PlayerStrategies* pstr);
    int DoStrategy(Hand* hand);

private:
    PlayerStrategies* playerStrategies;
};

class GreedyPlayer:public PlayerStrategies{
public:
    int doSth(Hand* hand);
};

class ModeratePlayer:public PlayerStrategies{
public:
    int doSth(Hand* hand);
};



#endif //INC_345A3_PLAYERSTRATEGIES_H
