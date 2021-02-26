//
// Created by Nian Liu on 2021-02-14.
//

#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

MapLoader::MapLoader()
{
    worldMap= nullptr;
    mapFile="/Users/nianliu/Desktop/part2/";
}

/*******************/
//Copy Constructor
MapLoader::MapLoader(const MapLoader& object) {
    this->worldMap = new Map(*(object.worldMap));
    this->mapFile = object.mapFile;
}
//Assignment Operator
MapLoader& MapLoader::operator = (const MapLoader& object) {
    this->worldMap = new Map(*(object.worldMap));
    this->mapFile = object.mapFile;
    return *this;
}
//Destructor
MapLoader::~MapLoader() {
	for (int i = 0; i < worldMap->allTerritory.size(); i++) {
        delete worldMap->allTerritory.at(i);
        worldMap->allTerritory[i] = nullptr;
    }
    for (int i = 0; i < worldMap->allContinent.size(); i++) {
        delete worldMap->allContinent.at(i);
        worldMap->allContinent[i] = nullptr;
    }
    delete worldMap;
    worldMap = NULL;
};

//Stream Insertion Operator
ostream& operator<<(ostream& output, const MapLoader& object) {
    return output << "Map Information: " << *object.worldMap << "File Path: " << object.mapFile << endl;
}
/*******************/

string MapLoader::getMapFile() {return mapFile;}
void MapLoader::setMapFile(const string& mf) {this->mapFile+=mf;}
vector<string> MapLoader::tokenizeString(const string& s){
    // Vector of string to save tokens
    vector <string> tokens;
    // stringstream class check1
    stringstream check1(s);
    string intermediate;
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ','))
    {
        tokens.push_back(intermediate);
    }
    return tokens;
}
void MapLoader::readMap()
{
    bool mapFlag=false;
    bool continentFlag=false;
    bool territoryFlag=false;
    bool adjacentFlag=false;
    int continentNum=0;
    int territoryNum=0;
    int adjacentRow=0;
    string myText;
    // Read from the text file
    ifstream MyReadFile(this->mapFile);
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        if(myText=="Map:"){
            mapFlag=true;
            continue;
        }
        if(mapFlag){
            vector<string> line;
            cout<<myText<<endl;
            line=tokenizeString(myText);
            if(line.size()!=3){
                cout<<"Wrong MapFile format!!! Map has invalid Map elements"<<endl;
                break;
            }
            this->worldMap=new Map(line[0],stoi(line[1]),stoi(line[2]));
            mapFlag=false;
            //cout<<worldMap->getNumOfAllTerritory()<<endl;
        }
        if(myText=="Continent:"){
            continentFlag=true;
            continue;
        }
        if(continentFlag){
            continentNum++;
            vector<string> line;
            cout<<myText<<endl;
            line=tokenizeString(myText);
            if(line.size()!=2){
                cout<<"Wrong MapFile format!!! Map has invalid Continent elements"<<endl;
                break;
            }
            worldMap->allContinent.push_back(new Continent(line[0],stoi(line[1])));
            if(continentNum==worldMap->getNumOfAllContinent()){
                continentFlag=false;
            }
        }
        if(myText=="Territory:"){
            territoryFlag=true;
            continue;
        }
        if(territoryFlag){
            territoryNum++;
            vector<string> line;
            cout<<myText<<endl;
            line=tokenizeString(myText);
            if(line.size()!=4){
                cout<<"Wrong MapFile format!!! Map has invalid Territory elements"<<endl;
                break;
            }
            worldMap->allTerritory.push_back(new Territory(line[0],line[1],stoi(line[2]),stoi(line[3])));
            if(territoryNum==worldMap->getNumOfAllTerritory()){
                territoryFlag=false;
            }
        }
        if(myText=="Adjacent status:"){
		int len = worldMap->allTerritory.size();
	    for (int i = 0; i < len; i++) {
                worldMap->allContinent[worldMap->allTerritory[i]->getContinentID()]->territoryMemberInContinent.push_back(worldMap->allTerritory[i]);
            }
     
            adjacentFlag=true;
            continue;
        }
        if(adjacentFlag){
            vector<string> line;
            line=tokenizeString(myText);
            if(line.size()>worldMap->getNumOfAllTerritory()){
                cout<<"Wrong MapFile format!!! Map has invalid adjacent elements"<<endl;
                break;
            }
            for(auto & i : line){
                worldMap->allTerritory[adjacentRow]->adjacentTerritoryInMap.push_back(stoi(i));
                int currentContinent=worldMap->allTerritory[adjacentRow]->getContinentID();
                if(adjacentRow!=stoi(i)&&currentContinent==worldMap->allTerritory[stoi(i)]->getContinentID()){
                    worldMap->allTerritory[adjacentRow]->adjacentTerritoryInSameContinent.push_back(stoi(i));
                }
                if(adjacentRow!=stoi(i)&&currentContinent!=worldMap->allTerritory[stoi(i)]->getContinentID()){
                    worldMap->allContinent[currentContinent]->reachableForeignContinent.insert(worldMap->allTerritory[stoi(i)]->getContinentID());
                }
            }
            adjacentRow++;
            if(adjacentRow==worldMap->getNumOfAllTerritory()){
                territoryFlag=false;
            }
        }

    }
    // Close the file
    MyReadFile.close();
}
