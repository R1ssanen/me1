cmake_minimum_required(VERSION 4.0)
project(ME1
	VERSION 2025.1.0
	LANGUAGES C
	DESCRIPTION "Move Evaluator 1"
)

add_library(me1 SHARED
	"src/me_engine.c"
	"src/me_piece.c"
	"src/me_bitboard.c"
)

set_target_properties(me1 PROPERTIES
	EXPORT_COMPILE_COMMANDS TRUE
	C_VISIBILITY_PRESET hidden
	C_STANDARD 99
	C_STANDARD_REQUIRED TRUE
	C_EXTENSIONS OFF
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
	set (OPTIMIZATIONS "-O3")
else()
	set (OPTIMIZATIONS "-g")
endif()

target_include_directories(me1 PUBLIC "include")
target_compile_options(me1 PUBLIC ${OPTIMIZATIONS} -Wall -Wextra -Wpedantic -march=native)

add_subdirectory("testing")
