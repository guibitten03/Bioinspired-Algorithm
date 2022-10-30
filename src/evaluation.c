#include "evaluation.h"

int routeCalculate(Individuo individuo, Matrix matrix){
    int dist = 0;
    for(int i = 0; i < matrix.len; i++){
        if (i == (matrix.len - 1)){
            dist += matrix.matrix[individuo.traits[i]][individuo.traits[0]];

            break;
        }
        dist += matrix.matrix[individuo.traits[i]][individuo.traits[i+1]];
    }

    return dist;
}

void evaluation(Population * population){

    #ifdef printSteps
    printf("Evaluation individuos...\n");
    #endif

    for(int i = 0; i < population->populationSz; i++){
        population->population[i].dist = routeCalculate(population->population[i], population->matrix);
        
        if(population->population[i].dist < population->bestIndividuo.dist){
            population->bestIndividuo = population->population[i];
        }
    }
}

Individuo selection(Population * population, int seed){
    srand(time(NULL)+seed);
    seed--;
    int firstRPosition = rand() % population->populationSz;
    srand(time(NULL)+seed);
    seed--;
    int secondRPosition = rand() % population->populationSz;

    if(population->population[firstRPosition].dist <= population->population[secondRPosition].dist){
        return population->population[firstRPosition];
    }else{
        return population->population[secondRPosition];
    }

}