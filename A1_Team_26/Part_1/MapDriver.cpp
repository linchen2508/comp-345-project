#include <iostream>
#include "Map.h"
int main() {
    Territory* t0=new Territory("t0","c0",0,0);
    Territory* t1=new Territory("t1","c0",1,0);
    Territory* t2=new Territory("t2","c1",2,1);
    Territory* t3=new Territory("t3","c1",3,1);
    Territory* t4=new Territory("t4","c2",4,2);
    Territory* t5=new Territory("t5","c2",5,2);
    Territory* t6=new Territory("t6","c2",6,2);
    Continent* c0=new Continent("c0",0);
    Continent* c1=new Continent("c1",1);
    Continent* c2=new Continent("c2",2);
    Map* m0=new Map("BigMap",7,3);
    m0->allTerritory.push_back(t0);
    m0->allTerritory.push_back(t1);
    m0->allTerritory.push_back(t2);
    m0->allTerritory.push_back(t3);
    m0->allTerritory.push_back(t4);
    m0->allTerritory.push_back(t5);
    m0->allTerritory.push_back(t6);
    m0->allContinent.push_back(c0);
    m0->allContinent.push_back(c1);
    m0->allContinent.push_back(c2);
    std::cout << m0->getNumOfAllContinent() << std::endl;
    m0->printAllContinent();
    m0->setMapName("BBigMap");
    std::cout << m0->getMName() << std::endl;
    std::cout << m0->getNumOfAllTerritory() << std::endl;
    std::cout << t1->getContinentName() << std::endl;
    //t1.setConnectedForeignContinent(true);//default false
    t0->adjacentTerritoryInMap.push_back(0);
    t0->adjacentTerritoryInMap.push_back(1);
    t0->adjacentTerritoryInMap.push_back(2);
    t0->adjacentTerritoryInSameContinent.push_back(1);

    t1->adjacentTerritoryInMap.push_back(0);
    t1->adjacentTerritoryInMap.push_back(1);
    t1->adjacentTerritoryInSameContinent.push_back(0);

    t2->adjacentTerritoryInMap.push_back(0);
    t2->adjacentTerritoryInMap.push_back(2);
    t2->adjacentTerritoryInMap.push_back(3);
    t2->adjacentTerritoryInSameContinent.push_back(3);

    t3->adjacentTerritoryInMap.push_back(2);
    t3->adjacentTerritoryInMap.push_back(3);
    t3->adjacentTerritoryInMap.push_back(5);
    t3->adjacentTerritoryInSameContinent.push_back(2);

    t4->adjacentTerritoryInMap.push_back(4);
    t4->adjacentTerritoryInMap.push_back(5);
    t4->adjacentTerritoryInMap.push_back(6);
    t4->adjacentTerritoryInSameContinent.push_back(5);
    t4->adjacentTerritoryInSameContinent.push_back(6);

    t5->adjacentTerritoryInMap.push_back(3);
    t5->adjacentTerritoryInMap.push_back(4);
    t5->adjacentTerritoryInMap.push_back(5);
    t5->adjacentTerritoryInSameContinent.push_back(4);

    t6->adjacentTerritoryInMap.push_back(4);
    t6->adjacentTerritoryInMap.push_back(6);
    t6->adjacentTerritoryInSameContinent.push_back(4);


    int tLen=m0->allTerritory.size();
    for(int i=0;i<tLen;i++){
        cout<< "Territory name: " << m0->allTerritory[i]->getTName();
        cout<< " Territory adjacentInMap:";
        m0->allTerritory[i]->printTerritoryVector(m0->allTerritory[i]->adjacentTerritoryInMap);
        cout<< " Territory adjacentInSameContinent:";
        m0->allTerritory[i]->printTerritoryVector(m0->allTerritory[i]->adjacentTerritoryInSameContinent);
        cout<<endl;
    }
    c0->territoryMemberInContinent.push_back(t0);
    c0->territoryMemberInContinent.push_back(t1);
    c0->reachableForeignContinent.insert(1);
    c1->territoryMemberInContinent.push_back(t2);
    c1->territoryMemberInContinent.push_back(t3);// comment out any of these will break the continent subGraph
    c1->reachableForeignContinent.insert(0);
    c1->reachableForeignContinent.insert(2);
    c2->territoryMemberInContinent.push_back(t4);
    c2->territoryMemberInContinent.push_back(t5);
    c2->territoryMemberInContinent.push_back(t6);
    c2->reachableForeignContinent.insert(1);


//    vector<Territory*> mt=m0.getAllTerritory();
//    for(int i=0;i<tLen;i++){
//        std::cout << "Territory can go oversea: " << mt[i]->getConnectedForeignContinent() << std::endl;//true->1, false->0
//        std::cout << "Territory Name: " << mt[i]->getTName() << std::endl;
//        std::cout << "Territory id: " << mt[i]->getTID() << std::endl;
//        std::cout << "Territory army: " << mt[i]->getArmyNum() << std::endl;
//        std::cout << "Territory belong to Continent: " << mt[i]->getContinentID() << std::endl;
//        std::cout << "Territory owner: " << mt[i]->getPlayerID() << std::endl;
//    }
    bool check;
    check=c0->checkSubGraph();
    cout<< "Continent0 subgraph is connected? " << check <<endl;
    check=c1->checkSubGraph();
    cout<< "Continent1 subgraph is connected? " << check <<endl;
    check=c2->checkSubGraph();
    cout<< "Continent2 subgraph is connected? " << check <<endl;
    m0->validate();

    delete m0;
    m0=nullptr;
    delete c0;
    c0=nullptr;
    delete c1;
    c1=nullptr;
    delete c2;
    c2=nullptr;
    delete t0;
    t0=nullptr;
    delete t1;
    t1=nullptr;
    delete t2;
    t2=nullptr;
    delete t3;
    t3=nullptr;
    delete t4;
    t4=nullptr;
    delete t5;
    t5=nullptr;
    delete t6;
    t6=nullptr;


    return 0;
}
