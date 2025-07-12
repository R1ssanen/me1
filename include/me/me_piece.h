
#ifndef ME_PIECE_H_
#define ME_PIECE_H_

enum { ME_WHITE, ME_BLACK };

enum me_piece {
    ME_PAWN   = 1,
    ME_KNIGHT = 3,
    ME_BISHOP = 4,
    ME_ROOK   = 5,
    ME_QUEEN  = 9,
    ME_KING   = 256,
};

char me_get_piece_character(enum me_piece piece, int side);

#endif
