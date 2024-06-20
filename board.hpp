#ifndef BOARD_HPP
#define BOARD_HPP


#include <vector>
#include "tile.hpp"
#include "edge.hpp"
#include "vertices.hpp"
#include "player.hpp"

class Board {
    private:
        std::vector<Tile> tiles;
        std::vector<Edge> edges;
        std::vector<Vertex> vertices;
        Player& p1;
        Player& p2;
        Player& p3;
        int playerTurn;
        int positionOfRobber; // first position is 10. at the Desert tile
    public:
        Board(Player& p1, Player& p2, Player& p3);
        void initialize();
        void buildSettlement(int vertex, Player &player);
        void buildRoad(int edge, Player &player);
        void buildCity(int vertex, Player &player);
        void shareResources(size_t dices);
        void reduceHalfResourcesFromPlayers();
        void monopolyAction(size_t res, Player &player);
        void chechVictoryPoints();

        // finish game when everyone has no power to play anymore
        void finishGame();

        // Getters
        std::vector<Tile>& getTiles();
        Edge& getEdge(int id);
        Vertex& getVertex(int id);
        Player& getPlayer(int id);
        int getPlayerTurn() const;
        int getRobber() const;

        // Setters
        void nextTurn();
        void setRobber(int position);
};

//#include "player.hpp" 

#endif // 
