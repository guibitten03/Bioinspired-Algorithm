#include <stdbool.h>
#include "evaluation.h"
#include "bioinsp.h"

#define INFINITO 100000000

int seed = 0;

int bioinsp(Matrix matrix, int populationSz, int plato){
    int stop = 0;
    int pastBestDist = INFINITO;
    Population population = createPopulation(matrix, populationSz);

    do{
        population.bestIndividuo = evaluation(&population);

        if(population.bestIndividuo.dist == pastBestDist){stop++;}
        else{
            stop = 0;
            pastBestDist = population.bestIndividuo.dist; 
        }

        darwinism(&population);

    }while(stop > plato);

    return population.bestIndividuo.dist;
}

Population createPopulation(Matrix matrix, int populationSz){
    Population population;

    population.matrix = matrix;
    population.populationSz = populationSz;
    population.bestIndividuo.dist = INFINITO;
    population.bestIndividuo.traits = NULL;
    population.population = (Individuo*)malloc(populationSz*sizeof(Individuo));

    for(int c=0; c<populationSz; c++){
        population.population[c] = createIndividuo(population.matrix.len);

    }


    return population;
}

Individuo createIndividuo(int individuoSz){
    int random, modifi;

    Individuo individuo;
    individuo.dist = INFINITO;
    individuo.traits = (int*)malloc(individuoSz*sizeof(int));
    individuo.traitsSz = individuoSz;

    srand(time(NULL)+seed);
    seed++;
    for(int c=0; c<individuoSz; c++){
        random = rand()  % individuoSz;
        
        modifi = 1;
        while (modifi){
            modifi = 0;
            for(int i=0; i<c; i++){
                if(individuo.traits[i]==random){
                    modifi = 1;
                    random = rand()  % individuoSz;
                    break;
                }
            }
            
        }
        individuo.traits[c] = random;
    }

    return individuo;
}

Individuo crossingIndividuos(Population * pop, Individuo father, Individuo mother, int vLen){
    Individuo child_1 = createIndividuo(vLen);
    Individuo child_2 = createIndividuo(vLen);

    int strip = (int)vLen / 3;
    for(int trait = 0; trait < strip; trait++){
        child_1.traits[strip + trait] = mother.traits[strip + trait];
        child_2.traits[strip + trait] = father.traits[strip + trait];
    }

    
}

void darwinism(Population * population){
    Population newPopulation = createPopulation(population->matrix, population->populationSz);

    for(int i = 0; i < population->populationSz; i++){
        newPopulation.population[i] = selection(population);
    }

    for(int i = 0; i < population->populationSz; (i+2)){
        newPopulation.population[i] = crossover(population->population[i], population->population[i+1]);
        newPopulation.population[i + 1] = crossover(population->population[i], population->population[i+1]);
    }

}

Individuo crossover(Individuo father, Individuo mother){
    

}

void Mutation(Individuo* individuo, int mutationP){
    int random1, random2, aux;
    
    srand(time(NULL)+seed);
    seed++;
    for(int c=0; c<individuo->traitsSz; c++){
        random1 = (rand()%100);

        if(random1<=mutationP){
            random2 = rand() % individuo->traitsSz;

            aux = individuo->traits[c];
            individuo->traits[c] = individuo->traits[random2];
            individuo->traits[random2] = aux;
        }
    }
}