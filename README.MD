# liTech
![Logo](Assets/Logos/SquareInverted.png)
![liTechLogo](Assets/Logos/liTech.png)

## About

## Building
***Building this project requires a Windows system and CMake.***
1. Generate the project files
```sh
cmake -B build -S .
```

2. Build the project

> The config can be changed with the desired configuration, and the '-j' argument can be changed or removed if you want multithreaded compilation.
```sh
cmake --build build --config Debug -j 4
```

## Running
Run the compiled project through your favorite IDE or directly from Debug/Release folder in the build directory.