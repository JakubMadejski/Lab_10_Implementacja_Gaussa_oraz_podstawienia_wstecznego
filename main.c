#include <stdio.h>
#include <stdlib.h>

#include "Implementacja_eliminacji_gaussa.h"
#include "Implementacja_podstawienia_wstecznego.h"

int main(void)
{
    int n = Wielkosc_macierzy();
    printf("Rozpoczynam program dla N = %d\n", n);

    double **A = przydzielanie_macierzy(n);
    double *b  = (double *)malloc(n * sizeof(double));
    double *x  = (double *)malloc(n * sizeof(double));

    if (!A || !b || !x) {
        fprintf(stderr, "Blad alokacji pamieci.\n");
        exit(EXIT_FAILURE);
    }

    /* Wczytywanie danych (kolega) */
    wczytywanie_danych(A, b, n);

    /* TWOJA CZĘŚĆ */
    eliminacja_gaussa(A, b, n);

    /* Sprawdzenie poprawności (opcjonalne, ale dobre) */
    sprawdzanie_czy_trojkat(A, n);

    /* CZĘŚĆ KOLEGI */
    podmiana_wsteczna(A, b, x, n);

    printf("\n--- Rozwiazanie ukladu ---\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }

    zwalnianie_pamieci(A, b, x, n);
    return 0;
}
