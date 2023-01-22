#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//All properties about the enviroment at the plant's position that a plant needs to be given
typedef struct enviromentProperties {
    float temp;
    float percip;
    float month;
} envProp;

typedef struct plantProperties {
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
} plantProp;

plantProp* createPlantProp();
envProp* createEnvProp();
inline float clamp(float x, float min, float max);

class simulatedPlant {
    private:
        static const float tempVulnerability; //How much to lower satisfaction by for every degree outside nominal
        static const float percipVulnerability; //How much to lower satisfaction by for every mm of rain per year outside nominal

        string name;
        float height = 0.01; //In meters
        int age = 1;
        plantProp *properties; // Pointer to plant properties, needs to be created / destroyed outside the class

    public:
        virtual float calculateGrowth(float satisfaction); 
        virtual float calculateSatisfaction(const envProp *weather);
        simulatedPlant(plantProp *prop);
        simulatedPlant(string _name, float _height, plantProp *prop);
        
        string getName(){return name;}
        float getHeight(){return height;}
        int getAge(){return age;}
        void reset();
        void simulateGrowth(const envProp *weather);  
};
