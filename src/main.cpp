#include "board.hpp"
#include <iostream>

int main()
{
    std::cout << "Chess engine starting...\n";
    Board board;

    board.print_board();

    return 0;
}
