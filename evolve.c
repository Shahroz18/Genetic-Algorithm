#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

// Integer compare function for qsort
static int int_cmp(const void * a, const void * b)
{
	const Individual *individualA = a, *individualB = b;
	return (individualA->fitness - individualB->fitness);
}

// Evolve image using genetic algorithm
PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate)
{
	// (1) Generate random population of population_size
	Individual *population = generate_population(population_size, image->width, image->height, image->max_color);

	// (2) Compute ﬁtness of each individual in population
	comp_fitness_population(image->data, population, population_size);

	// (3) Sort individuals in non-decreasing order of ﬁtness
	qsort(population, population_size, sizeof(Individual), int_cmp);

	// (4) For each generation:
	for (int i = 0; i < num_generations; i++)
	{
		// (a) do crossover on population
		crossover(population, population_size);

		// (b) mutate population from 1/4 of population to end
		mutate_population(population, population_size, rate);

		// (c) compute ﬁtness of each individual
		comp_fitness_population(image->data, population, population_size);

		// (d) sort individuals in non-decreasing order of ﬁtness value
		qsort(population, population_size, sizeof(Individual), int_cmp);

		char file[20];
		sprintf(file, "%d.ppm", i);

		write_ppm(file, &population[0].image);

		// *********FOR TESTING*************
		printf("Generation: %d\n", i+1);
		// *********************************
	}

	// Create temporary PPM_IMAGE to store fittest image
	PPM_IMAGE *fittest = malloc(sizeof(PPM_IMAGE)); 
	fittest->width = image->width;
	fittest->height = image->height;
	fittest->max_color = image->max_color;
	fittest->data = population[0].image.data;

	// Free population data
	for (int i = 1; i < population_size; i++)
	{
		free(population[i].image.data);
	}

	// Free population
	free(population);
		
	// (5) Return pointer to ﬁttest image
	return fittest;
}

// Free memory allocated for image
void free_image(PPM_IMAGE *p)
{
	// Free PIXEL struct in image
	free(p->data);

	// Free image
	free(p);
}
