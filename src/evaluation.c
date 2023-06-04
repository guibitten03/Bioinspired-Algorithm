#include "evaluation.h"

float routeCalculate(Individuo individuo, Matrix matrix){    
    float distancia = 0;

    for(int i = 0; i < matrix.len-1; i++){
        distancia += matrix.matrix[individuo.traits[i]][individuo.traits[i+1]];  
    }

    distancia += matrix.matrix[individuo.traits[matrix.len-1]][individuo.traits[0]];
    return distancia;
}

void evaluation(Population * population){

    #ifdef printSteps
    printf("Evaluation individuos...\n");
    #endif

    for(int i = 0; i < population->populationSz; i++){
        population->population[i].dist = routeCalculate(population->population[i], population->matrix);
        
        if(population->population[i].dist < population->bestIndividuo.dist){
            population->bestIndividuo.dist = population->population[i].dist;
            for(int c=0; c<population->bestIndividuo.traitsSz; c++){
                population->bestIndividuo.traits[c] = population->population[i].traits[c];
            }
        }
    }
}

Individuo selection(Population * population){
    srand(microseg());
    int firstRPosition = rand() % population->populationSz;
    int secondRPosition = rand() % population->populationSz;

    if(population->population[firstRPosition].dist <= population->population[secondRPosition].dist){
        return population->population[firstRPosition];
    }else{
        return population->population[secondRPosition];
    }

}

Individuo selection_in_4(Population * population){
    srand(microseg());
    int Position[4];
    Position[0] = rand() % population->populationSz;
    Position[1] = rand() % population->populationSz;
    Position[2] = rand() % population->populationSz;
    Position[3] = rand() % population->populationSz;
    Individuo menor = population->population[Position[0]];

    for (int i = 0; i < 4; i++){
        if(population->population[Position[i]].dist<menor.dist){
            menor = population->population[Position[i]];
        }
    }

    return menor;
    

}