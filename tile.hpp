#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <vector>
using namespace std;

class Board;

enum ResourceType { WOOD, BRICK, WHEAT, SHEEP, IRON, DESERT };

class Tile {
    private:
        int id;
        ResourceType resource;
        size_t number;
        vector<int> vertices;
    public:
        Tile(int id, ResourceType res, int num);
        void addVertex(int v1, int v2, int v3, int v4, int v5, int v6);

        // Getters
        size_t getNumber() const;
        ResourceType getResource() const;
        vector<int> getVertices() const;
        int getId() const;
};

#endif // TILE_HPP
