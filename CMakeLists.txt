cmake_minimum_required(VERSION 3.9)
project(FlappyBirds)

set(CMAKE_CXX_STANDARD 11)

add_executable(FlappyBirds main.cpp DEFINITIONS.h State.h StateMachine.cpp StateMachine.h AssetManager.cpp AssetManager.h InputManager.cpp InputManager.h Game.cpp Game.h IntroState.cpp IntroState.h MainMenuState.cpp MainMenuState.h GameState.cpp GameState.h GameOverState.cpp GameOverState.h Pipe.cpp Pipe.h Ground.cpp Ground.h Bird.cpp Bird.h Collision.cpp Collision.h HeadupDisplay.cpp HeadupDisplay.h)
# Detect and add SFML
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(FlappyBirds ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()