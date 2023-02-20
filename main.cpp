#include "main.h"

using namespace std;

int main () {
    al_init();
    al_install_keyboard();
    al_init_primitives_addon();

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_DISPLAY *display = al_create_display(SCREEN_W, SCREEN_H);
    ALLEGRO_FONT *font = al_create_builtin_font();

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool redraw = true;
    ALLEGRO_EVENT event;

    
    
    al_start_timer(timer);
    while(true)
    {
        al_wait_for_event(queue, &event);
        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
            break;
        if(redraw && al_is_event_queue_empty(queue))
        {
            //al_clear_to_color(WHITE);
            al_draw_text(font, BLACK, 0, 0, 0, "Test");
            al_flip_display();
            redraw = false;
        }
    }
    al_clear_to_color(WHITE);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}
void testTools::drawTestFunction(float func(float x), int iterations){
    float prev = func(0);
    float temp = 0.0f;
    for (int i = 1; i < iterations; i++){
        temp = func(i);
        al_draw_line((float(SCREEN_W)/ iterations) * i - 1, SCREEN_H - prev, (float(SCREEN_W)/ iterations) * i, SCREEN_H - temp, BLACK, 2);
        prev = temp;
    }
}
void testTools::drawTestParamFunction(float func(float x, float param[]), float param[], ALLEGRO_COLOR colour,  int iterations, float maxValue, float rng){
    float prev = func(0, param);
    float temp = 0.0f;
    for (int i = 1; i < iterations; i++){
        temp = func(rng * (float)i / (float)iterations, param);
        al_draw_line((float(SCREEN_W)/ iterations) * i - 1, SCREEN_H - SCREEN_H * prev / maxValue, (float(SCREEN_W)/ iterations) * i, SCREEN_H - SCREEN_H * temp / maxValue, colour, 2);
        prev = temp;
    }
}
void testTools::drawTestPlantGrowth(plantSimulation::simulatedPlant *plant, ALLEGRO_COLOR *drawColor, plantSimulation::envProperties *weather, int iterations, int maxHeight){
    float previousHeight = 0;
    int month = 0;
    for (int i = 1; i < iterations; i++, month++){
        plant->simulateGrowth(weather + (month % 12));
        al_draw_line(SCREEN_W * (i - 1) / iterations, SCREEN_H - SCREEN_H * previousHeight / maxHeight, SCREEN_W * i / iterations, SCREEN_H - SCREEN_H * plant->getHeight() / maxHeight, *drawColor, 2);
        previousHeight = plant->getHeight();
        if (previousHeight > maxHeight) {
            return;
        }
    }
}

float testTools::x_squared(float x){
    return 0.01 * x * x;
}
float testTools::linear(float x){
    return 10 * x;
}
float testTools::linear_p(float x, float param[]){
    return param[0] * x + param[1];
}
float testTools::exponential(float x, float param[]){
    return param[0] * pow(x, param[1]);
}

/*float par[2];
    for (int i = 1; i < 11; i++){
        par[0] = -2 * pow(i / 10.0, 1);
        par[1] = pow(i / 10.0, 0.5);
        drawColor = al_map_rgb(255 * i / 10, 0, 0);
        testTools::drawTestParamFunction(testTools::linear_p, par, drawColor, 200, 1.0f, 1.0f);
    }*/

//Testing Plant Growth Characteristics
/*plantProperties properties;
simulatedPlant testPlant(properties);
envProperties testEnv[12];
for (int i = 0; i < 12; i++){
    testEnv[i].month = i;
    testEnv[i].temp = (20.0f / 11.0f) * i;
    testEnv[i].percip = 50;
}
ALLEGRO_COLOR drawColor;
al_clear_to_color(WHITE);

for (int j = 1; j < 12; j++){
    testPlant.reset();
    properties->growthRate = (1.0f / 12.0f) * j;
    drawColor = al_map_rgb(255 * j / 13, 0, 0);
    testTools::drawTestPlantGrowth(&testPlant, &drawColor, testEnv, 200, 150);
    cout << "Height: " << testPlant.getHeight() << " Growth Rate: " << properties->growthRate << endl;
}

for (int i = 0; i < 12; i++){
    testEnv[i].month = i;
    testEnv[i].temp = (20.0f / 11.0f) * i - 30.0f;
    testEnv[i].percip = 50;
}
for (int j = 1; j < 12; j++){
    testPlant.reset();
    properties->growthRate = (1.0f / 12.0f) * j;
    drawColor = al_map_rgb(0, 0, 255 * j / 13);
    testTools::drawTestPlantGrowth(&testPlant, &drawColor, testEnv, 100, 100);
    cout << "Height: " << testPlant.getHeight() << " Growth Rate: " << properties->growthRate << endl;
}*/