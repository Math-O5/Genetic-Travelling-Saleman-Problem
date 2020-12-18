/*
    Genetic Traveling Salesman Problem
    reference: https://aip.scitation.org/doi/pdf/10.1063/1.5039131
*/
#ifndef __ENV__
#define __ENV__
#include <iostream>
#include "population.h"
#include "individual.h"

using namespace std;

/*
    Generate population

    parameters:
        matrix: Matrix of distances between the nodes
        mutation_rate: rate of mutation
        popmax: max population
        elite:
*/
Population createPopulation(const vector<vector<double>>& matrix, int popmax, int elite);

/*
    Run : void
    Paramets:

*/
void env_run();

/**/
vector<vector<double>> load_distance_matrix();

#endif