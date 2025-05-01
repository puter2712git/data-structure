#ifndef __QUEUE_SIM_H__
#define __QUEUE_SIM_H__

#include "subsim.h"

extern subsim queue_ssim;

int queue_ssim_initialize();
int queue_ssim_finalize();

int queue_ssim_execute(char** args, int arg_count);

void queue_help();

#endif