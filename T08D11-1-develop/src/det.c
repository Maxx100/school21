#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
void input(double **matrix, int *n, int *m);
void output(double det);

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n != m) {
        printf("n/a");
    } else {
        double **matrix = malloc(n * m * sizeof(double) + n * sizeof(double *));
        double *ptr = (double *)(matrix + n);
        for (int i = 0; i < n; i++) matrix[i] = ptr + m * i;
        input(matrix, &n, &m);
        output(det(matrix, n, m));
        free(matrix);
    }

    return 0;
}

double det(double **matrix, int n, int m) {
    double ans = 0;
    if (n == 1)
        ans = matrix[0][0];
    else {
        double **temp = malloc((n - 1) * (m - 1) * sizeof(double) + (n - 1) * sizeof(double *));
        double *ptr = (double *)(temp + n - 1);
        for (int i = 0; i < n - 1; i++) temp[i] = ptr + (m - 1) * i;
        for (int i = 0; i < n; i++) {
            for (int k1 = 0; k1 < n; k1++) {
                for (int k2 = 1; k1 != i && k2 < m; k2++) {
                    if (k1 < i)
                        temp[k1][k2 - 1] = matrix[k1][k2];
                    else
                        temp[k1 - 1][k2 - 1] = matrix[k1][k2];
                }
            }
            if (i % 2 == 0)
                ans += matrix[i][0] * det(temp, n - 1, m - 1);
            else
                ans -= matrix[i][0] * det(temp, n - 1, m - 1);
        }
        free(temp);
    }
    return ans;
}

void input(double **matrix, int *n, int *m) {
    for (int i = 0; i < *(n + 0); i++) {
        for (int j = 0; j < *(m + 0); j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void output(double det) { printf("%0.6lf", det); }
