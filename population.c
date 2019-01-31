#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

// Return pointer to array of width * height random pixels
PIXEL *generate_random_image(int width, int height, int max_color)
{
	// Initialize list of PIXELS
	PIXEL *list = malloc(width * height * sizeof(PIXEL));

	// Set RGB values to random integers between 0 and max_color
	for (int i = 0; i < width * height; i++)
	{
		list[i].r = rand() % max_color;
		list[i].g = rand() % max_color;
		list[i].b = rand() % max_color;
	}

	// Return pointer to list
	return list;
}

// Return pointer to array of size population_size
Individual *generate_population(int population_size, int width, int height, int max_color)
{
	// Initialize list of Individuals
	Individual *population = malloc(population_size * sizeof(Individual));

	// Assign each Individual it's values
	for (int i = 0; i < population_size; i++)
	{
		population[i].image.width = width;
		population[i].image.height = height;
		population[i].image.max_color = max_color;
		population[i].image.data = generate_random_image(width, height, max_color);
	}

	// Return pointer to list
	return population;
}

