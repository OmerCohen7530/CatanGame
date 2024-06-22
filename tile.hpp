// mail - omer7530@gmail.com
// Author - Omer Cohen

#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <vector>
using namespace std;

class Board;

enum ResourceType { WOOD, BRICK, WHEAT, SHEEP, IRON, DESERT };

class Tile {
    private:
        int id; // Tile ID
        ResourceType resource; // Resource type of the tile
        size_t number; // Tile number for resource distribution
        vector<int> vertices; // IDs of vertices connected to the tile
    public:
        // Constructor
        Tile(int id, ResourceType res, int num);

        // Adds vertices connected to this tile
        void addVertex(int v1, int v2, int v3, int v4, int v5, int v6);

        // Getters
        size_t getNumber() const;
        ResourceType getResource() const;
        vector<int> getVertices() const;
        int getId() const;
};

#endif // TILE_HPP
