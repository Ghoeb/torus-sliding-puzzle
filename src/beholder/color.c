#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "color.h"

#define UPPER 0.75
#define LOWER 0.15

/** Inicializa un color dentro de los márgenes establecidos */
Color color_init(uint8_t R, uint8_t G, uint8_t B)
{
	Color c;
	c.R = (((double)(R))/255.0) * (UPPER - LOWER) + LOWER;
	c.G = (((double)(G))/255.0) * (UPPER - LOWER) + LOWER;
	c.B = (((double)(B))/255.0) * (UPPER - LOWER) + LOWER;
	return c;
}

/** Inicializa la tabla de 8 colores */
Color* color_table()
{
	Color* table = calloc(8, sizeof(Color));

	table[0] = color_init(0,0,0);
	table[1] = color_init(0,0,255);
	table[2] = color_init(0,255,0);
	table[3] = color_init(0,255,255);
	table[4] = color_init(255,0,0);
	table[5] = color_init(255,0,255);
	table[6] = color_init(255,255,0);
	table[7] = color_init(255,255,255);

	// uint8_t r,g,b;
	//
	// for(uint8_t i = 0; i < 8; i++)
	// {
	// 	fscanf(stdin, "%hhu %hhu %hhu", &r, &g, &b);
	// 	table[i] = color_init(r, g, b);
	// }

	return table;
}
