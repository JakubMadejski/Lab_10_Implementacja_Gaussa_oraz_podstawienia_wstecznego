#include "Implementacja_eliminacji_gaussa.h"

int wybor_elementu_glownego(double **A, int n, int k) {
    int pivot = k;
    double best = fabs(A[k][k]);

    for (int i = k + 1; i < n; i++) {
        double v = fabs(A[i][k]);
        if (v > best) {
            best = v;
            pivot = i;
        }
    }
    return pivot;
}

void zamien_wiersze(double **A, double *b, int w1, int w2, int n) {
    if (w1 == w2) return;

    double *tmpRow = A[w1];
    A[w1] = A[w2];
    A[w2] = tmpRow;

    double tmp = b[w1];
    b[w1] = b[w2];
    b[w2] = tmp;
}

int eliminacja_gaussa(double **A, double *b, int n) {
    for (int k = 0; k < n - 1; k++) {

        int pivot = wybor_elementu_glownego(A, n, k);
        if (fabs(A[pivot][k]) < EPSILON) {
            return 1;
        }
        zamien_wiersze(A, b, k, pivot, n);

        for (int i = k + 1; i < n; i++) {
            double m = A[i][k] / A[k][k];
            A[i][k] = 0.0;

            for (int j = k + 1; j < n; j++) {
                A[i][j] -= m * A[k][j];
            }
            b[i] -= m * b[k];
        }
    }

    if (fabs(A[n - 1][n - 1]) < EPSILON) {
        return 1;
    }

    return 0;
}
