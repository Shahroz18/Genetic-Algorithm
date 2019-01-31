#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

// Select n pixels at random and set random values for RGB values of pixels
void mutate(Individual *individual, double rate)
{
	// Calculate image size
	int n = individual->image.width * individual->image.height;

	// Mutate randomly, specified amount of pixels
	for (int i = 0; i < (int)((rate / 100) * n); i++)
	{
		// Choose random pixel to mutate
		int j = rand() % n;

		// Mutate pixel by giving it random RGB values
		individual->image.data[j].r = rand() % individual->image.max_color;
		individual->image.data[j].g = rand() % individual->image.max_color;
		individual->image.data[j].b = rand() % individual->image.max_color;
	}
}

// Mutate population from 1/4 of population to end
void mutate_population(Individual *individual, int population_size, double rate)
{
	for (int i = population_size / 4; i < population_size; i++)
		mutate(&individual[i], rate);
}