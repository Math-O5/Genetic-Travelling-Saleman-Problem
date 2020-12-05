/*
    Genetic Traveling Salesman Problem
    reference: https://aip.scitation.org/doi/pdf/10.1063/1.5039131
*/
#include "environment.h"

using namespace std;

/* Global definitions */
const int MAX_N = 10;
const int MAX_GEN = 100;
const int POPULATION_SIZE = 10;
const int ELITE_SIZE = 0.3 * POPULATION_SIZE;

/*
    Generate population

    parameters:
        matrix: Matrix of distances between the nodes
        mutation_rate: rate of mutation
        popmax: max population
        elite:
*/
Population create_population(const vector<vector<double>>& matrix, int popmax, int elite) {
    return Population(matrix, popmax, elite);
}

/*
    Run : void
    Paramets:

*/
void env_run() {
    
    int i = 0;

    // Load matrix
    vector<vector<double>> matrix = load_distance_matrix();

    // Create population initial
    Population population = create_population(matrix, POPULATION_SIZE, ELITE_SIZE);

    while(i < MAX_GEN) {
        cout << "Generation: " << population.generation << endl;
        cout << "Calculate fitness\n";
        
        // Classification: calculate all scores
        population.calc_fitness();
        cout << "Evaluate the best crew\n";

        // Select actual population
        population.selection();
        cout << "Best fitniss: " << population.best_individual.fitness << endl;
        for(int j =0; j < population.best_individual.length; ++j)
            cout << population.best_individual.genes[j] << ' ';
        cout << endl;
        cout << "Distance: " << population.best_individual.distance << endl;

        // Reproduction of new life, called also sex
        population.generate();
        cout << "Population sucessiful crossovered\n";
        
        // if(population.get_is_finish()) {
        //     cout << "End of Evolution" << endl;
        //     return;
        // }

        i += 1;
    }

    // Clear matrix
    for(int i = 0; i < 10; ++i)
        matrix[i].clear();
}

/**/
vector<vector<double>> load_distance_matrix() {
    vector<vector<double>> matrix(MAX_N, vector<double>(MAX_N));

    for(int i = 0; i < 10; ++i) {
        vector<double> row;
        for(int j = i; j < 10; ++j) {
            if(i != j) {
                matrix[i][j] = i + 1;
                matrix[j][i] = i + 1;
            }
            else matrix[i][j] = MAX_N*10;
        }
    }

    // read matrix
    return matrix;
}