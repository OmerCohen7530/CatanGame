// mail - omer7530@gmail.com
// Author - Omer Cohen

#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "board.hpp"
#include "player.hpp"

class Catan {
    private:
        Board board; // The game board
    public:
        // Constructor
        Catan(Player& p1, Player& p2, Player& p3);

        // Getters
        Board& getBoard();
};

#endif // CATAN_HPP
