#ifndef DEVELOPMENTCARDS_HPP
#define DEVELOPMENTCARDS_HPP

#include <iostream>
using namespace std;

class DevelopmentCards {
    private:
        size_t knights;
        size_t victoryPoints;
        size_t roadBuilding;
        size_t yearOfPlenty;
        size_t monopoly;
        size_t openKnights;
        bool biggestArmy;
    public:

        static const size_t MAX_KNIGHTS = 3;
        static const size_t MAX_VICTORY_POINTS = 4;

        DevelopmentCards();

        void buyCard();

        void addKnight();
        void addVictoryPoint();
        void addRoadBuilding();
        void addYearOfPlenty();
        void addMonopoly();
        void addOpenKnight();

        void removeKnight();
        void removeVictoryPoint();
        void removeRoadBuilding();
        void removeYearOfPlenty();
        void removeMonopoly();
        void removeOpenKnight();
        void setBiggestArmy(bool biggestArmy);

        size_t getKnight() const;
        size_t getVictoryPoint() const;
        size_t getRoadBuilding() const;
        size_t getYearOfPlenty() const;
        size_t getMonopoly() const;
        size_t getOpenKnight() const;
        bool getBiggestArmy() const;
        
        size_t countCards() const;
        void status() const;
        size_t getPoints() const;
};

#endif // DEVELOPMENTCARDS_HPP
