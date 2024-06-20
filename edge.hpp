#ifndef EDGE_HPP
#define EDGE_HPP

#include "player.hpp"
#include <vector>
#include <iostream>
using namespace std;

enum Road{ROAD, NO_ROAD};
class Edge {
    private:
        Road road;
        int id;
        int owner;
        vector<int> vertices;
        
    public:
        Edge(int id);
        void buildRoad(int player);
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
