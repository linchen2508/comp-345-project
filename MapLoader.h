//
// Created by Nian Liu on 2021-02-14.
//

#ifndef PART2_MAPLOADER_H
#define PART2_MAPLOADER_H

#include "Map.h"

class MapLoader {
public:
    Map* worldMap;
    string mapFile;

    MapLoader();
 
    /*******************/
    //Copy Constructor
    MapLoader(const MapLoader& object);
    //Assignment Operator
    MapLoader& operator = (const MapLoader& object);
    //Destructor
    ~MapLoader();
    //Stream Insertion Operator
    friend ostream& operator<<(ostream& output, const MapLoader& object);
    /*******************/

    string getMapFile();
    Map* getMap() { return worldMap; };
    void setMapFile(const string& mf);
    vector<string> tokenizeString(const string& s);
    void readMap();
};

#endif //PART2_MAPLOADER_H