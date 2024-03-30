#include "deck.h"
#include "card.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    /*
    Information for the Players
    */
    string player1;
    string player2;
    int numPlays = 0;
    int player1_numWins = 0;
    int player1_numLosses = 0;
    int player2_numWins = 0;
    int player2_numLosses = 0;
    int ties = 0;
    cout << "\nEnter the name of the first player: ";
    cin >> player1;
    cout << "Enter the name of the second player: ";
    cin >> player2;
    cout << "\nHow many games will they play? ";
    cin >> numPlays;

    /*
    Deck initialization and display
    */
    Deck cards;
    cout << endl;
    cout << "Original Deck" << endl;
    cards.display();
    
    
    /*
    Shuffle Deck and Display
    */
    cards.shuffle();
    cout << endl;
    cout << "Shuffled Deck" << endl;
    cards.display();
    cout << endl;

    /*
    Playing the Game
    */

   for(int i = 1; i < numPlays + 1; i++)
   {
    try
    {
        if (cards.isEmpty())
        {
            throw 0;
        }
        cout << "Game " << i << endl;
        cout << "--------" << endl;

        /*
        Dealing for Player 1
        */
        Card firstCard = cards.deal();
        cout << "        " << player1 << "=>";
        firstCard.display();

        /*
        Dealing for Player 2
        */
        Card secondCard = cards.deal();
        cout << endl;
        cout << "        " << player2 << "=>";
        secondCard.display();
        cout << endl;

        /*
        Comparison
        */
        int compared = firstCard.compare(secondCard);
        if(compared == 1)
        {
            player1_numWins++;
            player2_numLosses++;
            cout << player1 << "=> Winner" << endl;
        }
        else if(compared == -1)
        {
            player2_numWins++;
            player1_numLosses++;
            cout << player2 << "=> Winner" << endl;
        }
        else if(compared == 0)
        {
            ties++;
            cout << "Tie game" << endl;
        }
        cout << endl;
    }
    catch(int o)
    {
        cout << "Error - Deck is Empty\n" << endl;
        break;
    }
    
   }

    /*
    Game Stats
    */
    cout << "------Final Stats------" << endl;
    cout << "       " << player1 << " vs. " << player2 << endl;
    cout << "Wins   " << player1_numWins << setw((player1.size() - to_string(player1_numWins).size() + 1) + 5) << player2_numWins << endl;
    cout << "Losses " << player1_numLosses << setw(player1.size() - to_string(player1_numLosses).size() + 6) << player2_numLosses << endl;
    cout << "Ties   " << ties << setw(player1.size() - to_string(ties).size() + 6) << ties << endl;

    string endGame;
    cout << "\n";
    cin >> endGame;
}
