#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int max(int a, int b);

int main() {
    int mode, n1, m1, n2, m2;
    int flag = -1;
    if (scanf("%d", &mode) != 1 || mode < 1 || mode > 3)
        flag = -1;
    else if (scanf("%d%d", &n1, &m1) != 2)
        flag = -1;
    else {
        int **data1 = malloc(max(n1, m1) * max(n1, m1) * sizeof(int) + max(n1, m1) * sizeof(int *));
        int *ptr1 = (int *)(data1 + max(n1, m1));
        for (int i = 0; i < max(n1, m1); i++) data1[i] = ptr1 + max(n1, m1) * i;

        if (input(data1, &n1, &m1) != 0)
            flag = -1;
        else if (mode != 3 && scanf("%d%d", &n2, &m2) != 2)
            flag = -1;
        else {
            if (mode == 3) {
                transpose(data1, n1, m1);
                flag = 0;
                output(data1, m1, n1);
            } else {
                int **data2 = malloc(n2 * m2 * sizeof(int) + n2 * sizeof(int *));
                int *ptr2 = (int *)(data2 + n2);
                for (int i = 0; i < n2; i++) data2[i] = ptr2 + m2 * i;

                if (input(data2, &n2, &m2) != 0)
                    flag = -1;
                else {
                    int nr, mr;
                    if (mode == 1) {
                        int **result = malloc(n1 * m1 * sizeof(int) + n1 * sizeof(int *));
                        int *ptr = (int *)(result + n1);
                        for (int i = 0; i < n1; i++) result[i] = ptr + m1 * i;

                        if (sum(data1, n1, m1, data2, n2, m2, result, &nr, &mr) != 0)
                            flag = -1;
                        else {
                            flag = 0;
                            output(result, n1, m1);
                        }
                        free(result);
                    } else {
                        int **result = malloc(n1 * m2 * sizeof(int) + n1 * sizeof(int *));
                        int *ptr = (int *)(result + n1);
                        for (int i = 0; i < n1; i++) result[i] = ptr + m2 * i;

                        if (mul(data1, n1, m1, data2, n2, m2, result, &nr, &mr) != 0)
                            flag = -1;
                        else {
                            flag = 0;
                            output(result, n1, m2);
                        }
                        free(result);
                    }
                }
                free(data2);
            }
        }
        free(data1);
    }
    if (flag == -1) printf("n/a");
    return 0;
}

int input(int **matrix, int *n, int *m) {
    int flag = *(n + 0) - *n + *(m + 0) - *m;
    for (int i = 0; i < *n && flag == 0; i++) {
        for (int j = 0; j < *m && flag == 0; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) flag = -1;
        }
    }
    return flag;
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    int flag = 0;
    if (n_first != n_second || m_first != m_second)
        flag = -1;
    else {
        for (int i = 0; i < n_first; i++) {
            for (int j = 0; j < m_first; j++) {
                matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
            }
        }
    }
    *n_result = n_first;
    *m_result = m_first;
    return flag;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    int flag = 0;
    if (m_first != n_second)
        flag = -1;
    else {
        for (int i = 0; i < n_first; i++) {
            for (int j = 0; j < m_second; j++) {
                matrix_result[i][j] = 0;
                for (int k = 0; k < m_first; k++)
                    matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
    *n_result = n_first;
    *m_result = m_second;
    return flag;
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int transpose(int **matrix, int n, int m) {
    for (int i = 0; i < max(n, m); i++) {
        for (int j = i + 1; j < max(n, m); j++) {
            matrix[i][j] += matrix[j][i];
            matrix[j][i] = matrix[i][j] - matrix[j][i];
            matrix[i][j] -= matrix[j][i];
        }
    }
    return 0;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0) printf(" ");
            printf("%d", matrix[i][j]);
        }
        if (i < n - 1) printf("\n");
    }
}
