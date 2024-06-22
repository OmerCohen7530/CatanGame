// mail - omer7530@gmail.com
// Author - Omer Cohen

#include "catan.hpp"
#include <iostream>
#include "board.hpp"
using namespace std;


int main() 
{
    Player p1(1, "Amit"); // red
    Player p2(2, "Yossi"); // yellow
    Player p3(3, "Dana"); // blue
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();
    
    cout << "-----------------------------------------" << endl;

    // initialize settlments and roads for each player
    p1.initSettlements_Roads(2, 10, board);
    p1.initSettlements_Roads(25, 39, board);
    p2.initSettlements_Roads(13, 15, board);
    p2.initSettlements_Roads(42, 59, board);
    p3.initSettlements_Roads(44, 57, board);
    p3.initSettlements_Roads(40, 56, board);

    cout << "-----------------------------------------" << endl;

    if(board.getVertex(13).getBuilding() == SETTLEMENT)
    {
        cout << "Vertex 13 has a settlement" << endl;
    }
    else
    {
        cout << "Vertex 13 has no settlement" << endl;
    }

    cout << "-----------------------------------------" << endl;
    
    
    for (int i = 0; i < 100; i++)
    {
        p1.rollDices(board);
        p1.endTurn(board);

        p2.rollDices(board);
        p2.endTurn(board);

        p3.rollDices(board);
        p3.endTurn(board);
    }
    
    cout << "-----------------------------------------" << endl;
    
    p1.placeRoad(5, board);
    p1.placeSettlement(4, board);
    p1.endTurn(board);

    p2.rollDices(board);
    p2.placeRoad(26, board);
    p2.placeSettlement(21, board);
    p2.endTurn(board);

    p3.rollDices(board);
    p3.tradeFromto(SHEEP, WOOD, board);
    p3.endTurn(board);

    cout << "-----------------------------------------" << endl;

    p1.buyDevCard(board);
    p1.useDevCard("Road Building", board);
    p1.useDevCard("Knight", board);
    p1.useDevCard("Year of Plenty", board);
    p1.useDevCard("Monopoly", board);
    p1.endTurn(board);

    cout << "-----------------------------------------" << endl;
    p1.status();
    p2.status();
    p3.status();
    
    // This program will close the game arbitrarily regardless of the game progress
    board.finishGame();
}
