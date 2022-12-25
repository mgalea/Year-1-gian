cmake_minimum_required(VERSION 3.0.0)
project(wordsearch VERSION 0.1.0)

set(CFLAGS Wall)

file(GLOB worldsearch_SRC CONFIGURE_DEPENDS "*.h" "*.c")

add_executable(wordsearch ${worldsearch_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

#game_logic.c word_bank.c puzzle_generator.c