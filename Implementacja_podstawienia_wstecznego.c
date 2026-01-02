#include "Implementacja_podstawienia_wstecznego.h"

int Wielkosc_macierzy() {
    int n;
    char buffer[100];

    printf("Podaj rozmiar macierzy N (wcisnij ENTER dla domyslnego N=3): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (buffer[0] == '\n') {
            return 3;
        }
        n = atoi(buffer);
        if (n <= 0) {
            fprintf(stderr, "Blad: Rozmiar macierzy musi byc dodatni.\n");
            exit(EXIT_FAILURE);
        }
        return n;
    }
    return 3;
}

double** przydzielanie_macierzy(int n) {
    double **macierz = (double**)malloc(n * sizeof(double*));
    if (macierz == NULL) {
        fprintf(stderr, "Blad alokacji pamieci dla wierszy.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        macierz[i] = (double*)malloc(n * sizeof(double));
        if (macierz[i] == NULL) {
            fprintf(stderr, "Blad alokacji pamieci dla kolumn.\n");
            exit(EXIT_FAILURE);
        }
    }
    return macierz;
}

void zwalnianie_pamieci(double **A, double *b, double *x, int n) {
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);
}

void sprawdzanie_czy_trojkat(double **A, int n) {
    for (int i = 1; i < n; i++) {     
        for (int j = 0; j < i; j++) { 
            if (fabs(A[i][j]) > EPSILON) {
                fprintf(stderr, "BLAD: Macierz nie jest trojkatna gorna!\n");
                fprintf(stderr, "Znaleziono niezerowy element A[%d][%d] = %lf\n", i, j, A[i][j]);
                exit(EXIT_FAILURE);
            }
        }
    }
}


void podmiana_wsteczna(double **A, double *b, double *x, int n) {
    for (int i = n - 1; i >= 0; i--) {
        
        if (fabs(A[i][i]) < EPSILON) {
            fprintf(stderr, "BLAD KRYTYCZNY: Zero na przekatnej w wierszu %d.\n", i);
            fprintf(stderr, "Dzielenie przez zero jest niemozliwe. Program zakonczony.\n");
            exit(EXIT_FAILURE);
        }

        double sum = b[i];
        for (int j = i + 1; j < n; j++) {
            sum -= A[i][j] * x[j];
        }

        x[i] = sum / A[i][i];
    }
}

void wczytywanie_danych(double **A, double *b, int n) {
    int choice;
    char buffer[100];
    
    printf("\nWybierz zrodlo danych:\n");
    printf("1. Wpisanie reczne\n");
    printf("2. Wczytanie z pliku (np. dane.txt)\n");
    printf("Wybor: ");
    
    if (fgets(buffer, sizeof(buffer), stdin)) {
        choice = atoi(buffer);
    } else {
        choice = 1;
    }

    if (choice == 2) {
        char filename[100];
        printf("Podaj nazwe pliku: ");
        if (scanf("%99s", filename) != 1) {
             fprintf(stderr, "Blad odczytu nazwy pliku.\n");
             exit(EXIT_FAILURE);
        }

        FILE *f = fopen(filename, "r");
        if (f == NULL) {
            perror("Nie mozna otworzyc pliku");
            exit(EXIT_FAILURE);
        }

        printf("Wczytywanie macierzy A (%dx%d)...\n", n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (fscanf(f, "%lf", &A[i][j]) != 1) {
                    fprintf(stderr, "Blad: Plik zawiera za malo danych dla macierzy A.\n");
                    fclose(f); exit(EXIT_FAILURE);
                }
            }
        }
        
        printf("Wczytywanie wektora b (%d elementow)...\n", n);
        for (int i = 0; i < n; i++) {
            if (fscanf(f, "%lf", &b[i]) != 1) {
                fprintf(stderr, "Blad: Plik zawiera za malo danych dla wektora b.\n");
                fclose(f); exit(EXIT_FAILURE);
            }
        }
        fclose(f);

    } else {
        printf("\n--- Wprowadzanie macierzy A ---\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("A[%d][%d]: ", i, j);
                scanf("%lf", &A[i][j]);
            }
        }

        printf("\n--- Wprowadzanie wektora b ---\n");
        for (int i = 0; i < n; i++) {
            printf("b[%d]: ", i);
            scanf("%lf", &b[i]);
        }
    }
}

