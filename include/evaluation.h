#ifndef __EVALUATION_H__
#define __EVALUATION_H__

#include "file.h"
#include "bioinsp.h"

Individuo evaluation(Population* population);
void routeCalculate(Individuo* individuo, Matrix matrix);
Individuo selection(Population * population, int seed);

#endif