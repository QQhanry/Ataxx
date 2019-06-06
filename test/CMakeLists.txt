cmake_minimum_required(VERSION 3.7.2)
project(tp4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

#file (GLOB_RECURSE CIR2_sceneview_src src/*.cpp src/*.h)

add_executable(tp4 src/main.cpp src/Parametres.cpp src/Parametres.h src/MainScene.cpp src/MainScene.h src/game.cpp src/game.h src/plateau.cpp src/plateau.h src/pion.cpp src/pion.h src/pion.cpp src/pion.h src/game.cpp src/game.h src/plateau.cpp src/plateau.h src/AffichageJeu.cpp src/AffichageJeu.h src/ChooseName.cpp src/ChooseName.h)


target_link_libraries(tp4 Qt5::Widgets)
