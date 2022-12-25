cmake_minimum_required(VERSION 3.0.0)
project(wordsearch VERSION 0.1.0)

set(CFLAGS Wall)

add_library(menu menu.c  menu.h )
add_library(timer timer.c  timer.h )
add_library(puzzle puzzle.c  puzzle.h )

add_executable(wordsearch main.c)

target_link_libraries(wordsearch PRIVATE menu)
target_link_libraries(wordsearch PRIVATE timer)
target_link_libraries(wordsearch PRIVATE puzzle)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

#game_logic.c word_bank.c puzzle_generator.c