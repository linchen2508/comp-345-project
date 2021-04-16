//#include "Cards.h"
//#include "Player.h"
//#include "Map.h"
//#include "MapLoader.h"
//#include "GameEngine.h"
//#include <string>
//
//using namespace std;
//
//int main() {
//
//    GameEngine* gamebot = new GameEngine();
//
//    gamebot->setPlayers();
//    gamebot->setDeck();
//    gamebot->setHand();
//    gamebot->setMap();
//    
//    gamebot->setStartRegoin();
//
//    //Oberserver For Part 2
//    ActionObserver* A1 = new ActionObserver(gamebot->getPlayerVector()[0]);
//    ActionObserver* A2 = new ActionObserver(gamebot->getPlayerVector()[1]);
//
//    //variable to keep track how many card each player has drawn
//    int numberOfCardEachPlayer = 0;
//
//    cout << "\n\n//***** ONLY FOR DEMO PART 2 with 4 Rounds and NOT USE GameEngine Loop *****//\n" << endl;
//
//    while (numberOfCardEachPlayer < 4)
//    {
//        //Players will take turns doing actions
//        for (int i = 0; i < gamebot->getPlayerVector().size(); i++)
//        {
//            cout << "\nThis is the turn of player  " << gamebot->getPlayerVector()[i]->getName() << endl;
//            cout << "\nFirst Card Costs << 0 coin >>, Second/Third Card Card Costs << 1 coin >>, Fourth/Fifth Card Costs << 2 coin >>, Sixth Card Costs << 3 coin >> \n" << endl;
//            cout << *gamebot->getHand()<< endl;
//            //index of the card the player choose
//            int chosenCardNumber;
//            cout << "Please enter the index of the card you wanna choose: ";
//            cin >> chosenCardNumber;
//
//            while (chosenCardNumber < 1 || chosenCardNumber > 6)
//            {
//                cout << "Sorry the index you chose is not valid. Please enter a number from 1 to 6"<<endl;
//                cout << "Please enter the index of the card you wanna choose: ";
//                cin >> chosenCardNumber;
//            }
//
//            gamebot->getPlayerVector()[i]->setNum(chosenCardNumber);
//
//            //the player choose the card, pay the coin then add it to his hand cards
//            gamebot->getHand()->exchange(chosenCardNumber, gamebot->getPlayerVector()[i]);
//
//            //add 1 more card to the hand to replace for the card that has been chosen
//            gamebot->getHand()->setHand(gamebot->getDeck()->draw());
//
//            //print out the player's info
//            //cout << *players[i];
//
//            gamebot->getPlayerVector()[i]->dealWithHand(gamebot->getPlayerVector(), gamebot->getMapLoader());
//
//            numberOfCardEachPlayer++;
//        }
//    }
//
//    //gamebot->computeScord();
//
//    delete gamebot;
//    gamebot = NULL;
//    delete A1;
//    A1 = NULL;
//    delete A2;
//    A2 = NULL;
//}