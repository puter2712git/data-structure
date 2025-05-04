#ifndef __LLISTSIM_H__
#define __LLISTSIM_H__

#include "subsim.h"

extern subsim llist_ssim;

int llist_ssim_initialize();
int llist_ssim_finalize();

int llist_ssim_execute(char** args, int argc);

void llist_help();

#endif