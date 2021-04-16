//
// Created by Nian Liu on 2021-02-09.
//

#include "Map.h"
#include <iostream>
#include <iomanip>
#include <stack>
#include <typeinfo>

using namespace std;

CardScord::CardScord()
{
    cs["Arcane"] = 0;
    cs["Arcane Temple"] = 0;//each arcane +1 vp
    cs["Ancient"] = 0;
    cs["Ancient Sage"] = 0;//each ancient +1 vp
    cs["Cursed"] = 0;
    cs["Graveyard"] = 0;//each cursed +1 vp
    cs["Flying"] = 0;
    cs["Cursed Tower"] = 0;//each flying +1 vp
    cs["Dire"] = 0;
    cs["Dire Ogre"] = 0;//every 3 coins +1 vp
    cs["Stronghold"] = 0;//each dire +1 vp
    cs["Lake"] = 0;//each forest +1 vp
    cs["Forest"] = 0;
    cs["Noble"] = 0;
    cs["Noble Hills"] = 0;//3 nobles +4 vp
    cs["Night"] = 0;
    cs["Night Wizard"] = 0;//each night +1 vp
    cs["Mountain"] = 0;
    cs["Mountain Dwarf"] = 0;//2 mountain +3 vp
    cs["elixir"] = 0;
}
void CardScord::printCS()
{
    for (auto& c : cs)
        std::cout << c.first << " => " << c.second << '\n';
}

Territory::Territory()
{
    tName = "";
    tID = 0;
    continentName = "";
    continentID = 0;
    player = "";
    armyNum = 0;
    whiteNum = 0;
    connectedForeignContinent = false;

}
Territory::Territory(string tName, string continentName, int tID, int continentID)
{
    this->tName = tName;
    this->tID = tID;
    this->continentName = continentName;
    this->continentID = continentID;
    this->armyNum = 0;
    this->whiteNum = 0;
    this->connectedForeignContinent = false;

}

/*********** Consturtor For Part 3 ***********/
Territory::Territory(string tName, string continentName, int tID, int continentID, bool connectedForeignContient, string player, bool build_city, int armyNum) {
    this->tName = tName;
    this->continentName = continentName;
    this->tID = tID;
    this->continentID = continentID;
    this->connectedForeignContinent = connectedForeignContient;
    this->player = player;
    this->armyNum = armyNum;
    this->whiteNum = 0;
    this->build_city = build_city;
}
/********************************************/

//Constructor for debug Assignment 2 - Part 2
Territory::Territory(string tName, bool build_city) {
    this->tName = tName;
    this->build_city = build_city;
    this->player = "none";
    this->whiteNum = 0;
    this->armyNum = 0;
}

//Copy Constructor
Territory::Territory(const Territory& object) {
    this->tName = object.tName;
    this->continentName = object.continentName;
    this->tID = object.tID;
    this->continentID = object.continentID;
    this->connectedForeignContinent = object.connectedForeignContinent;
    this->player = object.player;
    this->armyNum = object.armyNum;
    this->whiteNum = object.whiteNum;
    this->build_city = object.build_city;
    this->adjacentTerritoryInMap = object.adjacentTerritoryInMap;
    this->adjacentTerritoryInSameContinent = object.adjacentTerritoryInSameContinent;
}

//Assignment Operator
Territory& Territory::operator = (const Territory& object) {
    this->tName = object.tName;
    this->continentName = object.continentName;
    this->tID = object.tID;
    this->continentID = object.continentID;
    this->connectedForeignContinent = object.connectedForeignContinent;
    this->player = object.player;
    this->armyNum = object.armyNum;
    this->whiteNum = object.whiteNum;
    this->build_city = object.build_city;
    this->adjacentTerritoryInMap = object.adjacentTerritoryInMap;
    this->adjacentTerritoryInSameContinent = object.adjacentTerritoryInSameContinent;
    return *this;
};
//Destructor
Territory::~Territory() {

};
/*********************/


string Territory::getTName() { return tName; }
int Territory::getTID() { return tID; }
string Territory::getContinentName() { return continentName; }
int Territory::getContinentID() { return continentID; }
string Territory::getPlayer() { return player; }// Modify PlayerID into String type
int Territory::getArmyNum() { return armyNum; }
bool Territory::getConnectedForeignContinent() { return connectedForeignContinent; }
vector<int> Territory::getAdjacentTerritoryInMap() { return adjacentTerritoryInMap; }
vector<int> Territory::getAdjacentTerritoryInSameContinent() { return adjacentTerritoryInSameContinent; }
void Territory::setTName(string tName)
{
    tName = tName;
}
void Territory::setTID(int tID)
{
    tID = tID;
}
void Territory::setConnectedForeignContinent(bool canGoOut)
{
    connectedForeignContinent = canGoOut;
}
void Territory::printTerritoryVector(vector<int> v)
{
    if (v.size() != NULL) {
        int len = v.size();
        for (int i = 0; i < len; i++) {
            cout << " " << v[i];
        }
    }
    else {
        cout << " no element ";
    }

}
/**********************/
//For Part 3 Method
bool Territory::getBuildCity() {
    return build_city;
}
void Territory::setArmy(int armyNum) {
    this->armyNum += armyNum;
}
void Territory::setBuildCity() {
    build_city = true;
}
void Territory::setPlayer(string player) {
    this->player = player;
}
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Territory& object) {
    string temp;
    if (object.build_city == 0) {
        temp = "No";
    }
    else {
        temp = "Yes";
    }
    //output << "Territory Information: \n";
    output << "Territory Name: << " << object.tName << " >> Continent Name: << " << object.continentName << " >> Owner: << " << object.player << " >> Build City: << ";
    output << temp << " >> Army: << " << object.armyNum << " >> Non-Player Army: < "<< object.whiteNum<<" >>"<<endl;
    return output;
}
//For assignment 2
void Territory::setWhiteNum(int whiteNum) {
    this->whiteNum += whiteNum;
}

int Territory::getWhiteNum() {
    return whiteNum;
}


/**********************/

Continent::Continent()
{
    cName = "";
    cID = 0;

    //part 6 by nian
    pName = "";
}
Continent::Continent(string cName, int cID)
{
    this->cName = cName;
    this->cID = cID;

    //part 6 by nian
    this->pName = "";
}

/**********************/
//Copy Constructor
Continent::Continent(const Continent& object) {
    this->cName = object.cName;
    this->cID = object.cID;

    //part 6 by nian
    this->pName = object.pName;
}
//Assignment Operator
Continent& Continent::operator = (const Continent& object) {
    this->cName = object.cName;
    this->cID = object.cID;

    //part6 by nian
    this->pName = object.pName;
    return *this;
}
//Destructor
Continent::~Continent() {

}
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Continent& object) {
    output << "Continent Name: " << object.cName << "Continent ID: " << object.cID << endl;
    return output;
}
/*********************/

Territory* Continent::getCentre()
{
    if (territoryMemberInContinent.empty()) {
        return NULL;
    }
    Territory* max = territoryMemberInContinent[0];
    for (auto i = 0; i < territoryMemberInContinent.size(); i++) {
        if (max->getAdjacentTerritoryInSameContinent() < territoryMemberInContinent[i]->getAdjacentTerritoryInSameContinent()) {
            max = territoryMemberInContinent[i];
        }
    }
    return max;
}

string Continent::getCName() { return cName; }
int Continent::getCID() { return cID; }
vector<Territory*> Continent::getTerritoryMemberInContinent() { return territoryMemberInContinent; }
//check continent's subGraph is a connected graph or not
//if subGraph is good, return true.
//if not, return false.
bool Continent::checkSubGraph()
{
    int len = this->territoryMemberInContinent.size();//get length of all nodes in one continent
    vector<int> visited;//record all visited node in same continent
    for (int i = 0; i < len; i++) {//loop all nodes
        if (visited.empty()) {//add first node into visited list
            visited.push_back(this->territoryMemberInContinent[i]->getTID());
        }
        int len1 = this->territoryMemberInContinent[i]->adjacentTerritoryInSameContinent.size();//get length of each node's adjacent list
        for (int j = 0; j < len1; j++) {//loop the adjacent list
            int temp = this->territoryMemberInContinent[i]->adjacentTerritoryInSameContinent[j];//get the adjacent node id
            int len2 = visited.size();//get the length of visited list
            for (int k = 0; k < len2; k++) {//loop visited list
                if (temp == visited[k]) {//if adjacent node id exist in visited list, goto next adjacent node
                    break;
                }
                if (k == (len2 - 1)) {//if adjacent node not exist in visited list, add it into visited list
                    if (temp != visited[k]) {
                        visited.push_back(temp);
                    }
                }
            }
        }
    }
    if (visited.size() != len) {//all visited list length should equal length of all nodes in one continent
        return false;//subgraph is not connected
    }
    return true;//subgraph is connected
}
set<int> Continent::getReachableForeignContinent() { return reachableForeignContinent; }

//part 6 by nian
string Continent::getPName() { return this->pName; }
void Continent::setPName(string p) { this->pName = p; }

Map::Map()
{
    mName = "";
    numOfAllContinent = 0;
    numOfAllTerritory = 0;
    invalid = false;

}
Map::Map(string mName, int numOfAllTerritory, int numOfAllContinent)
{
    this->mName = mName;
    this->numOfAllTerritory = numOfAllTerritory;
    this->numOfAllContinent = numOfAllContinent;
    this->invalid = false;

}
/**********************/
//Copy Constructor
Map::Map(const Map& object) {
    this->mName = object.mName;
    this->numOfAllTerritory = object.numOfAllTerritory;
    this->numOfAllContinent = object.numOfAllContinent;
    this->allTerritory = object.allTerritory;
    this->allContinent = object.allContinent;
    this->invalid = object.invalid;
}
//Assignment Operator
Map& Map::operator = (const Map& object) {
    this->mName = object.mName;
    this->numOfAllTerritory = object.numOfAllTerritory;
    this->numOfAllContinent = object.numOfAllContinent;
    this->allTerritory = object.allTerritory;
    this->allContinent = object.allContinent;
    this->invalid = object.invalid;
    return *this;
}
//Destructor
Map::~Map() {};
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Map& object) {
    return output << "Map:" << object.mName << "Num Territory: " << object.numOfAllTerritory << "Num Continent: " << object.numOfAllContinent << endl;
}
/**********************/

Territory* Map::getCentre()
{
    Territory* max = NULL;
    int maxContinent = 0;
    for (auto i = 1; i < allContinent.size(); i++) {
        if (allContinent[maxContinent]->getReachableForeignContinent().size() < allContinent[i]->getReachableForeignContinent().size())
            maxContinent = i;
    }
    return allContinent[maxContinent]->getCentre();
}
Territory* Map::getTerritoryById(int id)
{
    for (auto i = 0; i < allTerritory.size(); i++) {
        if (allTerritory[i]->getTID() == id)
            return allTerritory[i];
    }
    return nullptr;
}
string Map::getMName() { return mName; }
bool Map::getInvalid() { return invalid; }
int Map::getNumOfAllTerritory() { return numOfAllTerritory; }
int Map::getNumOfAllContinent() { return numOfAllContinent; }
vector<Territory*> Map::getAllTerritory() { return allTerritory; }

void Map::setMapName(string mName)
{
    mName = mName;
}
void Map::printAllTerritory()
{
    cout << allTerritory.size() << endl;
}
void Map::printAllContinent()
{
    cout << allContinent.size() << endl;
}
//Map validate() check if each continent in map, its subGraph is connected or not
//if false, map is invalid, if true, check all continent are connected to each other
//if false, map is invalid, if true, map is valid
void Map::validate()
{
    int len = this->allContinent.size();
    set<int> visitedContinent;
    set<int>::const_iterator iter;
    for (int i = 0; i < len; i++) {
        if (this->allContinent[i]->checkSubGraph()) {
            //cout << "Map's Continent->" << this->allContinent[i]->getCName() << " is connected." << endl;
        }
        else {
            cout << "Map's Continent->" << this->allContinent[i]->getCName() << " is disconnected." << endl;
            cout << "Map is invalid because at least one Continent subgraph is not connected." << endl;
            return;
        }
    }
    for (int j = 0; j < len; j++) {
        for (iter = this->allContinent[j]->reachableForeignContinent.begin(); iter != this->allContinent[j]->reachableForeignContinent.end(); ++iter) {
            visitedContinent.insert(*iter);
        }
    }
    if (visitedContinent.size() != len) {
        cout << "Map is invalid because at least one continent is not reachable!!!" << endl;
    }
    else {
        this->invalid = true;
        cout << "Map is good, you can enjoy the game." << endl;
    }
}