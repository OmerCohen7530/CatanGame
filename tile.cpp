// mail - omer7530@gmail.com
// Author - Omer Cohen

#include "tile.hpp"
#include "board.hpp"

Tile::Tile(int id, ResourceType res, int num) : id(id), resource(res), number(num) 
{
    vertices.resize(6);
}

void Tile::addVertex(int v1, int v2, int v3, int v4, int v5, int v6)
{
    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);
    vertices.push_back(v5);
    vertices.push_back(v6);
}

size_t Tile::getNumber() const
{
    return number;
}

ResourceType Tile::getResource() const
{
    return resource;
}

vector<int> Tile::getVertices() const
{
    return vertices;
}

int Tile::getId() const
{
    return id;
}

