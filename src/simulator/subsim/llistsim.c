#include "llistsim.h"
#include <data-structure/linked_list.h>

subsim llist_ssim = {
    .initialize = llist_ssim_initialize,
    .finalize = llist_ssim_finalize,
    .execute = llist_ssim_execute
};

int llist_ssim_initialize()
{
    return llist_initialize();
}

int llist_ssim_finalize()
{
    return llist_finalize();
}

int llist_ssim_execute(char** args, int argc)
{
    if (argc <= 0) return -1;

    system("clear");

    if (strcmp(args[0], "add") == 0 && argc == 3) {
        if (strcmp(args[1], "head") == 0 && !llist_add_head(args[2])) {
            fprintf(stdout, "Item %s successfully added in the head of the list!\n", args[2]);
        } else if (strcmp(args[1], "tail") == 0 && !llist_add_tail(args[2])) {
            fprintf(stdout, "Item %s successfully added in the tail of the list!\n", args[2]);            
        }
    } else if (strcmp(args[0], "remove") == 0 && argc == 2) {
        if (strcmp(args[1], "head") == 0) {
            char* removed = llist_remove_head();
            fprintf(stdout, "Item %s successfully removed from the list!\n", removed);
        } else if (strcmp(args[1], "tail") == 0) {
            char* removed = llist_remove_tail();
            fprintf(stdout, "Item %s successfully removed from the list!\n", removed);
        }
    } else if (strcmp(args[0], "dump") == 0 && argc == 1) {
        if (llist_dump()) {
            fprintf(stderr, "[!] An error occurred in the command \"dump\".\n");
        }
    } else if (strcmp(args[0], "exit") == 0 && argc == 1) {
        return 1;
    } else {
        llist_help();
    }

    return 0;
}

void llist_help()
{
    fprintf(stdout, "Linked List Commands\n");
    fprintf(stdout, "- add [head/tail] {item}\n");
    fprintf(stdout, "- remove [head/tail]\n");
    fprintf(stdout, "- dump\n");
    fprintf(stdout, "- exit\n");
}