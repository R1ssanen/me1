#include "me/me_piece.h"

#include <ctype.h>

char me_get_piece_character(enum me_piece piece, int side) {
    char p = 0;

    switch (piece) {
    case ME_PAWN: p = 'p'; break;
    case ME_ROOK: p = 'r'; break;
    case ME_KNIGHT: p = 'n'; break;
    case ME_BISHOP: p = 'b'; break;
    case ME_QUEEN: p = 'q'; break;
    case ME_KING: p = 'k'; break;
    default: return p;
    }

    return (side == ME_WHITE) ? p : toupper(p);
}
