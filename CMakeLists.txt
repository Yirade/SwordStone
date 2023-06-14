cmake_minimum_required(VERSION 3.21)
project(game LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

FILE(GLOB SRCFILES source/*.cpp source/scenes/*.cpp source/scenes/utils/*.cpp)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

ADD_EXECUTABLE(game ${SRCFILES})

target_link_libraries(game PRIVATE sfml-graphics sfml-audio sfml-window sfml-system)
target_compile_features(game PRIVATE cxx_std_17)

install(TARGETS game)