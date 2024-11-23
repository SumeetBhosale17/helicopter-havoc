# Helicopter Havoc

Helicopter Havoc is an addictive 2D arcade game, inspired by Flappy Bird. Navigate your helicopter through endless obstacles, aiming for the highest score. With intuitive controls, vibrant graphics, and an engaging soundtrack, Helicopter Havoc offers an exhilarating gaming experience.

## Features
- Simple and intuitive controls
- Endless gameplay
- Score tracking
- Game over screen

## Requirements
- CMake 3.10 or higher
- SDL2
- SDL2_image
- SDL2_ttf

## Building the Project

### 1. Clone the repository:
First, clone the repository to your local machine:

```sh
    git clone <repository-url>
    cd helicopter-havoc
```

### 2. Create a build directory
Create a build directory and navigate into it

```sh
    mkdir build
    cd build
```

### 3. Configure the Project
Run CMake to generate build files for your project:

```sh
    cmake ..
```

### 4. Build the project
Build the project using CMake:
```sh
    cmake --build .
```

## Running the Game

After building the project, you can run the game executable from the build directory:
```sh
./HelicopterHavoc
```

## Usage
### Controls
- **Spacebar**: Make the helicopter jump
- **Escape**: Quit the game

## Contributing
Constributions are welcomed! Please follow these guides to contribute:

1.  Fork the repository.
2.  Create a new branch for your changes
(```git checkout -b feature/new-feature```)
3.  Make your changes
4. Commit your changes (```git commit -am 'Add new feature'```)
5. Push your changes to your fork (```git push origin feature-branch```)
6. Create a new Pull Request from your fork to the main repository.
