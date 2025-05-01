#pragma once

#include "subsim.h"

extern subsim stack_ssim;

int stack_ssim_initialize();
int stack_ssim_finalize();

int stack_ssim_execute(char** args, int arg_count);

void stack_help();