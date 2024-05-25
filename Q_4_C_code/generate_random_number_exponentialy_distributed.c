#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_RANDOM_NUMBERS 10000
#define MEAN 0.5

// Function to generate a random number uniformly distributed between 0 and 1
double uniform_random() {
    return rand() / (RAND_MAX + 1.0);
}

// Function to generate a random number with exponential distribution
double exponential_random(double mean) {
    double u = uniform_random();
    return -mean * log(1 - u);
}

int main() {
    FILE *file = fopen("exponential_random_numbers.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < NUM_RANDOM_NUMBERS; i++) {
        double random_number = exponential_random(MEAN);
        fprintf(file, "%f\n", random_number);
    }

    fclose(file);
    return 0;
}

