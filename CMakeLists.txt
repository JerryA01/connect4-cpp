cmake_minimum_required(VERSION 4.0)
project(Cversion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cversion
        main.cpp
        Piece.cpp
        HumanPlayer.cpp
        Board.cpp
        Game.cpp
)



target_include_directories(Cversion PRIVATE
        ${PROJECT_SOURCE_DIR}/external
)
