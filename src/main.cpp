/*
    Version in c++ of the shakespere from Natural of the Code
    reference: https://aip.scitation.org/doi/pdf/10.1063/1.5039131
*/
#include <iostream>
#include "DNA.h"
#include "population.h"

using namespace std;

/*
    Generate population

    parameters:
        matrix: Matrix of distances between the nodes
        mutation_rate: rate of mutation
        popmax: max population
        elite:
*/
Population createPopulation(const vector<vector<double>>& matrix, double mutation_rate, int popmax, int elite) {
    return Population(matrix, mutation_rate, popmax, elite);
}

/*
*/
void run(Population population) {
    int i = 0, max_gen = 200;

    population.start_clock();

    while(i++ < max_gen) {
        cout << "Generation: " << population.generation << endl;
        cout << "Calculate fitness\n";
        
        // Classification: calculate all scores
        population.calc_fitness();
        cout << "Evaluate the best crew\n";

        // Get best individual
        population.evaluete();
        cout << "Best fitniss: " << population.best_individual.fitness << endl;

        // Select actual population
        population.selection();
        cout << "Population selected\n";

        // Reproduction of new life, called also sex
        population.generate();
        cout << "Population sucessiful crossovered\n";
        
        if(population.get_is_finish()) {
            cout << "End of Evolution" << endl;
            return;
        }
    }   
}

const int MAX_N = 10;
vector<vector<double>> load_distance_matrix() {
    vector<vector<double>> matrix(MAX_N, vector<double>(MAX_N));

    for(int i = 0; i < 10; ++i) {
        vector<double> row;
        for(int j = 0; j < 10; ++j) {
            if(i != j)
                row.push_back(j);
            else row.push_back(MAX_N*10);
        }
        matrix[i] = row;
    }

    // read matrix
    return matrix;
}

// will be deleted 
int main() {
    string target = "TO BE OR NOT TO BE";
    int popmax = 2500;
    double mutationRate = 0.02;
    int elite = 5;
    
    vector<vector<double>> matrix = load_distance_matrix();

    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            cout << matrix[i][j] << ' ';
        cout << endl;

    // Create population initial
    Population population = createPopulation(matrix, mutationRate, popmax, elite);
    
    // Run life
    run(population);
    
    return 0;
}