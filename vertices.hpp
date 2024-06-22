#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
using namespace std;

enum Building { CITY, SETTLEMENT, NO_BUILDING };

class Vertex {
    private:
        Building building; // Type of building on the vertex
        int id; // Vertex ID
        int owner; // ID of the player owning the vertex
        vector<int> edges; // IDs of connected edges
    public:
        // Constructor
        Vertex(int id);

        // Builds a structure (city or settlement) for a player
        void build(int player, Building type);

        // Adds edges connected to this vertex
        void addEdges(int vertex, int vertex2, int vertex3 = -1);

        // Getters
        Building getBuilding() const;
        int getId() const;
        int getOwner() const;
        vector<int>& getEdges();

        // Setters
        void setOwner(int player);
        void setBuilding(Building type);
};

#endif // VERTEX_HPP
