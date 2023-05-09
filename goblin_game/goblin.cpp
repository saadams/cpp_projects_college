#include <iostream>
#include "goblin.h"
#include <vector>
#include <random>

namespace goblin
{

    std::mt19937 mt{std::random_device{}()};
    // std::uniform_int_distribution d6rng { 1, 6 };
    std::uniform_int_distribution d10rng{0, 9};
    std::uniform_int_distribution d20rng{1, 20};

    int d10()
    {
        return d10rng(mt);
    };

    int d20()
    {
        return d20rng(mt);
    };

    int rollSum(int d20, int d10a, int d10b)
    {
        return d20 + d10a + d10b;
    };

    int gamesAfforded(double balance)
    {

        return balance / 0.25;
    };

    Deck::Deck()
    {
        // Two jokers
        deck.push_back(0);
        deck.push_back(0);

        // Thirteen cards in each suit
        for (int i = 1; i <= 4; ++i)
        {
            for (int i = 1; i <= 13; ++i)
            {
                deck.push_back(i);
            }
        }

        shuffleCards();
    }

    void Deck::shuffleCards()
    {
        // Shuffle with the seed mt from above.
        std::shuffle(deck.begin(), deck.end(), mt);
    };

    int Deck::draw()
    {
        int card = deck.back();
        deck.pop_back();
        return card;
    };

    bool isRollEven(int d20, int d10a, int d10b)
    {
        return rollSum(d20, d10a, d10b) % 2 == 0;
    }

    double rollWinnings(int cardA, int cardB, int cardC, int d20, int d10a, int d10b)
    {
        int cSum{deckSum(cardA, cardB, cardC)};
        int rSum{rollSum(d20, d10a, d10b)};

        if (cSum == rSum)
        {
            return 1.0;
        }
        else if (d20 == 20 && (cSum == rSum - 1 || cSum == rSum + 1))
        {
            return 1.0;
        }
        else
        {
            return 0.0;
        }
    };

    void printCards(int card)
    {
        if (card == 0)
        {
            std::cout << "Card: Joker" << std::endl;
            return;
        }

        std::cout << "Card: ";

        switch (card)
        {
        case 1:
            std::cout << "Ace";
            break;
        case 11:
            std::cout << "Jack";
            break;
        case 12:
            std::cout << "Queen";
            break;
        case 13:
            std::cout << "King";
            break;
        default:
            std::cout << card;
        }

        std::cout << std::endl;
    };

    int deckSum(int cardA, int cardB, int cardC)
    {
        return cardA + cardB + cardC;
    };

    double endWinnings(bool r1, bool r2, bool r3)
    {
        int evens { 0 };
        int odds { 0 };

        if (r1) evens++; else odds++;
        if (r2) evens++; else odds++;
        if (r3) evens++; else odds++;

        if (evens == 3 || odds == 3) {
            return 0.25;
        }
        
        return 0.0;
    }
};
