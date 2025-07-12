#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "me/me1.h"
#include "me/me_bitboard.h"
#include "me/me_piece.h"
#include "me/me_result.h"

struct ME_Engine {
    ME_Bitboard white;
    ME_Bitboard black;
};

// NOTE: must be freed manually by 'free'
ME_Engine* me_create_engine(void) {
    ME_Engine* engine = calloc(1, sizeof(ME_Engine));

    if (!engine) ME_PANIC("fatal error: system out of memory; cannot allocate engine state.");
    return engine;
}

ME_Result me_set_state(ME_Engine* engine, const char* fen_str) {
    ME_REQUIRE_NON_NULL(engine, "me_initialize_state: engine argument null.");
    ME_REQUIRE_NON_NULL(fen_str, "me_initialize_state: FEN-string argument null.");

    size_t    pieces_end = 0;
    ME_Result result = me_parse_pieces_fen(fen_str, &engine->white, &engine->black, &pieces_end);

    return result;
}

ME_Result me_debug_state(const ME_Engine* engine) {
    ME_REQUIRE_NON_NULL(engine, "me_debug_state: engine argument null.");
    me_debug_bitboard("white", ME_WHITE, engine->white);
    me_debug_bitboard("black", ME_BLACK, engine->black);
    return ME_OK();
}
