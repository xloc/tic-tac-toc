#include "myRand.h"

void initRandSeed(){
    srand(time(NULL));
    rand();
}


float getRand(){
    return (float) rand() / RAND_MAX;
}