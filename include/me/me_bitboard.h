/**
 * @file me_bitboard.h
 * @author R1ssanen
 * @brief Bitboard utils.
 * @see http://www.github.com/R1ssanen/me1.git
 */

#ifndef ME_BITBOARD_H_
#define ME_BITBOARD_H_

#include <stddef.h>
#include <stdint.h>

#include "me/me_result.h"

#define ME_SET_BIT(n)          (uint64_t)(1ull << n)
#define ME_IS_SET(mask, n)     (ME_SET_BIT(n) & mask)
#define ME_COMPOSE(rank, file) (int)(rank * 8 + file)
#define ME_MASK(rank, file)    ME_SET_BIT(ME_COMPOSE(rank, file));

#define ME_DECOMPOSE(square, rank, file)                                                           \
    do {                                                                                           \
        rank = (square / 8) + 1;                                                                   \
        file = (square % 8) + 1;                                                                   \
    } while (0);

// clang-format off
enum {
    ME_A1, ME_B1, ME_C1, ME_D1, ME_E1, ME_F1, ME_G1, ME_H1,
    ME_A2, ME_B2, ME_C2, ME_D2, ME_E2, ME_F2, ME_G2, ME_H2,
    ME_A3, ME_B3, ME_C3, ME_D3, ME_E3, ME_F3, ME_G3, ME_H3,
    ME_A4, ME_B4, ME_C4, ME_D4, ME_E4, ME_F4, ME_G4, ME_H4,
    ME_A5, ME_B5, ME_C5, ME_D5, ME_E5, ME_F5, ME_G5, ME_H5,
    ME_A6, ME_B6, ME_C6, ME_D6, ME_E6, ME_F6, ME_G6, ME_H6,
    ME_A7, ME_B7, ME_C7, ME_D7, ME_E7, ME_F7, ME_G7, ME_H7,
    ME_A8, ME_B8, ME_C8, ME_D8, ME_E8, ME_F8, ME_G8, ME_H8
};

// clang-format on

typedef struct ME_Bitboard {
    uint64_t all; // combined board
    uint64_t pawn;
    uint64_t rook;
    uint64_t knight;
    uint64_t bishop;
    uint64_t queen;
    uint64_t king;
} ME_Bitboard;

ME_Result
     me_parse_pieces_fen(const char* fen_str, ME_Bitboard* white, ME_Bitboard* black, size_t* end);

void me_debug_bitboard(const char* label, int side, ME_Bitboard board);

#endif
