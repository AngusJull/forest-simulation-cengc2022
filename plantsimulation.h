#include "plant.h"

typedef struct {
    int x, y;
    simulatedPlant* storedPlant = NULL;
} gridsquare;

class simulationGrid {
    public: 
        int width;
        int height; 
        float squareSize;
        gridsquare *grid;
        inline gridsquare *get(int row, int col) {return grid + width * row + col;}
        void createGrid(int width, int height, float gridsquareSize);
        void deleteGrid() {delete[] grid;};
};

class simulationManager {
    private:
        int time = 0; //The current time in months
        simulationGrid board;
        envProp *enviromentData;
        int envDataSize;
        plantProp *sharedProperties;
        int sharedPropSize;


        void readPlantData(string filename);
        void destroyTrees();
        void destroyBoard();

    public:
        simulationManager(int width, int height, float gridSquareSize);
        ~simulationManager();

        void stepSimulation();
        void runSimulation(int iterations);
        void resetSimulation();
        void displayBoard();
};