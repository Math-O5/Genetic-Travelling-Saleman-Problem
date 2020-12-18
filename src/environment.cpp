/*
    Genetic Traveling Salesman Problem
    reference: https://aip.scitation.org/doi/pdf/10.1063/1.5039131
*/
#include "environment.h"
#include <iostream>

using namespace std;

/* Global definitions */
int N;
const int MAX_GEN = 5000;
const int POPULATION_SIZE = 30000;
const int ELITE_SIZE = 1;


/*
    Generate population

    parameters:
        matrix: Matrix of distances between the nodes
        mutation_rate: rate of mutation
        popmax: max size of population
        elite: size of elite
*/
Population create_population(const vector<vector<double>>& matrix, int popmax, int elite) {
    return Population(matrix, popmax, elite);
}

/*
    Print parameters of the individual
*/
void print_individual(Individual& individual) {
        cout << "Best fitness: " << individual.fitness << endl;
        cout << "Distance: " << individual.distance << endl;
        for(int j =0; j < individual.length; ++j)
            cout << individual.genes[j] << ' ';
        cout << endl;
}

/* 
    Print tour of all population
*/
void print_all_tours(Population& population) {
    for(int i = 0; i < POPULATION_SIZE; ++i) {
        for(int j = 0; j < population.individuals[i].length; ++j) {
            cout << population.individuals[i].genes[j] << ' ';
        }
        cout << endl;     
    }
}

void env_life(const vector<vector<double>>& matrix, Population& population) {
    
    // Generation actual
    int i = 0;

    while(i < MAX_GEN) {
        if(ENABLE_OUTPUT)
            cout << "Generation: " << population.generation << endl;
        
        if(ENABLE_OUTPUT)
            cout << "Calculate fitness\n";
        
        // Classification: calculate all scores
        population.calc_fitness();
        
        //print_all_tours(population);
       
        if(ENABLE_OUTPUT)
            cout << "Selection the best crew\n";
    
        // Select current population
        population.selection();
        // Show the best individual
        if(ENABLE_OUTPUT)
            print_individual(population.best_individual);
        
        // Reproduction of new life, called also sex
        population.generate();
        if(ENABLE_OUTPUT)
            cout << "Population sucessiful crossovered\n";

        population.evolutionary_reversal();
        if(ENABLE_OUTPUT)
            cout << "Evolutionry Reversal" << endl;

        i += 1;
    }
}

/*  
    This function create the environment for algorithm evolution

    Steps:
        Create the distance matrix
        Create the population
        Call algorithm evolution for population
        Clear memory
*/
void env_run() {

    // Load matrix
    vector<vector<double>> matrix = load_distance_matrix();

    // Create population initial
    Population population = create_population(matrix, POPULATION_SIZE, ELITE_SIZE);

    // Run evolution algoritm on this population
    env_life(matrix, population);

    // Clear matrix
    for(int i = 0; i < N; ++i)
        matrix[i].clear();
}

/**/
vector<vector<double>> load_distance_matrix() {
    vector<pair<double,double>> pos;
    string path, filename, ext;

    path = "./data/";
    cin >> filename;
    ext = ".txt";

    fstream my_file;
    cout << path + filename + ext << endl;
    my_file.open(path + filename + ext, ios::in);
    if (!my_file.is_open()) {
        cout << "Failed to open file\n";
        exit(1);
    }
    my_file >> N;

    vector<vector<double>> matrix(N, vector<double>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            my_file >> matrix[i][j]; 
        }
    }
  
    my_file.close();

    return matrix;
}
