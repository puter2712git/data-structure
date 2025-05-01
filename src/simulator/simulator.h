#pragma once

#include "subsim/subsim.h"

typedef enum {
    STACK,
    QUEUE,
    SIM_TYPES
} sim_type;

extern const char* SIM_NAMES[];
extern subsim* ssims;

typedef struct {
    subsim* ssim;
} simulator;

extern simulator* sim;

int sim_initialize();
int sim_finalize();

int sim_run();