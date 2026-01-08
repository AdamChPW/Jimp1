#include "backsubst.h"
#include <stdio.h>

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	
	if((mat->c != mat-> r) || (x->r != b->r) || (mat->c != x->r)){
		fprintf(stderr,"backsubst.c: [2] Niespojne rozmiary macierzy.");
		return 2;
	}

	int i = 0;
	int point = mat -> r - 1;
	int toSub = 0;

	while(point >= 0)
	{
		if(mat->data[point][point] == 0){
			fprintf(stderr,"backsubst.c: [1] Element zerowy na diagonali (Blad dzielenia przez 0).");
			return 1;
		}

		for( i = 0; i<toSub; i++){
			b->data[point][0] -= mat->data[point][point + 1 + i] * b->data[point + 1 + i][0];
		}

		b -> data[point][0] /= mat -> data [point][point];
		mat->data[point][point] = 1;

		point--;
		toSub++;
	}

	for (i =0; i < x->r; i++) {
		x->data[i][0] = b->data[i][0];
	}
	return 0;
}


