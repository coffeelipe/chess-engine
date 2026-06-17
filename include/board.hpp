#include "bitwise_helpers.hpp"

#include <cstdint>
#include <iostream>
using namespace std;

typedef uint64_t U64;

class Board
{
    char files[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char ranks[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};

public:
    Board()
    {
        init();
    };

    void print()
    {
        for (int rank = 7; rank >= 0; rank--)
        {
            for (int file = 0; file < 8; file++)
            {
                int square_index = rank * 8 + file;
                char piece = '.';

                if (w_pawns & (1ULL << square_index))
                    piece = 'P';
                else if (w_knights & (1ULL << square_index))
                    piece = 'N';
                else if (w_bishops & (1ULL << square_index))
                    piece = 'B';
                else if (w_rooks & (1ULL << square_index))
                    piece = 'R';
                else if (w_queens & (1ULL << square_index))
                    piece = 'Q';
                else if (w_king & (1ULL << square_index))
                    piece = 'K';
                else if (b_pawns & (1ULL << square_index))
                    piece = 'p';
                else if (b_knights & (1ULL << square_index))
                    piece = 'n';
                else if (b_bishops & (1ULL << square_index))
                    piece = 'b';
                else if (b_rooks & (1ULL << square_index))
                    piece = 'r';
                else if (b_queens & (1ULL << square_index))
                    piece = 'q';
                else if (b_king & (1ULL << square_index))
                    piece = 'k';

                cout << piece << " ";
            }
            cout << endl;
        }
    };

private:
    U64 w_pawns;
    U64 w_knights;
    U64 w_bishops;
    U64 w_rooks;
    U64 w_queens;
    U64 w_king;

    U64 b_pawns;
    U64 b_knights;
    U64 b_bishops;
    U64 b_rooks;
    U64 b_queens;
    U64 b_king;

    U64 all_white = w_pawns | w_knights | w_bishops | w_rooks | w_queens | w_king;
    U64 all_black = b_pawns | b_knights | b_bishops | b_rooks | b_queens | b_king;
    U64 all_occupied = all_white | all_black;
    U64 all_empty = ~all_occupied;
    
    void init()
    {
        /*
            00000000
            00000000
            00000000
            00000000
            00000000
            00000000
            00000000
            00000000
        */
        w_pawns = 0x000000000000FF00ULL;
        w_knights = 0x0000000000000042ULL;
        w_bishops = 0x0000000000000024ULL;
        w_rooks = 0x0000000000000081ULL;
        w_queens = 0x0000000000000008ULL;
        w_king = 0x0000000000000010ULL;

        b_pawns = 0x00FF000000000000ULL;
        b_knights = 0x4200000000000000ULL;
        b_bishops = 0x2400000000000000ULL;
        b_rooks = 0x8100000000000000ULL;
        b_queens = 0x0800000000000000ULL;
        b_king = 0x1000000000000000ULL;

        print();
    };
};
