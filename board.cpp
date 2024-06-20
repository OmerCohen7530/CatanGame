#include "board.hpp"


Board::Board(Player& p1, Player& p2, Player& p3) : p1(p1), p2(p2), p3(p3)
{
    initialize();
    cout << "Board initialized" << endl;
    
}

void Board::initialize()
{
    // initialize the tiles
    tiles.push_back(Tile(1,IRON, 10));
    tiles.push_back(Tile(2,SHEEP, 2));
    tiles.push_back(Tile(3,WOOD, 9));
    tiles.push_back(Tile(4,WHEAT, 12));
    tiles.push_back(Tile(5,BRICK, 6));
    tiles.push_back(Tile(6,SHEEP, 4));
    tiles.push_back(Tile(7,BRICK, 10));
    tiles.push_back(Tile(8,WHEAT, 9));
    tiles.push_back(Tile(9,WOOD, 11));
    tiles.push_back(Tile(10,DESERT, 7));
    tiles.push_back(Tile(11,WOOD, 3));
    tiles.push_back(Tile(12,IRON, 8));
    tiles.push_back(Tile(13,WOOD, 8));
    tiles.push_back(Tile(14,IRON, 3));
    tiles.push_back(Tile(15,WHEAT, 4));
    tiles.push_back(Tile(16,SHEEP, 5));
    tiles.push_back(Tile(17,BRICK, 5));
    tiles.push_back(Tile(18,WHEAT, 6));
    tiles.push_back(Tile(19,SHEEP, 11));

    // initialize the edges
    for(int i = 1; i <= 72; i++)
    {
        edges.push_back(Edge(i));
    }

    // initialize the vertices
    for(int i = 0; i <= 53; i++)
    {
        vertices.push_back(Vertex(i));
    }

    // connect the tiles to the vertices
    tiles[0].addVertex(0, 1, 2, 3, 4, 5);
    tiles[1].addVertex(1, 6, 7, 8, 9, 2);
    tiles[2].addVertex(7, 10, 11, 12, 13, 8);
    tiles[3].addVertex(4, 3, 14, 15, 16, 17);
    tiles[4].addVertex(3, 2, 9, 18, 19, 14);
    tiles[5].addVertex(9, 8, 13, 20, 21, 18);
    tiles[6].addVertex(13, 12, 22, 23, 24, 20);
    tiles[7].addVertex(16, 15, 25, 26, 27, 28);
    tiles[8].addVertex(15, 14, 19, 29, 30, 25);
    tiles[9].addVertex(19, 18, 21, 31, 32, 29);
    tiles[10].addVertex(21, 20, 24, 33, 34, 31);
    tiles[11].addVertex(24, 23, 35, 36, 37, 33);
    tiles[12].addVertex(26, 25, 30, 40, 39, 38);
    tiles[13].addVertex(30, 29, 32, 41, 42, 40);
    tiles[14].addVertex(32, 31, 34, 43, 44, 42);
    tiles[15].addVertex(34, 33, 37, 45, 46, 44);
    tiles[16].addVertex(39, 40, 41, 49, 47, 48);
    tiles[17].addVertex(41, 42, 43, 51, 50, 49);
    tiles[18].addVertex(43, 44, 45, 53, 52, 51);

    // connect the ver to the vertices
    vertices[0].addEdges(1,6);
    vertices[1].addEdges(1,2,11);
    vertices[2].addEdges(2,3,10);
    vertices[3].addEdges(3,4,17);
    vertices[4].addEdges(4,5,21);
    vertices[5].addEdges(5,6);
    vertices[6].addEdges(11,7);
    vertices[7].addEdges(7,8,16);
    vertices[8].addEdges(8,9,15);
    vertices[9].addEdges(10,9,22);
    vertices[10].addEdges(16,12);
    vertices[11].addEdges(12,13);
    vertices[12].addEdges(13,14,28);
    vertices[13].addEdges(14,15,25);
    vertices[14].addEdges(17,18,24);
    vertices[15].addEdges(18,19,32);
    vertices[16].addEdges(19,20,36);
    vertices[17].addEdges(21,20);
    vertices[18].addEdges(22,23,27);
    vertices[19].addEdges(23,24,37);
    vertices[20].addEdges(25,26,31);
    vertices[21].addEdges(26,27,40);
    vertices[22].addEdges(28,29);
    vertices[23].addEdges(29,30,46);
    vertices[24].addEdges(30,31,43);
    vertices[25].addEdges(32,33,39);
    vertices[26].addEdges(33,34,53);
    vertices[27].addEdges(34,35);
    vertices[28].addEdges(35,36);
    vertices[29].addEdges(37,38,42);
    vertices[30].addEdges(38,39,50);
    vertices[31].addEdges(40,41,45);
    vertices[32].addEdges(41,42,54);
    vertices[33].addEdges(43,44,49);
    vertices[34].addEdges(44,45,57);
    vertices[35].addEdges(46,47);
    vertices[36].addEdges(47,48);
    vertices[37].addEdges(48,49,60);
    vertices[38].addEdges(53,52);
    vertices[39].addEdges(51,52,66);
    vertices[40].addEdges(50,51,56);
    vertices[41].addEdges(55,56,63);
    vertices[42].addEdges(54,55,59);
    vertices[43].addEdges(58,59,67);
    vertices[44].addEdges(57,58,62);
    vertices[45].addEdges(61,62,70);
    vertices[46].addEdges(60,61);
    vertices[47].addEdges(65,66);    
    vertices[48].addEdges(64,65);
    vertices[49].addEdges(63,64,69);
    vertices[50].addEdges(68,69);
    vertices[51].addEdges(67,68,72);
    vertices[52].addEdges(71,72);
    vertices[53].addEdges(70,71);

    // connect the edges to the vertices
    edges[0].addVertices(0,1);
    edges[1].addVertices(1,2);
    edges[2].addVertices(2,3);
    edges[3].addVertices(3,4);
    edges[4].addVertices(4,5);
    edges[5].addVertices(5,0);
    edges[6].addVertices(6,7);
    edges[7].addVertices(7,8);
    edges[8].addVertices(8,9);
    edges[9].addVertices(9,2);
    edges[10].addVertices(1,6);
    edges[11].addVertices(10,11);
    edges[12].addVertices(11,12);
    edges[13].addVertices(12,13);
    edges[14].addVertices(13,8);
    edges[15].addVertices(7,10);
    edges[16].addVertices(3,14);
    edges[17].addVertices(14,15);
    edges[18].addVertices(15,16);
    edges[19].addVertices(16,17);
    edges[20].addVertices(17,4);
    edges[21].addVertices(9,18);
    edges[22].addVertices(18,19);
    edges[23].addVertices(19,14);
    edges[24].addVertices(13,20);
    edges[25].addVertices(20,21);
    edges[26].addVertices(21,18);
    edges[27].addVertices(12,22);
    edges[28].addVertices(22,23);
    edges[29].addVertices(23,24);
    edges[30].addVertices(24,20);
    edges[31].addVertices(15,25);
    edges[32].addVertices(25,26);
    edges[33].addVertices(26,27);
    edges[34].addVertices(27,28);
    edges[35].addVertices(28,16);
    edges[36].addVertices(19,29);
    edges[37].addVertices(29,30);
    edges[38].addVertices(30,25);
    edges[39].addVertices(21,31);
    edges[40].addVertices(31,32);
    edges[41].addVertices(32,29);
    edges[42].addVertices(24,33);
    edges[43].addVertices(33,34);
    edges[44].addVertices(34,31);
    edges[45].addVertices(23,35);
    edges[46].addVertices(35,36);
    edges[47].addVertices(36,37);
    edges[48].addVertices(37,33);
    edges[49].addVertices(30,40);
    edges[50].addVertices(40,39);
    edges[51].addVertices(38,39);
    edges[52].addVertices(26,38);
    edges[53].addVertices(32,42);
    edges[54].addVertices(42,41);
    edges[55].addVertices(40,41);
    edges[56].addVertices(34,44);
    edges[57].addVertices(44,43);
    edges[58].addVertices(43,42);
    edges[59].addVertices(37,46);
    edges[60].addVertices(46,45);
    edges[61].addVertices(45,44);
    edges[62].addVertices(41,49);
    edges[63].addVertices(49,48);
    edges[64].addVertices(48,47);
    edges[65].addVertices(47,39);
    edges[66].addVertices(43,51);
    edges[67].addVertices(51,50);
    edges[68].addVertices(50,49);
    edges[69].addVertices(45,53);
    edges[70].addVertices(53,52);
    edges[71].addVertices(52,51);


    // first turn is for player 1
    playerTurn = 1;
    positionOfRobber = 10;

}

void Board::buildRoad(int edge, Player &player)
{
    edges[edge - 1].setOwner(player.getId());
    player.addAssets("road");
    cout << "Road built at edge: " << edge << endl;
    
}

void Board::buildSettlement(int vertex, Player &player)
{
    vertices[vertex].setOwner(player.getId());
    vertices[vertex].setBuilding(SETTLEMENT);
    player.addAssets("settlement");
    cout << "Settlement built at vertex: " << vertex << endl;
}

void Board::buildCity(int vertex, Player &player)
{
    vertices[vertex].setBuilding(CITY);
    player.addAssets("city");
    cout << "City built at vertex: " << vertex << endl;
}

void Board::shareResources(size_t dice)
{
    cout << "Sharing resources: " << endl;
    string res[] = {"Wood", "Brick", "Wheat", "Sheep", "Iron"};
    bool share = false;
    for (Tile& tile : getTiles())
    {
        if (tile.getNumber() == dice && getRobber() != tile.getId())
        {
            if (getRobber() == tile.getId()) continue;
            for (int vertex : tile.getVertices())
            {
                Vertex& current_vertex = vertices[vertex];
                if (current_vertex.getBuilding() == SETTLEMENT)
                {
                    Player& player = getPlayer(current_vertex.getOwner());
                    player.addResource(tile.getResource(), 1);
                    cout << "\tPlayer " << player.getName() << " got 1 " << res[tile.getResource()] << endl;
                    share = true;
                }
                else if (current_vertex.getBuilding() == CITY)
                {
                    Player& player = getPlayer(current_vertex.getOwner());
                    player.addResource(tile.getResource(), 2);
                    cout << "\tPlayer " << player.getName() << " got 2 " << res[tile.getResource()] << endl;
                    share = true;
                }
            }
        }
    }
    if (!share)
    {
        cout << "No settlements or cities on the tiles with number " << dice << endl;
    }
}

int Board::getPlayerTurn() const
{
    return playerTurn;
}

void Board::nextTurn()
{
    chechVictoryPoints();
    if (playerTurn == 1)
    {
        playerTurn = 2;
        getPlayer(2).setAlreadyRolled(false);
    }
    else if (playerTurn == 2)
    {
        playerTurn = 3;
        getPlayer(3).setAlreadyRolled(false);
    }
    else
    {
        playerTurn = 1;
        getPlayer(1).setAlreadyRolled(false);
    }
}

void Board::reduceHalfResourcesFromPlayers()
{
    cout << "Reducing half resources from players who has more than 7 resources" << endl;
    for (int i = 1; i <= 3; i++)
    {
        Player player = getPlayer(i);
        player.setHalfResources();
    }
}

void Board::setRobber(int position)
{
    if (position < 1 || position > 19)
    {
        cout << "Invalid position tile for robber" << endl;
        return;
    }
    positionOfRobber = position;
    cout << "Robber moved to tile id: " << position << endl;
}

int Board::getRobber() const
{
    return positionOfRobber;
}

Edge& Board::getEdge(int id)
{
    return edges[id -1];
}

vector<Tile>& Board::getTiles()
{
    return tiles;
}

Vertex& Board::getVertex(int id)
{
    return vertices[id];
}

Player& Board::getPlayer(int id) {
    if (id == 1) {
        return p1;
    } else if (id == 2) {
        return p2;
    } else if (id == 3) {
        return p3;
    } else {
        std::cout << "Invalid player id" << std::endl;
        return p1; // or handle this case appropriately
    }
}

void Board::monopolyAction(size_t res, Player &player)
{
    cout << "Monopoly action: " << endl;
    string res_str[] = {"Wood", "Brick", "Wheat", "Sheep", "Iron"};
    for (int i = 1; i <= 3; i++)
    {
        Player& current_player = getPlayer(i);
        if (current_player.getId() == player.getId())
        {
            continue;
        }
        if (current_player.resources[static_cast<ResourceType>(res)] == 0)
        {
            continue;
        }
        current_player.addResource(static_cast<ResourceType>(res), -1);
        player.addResource(static_cast<ResourceType>(res), 1);
        cout << "\tPlayer " << player.getName() << " got 1 " << res_str[res] << " from player " << current_player.getName() << endl;
    }
}

void Board::chechVictoryPoints()
{
    for (int i = 1; i <= 3; i++)
    {
        Player& player = getPlayer(i);
        if (player.getVictoryPoints() >= 10)
        {
            cout << "Player " << player.getName() << " won the game" << endl;
            std::exit(0); // סיים את התוכנית
            return;
        }
    }
}

void Board::finishGame()
{
    std::exit(0);
}







