#include "plantsimulation.h"

simulationManager::simulationManager(int width, int height, float gridsquareWidth){
    createBoard(width, height, gridsquareWidth);
}
simulationManager::~simulationManager(){
    destroyTrees();
    destroyBoard();
}

void simulationManager::createBoard(int width, int height, float gridsquareWidth){
    board.grid = new gridsquare[height][width];
    
    board.height = height;
    board.width = width;
    board.squareSize = gridsquareWidth;
}


