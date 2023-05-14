cmake_minimum_required(VERSION 3.24)
project(StrustProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(StrustProject main.cpp coordinate.h welcome.cpp showGameField.cpp Creature.h loadGame.cpp saveGame.cpp pauseScreen.cpp generateUniqueCoordinates.cpp updateCoordinates.cpp stateEnemy.cpp state_enemy.h)
