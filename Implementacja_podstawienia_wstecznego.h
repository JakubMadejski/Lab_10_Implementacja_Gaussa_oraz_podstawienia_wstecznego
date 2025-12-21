#ifndef MOJE_FUNKCJE_H
#define MOJE_FUNKCJE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-9

int Wielkosc_macierzy();
double** przydzielanie_macierzy(int n);
void zwalnianie_pamieci(double **A, double *b, double *x, int n);
void sprawdzanie_czy_trojkat(double **A, int n);
void podmiana_wsteczna(double **A, double *b, double *x, int n);
void wczytywanie_danych(double **A, double *b, int n);

#endif