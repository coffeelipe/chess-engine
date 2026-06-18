#include "common.hpp"
#include "board.hpp"

#include <iostream>

void Board::print_board()
{
    using std::cout;

    for (int rank = 7; rank >= 0; rank--)
    {
        for (int file = 7; file >= 0; file--)
        {
            unsigned int shift = rank * 8 + file;
            U64 square_mask = 0x0000000000000001ULL << shift;

            if (w_pawns & square_mask)
            {
                cout << "P ";
            }
            else if (w_knights & square_mask)
            {
                cout << "N ";
            }
            else if (w_bishops & square_mask)
            {
                cout << "B ";
            }
            else if (w_rooks & square_mask)
            {
                cout << "R ";
            }
            else if (w_queens & square_mask)
            {
                cout << "Q ";
            }
            else if (w_king & square_mask)
            {
                cout << "K ";
            }
            else if (b_pawns & square_mask)
            {
                cout << "p ";
            }
            else if (b_knights & square_mask)
            {
                cout << "n ";
            }
            else if (b_bishops & square_mask)
            {
                cout << "b ";
            }
            else if (b_rooks & square_mask)
            {
                cout << "r ";
            }
            else if (b_queens & square_mask)
            {
                cout << "q ";
            }
            else if (b_king & square_mask)
            {
                cout << "k ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}
