#include "stacksim.h"
#include <data-structure/stack.h>

subsim stack_ssim = {
    .initialize = stack_ssim_initialize,
    .finalize = stack_ssim_finalize,
    .execute = stack_ssim_execute
};

int stack_ssim_initialize()
{
    stack_initialize();
}

int stack_ssim_finalize()
{
    stack_finalize();
}

int stack_ssim_execute(char** args, int arg_count)
{
    if (arg_count <= 0) return -1;

    if (strcmp(args[0], "push") == 0 && arg_count == 2) {
        stack_push(args[1]);
    } else if (strcmp(args[0], "pop") == 0 && arg_count == 1) {
        stack_pop();
    } else if (strcmp(args[0], "dump") == 0 && arg_count == 1) {
        stack_dump();
    }
}