cmake_minimum_required(VERSION 3.20.0)

project(mcounter VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)



# compile options (warnings, ASan, UBSan)
if(MSVC)
    add_compile_options(/W4)
    add_compile_options($<$<CONFIG:Debug>:/fsanitize=address>)
else()
    add_compile_options(-Wpedantic -Wall -Wextra -Werror)
    add_compile_options($<$<CONFIG:Debug>:-fsanitize=address> $<$<CONFIG:Debug>:-fsanitize=undefined>)
    add_link_options($<$<CONFIG:Debug>:-fsanitize=address> $<$<CONFIG:Debug>:-fsanitize=undefined>)
endif()



# MCounter library (procedural)
add_library(mcounter STATIC src/mcounter.c)
target_include_directories(mcounter PUBLIC include)

#MooCounter library (object-oriented)
add_library(moocounter STATIC src/moocounter.c)
target_include_directories(moocounter PUBLIC include)



# procedural demo
add_executable(demo src/demo.c)
target_link_libraries(demo PRIVATE mcounter)



# tests
enable_testing()
include(CTest)
add_subdirectory(lib/unity)

# procedural test
add_executable(test_mcounter tests/test_mcounter.c)
target_link_libraries(test_mcounter
    unity
    mcounter
)
add_test(TestMCounter test_mcounter)

# object-oriented test
add_executable(test_moocounter tests/test_moocounter.c)
target_link_libraries(test_moocounter
    unity
    moocounter
)
add_test(TestMooCounter test_moocounter)
