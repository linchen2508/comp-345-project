//
// Created by Nian Liu on 2021-02-09.
//

#ifndef COMP345W_MAP_H
#define COMP345W_MAP_H

#include <string>
//#include <list>
//#include <array>
//#include <map>
#include <vector>
using namespace std;

class Territory
{
public:
    string tName;
    int tID;
    string continentName;
    int continentID;
    string player;
    int armyNum;
    bool connectedForeignContinent;
    bool build_city;


    vector<int> adjacentTerritoryInMap;
    vector<int> adjacentTerritoryInSameContinent;
    vector<int> reachableForeignContinent;

    Territory();
    Territory(string tName, string continentName, int tID, int continentID,bool connectedForeignContient,string player,bool build_city,int armyNum);

    string getTName();
    int getTID();
    string getContinentName();
    int getContinentID();
    int getPlayer();
    int getArmyNum();
    bool getConnectedForeignContinent();
    vector<int> getAdjacentTerritoryInMap();
    vector<int> getAdjacentTerritoryInSameContinent();
    vector<int> getReachableForeignContinent();
    void setTName(string tName);
    void setTID(int tID);
    void setConnectedForeignContinent(bool canGoOut);
    void printTerritoryVector(vector<int> v);
    //For Part 3 Method
    bool getBuildCity();
    void setArmy(int armyNum);
    void setBuildCity();
    void setPlayer(string player);
    void toString();// Temp for toString, need to modify late
    
};

class Continent
{
public:
    string cName;
    int cID;
    vector<Territory*> territoryMemberInContinent;

    Continent();
    Continent(string cName, int cID);

    string getCName();
    int getCID();
    vector<Territory*> getTerritoryMemberInContinent();
    bool checkSubGraph();

};

class Map
{
public:
    string mName;
    int numOfAllTerritory;
    int numOfAllContinent;
    vector<Territory*> allTerritory;
    vector<Continent*> allContinent;

    Map();
    Map(string mName, int numOfAllTerritory, int numOfAllContinent);

    string getMName();
    int getNumOfAllTerritory();
    int getNumOfAllContinent();
    vector<Territory*> getAllTerritory();
    void setMapName(string mName);
    void printAllTerritory();
    void printAllContinent();
    void validate();

};


#endif //COMP345W_MAP_H
