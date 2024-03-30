#include <iostream>
#include <string>
#include "card.h"
using namespace std;

Card:: Card()
{
}

Card::Card(char rank1, char suit1)
{
	rank = rank1;
    suit = suit1;
}

void Card::display()
{
    if(rank == 'T')
    {
        cout << "10" << suit << ' ';
    }
    else if(rank == '\0')
    {
        cout << '\0';
    }
	else
    {
        cout << rank << suit << ' ';
    }
}

int Card::compare(Card toCompare)
{

    /*
    No use of maps so if statements are used to convert Ace to 1 and T to I (I < J) for ASCII comparison
    */
    char newRank = rank;
    char toCompareNewRank = toCompare.rank;
    if(rank == 'A')
    {
        newRank = '1';
    }
    if(rank == 'T')
    {
        newRank = 'I';
    }
    if(rank == 'K')
    {
        newRank = 'Z';
    }
    if(toCompare.rank == 'A')
    {
        toCompareNewRank = '1';
    }
    if(toCompare.rank == 'T')
    {
        toCompareNewRank = 'I';
    }
    if(toCompare.rank == 'K')
    {
        toCompareNewRank = 'Z';
    }

    /*
    Compare via ASCII Comparison
    */
    if(newRank > toCompareNewRank)
    {
        return 1;
    }
    else if(newRank < toCompareNewRank)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
