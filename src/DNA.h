#ifndef DNA_H
#define DNA_H

#include<string>
#include<stdlib.h>     /* srand, rand */
#include<time.h>       /* time */
#include<iostream>
#include<math.h>
#include<algorithm>    // std::random_shuffle

using namespace std;

// random generator function:
int random_number(int i) { 
    return rand()%i;
}

/*
    DNA is a collection genes.
    Genes is expreseed as tours
*/
class DNA { 
    public:
        vector<int> genes; // tour
        double fitness;
        int length;

        DNA() {
            fitness = 0;
            length = 0;
        };

        DNA(const DNA& dna) {
            this->genes = dna.genes;
            this->fitness = dna.fitness;
            this->length = dna.length;
        };

        DNA(int length) {
            this->fitness = 0;
            this->genes = new_tour(length);
            this->length = length;
        }

        vector<int> new_tour(int n) {
            vector<int> tour;

            // set default tour sequencial
            for (int i = 1; i < n; ++i)
                tour.push_back(i); // 1 2 ... n

            // using built-in random generator:
            random_shuffle(tour.begin(), tour.end());

            // using myrandom:
            random_shuffle ( tour.begin(), tour.end(), random_number;

            return tour;   
        }

        /*
            This function calculate the score of this indi
        */
        void calc_fitness(const vector<vector<double>> matrix_distance) {
            double fit = 0.0;
        
            // cout << genes << ' ' << target << endl;
            double sum = 0.0;
            for(int i = 0; i < this->length; ++i) {
                sum += matrix_distance[this->genes[i]][this->genes[(i + 1 ) % length]];
            }
            // cout << "End match\n";
            fitness = 1 / (double)sum;
            // cout << fitness << endl;
        }

        // Mescle father and mother, generate a CHILD
        DNA crossover(DNA partner) {
            DNA child = DNA((int)this->genes.size());

            int threshould = int(rand()%(int)this->genes.size());
            // cout << "Threshould test: " << threshould << endl;

            for(int i = 0; i < (int)this->genes.size(); ++i) {
                if(i > threshould) child.genes[i] = partner.genes[i];
                else child.genes[i] = this->genes[i]; 
            }
            // cout << "Pass crossover\n";
            // Return the new child
            return child;
        }

        // Chance of a gene suffer a mutation
        void mutate(double mutationRate) {
            for(int i = 0; i < genes.size(); ++i) {
                if (rand()/(double)RAND_MAX < mutationRate) {
                    genes[i] = new_char();
            }
        }
  }
};


#endif