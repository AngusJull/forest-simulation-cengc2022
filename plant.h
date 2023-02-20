/**
 * @file plant.h
 * @author Angus Jull
 * @brief Classes and structures related to creating and simulating a plant
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef plant_h
#define plant_h

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//All properties about the enviroment at the plant's position that a plant needs to be given
class envProperties {
    public:
        float temp;
        float percip;
        float month;
        envProperties();
        ~envProperties();
};

class plantProperties {
    public:
        int modifiers = 0;
        int lifetime;

        float maxHeight;
        float growthRate;
        float shadeTolerance;
        float seedsProduced;
        float seedRadius;
        float seedTime;

        float idealTemp[2]; //First value is low, second is high
        float idealPercip[2]; //First value is low, second is high 

        plantProperties();
        ~plantProperties(){};
};

//inline float clamp(float x, float min, float max);

class simulatedPlant {
    private:
        static const float tempVulnerability; //How much to lower satisfaction by for every degree outside nominal
        static const float percipVulnerability; //How much to lower satisfaction by for every mm of rain per year outside nominal

        string name;
        float height = 0.01; //In meters
        int age = 1;
        plantProperties *properties; // Pointer to plant properties, needs to be created / destroyed outside the class

    public:
        virtual float calculateGrowth(float satisfaction); 
        virtual float calculateSatisfaction(const envProperties *weather);
        simulatedPlant(plantProperties *prop);
        simulatedPlant(string _name, float _height, plantProperties *prop);
        
        string getName(){return name;}
        float getHeight(){return height;}
        int getAge(){return age;}
        void reset();
        void simulateGrowth(const envProperties *weather);  
};

#endif /* plant_h */