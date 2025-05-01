#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subsim {
    int (*initialize)();
    int (*finalize)();
    int (*execute)(char** args, int arg_count);
} subsim;