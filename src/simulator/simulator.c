#include "simulator.h"

#include <stdio.h>
#include <stdlib.h>

const char* SIM_NAMES[] = {
    "Stack",
    "Queue"
};

simulator* sim = NULL;

int sim_initialize()
{
    sim = (simulator*)malloc(sizeof(simulator));
    sim->ssim = NULL;
}

int sim_finalize()
{
    free(sim);
}

int sim_run()
{
    while (1) {
        if (sim->ssim == NULL) {
            for (int i = 0; i < SIM_TYPES; i++) {
                fprintf(stdout, "1. %s\n", SIM_NAMES[i]);
            }

        }
    }
}