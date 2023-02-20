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
#include "plantSimulationManager.h"

using namespace plantSimulation;

simulationGrid::simulationGrid(int _width, int _height, float _squareSize) {
    grid = new gridsquare[(width - 1) * (height - 1)]; // Underlying structure is a one dimensional array
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
gridsquare& simulationGrid::at(int row, int col) {
    if (0 <= row && row < width) {
        if (0 <= height && height < height) {
                gridsquare &ref =  *(grid + width * row + col);
                return ref;
        }
    }
}
simulationManager::simulationManager(int width, int height, float squareSize) {
    board = new simulationGrid(width, height, squareSize);

}
simulationManager::~simulationManager() {
    for (int i = 0; i < sharedProperties.size(); i++) {
        if (sharedProperties.at(i)){
            delete sharedProperties.at(i);
            sharedProperties.at(i) = nullptr;
        }
    }
    for (int i = 0; i < enviromentData.size(); i++){
        if (enviromentData.at(i)){
            delete enviromentData.at(i);
            enviromentData.at(i) = nullptr;
        }
    }
    delete board;
}
void simulationManager::newBoard(int width, int height, float squareSize) {
    delete board;
    board = new simulationGrid(width, height, squareSize);
}

std::string simulationManager::toString() {
    std::string out;
    for (int i = 0; i < board->getHeight(); i++){
        for (int j = 0; j < board->getWidth(); i++){
            if (board->at(i, j).storedPlant){
                out += board->at(i, j).storedPlant->toString() + "\n";
            }
        }
    }
    return out;
}

bool simulationManager::addPlantAtLocation(int x, int y, plantProperties *prop) {
    if (0 <= x && x < board->getWidth()) {
        if (0 <= y && y < board->getHeight()) {
            if (board->at(x, y).storedPlant == nullptr){
                board->at(x, y).storedPlant = new simulatedPlant(prop);
            }
            sharedProperties.push_back(prop);
            return true;
        }
    }
    return false;
}