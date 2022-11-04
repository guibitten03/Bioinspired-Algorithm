#ifndef __EVALUATION_H__
#define __EVALUATION_H__

#include "file.h"
#include "bioinsp.h"

void evaluation(Population * population);
int routeCalculate(Individuo individuo, Matrix matrix);
Individuo selection(Population * population, int seed);
Individuo selection_in_4(Population * population, int seed);

#endif