cmake_minimum_required(VERSION 3.15)
project(UntitledCarGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(UntitledCarGame src/main.cpp src/Screen.cpp src/Screen.h src/entities/Entity.cpp src/entities/Entity.h src/entities/TestEntity.cpp src/entities/TestEntity.h src/entities/PlayerEntity.cpp src/entities/PlayerEntity.h src/Controls.cpp src/Controls.h src/globals.h src/entities/NpcEntity.cpp src/entities/NpcEntity.h src/EntityManager.cpp src/EntityManager.h src/LevelManager.cpp src/LevelManager.h src/spawners/Spawner.cpp src/spawners/Spawner.h src/spawners/CarSpawner.cpp src/spawners/CarSpawner.h src/entities/CarEntity.cpp src/entities/CarEntity.h)