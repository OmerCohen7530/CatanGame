// mail - omer7530@gmail.com
// Author - Omer Cohen

#ifndef EDGE_HPP
#define EDGE_HPP

#include "player.hpp"
#include <vector>
#include <iostream>
using namespace std;

enum Road { ROAD, NO_ROAD };

class Edge {
    private:
        Road road; // Type of road on the edge
        int id; // Edge ID
        int owner; // ID of the player owning the edge
        vector<int> vertices; // IDs of vertices connected to the edge

    public:
        // Constructor
        Edge(int id);

        // Builds a road for a player
        void buildRoad(int player);

        // Adds vertices connected to this edge
        void addVertices(int vertex1, int vertex2);

        // Getters
        Road getRoad() const;
        int getId() const;
        int getOwner() const;
        vector<int> getVertices() const;

        // Setters
        void setOwner(int player);
};

#endif // EDGE_HPP
