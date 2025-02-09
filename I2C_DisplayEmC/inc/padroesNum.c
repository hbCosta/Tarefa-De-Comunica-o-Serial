#define NUM_PIXELS 25
// Buffer para armazenar quais LEDs estão ligados matriz 5x5
bool led_buffer0[NUM_PIXELS] = {
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 1, 
    1, 0, 0, 0, 1, 
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1
};

bool led_buffer1[NUM_PIXELS] = {
    0, 0, 1, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 0, 1, 0, 0
};

bool led_buffer2[NUM_PIXELS] = {
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 0, 
    1, 1, 1, 1, 1, 
    0, 0, 0, 0, 1, 
    1, 1, 1, 1, 1
};

bool led_buffer3[NUM_PIXELS] = {
    1, 1, 1, 1, 1, 
    0, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    0, 0, 0, 0, 1, 
    1, 1, 1, 1, 1
};

bool led_buffer4[NUM_PIXELS]={
    0, 0, 1, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 1, 1, 1, 1, 
    0, 1, 1, 0, 0, 
    0, 0, 1, 0, 0
};

bool led_buffer5[NUM_PIXELS]={
    1, 1, 1, 1, 1, 
    0, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 0, 
    1, 1, 1, 1, 1
};

bool led_buffer6[NUM_PIXELS]={
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 0, 
    1, 1, 1, 1, 1
};

bool led_buffer7[NUM_PIXELS] = {
    0, 0, 1, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 1, 1, 1, 0, 
    0, 0, 1, 0, 0, 
    0, 0, 1, 1, 1
};

bool led_buffer8[NUM_PIXELS] = {
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1
};

bool led_buffer9[NUM_PIXELS] = {
    1, 0, 0, 0, 0, 
    0, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 
    1, 0, 0, 0, 1, 
    1, 1, 1, 1, 1
};
