#include "gauss.h"
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int i, j, c, r, maxr;
	c = 0;
	r = 0;
	double x;
	const double EPS = 1e-12;
	while (r < mat->r - 1 && c < mat->c) {
		//new pivot
		maxr = r;
		if (fabs(mat->data[maxr][c]) < EPS) {
			return 1;
		}
		if (maxr != r) {
			for (j = c; j < mat->c; j++) {
				double tmp;
				tmp = mat->data[r][j];
				mat->data[r][j] = mat->data[maxr][j];
				mat->data[maxr][j] = tmp;
			}
			double tmpb;
			tmpb = b->data[r][0];
			b->data[r][0] = b->data[maxr][0];
			b->data[maxr][0] = tmpb;
		}
		for (i = r + 1; i < mat->r; i++) {
			if (fabs(mat->data[r][c]) > EPS) {
				x = mat->data[i][c] / mat->data[r][c];
				for (j = 0; j < mat->c; j++) {
					mat->data[i][j] -= x * mat->data[r][j];
				}
				b->data[i][0] -= x * b->data[r][0];
			}
		}
		r++;
		c++;
	}
		return 0;
}
