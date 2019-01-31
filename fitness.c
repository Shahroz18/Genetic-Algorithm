#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Compute distance between images at A and B
double comp_distance(const PIXEL *A, const PIXEL *B, int image_size)
{
	// Initialize variable for distance
	double distance = 0;

	// Sum distances between each pixel
	for (int i = 0; i < image_size; i++)
		distance += pow(A[i].r - B[i].r, 2) + pow(A[i].g - B[i].g, 2) + pow(A[i].b - B[i].b, 2);

	// Return square root of sum
	return sqrt(distance);
}

// Compute ﬁtness of each individual in population
void comp_fitness_population(const PIXEL *image, Individual * individual, int population_size)
{
	// Compute fitness of each individual and assign it to fitness variable
	for (int i = 0; i < population_size; i++)
		individual[i].fitness = comp_distance(image, individual[i].image.data, individual[i].image.width * individual[i].image.height);
}