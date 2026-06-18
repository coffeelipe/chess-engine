#include "common.hpp"

class Board
{
public:
    U64 w_pawns = 0x000000000000FF00ULL;
    U64 w_knights = 0x0000000000000042ULL;
    U64 w_bishops = 0x0000000000000024ULL;
    U64 w_rooks = 0x0000000000000081ULL;
    U64 w_queens = 0x0000000000000010ULL;
    U64 w_king = 0x0000000000000008ULL;

    U64 b_pawns = 0x00FF000000000000ULL;
    U64 b_knights = 0x4200000000000000ULL;
    U64 b_bishops = 0x2400000000000000ULL;
    U64 b_rooks = 0x8100000000000000ULL;
    U64 b_queens = 0x1000000000000000ULL;
    U64 b_king = 0x0800000000000000ULL;

    U64 all_white = w_pawns | w_knights | w_bishops | w_rooks | w_queens | w_king;
    U64 all_black = b_pawns | b_knights | b_bishops | b_rooks | b_queens | b_king;
    U64 all_occupied = all_white | all_black;
    U64 all_empty = ~all_occupied;

    void print_board();
};
