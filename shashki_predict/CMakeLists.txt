cmake_minimum_required(VERSION 3.20)
project(shahki_predict)

set(CMAKE_CXX_STANDARD 14)

add_executable(shahki_predict src/resourses/main.cpp src/resourses/Field.cpp src/headers/Field.h src/resourses/Figure.cpp src/headers/Figures.h src/resourses/Player.cpp src/headers/Player.h src/resourses/Cell.cpp src/headers/Cell.h src/resourses/King.cpp src/resourses/Queen.cpp src/resourses/Bishop.cpp src/resourses/Knight.cpp src/resourses/Rook.cpp src/resourses/Pawn.cpp)
