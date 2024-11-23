cmake_minimum_required(VERSION 3.10)
project(HelicopterHavoc)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    src/Source/Background.cpp
    src/Source/GameLoop.cpp
    src/Source/Object.cpp
    src/Source/Obstacle.cpp
    src/Source/Player.cpp
    src/Source/TextureManager.cpp
    main.cpp
)

# Add the header files
set(HEADERS
    src/Headers/Background.h
    src/Headers/Constants.h
    src/Headers/GameLoop.h
    src/Headers/Object.h
    src/Headers/Obstacle.h
    src/Headers/Player.h
    src/Headers/TextureManager.h
)

# Include directories
include_directories(src/Headers)

# Find SDL2 and its components
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link the SDL2 libraries
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)