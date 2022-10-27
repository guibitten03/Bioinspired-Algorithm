#include "evaluation.h"

void routeCalculate(Individuo * individuo, Matrix matrix){
    for(int i = 0; i < (matrix.len + 1); i++){
        if (i == matrix.len){
            individuo->dist += matrix.matrix[individuo->traits[i-1]][0];
        }
        individuo->dist += matrix.matrix[individuo->traits[i]][individuo->traits[i+1]];
    }
}

Individuo evaluation(Population * population){
    printf("Evaluation individuos...");
    for(int i = 0; i < population->populationSz; i++){
        routeCalculate(&population->population[i], population->matrix);
        
        if(population->population[i].dist < population->bestIndividuo.dist){
            population->bestIndividuo = population->population[i];
        }
    }

    return population->bestIndividuo;
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