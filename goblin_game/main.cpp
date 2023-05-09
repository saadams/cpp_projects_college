#include <iostream>
#include <string>
#include <limits>
#include <tuple>
#include "goblin.h"
using namespace goblin;



    std::tuple<bool, double> doRoll(int cardA, int cardB, int cardC)
    {   
        std::cout << "rolling......" << std::endl;
        int rollA{d20()};
        std::cout << "D20: " << rollA << std::endl;
        int rollB{d10()};
         std::cout << "D10: " << rollB << std::endl;
        int rollC{d10()};
         std::cout << "D10: " << rollC << std::endl;

        double w = rollWinnings(cardA, cardB, cardC, rollA, rollB, rollC);

        return std::make_tuple(isRollEven(rollA, rollB, rollC), w);
       
    };

    int main()
    {
        
        std::cout << "Hello, world!\n";
        std::cout.precision(2);
        std::cout << "Enter bank balance... ";
        double bal;
        std::cin >> bal;
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int games = gamesAfforded(bal);
        for (int i = 0; i <= games; i++)
        {
            std::cout << "Round " << i << "!" << std::endl;
            Deck deck;
            int card1 = deck.draw();
            int card2 = deck.draw();
            int card3 = deck.draw();
            std::cout << "Goblin master is revealling cards.... " << std::endl;
            printCards(card1);
            printCards(card2);
            printCards(card3);  
            bool roll1 = std::get<0>(doRoll(card1,card2,card3));
            //std::cout << roll1;
            bool roll2 = std::get<0>(doRoll(card1,card2,card3));
            bool roll3 = std::get<0>(doRoll(card1,card2,card3));
            double winnings = endWinnings(roll1,roll2,roll3);
            std::cout << "You won: " << winnings << "!" << std::endl;
        }; 
        return 0;
    };


