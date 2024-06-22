#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>
#include "tile.hpp"
#include "developmentCards.hpp"
using namespace std;

class Board;

class Player {
    private:
        string name; // Player's name
        int id; // Player's ID
    
    public:
        std::map<ResourceType, size_t> resources; // Resources owned by the player
        size_t cities; // Number of cities (2 points each, max 4)
        size_t settlements; // Number of settlements (1 point each, max 5)
        size_t roads; // Number of roads (max 15)
        size_t cards; // Number of development cards
        bool alreadyRolled; // Indicates if the player has already rolled the dice this turn
        DevelopmentCards devCards; // Development cards owned by the player

        // Constructor
        Player(int id, string name);

        // Copy constructor
        Player(Player &player);

        // Adds a specific amount of a resource to the player's inventory
        void addResource(ResourceType res, int amount);

        // Checks if the player has achieved victory
        bool checkVictory();

        // Rolls the dice and distributes resources accordingly
        void rollDices(Board &board);

        // Initializes the player's settlements and roads
        void initSettlements_Roads(int settlements, int roads, Board &board);

        // Displays the player's status
        void status();

        // Gets the player's total victory points
        size_t getVictoryPoints();

        // Places a settlement at a specified vertex
        int placeSettlement(int vertex, Board &board);

        // Places a road at a specified edge
        int placeRoad(int edge, Board &board);

        // Places a city at a specified vertex
        int placeCity(int vertex, Board &board);

        // Checks if the player can build a settlement at a specified vertex
        bool canBuildSettlement(int vertex, Board &board);

        // Checks if the player can build a road at a specified edge
        bool canBuildRoad(int edge, Board &board);

        // Checks if the player can build a city at a specified vertex
        bool canBuildCity(int vertex, Board &board);

        // Adds assets to the player's inventory
        void addAssets(string asset);

        // Trades resources from one type to another
        void tradeFromto(ResourceType from, ResourceType to, Board &board);

        // Counts the total number of resources the player has
        size_t countResources();

        // Ends the player's turn
        void endTurn(Board &board);

        // Buys a development card
        void buyDevCard(Board &board);

        // Uses a development card
        void useDevCard(string card, Board &board);

        // Helps with road building using the road building card
        void help_Road_Building_Card(Board &board);

        // Getters
        string getName() const;
        int getId() const;
        bool getAlreadyRolled() const;
        size_t getResources(ResourceType res);

        // Setters
        void setHalfResources();
        void setAlreadyRolled(bool rolled);
};

#endif // PLAYER_HPP
