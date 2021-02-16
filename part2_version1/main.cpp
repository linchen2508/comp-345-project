#include <iostream>
#include <fstream>
#include "MapLoader.h"

int main() {
    MapLoader wml;
    wml.setMapFile("map.txt");
    cout<<wml.getMapFile()<<endl;
    wml.readMap();
    wml.worldMap->printAllContinent();
    wml.worldMap->printAllTerritory();
    //print adjacent relation line by line
    //each line represent each territory's adjacent relation with other t in map
    for(int i=0;i<wml.worldMap->getNumOfAllTerritory();i++){
        for(int j : wml.worldMap->allTerritory[i]->adjacentTerritoryInMap){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    wml.worldMap->validate();
    return 0;
}
