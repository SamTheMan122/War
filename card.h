#ifndef CARDH
#define CARDH
class Card{
    private:
        char rank;
        char suit;
    public:
        Card(); // Default constructor
        Card(char, char); // constructor to create a card, setting the suit and rank
        void display( ); // display the card example: AC, 10S, KD
        int compare(Card); // return 1 for win, 0 for tie, -1 for lose
};
#endif