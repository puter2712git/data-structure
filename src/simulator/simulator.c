#include "simulator.h"
#include "subsim/stacksim.h"
#include "subsim/queuesim.h"
#include <util/parser.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* SIM_NAMES[] = {
    "Stack",
    "Queue"
};
const int SIM_COUNT = sizeof(SIM_NAMES) / sizeof(SIM_NAMES[0]);
subsim* ssims = NULL;

simulator* sim = NULL;

int sim_initialize()
{
    sim = (simulator*)malloc(sizeof(simulator));
    sim->ssim = NULL;

    ssims = (subsim*)malloc(sizeof(subsim) * SIM_COUNT);
    ssims[0] = stack_ssim;
    ssims[1] = queue_ssim;

    return 0;
}

int sim_finalize()
{
    free(sim);
    return 0;
}

int sim_run()
{
    while (1) {
        if (sim->ssim == NULL) {
            for (int i = 0; i < SIM_TYPES; i++) {
                fprintf(stdout, "%d. %s\n", i, SIM_NAMES[i]);
            }
            
            int type;
            fprintf(stdout, ">> ");
            scanf("%d", &type);
            getchar();

            if (type < SIM_COUNT) {
                sim->ssim = &ssims[type];
                sim->ssim->initialize();
            }
        } else {
            char command[100];
            char* args[24] = {};
            int arg_count;

            fprintf(stdout, ">> ");
            fgets(command, sizeof(command), stdin);
            int cmd_len = strlen(command);
            command[cmd_len - 1] = '\0';
            parse_command(command, args, &arg_count);

            if (sim->ssim->execute(args, arg_count) == 1) {
                sim->ssim->finalize();
                sim->ssim = NULL;
            }
        }
    }

    return 0;
}