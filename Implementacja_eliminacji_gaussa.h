#ifndef IMPLEMENTACJA_ELIMINACJI_GAUSSA_H
#define IMPLEMENTACJA_ELIMINACJI_GAUSSA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef EPSILON
#define EPSILON 1e-9
#endif

int wybor_elementu_glownego(double **A, int n, int k);
void zamien_wiersze(double **A, double *b, int w1, int w2, int n);

int eliminacja_gaussa(double **A, double *b, int n);

#endif
