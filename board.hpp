// mail - omer7530@gmail.com
// Author - Omer Cohen

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "tile.hpp"
#include "edge.hpp"
#include "vertices.hpp"
#include "player.hpp"

class Board {
    private:
        std::vector<Tile> tiles; // Collection of all tiles on the board
        std::vector<Edge> edges; // Collection of all edges on the board
        std::vector<Vertex> vertices; // Collection of all vertices on the board
        Player& p1; // Reference to player 1
        Player& p2; // Reference to player 2
        Player& p3; // Reference to player 3
        int playerTurn; // Tracks the current player's turn
        int positionOfRobber; // Position of the robber, initially set to the Desert tile
    public:
        // Constructor
        Board(Player& p1, Player& p2, Player& p3);

        // Initializes the board with tiles, edges, and vertices
        void initialize();

        // Builds a settlement at the specified vertex for the given player
        void buildSettlement(int vertex, Player &player);

        // Builds a road at the specified edge for the given player
        void buildRoad(int edge, Player &player);

        // Builds a city at the specified vertex for the given player
        void buildCity(int vertex, Player &player);

        // Distributes resources to players based on the dice roll
        void shareResources(size_t dices);

        // Reduces the resources of all players by half
        void reduceHalfResourcesFromPlayers();

        // Executes a monopoly action, taking all resources of a specific type from other players
        void monopolyAction(size_t res, Player &player);

        // Checks if any player has reached the victory points needed to win the game
        void chechVictoryPoints();

        // Ends the game when no player can continue playing
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

#endif // BOARD_HPP
