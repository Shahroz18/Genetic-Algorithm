#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

// Reads PPM image ﬁle and return pointer to PPM_IMAGE structure containing pixels of image, width, height, and max color
PPM_IMAGE *read_ppm(const char *file_name)
{
	// Open file for reading
	FILE *f = fopen(file_name, "r");

	// Initialize and allocate memory for PPM_IMAGE structure
	PPM_IMAGE *image = malloc(sizeof(PPM_IMAGE));

	// Store first line in random variable, since not needed
	char useless[2];
	fscanf(f, "%s", useless);

	// Read in important values at start of file
	fscanf(f, "%d", &image->width);
	fscanf(f, "%d", &image->height);
	fscanf(f, "%d", &image->max_color);

	// Initialize list of PIXEL structures, read in values and store in list
	PIXEL *list = malloc(image->width * image->height * sizeof(PIXEL));
	for (int i = 0; i < image->width * image->height; i++)
		fscanf(f, "%hhu %hhu %hhu", &list[i].r, &list[i].g, &list[i].b);

	// Set PPM_IMAGE structure data to point to list of PIXELS
	image->data = list;

	// Close file
	fclose(f);

	// Return pointer to PPM_IMAGE structure
	return image;
}

// Write PPM_IMAGE structure into ﬁle in PPM format
void write_ppm(const char *file_name, const PPM_IMAGE *image)
{
	// Open file for writing
	FILE *f = fopen(file_name, "w");

	// Write important values to start of file
	fprintf(f, "P3\n");
	fprintf(f, "%d %d\n", image->width, image->height);
	fprintf(f, "%d\n", image->max_color);

	// Write pixels to file
	for (int i = 0; i < image->width * image->height; i++)
		fprintf(f, "%hhu %hhu %hhu ", image->data[i].r, image->data[i].g, image->data[i].b);

	// Close file
	fclose(f);
}