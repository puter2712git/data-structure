#include "queuesim.h"
#include <data-structure/queue.h>

subsim queue_ssim = {
    .initialize = queue_ssim_initialize,
    .finalize = queue_ssim_finalize,
    .execute = queue_ssim_execute
};

int queue_ssim_initialize()
{
    return queue_initialize();
}

int queue_ssim_finalize()
{
    return queue_finalize();
}

int queue_ssim_execute(char** args, int arg_count)
{
    if (arg_count <= 0) return -1;

    system("clear");

    if (strcmp(args[0], "enqueue") == 0 && arg_count == 2) {
        if (!queue_enqueue(args[1])) {
            fprintf(stdout, "Item %s successfuly enqueued in queue!\n", args[1]);
        } else {
            fprintf(stderr, "[!] An error occurred in the command \"enqueue\".\n");
        }
    } else if (strcmp(args[0], "dequeue") == 0 && arg_count == 1) {
        char* dequeued = queue_dequeue();
        if (dequeued != NULL) {
            fprintf(stdout, "Item %s successfuly dequeued from the queue!\n", dequeued);
        } else {
            fprintf(stderr, "[!] An error occurred in the command \"dequeue\".\n");
        }
    } else if (strcmp(args[0], "dump") == 0 && arg_count == 1) {
        if (queue_dump()) {
            fprintf(stderr, "[!] An error occurred in the command \"dump\".\n");
        }
    } else if (strcmp(args[0], "exit") == 0 && arg_count == 1) {
        return 1;
    } else {
        queue_help();
    }

    return 0;
}

void queue_help()
{
    fprintf(stdout, "Queue Commands\n");
    fprintf(stdout, "- enqueue {item}\n");
    fprintf(stdout, "- dequeue\n");
    fprintf(stdout, "- dump\n");
    fprintf(stdout, "- exit\n");
}