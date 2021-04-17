GameEngine.cpp
#include"GameEngine.h"

GameEngine::GameEngine() {
    vector<Player*> players;
    playingDeck = new Deck();
    hand = new Hand();
    wml = new MapLoader();
    mode = "Defacult";
}

GameEngine::~GameEngine() {

}

void GameEngine::setMap() {
    cout << "\n**********  Selecting The Game Map  ************\n";
    cout << "1 ---> map.txt ( L )" << endl;
    cout << "2 ---> map1.txt ( Rectangular )" << endl;
    cout << "..." << endl;
    cout << "Please press the number keys to select the corresponding map to start the game " << endl;
    bool chooseMap = false;
    string mPath;//choose correct map path to prepare for loading the map
    while (!chooseMap) {
        int mapIndex = 0;
        cout << "Choose Number [1-2] : ";
        cin >> mapIndex;
        if (mapIndex == 1) {
            this->wml->mapFile = "/Users/Administrator/Desktop/2021winter/COMP 345 Project/A2_Team_26/Part_1_6/map.txt";
            chooseMap = true;
        }
        else if (mapIndex == 2) {
            this->wml->mapFile = "map1.txt";
            chooseMap = true;
        }

    }

    //cout << this->wml->getMapFile() << endl;
    this->wml->readMap();

    this->wml->worldMap->validate();//validate the map, only the good map will allow player continue to play
    if (this->wml->worldMap->getInvalid() == 0) {
        cout<< "Invalid Map. Exit!";
        exit(0);
    }
}


void GameEngine::setDeck() {
    ////2 players
   // cout << "Cards generating ..." << endl;//init cards and deck

    playingDeck->setDeck(new Cards("Ancient Tree Spirit", "3 elixirs", "Place 4 armies"));
    playingDeck->setDeck(new Cards("Ancient Phoenix", "Flying", "Move 5 armies"));
    playingDeck->setDeck(new Cards("Ancient Sage", "+1 VP per Ancient Card", "Move 3 armies"));
    playingDeck->setDeck(new Cards("Ancient Tree Spirit", "3 elixirs", "Place 4 armies"));
    playingDeck->setDeck(new Cards("Ancient Woods", "1 new army", "Build a city AND place 1 army"));
    playingDeck->setDeck(new Cards("Cursed Banshee", "2 elixirs", "Move 6 armies"));
    playingDeck->setDeck(new Cards("Cursed Gargoyles", "Flying", "Move 5 armies"));
    playingDeck->setDeck(new Cards("Cursed King", "1 elixir", "Place 3 armies OR Move 4 armies"));
    playingDeck->setDeck(new Cards("Cursed Mausoleum", "Move 1 army", "Build a city"));
    playingDeck->setDeck(new Cards("Cursed Tower", "+1 VP per flying", "Build a city"));
    playingDeck->setDeck(new Cards("Dire Dragon", "Flying", "Move 3 armies AND Destroy army"));
    playingDeck->setDeck(new Cards("Dire Eye", "Flying", "Place 4 armies"));
    playingDeck->setDeck(new Cards("Dire Giant", "Immune to attack", "Place 3 armies AND Destroy army"));
    playingDeck->setDeck(new Cards("Dire Goblin", "1 elixir", "Move 5 armies"));
    playingDeck->setDeck(new Cards("Dire Ogre", "+1 VP per 3 coins", "Move 2 armies"));
    playingDeck->setDeck(new Cards("Forest Elf", "1 army", "Place 3 armies OR Move 2 armies"));
    playingDeck->setDeck(new Cards("Forest Gnome", "3 elixirs", "Move 2 armies"));
    playingDeck->setDeck(new Cards("Forest Pixie", "1 army", "Move 4 armies"));
    playingDeck->setDeck(new Cards("Forest Tree Town", "Move 1 army", "Build a city"));
    playingDeck->setDeck(new Cards("Graveyard", "+1 VP per Cursed Card", "Place 2 armies"));
    playingDeck->setDeck(new Cards("Lake", "+1 VP per Forest Card", "Place 2 armies OR Move 3 armies"));
    playingDeck->setDeck(new Cards("Night Hydra", "1 army", "Move 5 armies AND Destroy army"));
    playingDeck->setDeck(new Cards("Night Village", "1 army", "Build a city"));
    playingDeck->setDeck(new Cards("Night Wizard", "+1 VP per Night Card", "Move 2 armies"));
    playingDeck->setDeck(new Cards("Noble Hills", "Three noble cards = 4VP", "Place 3 armies"));
    playingDeck->setDeck(new Cards("Noble Knight", "Move 1 army", "Place 4 armies AND Destroy army"));
    playingDeck->setDeck(new Cards("Noble Unicorn", "Move 1 army", "Move 4 armies AND Place 1 army"));
    playingDeck->setDeck(new Cards("Stronghold", "+1 VP per Dire card", "Build a city"));
    //Shuffle the cards
    playingDeck->shuffling();
}


void GameEngine::setHand() {
    for (int i = 0; i < 6; i++) {
        hand->setHand(playingDeck->draw());
    };
}


void GameEngine::setStartRegoin() {
    //Loop For Placing the Starting Regoin
    cout << "\n********** For Placing the Starting Regoin  ************\n";
    for (int i = 0; i < players.size(); i++) {
        //Displaying Territory
        for (int i = 0; i < wml->worldMap->getAllTerritory().size(); i++) {
            cout << i + 1 << " -- "<< *wml->worldMap->getAllTerritory()[i]<< endl;
        }
        int temp;
        cout << "Player " << i + 1 << " :\n";
        cout << "Enter The index of Territory , you want to set as the starting regoin: ";
        cin >> temp;

        while (!(temp > 0 && temp < wml->worldMap->getAllTerritory().size() && wml->worldMap->getAllTerritory()[temp-1]->getPlayer().length() == 0 ))
        {
            cout << "The Starting Regoin was ocuppied by Player Or Invaild Number. Please Try Again: ";
            cin >> temp;
        }
        players[i]->PlaceNewArmies(wml->worldMap->getAllTerritory()[temp-1], 4);
        //cout << *players[i]<<endl;
    }
}


void GameEngine::setNonPlayerArmy() {
    //Loop For Placing non-player Army
    int whiteNum = 0;
    cout << "\n********** For Placing non-player Army  ************\n";
    while (whiteNum < 9) {
        for (int i = 0; i < players.size(); i++) {
            int temp;
            for (int i = 0; i < wml->worldMap->getAllTerritory().size(); i++) {
                cout << i + 1 << " - " << *wml->worldMap->getAllTerritory()[i] << endl;
            }
            cout << "Player " << players[i]->getName() << " :\n";
            cout << "Enter The index of Territory , you want to put Non-Player Army: ";
            cin >> temp;
            while (temp <= 0 || temp > wml->worldMap->getAllTerritory().size()) {
                cout << "Invalied Input. Please try again: ";
                cin >> temp;
            }
            wml->worldMap->getAllTerritory()[temp - 1]->setWhiteNum(1);
            whiteNum++;
        }
    }
}


void GameEngine::setPlayers() {
    cout << "**********   Welcome to Eight-Minute Empire  **********\n" << endl;

    cout << "**********  Please Enter Player Information  **********" << endl;
    string name;
    //Set Player Loop and Bidding
    for (int i = 0; i < 2; i++) {

        cout << "Player ";
        cout << i + 1;
        cout << " : Please entery your name: ";
        cin >> name;

        this->players.push_back(new Player());
        this->players[i]->setName(name);
        this->players[i]->setArmy(-18);
        this->players[i]->setCityToken(3);
        this->players[i]->setCoin(-14);
        BiddingFacility* temp = new BiddingFacility();

        cout << "Player ";
        cout << i + 1;
        cout << " : ";

        temp->setBid();
        this->players[i]->setBidding(temp);

        cout << *this->players[i] << endl;

        delete temp;
        temp = nullptr;

    }
    //cout << "\n********** compareBidding Method And Rearrange the Player Vector  ************\n";
    //Finding Player bid highest and Rearrange the Player Vector
    compareBidding(players);

    //Displayer Players Rank
    cout << "\n********** Players Rank  ************\n";
    for (int i = 0; i < players.size(); i++) {
        cout << *players[i] << endl;
    }
}


void GameEngine::gameloop() {
    //variable to keep track how many card each player has drawn
    int numberOfCardEachPlayer = 0;

    //The game will end when each player has drawn 13 card
    while (numberOfCardEachPlayer < 12)
    {
        //Players will take turns doing actions
        for (int i = 0; i < players.size(); i++)
        {
            cout << "\nThis is the turn of player  " << players[i]->getName() << endl;
            cout << "\nFirst Card Costs << 0 coin >>, Second/Third Card Card Costs << 1 coin >>, Fourth/Fifth Card Costs << 2 coin >>, Sixth Card Costs << 3 coin >> \n" << endl;
            cout << *hand << endl;
            //index of the card the player choose
            int chosenCardNumber;
            cout << "Please enter the index of the card you wanna choose: ";
            cin >> chosenCardNumber;

            while (chosenCardNumber < 1 || chosenCardNumber > 6)
            {
                cout << "Sorry the index you chose is not valid. Please enter a number from 1 to 6" << endl;
                cout << "Please enter the index of the card you wanna choose: ";
                cin >> chosenCardNumber;
            }

            players[i]->setNum(chosenCardNumber);

            //the player choose the card, pay the coin then add it to his hand cards
            hand->exchange(chosenCardNumber, players[i]);

            //add 1 more card to the hand to replace for the card that has been chosen
            hand->setHand(playingDeck->draw());

            //print out the player's info
            //cout << *players[i];

            players[i]->dealWithHand(players, wml);

            //players[i]->fitMap(players, wml);

            numberOfCardEachPlayer++;
        }
    }
}

void GameEngine::computeScord() {
    //cout << "Below is for part6 testing ..." << endl;
    auto* cs1 = new CardScord();
    auto* cs2 = new CardScord();
    
    //Compute Card's Scord
    players[0]->loadCardMap(cs1);
    //cs1->printCS();
    int s1 = 0;
    s1 = players[0]->calCS(cs1);
    //cout << players[0]->getName() <<" get card total score: " << s << endl;
    players[1]->loadCardMap(cs2);
    //cs2->printCS();
    int s2 = 0;
    s2 = players[1]->calCS(cs2);
    //cout << players[0]->getName()<<" get card total score: " << ss << endl;

    int p1s = 0;
    int p2s = 0;

    //p1s += s1;
    //p2s += s2;

    //compute Territory Score For Player 1
    int count = 0;
    for (int i = 0; i < players[0]->getTerritory().size(); i++) {
        if (players[0]->getTerritory()[i]->getArmyNum() > players[0]->getTerritory()[i]->getWhiteNum()) {
            count++;
        }
    }
    p1s += count;

    //compute Territory Score For Player 2
    count = 0;
    for (int i = 0; i < players[1]->getTerritory().size(); i++) {
        if (players[1]->getTerritory()[i]->getArmyNum() > players[1]->getTerritory()[i]->getWhiteNum()) {
            count++;
        }
    }
    p2s += count;

    //compute Continent Score For Player 1
    count = 0;
    for (int i = 0; i < wml->worldMap->getNumOfAllContinent(); i++) {
        count = 0;
        for (int j = 0; j < wml->worldMap->getAllContinent()[i]->getTerritoryMemberInContinent().size(); j++) {
            if (wml->worldMap->getAllContinent()[i]->getTerritoryMemberInContinent()[j]->getPlayer() == players[0]->getName()) {
                count++;
            }
            if (wml->worldMap->getAllContinent()[i]->getTerritoryMemberInContinent()[j]->getPlayer() != players[0]->getName() && wml->worldMap->getAllContinent()[i]->getTerritoryMemberInContinent()[j]->getPlayer().length() != 0) {
                count--;
            }
        }
        if (count > 0) {
            count++;
        }
    }
    p1s += count*2;

    //compute Continent Score For Player 2
    count = 0;
    for (int i = 0; i < wml->worldMap->getNumOfAllContinent(); i++) {
        count = 0;
        for (int j = 0; j < wml->worldMap->getAllContinent()[i]->getTerritoryMemberInContinent().size(); j++) {
            if (wml->worldMap->getAllContinent()[i]->getTerritoryMemberInContinent()[j]->getPlayer() == players[1]->getName()) {
                count++;
            }
            if (wml->worldMap->getAllContinent()[i]->getTerritoryMemberInContinent()[j]->getPlayer() != players[1]->getName() && wml->worldMap->getAllContinent()[i]->getTerritoryMemberInContinent()[j]->getPlayer().length() != 0) {
                count--;
            }
        }
        if (count > 0) {
            count++;
        }
    }
    p2s += count*2;

    //Compute Card Score
    p1s += players[0]->calCS(cs1);
    p2s += players[1]->calCS(cs2);

    //Compute Elixir Score
    if (cs1->cs["elixir"] != cs2->cs["elixir"]) {
        if (cs1->cs["elixir"] > cs2->cs["elixir"]) {
            p1s += 2;
        }
        else {
            p2s += 2;
        }
    }

    cout << players[0]->getName() <<" Victory Points: " << p1s << endl;
    cout << players[1]->getName()<<" Victory Points: " << p2s << endl;

    if (p1s != p2s) {
        if (p1s > p2s) {
            cout << "Game winner is " << players[0]->getName() << endl;
            return;
        }
        else {
            cout << "Game winner is " << players[1]->getName() << endl;
            return;
        }
    }
    if (players[0]->getTerritory() != players[1]->getTerritory()) {
        if (players[0]->getTerritory() > players[1]->getTerritory()) {
            cout << "Game winner is " << players[0]->getName() << endl;
            return;
        }
        else {
            cout << "Game winner is " << players[1]->getName() << endl;
            return;
        }
    }
    if (players[0]->getCoin() != players[1]->getCoin()) {
        if (players[0]->getCoin() > players[1]->getCoin()) {
            cout << "Game winner is " << players[0]->getName() << endl;
            return;
        }
        else {
            cout << "Game winner is " << players[1]->getName() << endl;
            return;
        }
    }
    if (players[0]->getArmy() != players[1]->getArmy()) {
        if (players[0]->getArmy() > players[1]->getArmy()) {
            cout << "Game winner is " << players[0]->getName() << endl;
            return;
        }
        else {
            cout << "Game winner is " << players[1]->getName() << endl;
            return;
        }
    }

    cout << "Tow players are even, Game is over." << endl;

}