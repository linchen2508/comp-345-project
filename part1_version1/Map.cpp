//
// Created by Nian Liu on 2021-02-09.
//

#include "Map.h"
#include <iostream>
#include <iomanip>
#include <stack>
#include <typeinfo>

Territory::Territory()
{
    tName="";
    tID=0;
    continentName="";
    continentID=0;
    playerID=0;
    armyNum=0;
    connectedForeignContinent=false;

}
Territory::Territory(string tName, string continentName, int tID, int continentID)
{
    this->tName=tName;
    this->tID=tID;
    this->continentName=continentName;
    this->continentID=continentID;
    this->playerID=0;
    this->armyNum=0;
    this->connectedForeignContinent=false;

}
string Territory::getTName(){return tName;}
int Territory::getTID(){return tID;}
string Territory::getContinentName(){return continentName;}
int Territory::getContinentID(){return continentID;}
int Territory::getPlayerID(){return playerID;}
int Territory::getArmyNum(){return armyNum;}
bool Territory::getConnectedForeignContinent(){return connectedForeignContinent;}
vector<int> Territory::getAdjacentTerritoryInMap(){return adjacentTerritoryInMap;}
vector<int> Territory::getAdjacentTerritoryInSameContinent(){return adjacentTerritoryInSameContinent;}
vector<int> Territory::getReachableForeignContinent(){return reachableForeignContinent;}
void Territory::setTName(string tName)
{
    tName=tName;
}
void Territory::setTID(int tID)
{
    tID=tID;
}
void Territory::setConnectedForeignContinent(bool canGoOut)
{
    connectedForeignContinent=canGoOut;
}
void Territory::printTerritoryVector(vector<int> v)
{
    if(v.size()!=NULL){
        int len=v.size();
        for(int i=0;i<len;i++){
            cout<< " " << v[i];
        }
    }else{
        cout<< " no element ";
    }

}
/**********************/
//For Part 3 Method
bool getBuildCity(){
    return build_city;
}
void setArmy(int armyNum){
    this->armyNum += armyNum;
}
void setBuildCity(){
    build_city = true;    
}
void setPlayer(string player){
    this->player = player;
}
//Stream Insertion Operator
ostream& operator<<(ostream& output, const Territory& object){
    string temp;
    if(build_city == 0){
        temp = "No";
    }else{
        temp = "Yes";
    }
   output << "Territory Name: " << object.tName << " Player: " << object.player << " Build City: " << temp << " Army: " << object.armyNum << endl;
    return output;
}

/**********************/

Continent::Continent()
{
    cName="";
    cID=0;
}
Continent::Continent(string cName, int cID)
{
    this->cName=cName;
    this->cID=cID;
}
string Continent::getCName(){return cName;}
int Continent::getCID(){return cID;}
vector<Territory*> Continent::getTerritoryMemberInContinent(){return territoryMemberInContinent;}
bool Continent::checkSubGraph()
{
    int len=this->territoryMemberInContinent.size();//get length of all nodes in one continent
    vector<int> visited;//record all visited node in same continent
    for(int i=0;i<len;i++){//loop all nodes
        if(visited.empty()){//add first node into visited list
            visited.push_back(this->territoryMemberInContinent[i]->getTID());
        }
        int len1=this->territoryMemberInContinent[i]->adjacentTerritoryInSameContinent.size();//get length of each node's adjacent list
        for(int j=0;j<len1;j++){//loop the adjacent list
            int temp=this->territoryMemberInContinent[i]->adjacentTerritoryInSameContinent[j];//get the adjacent node id
            int len2=visited.size();//get the length of visited list
            for(int k=0;k<len2;k++){//loop visited list
                if(temp==visited[k]){//if adjacent node id exist in visited list, goto next adjacent node
                    break;
                }
                if(k==(len2-1)){//if adjacent node not exist in visited list, add it into visited list
                    if(temp!=visited[k]){
                        visited.push_back(temp);
                    }
                }
            }
        }
    }
    if(visited.size()!=len){//all visited list length should equal length of all nodes in one continent
        return false;//subgraph is not connected
    }
    return true;//subgraph is connected
}


Map::Map()
{
    mName="";
    numOfAllContinent=0;
    numOfAllTerritory=0;

}
Map::Map(string mName, int numOfAllTerritory, int numOfAllContinent)
{
    this->mName=mName;
    this->numOfAllTerritory=numOfAllTerritory;
    this->numOfAllContinent=numOfAllContinent;

}
string Map::getMName(){return mName;}
int Map::getNumOfAllTerritory(){return numOfAllTerritory;}
int Map::getNumOfAllContinent(){return numOfAllContinent;}
vector<Territory*> Map::getAllTerritory() {return allTerritory;}
void Map::setMapName(string mName)
{
    mName=mName;
}
void Map::printAllTerritory()
{
    cout<<allTerritory.size()<<endl;
}
void Map::printAllContinent()
{
    cout<<allContinent.size()<<endl;
}
void Map::validate()
{
    int len=this->allContinent.size();
    for(int i=0;i<len;i++){
        if(this->allContinent[i]->checkSubGraph()){
            cout<<"Map's Continent->"<<this->allContinent[i]->getCName()<<" is connected."<<endl;
        }else{
            cout<<"Map's Continent->"<<this->allContinent[i]->getCName()<<" is disconnected."<<endl;
            cout<<"Map is invalid because at least one Continent subgraph is not connected."<<endl;
            break;
        }
    }
}
