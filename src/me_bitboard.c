#include "me/me_bitboard.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "me/me_piece.h"
#include "me/me_result.h"

ME_Result
me_parse_pieces_fen(const char* fen_str, ME_Bitboard* white, ME_Bitboard* black, size_t* end) {
    ME_REQUIRE_NON_NULL(fen_str, "me_parse_pieces_fen: FEN-string argument null.");
    ME_REQUIRE_NON_NULL(white, "me_parse_pieces_fen: white bitboard argument null.");
    ME_REQUIRE_NON_NULL(black, "me_parse_pieces_fen: black bitboard argument null.");

    memset(white, 0, sizeof(ME_Bitboard));
    memset(black, 0, sizeof(ME_Bitboard));

    int square = ME_A1;
    for (size_t i = 0; i < strlen(fen_str); ++i) {

        char c = fen_str[i];
        if (isdigit(c)) {
            square += (int)(c) - '0';
            continue;
        }

        ME_Bitboard* board = isupper(c) ? white : black;
        uint64_t     mask  = ME_SET_BIT(square);

        switch (tolower(c)) {
        case ' ':
            if (end) *end = i;
            return ME_OK();

        case 'p': board->pawn |= mask; break;
        case 'r': board->rook |= mask; break;
        case 'n': board->knight |= mask; break;
        case 'b': board->bishop |= mask; break;
        case 'q': board->queen |= mask; break;
        case 'k': board->king |= mask; break;
        default: continue;
        }

        board->all |= mask;
        square += 1;
    }

    return ME_ERROR("me_parse_pieces_fen: invalid FEN-string.");
}

static void print_board(const char* label, char c, uint64_t board) {
    printf("%s:\n", label);

    for (size_t rank = 0; rank < 8; ++rank) {
        for (size_t file = 0; file < 8; ++file) {
            int square = ME_COMPOSE(rank, file);
            printf("%c ", ME_IS_SET(board, square) ? c : '_');
        }
        putchar('\n');
    }
    putchar('\n');
}

void me_debug_bitboard(const char* label, int side, ME_Bitboard board) {
    bool is_white = (side == ME_WHITE);

    printf("%s:\n", label);
    print_board("all", is_white ? 'W' : 'B', board.all);
    print_board("pawns", is_white ? 'P' : 'p', board.pawn);
    print_board("rooks", is_white ? 'R' : 'r', board.rook);
    print_board("knights", is_white ? 'N' : 'n', board.knight);
    print_board("bishops", is_white ? 'B' : 'b', board.bishop);
    print_board("queen", is_white ? 'Q' : 'q', board.queen);
    print_board("king", is_white ? 'K' : 'k', board.king);
}
