//
// Created by Nian Liu on 2021-02-09.
//

#ifndef COMP345W_MAP_H
#define COMP345W_MAP_H

#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class CardScord
{
public:
    map<string, int> cs;

    CardScord();

    void printCS();

};
    
class Territory
{
public:
    string tName;
    int tID;
    string continentName;
    int continentID;
    string player;
    int armyNum;
    int whiteNum;//Non-Player Army
    bool connectedForeignContinent;
    bool build_city;

    vector<int> adjacentTerritoryInMap;
    vector<int> adjacentTerritoryInSameContinent;
  
    Territory();
    Territory(string tName, string continentName, int tID, int continentID);

    /*********** Consturtor For Part 3 ***********/
    Territory(string tName, string continentName, int tID, int continentID, bool connectedForeignContient, string player, bool build_city, int armyNum);
    /********************************************/
    //Copy Constructor
    Territory(const Territory& object);
    //Assignment Operator
    Territory& operator = (const Territory& object);
    //Destructor
    ~Territory();

    string getTName();
    int getTID();
    string getContinentName();
    int getContinentID();
    string getPlayer();
    int getArmyNum();
    //int getWhiteNum() { return whiteNum; };
    bool getConnectedForeignContinent();
    vector<int> getAdjacentTerritoryInMap();
    vector<int> getAdjacentTerritoryInSameContinent();
    void setTName(string tName);
    void setTID(int tID);
    void setConnectedForeignContinent(bool canGoOut);
    void printTerritoryVector(vector<int> v);
    //For Part 3 Method
    bool getBuildCity();
    void setArmy(int armyNum);
    void setBuildCity();
    void setPlayer(string player);
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Territory& object);
    
    //For Assignment 2
    //Constructor for debug Assignment 2 - Part 2
    Territory(string tName, bool build_city);
    void setWhiteNum(int whiteNum);
    int getWhiteNum();
};

class Continent
{
public:
    string cName;
    int cID;
    vector<Territory*> territoryMemberInContinent;
    set<int> reachableForeignContinent;
    //part 6 by nian
    string pName;

    Continent();
    Continent(string cName, int cID);

    /**********************/
    //Copy Constructor
    Continent(const Continent& object);
    //Assignment Operator
    Continent& operator = (const Continent&);
    //Destructor
    ~Continent();
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Continent& object);
    /**********************/

    Territory* getCentre();
    string getCName();
    int getCID();
    vector<Territory*> getTerritoryMemberInContinent();
    bool checkSubGraph();
    set<int> getReachableForeignContinent();


    //part 6 by nian
    string getPName();
    void setPName(string p);

};

class Map
{
public:
    string mName;
    int numOfAllTerritory;
    int numOfAllContinent;
    bool invalid;
    vector<Territory*> allTerritory;
    vector<Continent*> allContinent;

    Map();
    Map(string mName, int numOfAllTerritory, int numOfAllContinent);

    /*********************/
    //Copy Constructor
    Map(const Map& object);
    //Assignment Operator
    Map& operator = (const Map&);
    //Destructor
    ~Map();
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const Map& object);
    /**********************/

    string getMName();
    Territory* getCentre();
    Territory* getTerritoryById(int tid);
    int getNumOfAllTerritory();
    int getNumOfAllContinent();
    vector<Territory*> getAllTerritory();
    vector<Continent*> getAllContinent() { return allContinent; };
    void setMapName(string mName);
    void printAllTerritory();
    void printAllContinent();
    void validate();

    bool getInvalid();

    //friend class MapLoader;
};

#endif //COMP345W_MAP_H
