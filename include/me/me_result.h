/**
 * @file me_error.h
 * @author R1ssanen
 * @brief Result type and helpers.
 * @see http://www.github.com/R1ssanen/me1.git
 */

#ifndef ME_RESULT_H_
#define ME_RESULT_H_

#include <stdbool.h>

typedef struct ME_Result {
    const char* msg;
    bool        ok;
} ME_Result;

#define ME_OK()                                                                                    \
    (ME_Result) { .msg = NULL, .ok = true }

#define ME_ERROR(err_msg)                                                                          \
    (ME_Result) { .msg = err_msg, .ok = false }

// NOTE: early-returns from function with error result
#define ME_REQUIRE_NON_NULL(ptr, err_msg)                                                          \
    do {                                                                                           \
        if ((ptr) == NULL) { return ME_ERROR(err_msg); }                                           \
    } while (0)

#define ME_PANIC(err_msg)                                                                          \
    do {                                                                                           \
        fprintf(stderr, "%s\n", err_msg);                                                          \
        abort();                                                                                   \
    } while (0)

#endif
