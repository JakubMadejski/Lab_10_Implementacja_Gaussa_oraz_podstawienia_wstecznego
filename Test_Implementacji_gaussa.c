#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Implementacja_eliminacji_gaussa.h"
#include "Implementacja_podstawienia_wstecznego.h"

#define EPS 1e-9

void wypisz_macierz(double **A, double *b, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.3f ", A[i][j]);
        }
        printf("| %8.3f\n", b[i]);
    }
    printf("\n");
}

int main(void)
{
    int n = 3;  

    double **A = przydzielanie_macierzy(n);
    double *b  = (double *)malloc(n * sizeof(double));

    if (!A || !b) {
        printf("Blad alokacji pamieci\n");
        return 1;
    }

    FILE *f = fopen("dane_test_gauss.txt", "r");
    if (!f) {
        printf("Nie mozna otworzyc pliku dane_test_gauss.txt\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(f, "%lf", &A[i][j]) != 1) {
                printf("Blad wczytywania macierzy A\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%lf", &b[i]) != 1) {
            printf("Blad wczytywania wektora b\n");
            return 1;
        }
    }

    fclose(f);

    printf("Macierz PRZED eliminacja Gaussa:\n");
    wypisz_macierz(A, b, n);

    eliminacja_gaussa(A, b, n);

    printf("Macierz PO eliminacji Gaussa:\n");
    wypisz_macierz(A, b, n);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (fabs(A[i][j]) > EPS) {
                printf("BLAD: A[%d][%d] = %lf (nie jest zero)\n", i, j, A[i][j]);
                return 1;
            }
        }
    }

    printf("TEST ZAKONCZONY SUKCESEM – macierz jest gornotrojkatna.\n");

    free(b);
    zwalnianie_pamieci(A, NULL, NULL, n);

    return 0;
}
