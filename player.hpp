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
        string name;
        int id;
    
    public:
        std::map<ResourceType, size_t> resources;
        size_t cities; // 2 points; 4
        size_t settlements; // 1 point; 5
        size_t roads; // 15
        size_t cards;
        bool alreadyRolled;
        DevelopmentCards devCards;


        Player(int id, string name);
        Player(Player &player);
        void addResource(ResourceType res, int amount);
        bool checkVictory();
        void rollDices(Board &board);
        void initSettlements_Roads(int settlements, int roads, Board &board);
        void status();
        size_t getVictoryPoints();

        // place building
        int placeSettlement(int vertex, Board &board);
        int placeRoad(int edge, Board &board);
        int placeCity(int vertex, Board &board);

        bool canBuildSettlement(int vertex, Board &board);
        bool canBuildRoad(int edge, Board &board);
        bool canBuildCity(int vertex, Board &board);
        void addAssets(string asset);
        void tradeFromto(ResourceType from, ResourceType to, Board &board);
        size_t countResources();
        void endTurn(Board &board);
        void buyDevCard(Board &board);
        void useDevCard(string card, Board &board);

        // help check if road can be built without resources check
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
