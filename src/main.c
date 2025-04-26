#include <simulator/simulator.h>

int main()
{
    sim_initialize();

    sim_run();

    sim_finalize();

    return 0;
}