#include <stdbool.h>

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

        crossover(&population);

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
        for(int i=0; i<population.matrix.len; i++){
            printf("%d ", population.population[c].traits[i]);
        }
        printf("\n");
    }


    return population;
}

Individuo createIndividuo(int individuoSz){
    int random, modifi;

    Individuo individuo;
    individuo.dist = INFINITO;
    individuo.traits = (int*)malloc(individuoSz*sizeof(int));

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

void crossover(Population* population){
    /*
    bool par = population->populationSz % 2 == 0;
    for(int i = 0; i < (population->populationSz+1); i++){
        if(bool){
            printf("d");
        }
    }
    */
}

void Mutation(Individuo* individuo, int mutationP){
    int random1, random2, aux;
    
    srand(time(NULL)+seed);
    seed--;
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