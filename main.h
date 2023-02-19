#ifndef main_h
#define main_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include "plant.h"

#define SCREEN_W 720
#define SCREEN_H 480

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)

namespace testTools{
    void drawTestFunction(float func(float x), int iterations);
    void drawTestParamFunction(float func(float x, float param[]), float param[], ALLEGRO_COLOR colour,  int iterations, float maxValue, float rng);
    void drawTestPlantGrowth(simulatedPlant *plant, ALLEGRO_COLOR *drawColor, envProp *weather, int iterations, int maxHeight);
    float exponential(float x, float param[]);
    float x_squared(float x);
    float linear(float x);
    float linear_p(float x, float param[]);
};

#endif /* main_h */
