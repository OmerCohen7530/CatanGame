#include "doctest.h"
#include "catan.hpp"

using namespace std;

static bool flag = true;

// if actually settlement is placed on vertex 13
TEST_CASE("settlement is placed on vertex 13")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();

    // initialize settlments and roads for each player
    p1.initSettlements_Roads(2, 10, board);
    p1.initSettlements_Roads(25, 39, board);
    p2.initSettlements_Roads(13, 15, board);
    p2.initSettlements_Roads(42, 59, board);
    p3.initSettlements_Roads(44, 57, board);
    p3.initSettlements_Roads(40, 56, board);

    CHECK(board.getVertex(13).getBuilding() == SETTLEMENT);
    if (board.getVertex(13).getBuilding() != SETTLEMENT)
    {
        flag = false;
    }  
}

TEST_CASE("player 1 does not have sheeps")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();

    // initialize settlments and roads for each player
    p1.initSettlements_Roads(2, 10, board);
    p1.initSettlements_Roads(25, 39, board);
    p2.initSettlements_Roads(13, 15, board);
    p2.initSettlements_Roads(42, 59, board);
    p3.initSettlements_Roads(44, 57, board);
    p3.initSettlements_Roads(40, 56, board);

    board.setRobber(2);

    for (int i = 0; i < 5000; i++)
    {
        p1.rollDices(board);

        board.setRobber(2);

        p1.endTurn(board);

        board.setRobber(2);

        p2.rollDices(board);

        board.setRobber(2);

        p2.endTurn(board);

        board.setRobber(2);

        p3.rollDices(board);

        board.setRobber(2);

        p3.endTurn(board);
    }

    CHECK(p1.getResources(SHEEP) == 0);
    
    if (p1.getResources(SHEEP) != 0)
    {
        flag = false;
    }  
}

TEST_CASE("points from DevCards")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();

    // initialize settlments and roads for each player
    p1.initSettlements_Roads(2, 10, board);
    p1.initSettlements_Roads(25, 39, board);
    p2.initSettlements_Roads(13, 15, board);
    p2.initSettlements_Roads(42, 59, board);
    p3.initSettlements_Roads(44, 57, board);
    p3.initSettlements_Roads(40, 56, board);

    for (int i = 0; i < 5000; i++)
    {
        p1.rollDices(board);
        p1.endTurn(board);

        p2.rollDices(board);
        p2.endTurn(board);

        p3.rollDices(board);
        p3.endTurn(board);
    }

    for(int i = 0; i < 100; i++)
        p1.buyDevCard(board);
    
    p1.useDevCard("Knight", board);
    p1.useDevCard("Knight", board);
    p1.useDevCard("Knight", board);

    CHECK(p1.getVictoryPoints() == 8);
    
    if (p1.getVictoryPoints() != 8)
    {
        flag = false;
    }  
}

TEST_CASE("year of plenty")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();

    // initialize settlements and roads for each player
    p1.initSettlements_Roads(2, 10, board);
    p1.initSettlements_Roads(25, 39, board);
    p2.initSettlements_Roads(13, 15, board);
    p2.initSettlements_Roads(42, 59, board);
    p3.initSettlements_Roads(44, 57, board);
    p3.initSettlements_Roads(40, 56, board);

    for (int i = 0; i < 3000; i++)
    {
        p1.rollDices(board);
        p1.endTurn(board);

        p2.rollDices(board);
        p2.endTurn(board);

        p3.rollDices(board);
        p3.endTurn(board);
    }

    for(int i = 0; i < 100; i++)
        p1.buyDevCard(board);

    // zero resources    
    p1.addResource(WOOD, -p1.getResources(WOOD));
    p1.addResource(BRICK, -p1.getResources(BRICK));
    p1.addResource(IRON, -p1.getResources(IRON));
    p1.addResource(WHEAT, -p1.getResources(WHEAT));
    p1.addResource(SHEEP, -p1.getResources(SHEEP));

    p1.useDevCard("Year of Plenty", board);
    

    CHECK(p1.countResources() >= 2);
    
    if (p1.countResources() < 2)
    {
        flag = false;
    } 
}

TEST_CASE("Road Building")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();

    // initialize settlements and roads for each player
    p1.initSettlements_Roads(2, 10, board);
    p1.initSettlements_Roads(25, 39, board);
    p2.initSettlements_Roads(13, 15, board);
    p2.initSettlements_Roads(42, 59, board);
    p3.initSettlements_Roads(44, 57, board);
    p3.initSettlements_Roads(40, 56, board);

    for (int i = 0; i < 3000; i++)
    {
        p1.rollDices(board);
        p1.endTurn(board);

        p2.rollDices(board);
        p2.endTurn(board);

        p3.rollDices(board);
        p3.endTurn(board);
    }

    for(int i = 0; i < 100; i++)
        p1.buyDevCard(board);
        
    // zero resources
    p1.addResource(WOOD, -p1.getResources(WOOD));
    p1.addResource(BRICK, -p1.getResources(BRICK));
    p1.addResource(IRON, -p1.getResources(IRON));
    p1.addResource(WHEAT, -p1.getResources(WHEAT));
    p1.addResource(SHEEP, -p1.getResources(SHEEP));

    p1.useDevCard("Road Building", board);
    
    // two more roads should be built
    CHECK(p1.roads == 4);
    
    if (p1.roads != 4)
    {
        flag = false;
    } 
}

TEST_CASE("Add resource")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);

    p1.addResource(WOOD, 1);
    CHECK(p1.getResources(WOOD) == 1);
    if (p1.getResources(WOOD) != 1)
    {
        flag = false;
    }

}

TEST_CASE("add assets")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    
    p1.addAssets("road");
    CHECK(p1.roads == 1);
    
    if (p1.roads != 1)
    {
        flag = false;
    }
}

TEST_CASE("next turn")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();
    
    CHECK(board.getPlayerTurn() == 1);
    if (board.getPlayerTurn() != 1)
    {
        flag = false;
    }

    board.nextTurn();

    CHECK(board.getPlayerTurn() == 2);
    if (board.getPlayerTurn() != 2)
    {
        flag = false;
    }

    board.nextTurn();

    CHECK(board.getPlayerTurn() == 3);
    if (board.getPlayerTurn() != 3)
    {
        flag = false;
    }

    board.nextTurn();

    CHECK(board.getPlayerTurn() == 1);
    if (board.getPlayerTurn() != 1)
    {
        flag = false;
    }
}

TEST_CASE("build invalid settlement (adjacent to another city)")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();
    // initialize settlements and roads for each player
    p1.initSettlements_Roads(2, 10, board);
    p1.initSettlements_Roads(25, 39, board);
    p2.initSettlements_Roads(13, 15, board);
    p2.initSettlements_Roads(42, 59, board);
    p3.initSettlements_Roads(44, 57, board);
    p3.initSettlements_Roads(40, 56, board);
    
    // add resources to player
    p1.addResource(WOOD, 2);
    p1.addResource(BRICK, 2);
    p1.addResource(IRON, 1);
    p1.addResource(WHEAT, 1);
    p1.addResource(SHEEP, 1);
    // Build a settlement adjacent to another city
    p1.placeRoad(4, board);
    p1.placeSettlement(3, board);
    
    CHECK(board.getVertex(3).getBuilding() == NO_BUILDING);
    
    if (board.getVertex(3).getBuilding() != NO_BUILDING)
    {
        flag = false;
    }
}

TEST_CASE("check player address")
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();

    CHECK(&p1 == &board.getPlayer(1));
    CHECK(&p2 == &board.getPlayer(2));
    CHECK(&p3 == &board.getPlayer(3));

    if (&p1 != &board.getPlayer(1) || &p2 != &board.getPlayer(2) || &p3 != &board.getPlayer(3))
    {
        flag = false;
    }
}



TEST_CASE("print tests results"){
    cout << "-----------------------------------------" << endl;
    if (flag)
    {
        cout << "All tests passed successfully!" << endl;
    }
    else
    {
        cout << "Some tests failed!" << endl;
    }
}

