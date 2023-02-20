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
#include <vector>
#include <string>

namespace plantSimulation {

typedef struct {
    float shade;
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
        simulationGrid(int _width, int _height, float _squareSize);
        ~simulationGrid();

        int getWidth() {return width;}
        int getHeight() {return height;}
        int getSquareSize() {return squareSize;}
        gridsquare &at(int row, int col);
};

class simulationManager {
    private:
        int time = 0; //The current time in months
        simulationGrid *board;
        std::vector<envProperties*> enviromentData;
        std::vector<plantProperties*> sharedProperties;

    public:
        simulationManager(int width, int height, float squareSize);
        ~simulationManager();

        void stepSimulation();
        void runSimulation(int iterations);
        bool addPlantAtLocation(int x, int y, plantProperties *prop);
        void resetSimulation();
        void newBoard(int width, int height, float squareSize);

        std::string toString();
};
}; // plantSimulation namespace
#endif /* plantsimulation_h */