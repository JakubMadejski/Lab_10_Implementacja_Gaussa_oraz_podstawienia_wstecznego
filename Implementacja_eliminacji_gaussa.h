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

/* Robi eliminację Gaussa (przekształca A do postaci trójkątnej górnej)
   i modyfikuje też wektor b.
   Zwraca 0 gdy ok, 1 gdy macierz osobliwa (brak jednoznacznego rozwiązania). */
int eliminacja_gaussa(double **A, double *b, int n);

#endif
