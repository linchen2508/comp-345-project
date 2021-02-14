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
string MapLoader::getMapFile() {return mapFile;}
void MapLoader::setMapFile(string mf) {this->mapFile+=mf;}
vector<string> MapLoader::tokenizeString(string s){
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
            if(continentNum==3){
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
            if(territoryNum==7){
                territoryFlag=false;
            }
        }
        if(myText=="Adjacent status:"){
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
            for(int i=0;i<line.size();i++){
                worldMap->allTerritory[adjacentRow]->adjacentTerritoryInMap.push_back(stoi(line[i]));
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
