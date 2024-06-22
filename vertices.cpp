// mail - omer7530@gmail.com
// Author - Omer Cohen

#include "vertices.hpp"

Vertex::Vertex(int id): building(NO_BUILDING), id(id), owner(0){}

void Vertex::build(int player, Building type)
{
    if(building == NO_BUILDING)
    {
        building = type;
        owner = player;
    }
    else
    {
        std::cout << "Building already built" << std::endl;
    }
}

void Vertex::addEdges(int vertex, int vertex2, int vertex3)
{
    edges.push_back(vertex);
    edges.push_back(vertex2);
    if(vertex3 != -1)
    {
        edges.push_back(vertex3);
    }
}

Building Vertex::getBuilding() const
{
    return building;
}

int Vertex::getId() const
{
    return id;
}

int Vertex::getOwner() const
{
    return owner;
}

std::vector<int>& Vertex::getEdges()
{
    return edges;
}

void Vertex::setOwner(int player)
{
    owner = player;
}

void Vertex::setBuilding(Building type)
{
    building = type;
}






