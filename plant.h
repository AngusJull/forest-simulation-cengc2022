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

namespace plantSimulation {

//All properties about the enviroment at the plant's position that a plant needs to be given
class envProperties {
    public:
        float temp;
        float percip;
        float month;
        envProperties(){};
        ~envProperties(){};
};

class plantProperties {
    public:
        //General characteristics
        const int modifiers = 0;
        const int lifetime = 10;
        //Growth and reproductive characteristics
        const float maxHeight = 100;
        const float growthRate = 0.5;
        const float shadeTolerance = 0.5;
        const float seedsProduced = 10;;
        const float seedRadius = 10;
        const float seedTime = 5;
        //Temperature in degrees C
        const float lowIdealTemp = 0;
        const float highIdealTemp = 20;
        //Percip in mm per year
        const float lowIdealPercip = 200;
        const float highIdealPercip = 800; 

        plantProperties();
        plantProperties(int modifiers, int lifetime, float maxHeight, float growthRate, float shadeTolerance, 
                        float seedsProduced, float seedRadius, float seedTime, float lowIdealTemp, 
                        float highIdealTemp, float lowIdealPercip, float highIdealPercip): 
                        modifiers(modifiers), 
                        lifetime(lifetime), 
                        maxHeight(maxHeight), 
                        growthRate(growthRate),
                        shadeTolerance(shadeTolerance), 
                        seedsProduced(seedsProduced), 
                        seedRadius(seedRadius), 
                        seedTime(seedTime),
                        highIdealTemp(highIdealTemp),
                        lowIdealTemp(lowIdealTemp),
                        highIdealPercip(highIdealPercip),
                        lowIdealPercip(lowIdealPercip) {};
        ~plantProperties(){};
};

//inline float clamp(float x, float min, float max);

class simulatedPlant {
    private:
        static const float tempVulnerability; //How much to lower satisfaction by for every degree outside nominal
        static const float percipVulnerability; //How much to lower satisfaction by for every mm of rain per year outside nominal

        std::string name;
        float height = 0.01; //In meters
        int age = 1;
        plantProperties *properties; // Pointer to plant properties, needs to be created / destroyed outside the class

    public:
        simulatedPlant(plantProperties *prop);
        simulatedPlant(std::string _name, float _height, plantProperties *prop);
        
        std::string getName(){return name;}
        float getHeight(){return height;}
        int getAge(){return age;}
        std::string toString();
        void reset();

        void simulateGrowth(const envProperties *weather);  
        virtual float calculateGrowth(float satisfaction); 
        virtual float calculateSatisfaction(const envProperties *weather);
};
};

#endif /* plant_h */