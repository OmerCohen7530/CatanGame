#ifndef DEVELOPMENTCARDS_HPP
#define DEVELOPMENTCARDS_HPP

#include <iostream>
using namespace std;

class DevelopmentCards {
    private:
        size_t knights; // Number of knight cards
        size_t victoryPoints; // Number of victory point cards
        size_t roadBuilding; // Number of road building cards
        size_t yearOfPlenty; // Number of year of plenty cards
        size_t monopoly; // Number of monopoly cards
        size_t openKnights; // Number of open knight cards
        bool biggestArmy; // Indicates if the player has the biggest army
    public:
        static const size_t MAX_KNIGHTS = 3; // Maximum number of knight cards
        static const size_t MAX_VICTORY_POINTS = 4; // Maximum number of victory point cards

        // Constructor
        DevelopmentCards();

        // Buys a development card
        void buyCard();

        // Adds a specific type of card
        void addKnight();
        void addVictoryPoint();
        void addRoadBuilding();
        void addYearOfPlenty();
        void addMonopoly();
        void addOpenKnight();

        // Removes a specific type of card
        void removeKnight();
        void removeVictoryPoint();
        void removeRoadBuilding();
        void removeYearOfPlenty();
        void removeMonopoly();
        void removeOpenKnight();

        // Sets the biggest army status
        void setBiggestArmy(bool biggestArmy);

        // Getters
        size_t getKnight() const;
        size_t getVictoryPoint() const;
        size_t getRoadBuilding() const;
        size_t getYearOfPlenty() const;
        size_t getMonopoly() const;
        size_t getOpenKnight() const;
        bool getBiggestArmy() const;

        // Other methods
        size_t countCards() const; // Counts the total number of cards
        void status() const; // Displays the status of development cards
        size_t getPoints() const; // Gets the total points from the cards
};

#endif // DEVELOPMENTCARDS_HPP
