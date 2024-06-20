#include "catan.hpp"
#include <iostream>
#include <cstdlib> // std::srand, std::rand
#include <ctime>   // std::time

Catan::Catan(Player& p1, Player& p2, Player& p3) : board(p1, p2, p3)
{
    cout << "Catan game started" << endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // אתחול מחולל המספרים האקראיים עם הזמן הנוכחי
}

Board& Catan::getBoard()
{
    return board;
}
