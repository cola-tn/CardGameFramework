#include <iostream>
#include <vector>
#include <algorithm>

class CardGameFramework {
private:
    std::vector<std::string> suit = { "Diamonds", "Hearts", "Clubs", "Spades" };
    std::vector<std::string> type = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
public:
    std::vector<std::string> cardGen(int genType, std::vector<std::string> customCardType = {}, std::vector<std::string> customCardSuit = {}, int customCardTypeAmount = {}, int customCardSuitAmount = 0) {
        if (genType == 1) { // Standard Deck
            int t = rand() % 13;
            int s = rand() % 4;
            return { type[t], suit[s] }; // Custom deck with "Suits"
        }
        else if (genType == 2) {
            int t = rand() % customCardTypeAmount;
            int s = rand() % customCardSuitAmount;
            return { customCardType[t], customCardSuit[s] };
        }
        else if (genType == 3) { // Custom deck, no suits
            int t = rand() % customCardTypeAmount;
            return { customCardType[t] };
        }
        else return {};

    }

    void printCards(std::vector<std::vector<std::string>> vector, int type) {
        if (type == 1 || type == 2) { // Standard deck or Custom deck with Suits
            for (int h = 0; h < vector.size(); h++) {
                std::cout << vector[h][0] << " of : " << vector[h][1] << "\n";
            }
        }
        else if (type == 3) { // Custom deck, no suits
            for (int h = 0; h < vector.size(); h++) {
                std::cout << vector[h][0];
            }
        }
    }

    std::vector<std::string> pickCard(std::vector<std::vector<std::string>> deckInput, int deckCount) {
        return { deckInput[deckCount][0], deckInput[deckCount][1] }; // Use this return value and add to hand
    }
};