#pragma once

#include <stdint.h>
#include <stdbool.h>

/** Representa un puzzle de colores */
struct puzzle
{
	/** La matriz de colores, cada uno un número entre 0 y 7 */
	uint8_t** matrix;
	/** Ancho de la matriz */
	uint8_t width;
	/** Alto de la matriz*/
	uint8_t height;
};

/** Representa un puzzle de colores */
typedef struct puzzle Puzzle;

/** Lee un puzzle a partir de un stream */
Puzzle* puzzle_from_stream (void* stream);
/** Desplaza la fila especificada hacia la izquierda */
void    puzzle_shift_left  (Puzzle* puz, uint8_t row);
/** Desplaza la fila especificada hacia la derecha */
void    puzzle_shift_right (Puzzle* puz, uint8_t row);
/** Desplaza la columna especificada hacia arriba */
void    puzzle_shift_up    (Puzzle* puz, uint8_t col);
/** Desplaza la columna especificada hacia abajo */
void    puzzle_shift_down  (Puzzle* puz, uint8_t col);
/** Indica si dos puzzles son equivalentes */
bool    puzzle_equals      (Puzzle* a, Puzzle* b);
/** Libera los recursos asociados a un  puzzle */
void    puzzle_destroy     (Puzzle* puzzle);
/** Imprime el puzzle a un stream determinado */
int     puzzle_print       (Puzzle* puzzle, void* stream);

/** Funciones de desplazamiento */
typedef void (*shift_fn_t)(Puzzle*,uint8_t);
