cmake_minimum_required(VERSION 3.16)
project(PBL2 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable(PBL2 ${SRC})

find_package(SDL2 CONFIG REQUIRED)
# quan trọng: SDL2main trước, SDL2 sau
target_link_libraries(PBL2 PRIVATE SDL2::SDL2main SDL2::SDL2)
