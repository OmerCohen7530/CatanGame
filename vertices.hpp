#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
using namespace std;

enum Building{CITY, SETTLEMENT, NO_BUILDING};
class Vertex {
    private:
        Building building;
        int id;
        int owner;
        vector<int> edges;
    public:
        Vertex(int id);
        void build(int player, Building type);
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

#endif // 
