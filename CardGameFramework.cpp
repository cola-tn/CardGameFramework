// CardGameFramework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "cgf.cpp"

// DEMO PROGRAM! HIGHLY UNFINSHED
int main() {
    srand(time(NULL)); // set rand seed
    CardGameFramework cgf; // create instance of class

    // Deck creation
    std::cout << "Generating deck...\n\n\n";
    std::vector<std::vector<std::string>> deck;
    int deckCount = 0;
    for (; deck.size() < 52;) {
        std::vector<std::string> chosenCard = { cgf.cardGen(1) };
        int count = std::count(deck.begin(), deck.end(), chosenCard);
        if (count > 0) {
            chosenCard.clear();
        }
        else {
            deck.push_back(chosenCard);
            chosenCard.clear();
        }
    }

    // Hand creation
    std::vector<std::vector<std::string>> playerHand, cpu1Hand, cpu2Hand, cpu3Hand;
    for (int z = 0; z < 5; z++) {
        playerHand.push_back(cgf.pickCard(deck, deckCount));
        deckCount++;
        cpu1Hand.push_back(cgf.pickCard(deck, deckCount));
        deckCount++;
        cpu2Hand.push_back(cgf.pickCard(deck, deckCount));
        deckCount++;
        cpu3Hand.push_back(cgf.pickCard(deck, deckCount));
        deckCount++;
    }

    // Variable declaration
    std::vector<std::vector<std::vector<std::string>>> playerPairs, cpu1Pairs, cpu2Pairs, cpu3Pairs;
    int playerPairNo, cpu1PairNo, cpu2PairNo, cpu3PairNo;
    int gameStatus = 0; // 0: in progress 1: finished
    int askedCardNo, askedPlayerNo, askStatus;

    while (gameStatus == 0) {


        std::cout << "Current pairs on the table\n";

        // print current pairs on the table
        if (playerPairs.size() != 0) {
            std::cout << "Player's pairs:\n";
            for (int c = 0; c < playerPairs.size(); c++) {
                std::cout << c + 1 << ". " << playerPairs[c][0][0] << " of " << playerPairs[c][0][1] << " and " << playerPairs[c][1][0] << " of " << playerPairs[c][1][1] << "\n";
            }
        }
        if (cpu1Pairs.size() != 0) {
            std::cout << "CPU 1's pairs";
            for (int c = 0; c < cpu1Pairs.size(); c++) {
                std::cout << c + 1 << ". " << cpu1Pairs[c][0][0] << " of " << cpu1Pairs[c][0][1] << " and " << cpu1Pairs[c][1][0] << " of " << cpu1Pairs[c][1][1] << "\n";
            }
        }
        if (cpu2Pairs.size() != 0) {
            std::cout << "CPU 2's pairs";
            for (int c = 0; c < cpu2Pairs.size(); c++) {
                std::cout << c + 1 << ". " << cpu2Pairs[c][0][0] << " of " << cpu2Pairs[c][0][1] << " and " << cpu2Pairs[c][1][0] << " of " << cpu2Pairs[c][1][1] << "\n";
            }
        }
        if (cpu3Pairs.size() != 0) {
            std::cout << "CPU 3's pairs";
            for (int c = 0; c < cpu3Pairs.size(); c++) {
                std::cout << c + 1 << ". " << cpu3Pairs[c][0][0] << " of " << cpu3Pairs[c][0][1] << " and " << cpu3Pairs[c][1][0] << " of " << cpu3Pairs[c][1][1] << "\n";
            }
        }

        std::cout << "Player's hand:\n";
        for (int c = 0; c < playerHand.size(); c++) {
            std::cout << c + 1 << ". " << playerHand[c][0] << " of " << playerHand[c][1] << "\n";
        }

        askStatus = 0;
        while (askStatus == 0 || askStatus == 2) {
            std::cout << "\nWhich card would you like to ask for?";
            std::cin >> askedCardNo;
            std::cout << "Which player?";
            std::cin >> askedPlayerNo;
            askStatus = 0;
            if (askedCardNo >= (playerHand.size() + 1) || askedCardNo < 1 || askedPlayerNo > 3 || askedPlayerNo < 1) {
                std::cout << "invalid input";
            }
            else if (askedPlayerNo == 1) {
                for (int i = 0; i < cpu1Hand.size();) {
                    std::string pulledCard = cpu1Hand[i][0];
                    std::string askedCard = playerHand[askedCardNo][0];
                    if (pulledCard == askedCard) {
                        askStatus = 2;
                        playerHand.push_back(cpu1Hand[i]);
                        std::cout << "Success!\n\n";
                        break;
                    }
                    else i++;
                }
                if (askStatus != 2) {
                    std::cout << "Go fish\n\n";
                    askStatus = 1;
                    break;
                }
            }
            else if (askedPlayerNo == 2) {
                for (int i = 0; i < cpu2Hand.size();) {
                    std::string pulledCard = cpu2Hand[i][0];
                    std::string askedCard = playerHand[askedCardNo][0];
                    if (pulledCard == askedCard) {
                        askStatus = 2;
                        playerHand.push_back(cpu2Hand[i]);
                        std::cout << "Success!\n\n";
                        break;
                    }
                    else i++;
                }
                if (askStatus != 2) {
                    std::cout << "Go fish\n\n";
                    playerHand.push_back(cgf.pickCard(deck, deckCount));
                    deckCount++;
                    askStatus = 1;
                    break;
                }
            }
            else if (askedPlayerNo == 3) {
                for (int i = 0; i < cpu3Hand.size();) {
                    std::string pulledCard = cpu3Hand[i][0];
                    std::string askedCard = playerHand[askedCardNo][0];
                    if (pulledCard == askedCard) {
                        askStatus = 2;
                        playerPairs.push_back({ cpu3Hand[i], playerHand[askedCardNo] });
                        std::cout << "Success!\n\n";
                        break;
                    }
                    else i++;
                }
                if (askStatus != 2) {
                    std::cout << "Go fish\n\n";
                    playerHand.push_back(cgf.pickCard(deck, deckCount));
                    deckCount++;
                    askStatus = 1;
                    break;
                }
            }
            else return 1;
        }

        // DEBUG STUFF
        // for (int i = deckCount; i < deck.size(); i++) {
          // std::cout << deck[i][0] << " of " << deck[i][1] << "\n";
        // }
    }
}

