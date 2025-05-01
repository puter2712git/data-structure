#include "stacksim.h"
#include <data-structure/stack.h>

subsim stack_ssim = {
    .initialize = stack_ssim_initialize,
    .finalize = stack_ssim_finalize,
    .execute = stack_ssim_execute
};

int stack_ssim_initialize()
{
    return stack_initialize();
}

int stack_ssim_finalize()
{
    return stack_finalize();
}

int stack_ssim_execute(char** args, int arg_count)
{
    if (arg_count <= 0) return -1;

    system("clear");

    if (strcmp(args[0], "push") == 0 && arg_count == 2) {
        if (!stack_push(args[1])) {
            fprintf(stdout, "Item %s successfully pushed in the stack!\n", args[1]);
        } else {
            fprintf(stderr, "[!] An error occurred in the command \"push\".\n");
        }
    } else if (strcmp(args[0], "pop") == 0 && arg_count == 1) {
        char* popped = stack_pop();
        if (popped != NULL) {
            fprintf(stdout, "Item %s successfully popped from the stack!\n", popped);
        } else {
            fprintf(stderr, "[!] An error occurred in the command \"pop\".\n");
        }
    } else if (strcmp(args[0], "dump") == 0 && arg_count == 1) {
        if (stack_dump()) {
            fprintf(stderr, "[!] An error occurred in the command \"dump\".\n");
        }
    } else if (strcmp(args[0], "exit") == 0 && arg_count == 1) {
        return 1;
    } else {
        stack_help();
    }

    return 0;
}

void stack_help()
{
    fprintf(stdout, "Stack Commands\n");
    fprintf(stdout, "- push {item}\n");
    fprintf(stdout, "- pop\n");
    fprintf(stdout, "- dump\n");
    fprintf(stdout, "- exit\n");
}