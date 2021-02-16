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

    string getMapFile();
    void setMapFile(string mf);
    vector<string> tokenizeString(string s);
    void readMap();

};


#endif //PART2_MAPLOADER_H
