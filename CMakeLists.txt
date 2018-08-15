cmake_minimum_required(VERSION 3.10)
project(SDLTest)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL_IMAGE REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_executable(SDLTest mains/main10.cpp sources/functions10.cpp sources/LTexture.cpp)

target_link_libraries(SDLTest ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)
