#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "deck.h"
#include "card.h"
using namespace std;

Deck::Deck()
{
    char suits[4] = {'C', 'S', 'D', 'H'};
    char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int counter = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            cardDeck[counter] = Card(ranks[j], suits[i]);
            counter++;
        }
    }
    // cardDeck[52] = Card('\0', '\0');
}

Card Deck::deal()
{
    Card dealed = cardDeck[dealTracker];
    dealTracker++;
    return dealed;
}

void Deck::display()
{
    for(int i = 1; i < 53; i++)
    {
        cardDeck[i-1].display();
        if(i % 13 == 0){
            cout << endl;
        }
    }
}

void Deck::shuffle()
{
    srand(time(0));
    for(int i = 0; i < 52; i++)
    {
        int num1 = rand() % 52;
        int num2 = rand() % 52;
        swap(cardDeck[num1], cardDeck[num2]);
    }
}

bool Deck::isEmpty()
{
    if (dealTracker == 52)
    {
        return true;
    }
    return false;
}