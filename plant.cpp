#include "plant.h"

using namespace plantSimulation;

/**
 * @brief Create a default plant property
 * 
 * @return plantProp* pointer to the new property
 */
plantProperties::plantProperties(){
    lifetime = 50;
    maxHeight = 100.0f;
    growthRate = 0.5f;
    shadeTolerance = 1.0f;
    seedsProduced = 2.0f;
    seedRadius = 10.0f;
    seedTime = 10.0f;
    idealTemp[0] = 0.0f;
    idealTemp[1] = 20.0f;
    idealPercip[0] = 100.0f;
    idealPercip[1] = 1000.0f;
}

//Clamp a value within min and max
static inline float clamp(float x, float min, float max){
    if (x > max){
        return max;
    }
    else if (x < min){
        return min;
    }
    return x;
}
//Returns the higher value
static inline float max(float x, float y){
    if (x > y){
        return x;
    }
    else {
        return y;
    }
}
//Set constants in plant class
const float simulatedPlant::percipVulnerability = 0.005;
const float simulatedPlant::tempVulnerability = 0.05;

/**
 * @brief Construct a new simulated Plant::simulated Plant object
 * 
 * @param prop The properties to give this plant
 */
simulatedPlant::simulatedPlant(plantProperties *prop){
    name = "Default";
    height = 0.01f;
    age = 0;
    properties = prop;
}
/**
 * @brief Construct a new simulated Plant::simulated Plant object
 * 
 * @param _name the name to give this plant
 * @param _height the starting height of the plant
 * @param prop the properties to give this plant
 */
simulatedPlant::simulatedPlant(std::string _name, float _height, plantProperties *prop){
    name = _name;
    height = _height;
    age = 0;
    properties = prop;
}
//Calculate how well the plant is doing
float simulatedPlant::calculateSatisfaction(const envProperties *weather){
    if (!weather || !properties) return 0;
    float deviance = 0;
    float satisfaction = 0;
    if (weather->temp < properties->idealTemp[0]){
        deviance += (properties->idealTemp[0] - weather->temp) * tempVulnerability;
    }
    else if (weather->temp > properties->idealTemp[1]){
        deviance += (weather->temp - properties->idealTemp[1]) * tempVulnerability;
    }
    
    float adjustedWeather = weather->percip * 12.0f; //Pericpitation data is mm/month but plant properties are mm/year, so must be adjusted
    if (adjustedWeather < properties->idealPercip[0]){
        deviance += (properties->idealPercip[0] - adjustedWeather) * percipVulnerability;
    }
    else if (adjustedWeather > properties->idealPercip[1]){
        deviance += (adjustedWeather - properties->idealPercip[1]) * percipVulnerability;
    }
    deviance = clamp(deviance, 0, 1);
    satisfaction = pow(2.5f * (1 - deviance), properties->growthRate) - (properties->growthRate * properties->growthRate + 0.5);
    //cout << "Deviance: " << deviance << " Satisfaction " << satisfaction << " Temp " << weather->temp << endl;
    return clamp(satisfaction, -1, 1);
}
float simulatedPlant::calculateGrowth(float satisfaction){
    if (!properties) return 0;
    //return 0.5 * satisfaction * pow(height, 0.6 * properties->growthRate);
    return 0.5 * clamp(satisfaction, 0.0f, 1.0f) * pow(height, 0.6f * properties->growthRate);
}
void simulatedPlant::simulateGrowth(const envProperties *weather){
    if (!properties) return;
    float growth = calculateGrowth(calculateSatisfaction(weather));
    if (height < (1.5f*properties->maxHeight) && height < 1000.0f){
        height += growth / pow(max(height - properties->maxHeight, 1), 2);
    }
    age++;
}
void simulatedPlant::reset(){
    height = 0.01f;
    age = 0;
}
