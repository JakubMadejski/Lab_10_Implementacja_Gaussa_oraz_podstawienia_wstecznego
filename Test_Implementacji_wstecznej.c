#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Implementacja_podstawienia_wstecznego.h"

int main() {
    printf("=== Test implementacji podstawienia wstecznego ===\n");
    printf("=== Test 1: Test wczytywania danych (wybierz opcje 2) ===\n");

    int n = 3;
    double **A = przydzielanie_macierzy(n);
    double *b = (double*)malloc(n * sizeof(double));
    double *x = (double*)malloc(n * sizeof(double));
    wczytywanie_danych(A, b, n);
    printf("Wczytane dane:\n");
    printf("Macierz A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
    }
    printf("\n");
    printf("Wektor b: ");
    for (int i = 0; i < n; i++) {
        printf("%lf ", b[i]);
    }
    printf("\n");
    if (A[0][0] != 2.0 || A[0][1] != 1.0 || A[0][2] != -1.0 ||
        A[1][0] != 0.0 || A[1][1] != 0.5 || A[1][2] != 0.5 ||
        A[2][0] != 0.0 || A[2][1] != 0.0 || A[2][2] != -1.0 ||
        b[0] != 8.0 || b[1] != 1.0 || b[2] != -1.0) {
        fprintf(stderr, "Blad: Wczytane dane nie zgadzaja sie z oczekiwanymi wartosciami.\n");
        zwalnianie_pamieci(A, b, x, n);
        exit(EXIT_FAILURE);
    }
    printf("=== Test zakonczony, dane wczytane poprawnie  ===\n");
    printf("=== TEst 2: Test sprawdzania trojkatnosci macierzy ===\n");
    sprawdzanie_czy_trojkat(A, n);
    printf("Macierz jest trojkatna gorna.\n");
    printf("=== Test zakonczony, trojkatnosc macierzy dziala poprawnie ===\n");
    printf("\n");    
    printf("=== Test 3: Test podstawienia wstecznego ===\n");
    podmiana_wsteczna(A, b, x, n);
    printf("Obliczone rozwiazanie:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }
    if (fabs(x[0] - 3.0) > 1e-6 || fabs(x[1] - 1.0) > 1e-6 || fabs(x[2] - 1.0) > 1e-6) {
        fprintf(stderr, "Blad: Obliczone rozwiazanie nie zgadza sie z oczekiwanymi wartosciami.\n");
        zwalnianie_pamieci(A, b, x, n);
        exit(EXIT_FAILURE);
    }
    printf("=== Test zakonczony, podstawienie wstecznego dziala poprawnie ===\n");
    zwalnianie_pamieci(A, b, x, n);
    return 0;


    
    


}