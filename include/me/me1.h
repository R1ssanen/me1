/**
 * @file me1.h
 * @author R1ssanen
 * @brief Main library header of libme1.
 * @see http://www.github.com/R1ssanen/me1.git
 */

#ifndef ME1_H_
#define ME1_H_

#include "me/me_result.h"

#if defined(__clang__) || defined(__GNUC__)
#    define MEAPI __attribute__((visibility("default")))
#else
#    error "Compiler not supported: Use GCC or Clang with C99."
#endif

typedef struct ME_Engine ME_Engine;

MEAPI ME_Engine*         me_create_engine(void);
MEAPI ME_Result          me_set_state(ME_Engine* engine, const char* fen_str);
MEAPI ME_Result          me_make_move(ME_Engine* engine, int from, int to);
MEAPI ME_Result          me_debug_state(const ME_Engine* engine);

#endif
