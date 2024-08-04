#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n < 1 || m < 1) {
        printf("n/a");
    } else {
        int **matrix, **result;
        matrix = malloc(n * m * sizeof(int) + n * sizeof(int *));
        int *ptr = (int *)(matrix + n);
        for (int i = 0; i < n; i++) matrix[i] = ptr + m * i;
        result = malloc(n * m * sizeof(int) + n * sizeof(int *));
        int *ptr2 = (int *)(result + n);
        for (int i = 0; i < n; i++) result[i] = ptr2 + m * i;

        input(matrix, &n, &m);

        sort_vertical(matrix, n, m, result);
        output(result, n, m);
        printf("\n\n");
        sort_horizontal(matrix, n, m, result);
        output(result, n, m);
        free(matrix);
        free(result);
    }
    return 0;
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *way = malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            way[i * m + j] = matrix[i][j];
        }
    }
    for (int i = 0; i < n * m - 1; i++) {
        for (int j = 0; j < n * m - 1; j++) {
            if (way[j] > way[j + 1]) {
                way[j] += way[j + 1];
                way[j + 1] = way[j] - way[j + 1];
                way[j] -= way[j + 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j % 2 == 0)
                result_matrix[i][j] = way[j * n + i];
            else
                result_matrix[n - i - 1][j] = way[j * n + i];
        }
    }
    free(way);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *way = malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            way[i * m + j] = matrix[i][j];
        }
    }
    for (int i = 0; i < n * m - 1; i++) {
        for (int j = 0; j < n * m - 1; j++) {
            if (way[j] > way[j + 1]) {
                way[j] += way[j + 1];
                way[j + 1] = way[j] - way[j + 1];
                way[j] -= way[j + 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 2 == 0)
                result_matrix[i][j] = way[i * m + j];
            else
                result_matrix[i][m - j - 1] = way[i * m + j];
        }
    }
    free(way);
}

void input(int **matrix, int *n, int *m) {
    for (int i = 0; i < *(n + 0); i++) {
        for (int j = 0; j < *(m + 0); j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0) printf(" ");
            printf("%d", matrix[i][j]);
        }
        if (i != n - 1) printf("\n");
    }
}
/*
./check.sh electro_snake.c "3 3\n1 2 3\n4 5 6\n7 8 9"
3 3
1 2 3
4 5 6
7 8 9

*/
