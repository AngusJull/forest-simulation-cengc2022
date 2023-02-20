/**
 * @file plantsimulation.h
 * @author Angus Jull
 * @brief Classes related to running a simulation with plants
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef plantsimulation_h
#define plantsimulation_h

#include "plant.h"

typedef struct {
    int x, y;
    simulatedPlant* storedPlant = NULL;
} gridsquare;

/**
 * @brief Class that stores plants in a gird, where each plant occupies a fixed size square area
 * 
 * New grid must be created to change its size
 */
class simulationGrid {
    private:
        int width;
        int height;
        float squareSize;
        gridsquare *grid;
    public: 
        inline gridsquare *get(int row, int col) {return grid + width * row + col;}
        simulationGrid(int _width, int _height, float _squareSize);
        ~simulationGrid(){delete[] grid;}
};

class simulationManager {
    private:
        int time = 0; //The current time in months
        simulationGrid *board;
        envProperties *enviromentData;
        plantProperties *sharedProperties;
        int envDataSize;
        int sharedPropSize;


        void readPlantData(string filename);
        void destroyTrees();
        void destroyBoard();

    public:
        simulationManager(int width, int height, float squareSize);
        ~simulationManager();

        void stepSimulation();
        void runSimulation(int iterations);
        void resetSimulation();
        void displayBoard();
};

#endif /* plantsimulation_h */