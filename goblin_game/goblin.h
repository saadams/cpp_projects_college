#ifndef GOBLIN_H
#define GOBLIN_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
namespace goblin
{

    // Takes an integer and returns the corresponding card as a string (e.g., "Ace", "Queen").
    // integrated/replaced within printCards method.
    // std::string displayCard(void);

    // Takes the player's bank balance as a double and returns the number of games they can afford as an integer.
    int gamesAfforded(double balance);

    // Takes the face values of a d20 and two d10s as integers and returns their sum.
    int rollSum(void);

    // print roll funct returns string
    std::string printRoll(void);

    // boolean func for even or odd roll
    bool isRollEven(int d20, int d10a, int d10b);
    // Simulates a d10 roll and returns the result as an integer.
    int d10();
    // Simulates a d20 roll and returns the result as an integer.
    int d20();
    // Takes the values of three cards and the face values of a d20 and two d10s, and calculates the winnings for a single roll.
    double rollWinnings(int cardA, int cardB, int cardC, int d20, int d10a, int d10b);
    // Takes three booleans representing if each roll sum is even or not and calculates the winnings for the game's end condition.
    // might change to float
    double endWinnings(bool r1, bool r2, bool r3);

    void printCards(int card);

    int deckSum(int cardA, int cardB, int cardC);

    class Deck
    {
    private:
        std::vector<int> deck;

    public:
        // create Deck method which adds deck to the deck arrary.
        Deck();

        void shuffleCards();

        int draw();

        // Takes the values of three deck as integers and returns their sum.
    };

};
#endif

/*Rules:

A game costs $0.25.

The Goblin Master reveals three deck. Sum the deck. Joker is 0, Ace is 1, Jack 11, Queen 12, King 13.

You get three rolls per game. A single roll is:

Roll one d20 (1-20) and two d10s (0-9).
Sum the face values of the dice.
Record if the dice sum is even or odd.
Winning:

If any dice sum equals the card sum, then you win $1.00.
If you roll a natural 20 and the dice sum is within 1 of the card sum, then you win $1.00.
If you roll three even dice sums or three odd dice sums, you get your $0.25 back.*/