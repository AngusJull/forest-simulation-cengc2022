/**
 * @file plantsimulation.cpp
 * @author Angus Jull
 * @brief Methods related to running simulation of plants
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "plantsimulation.h"

using namespace plantSimulation;

simulationGrid::simulationGrid(int _width, int _height, float _squareSize) {
    grid = new gridsquare[width * height]; // Underlying structure is a one dimensional array
    squareSize = _squareSize;
    width = _width;
    height = _height;
}
simulationGrid::~simulationGrid() {
    for (int i = 0; i < width * height; i++){
        delete grid[i].storedPlant;
    }
    delete[] grid;
}

simulationManager::simulationManager(int width, int height, float squareSize) {
    board = new simulationGrid(width, height, squareSize);

}
simulationManager::~simulationManager() {
    delete board;
}
void simulationManager::newBoard(int width, int height, float squareSize) {
    delete board;
    board = new simulationGrid(width, height, squareSize);
}

