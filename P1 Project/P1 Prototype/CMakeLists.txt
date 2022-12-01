cmake_minimum_required(VERSION 3.23)
project(P1_Prototype C)

set(CMAKE_C_STANDARD 99)

add_executable(Emils "Emils Prototype/main.c" "Emils Prototype/menu.c" "Emils Prototype/menu.h" "Emils Prototype/settings.c" "Emils Prototype/settings.h" "Emils Prototype/utilities.h" "Emils Prototype/utilities.c" "Emils Prototype/memory.c" "Emils Prototype/memory.h")
add_executable(Mathias "Mathiases Prototype/main.c" "Mathiases Prototype/main.h" "Mathiases Prototype/file_management.c" "Mathiases Prototype/file_management.h" "Mathiases Prototype/distance.c" "Mathiases Prototype/distance.h" "Mathiases Prototype/run_time.c" "Mathiases Prototype/run_time.h")
add_executable(Mathias2 "Mathiases Prototype2/main.c" "Mathiases Prototype2/main.h" "Mathiases Prototype2/file_management.c" "Mathiases Prototype2/file_management.h" "Mathiases Prototype2/distance.c" "Mathiases Prototype2/distance.h" "Mathiases Prototype2/run_time.c" "Mathiases Prototype2/run_time.h")


file(COPY "Emils Prototype/Databases/" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Lists/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Lists2/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})