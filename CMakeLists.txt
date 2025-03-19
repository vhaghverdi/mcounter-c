cmake_minimum_required(VERSION 3.10.0)
project(mcounter VERSION 0.1.0 LANGUAGES C)

add_executable(moocounter
    src/main.c
    src/moocounter.c
)
target_include_directories(moocounter PRIVATE
    inc/moocounter.h
)

add_executable(basic_test
    _tests/basic_test.c
    src/mcounter.c
)
target_include_directories(basic_test PRIVATE inc)

add_executable(basic_moo_test
    _tests/basic_moo_test.c
    src/moocounter.c
)
target_include_directories(basic_moo_test PRIVATE inc)
