// mail - omer7530@gmail.com
// Author - Omer Cohen

#include "edge.hpp"

Edge::Edge(int id):  road(NO_ROAD), id(id), owner(0){}

void Edge::buildRoad(int player)
{
    if(road == NO_ROAD)
    {
        road = ROAD;
        owner = player;
    }
    else
    {
        std::cout << "Road already built" << std::endl;
    }
}

void Edge::addVertices(int vertex1, int vertex2)
{
    vertices.push_back(vertex1);
    vertices.push_back(vertex2);
}

Road Edge::getRoad() const
{
    return road;
}

int Edge::getId() const
{
    return id;
}

int Edge::getOwner() const
{
    return owner;
}

std::vector<int> Edge::getVertices() const
{
    return vertices;
}

void Edge::setOwner(int player)
{
    owner = player;
    if (player == 0)
    {
        road = NO_ROAD;
    }
    else
    {
        road = ROAD;
    }
}
