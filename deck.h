#ifndef DECKH
#define DECKH
#include "card.h"
#include <vector>
using namespace std;

class Deck{
    private:
        Card cardDeck[53];
        int dealTracker;
    public:
        Deck( ); // constructor which creates a deck of 52 cards
        Card deal( ); // deal a card if you can - otherwise raise an exception
        void display( ); // show all the cards in the deck
        void shuffle( ); // shuffle the cards in the deck
        bool isEmpty(); // return true if deck is empty
};
#endif
