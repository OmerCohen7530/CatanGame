#include "developmentCards.hpp"

// Constructor
DevelopmentCards::DevelopmentCards() 
    : knights(0), victoryPoints(0), roadBuilding(0), yearOfPlenty(0), monopoly(0),openKnights(0), biggestArmy(false) {}

// Buy card
void DevelopmentCards::buyCard() 
{
    bool bought = false;
    while(!bought){
        size_t dice1 = rand() % 5 + 1;
        
        switch (dice1)
        {
        case 1:
            if(knights < MAX_KNIGHTS){
                addKnight();
                cout << "You bought a Knight card" << endl;
                bought = true;
            }
            break;
        case 2:
            if (victoryPoints < MAX_VICTORY_POINTS) {
                addVictoryPoint();
                cout << "You bought a Victory Point card" << endl;
                bought = true;
            }
            break;
        case 3:
            addRoadBuilding();
            cout << "You bought a Road Building card" << endl;
            bought = true;
            break;
        case 4:
            addYearOfPlenty();
            cout << "You bought a Year of Plenty card" << endl;
            bought = true;
            break;
        case 5:
            addMonopoly();
            cout << "You bought a Monopoly card" << endl;
            bought = true;
            break;
        default:
            break;
        }
    }
}

// Add cards
void DevelopmentCards::addOpenKnight() {
    openKnights++;
}

void DevelopmentCards::addKnight() {
    knights++;
}

void DevelopmentCards::addVictoryPoint() {
    victoryPoints++;
}

void DevelopmentCards::addRoadBuilding() {
    roadBuilding++;
}

void DevelopmentCards::addYearOfPlenty() {
    yearOfPlenty++;
}

void DevelopmentCards::addMonopoly() {
    monopoly++;
}

// Remove cards
void DevelopmentCards::removeOpenKnight() {
    if (openKnights > 0) openKnights--;
}

void DevelopmentCards::removeKnight() {
    if (knights > 0) knights--;
}

void DevelopmentCards::removeVictoryPoint() {
    if (victoryPoints > 0) victoryPoints--;
}

void DevelopmentCards::removeRoadBuilding() {
    if (roadBuilding > 0) roadBuilding--;
}

void DevelopmentCards::removeYearOfPlenty() {
    if (yearOfPlenty > 0) yearOfPlenty--;
}

void DevelopmentCards::removeMonopoly() {
    if (monopoly > 0) monopoly--;
}

// Get card counts
size_t DevelopmentCards::getKnight() const {
    return knights;
}

size_t DevelopmentCards::getVictoryPoint() const {
    return victoryPoints;
}

size_t DevelopmentCards::getRoadBuilding() const {
    return roadBuilding;
}

size_t DevelopmentCards::getYearOfPlenty() const {
    return yearOfPlenty;
}

size_t DevelopmentCards::getMonopoly() const {
    return monopoly;
}

size_t DevelopmentCards::getOpenKnight() const {
    return openKnights;
}

void DevelopmentCards::setBiggestArmy(bool biggestArmy) {
    this->biggestArmy = biggestArmy;
}

// Count total cards
size_t DevelopmentCards::countCards() const {
    return knights + victoryPoints + roadBuilding + yearOfPlenty + monopoly;
}

// Print status
void DevelopmentCards::status() const {
    std::cout << "\tDevelopment Cards Status:" << std::endl;
    std::cout << "\t\tKnights: " << knights << std::endl;
    std::cout << "\t\tVictory Points: " << victoryPoints << std::endl;
    std::cout << "\t\tRoad Building: " << roadBuilding << std::endl;
    std::cout << "\t\tYear of Plenty: " << yearOfPlenty << std::endl;
    std::cout << "\t\tMonopoly: " << monopoly << std::endl;
    std::cout << "\t\tBiggest Army: " << (biggestArmy ? "Yes" : "No") << std::endl;
}

// Get victory points
size_t DevelopmentCards::getPoints() const {
    size_t points = 0;
    points += victoryPoints;
    if (biggestArmy) points += 2;
    return points;
}