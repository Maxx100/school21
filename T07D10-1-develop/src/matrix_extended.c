#include <stdio.h>
#include <stdlib.h>

int input_static(int a[100][100], int n, int m) {
    int flag = 0;
    for (int i = 0; i < n && flag == 0; i++) {
        for (int j = 0; j < m && flag == 0; j++)
            if (scanf("%d", &a[i][j]) != 1) flag = -1;
    }
    char end = getchar();
    if (end != '\n' && (int)end != -1) flag = -1;
    return flag;
}

void output_static(int a[100][100], int n, int m, int nmax[], int mmin[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0) printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", nmax[i]);
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        if (i != 0) printf(" ");
        printf("%d", mmin[i]);
    }
}

int input(int **a, int n, int m) {
    int flag = 0;
    for (int i = 0; i < n && flag == 0; i++) {
        for (int j = 0; j < m && flag == 0; j++) {
            if (scanf("%d", &a[i][j]) != 1) flag = -1;
        }
    }
    char end = getchar();
    if (end != '\n' && (int)end != -1) flag = -1;
    return flag;
}

void output(int **a, int n, int m, int nmax[], int mmin[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0) printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", nmax[i]);
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        if (i != 0) printf(" ");
        printf("%d", mmin[i]);
    }
}

void mode1(int n, int m, int *flag) {
    int data[100][100];
    if (input_static(data, n, m) == -1)
        *flag = -1;
    else {
        int nmax[n], mmin[m];
        for (int i = 0; i < n; i++) {
            int temp = data[i][0];
            for (int j = 0; j < m; j++)
                if (temp < data[i][j]) temp = data[i][j];
            nmax[i] = temp;
        }
        for (int i = 0; i < m; i++) {
            int temp = data[0][i];
            for (int j = 0; j < n; j++)
                if (temp > data[j][i]) temp = data[j][i];
            mmin[i] = temp;
        }
        output_static(data, n, m, nmax, mmin);
    }
}

void mode2(int n, int m, int *flag) {
    int **data = malloc(n * m * sizeof(int) + n * sizeof(int *));
    int *ptr = (int *)(data + n);
    for (int i = 0; i < n; i++) data[i] = ptr + m * i;
    if (input(data, n, m) == -1)
        *flag = -1;
    else {
        int nmax[n], mmin[m];
        for (int i = 0; i < n; i++) {
            int temp = data[i][0];
            for (int j = 0; j < m; j++)
                if (temp < data[i][j]) temp = data[i][j];
            nmax[i] = temp;
        }
        for (int i = 0; i < m; i++) {
            int temp = data[0][i];
            for (int j = 0; j < n; j++)
                if (temp > data[j][i]) temp = data[j][i];
            mmin[i] = temp;
        }
        output(data, n, m, nmax, mmin);
    }
    free(data);
}

void mode3(int n, int m, int *flag) {
    int **data = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) data[i] = malloc(m * sizeof(int));
    if (input(data, n, m) == -1)
        *flag = -1;
    else {
        int nmax[n], mmin[m];
        for (int i = 0; i < n; i++) {
            int temp = data[i][0];
            for (int j = 0; j < m; j++)
                if (temp < data[i][j]) temp = data[i][j];
            nmax[i] = temp;
        }
        for (int i = 0; i < m; i++) {
            int temp = data[0][i];
            for (int j = 0; j < n; j++)
                if (temp > data[j][i]) temp = data[j][i];
            mmin[i] = temp;
        }
        output(data, n, m, nmax, mmin);
    }
    for (int i = 0; i < n; i++) free(data[i]);
    free(data);
}

void mode4(int n, int m, int *flag) {
    int **data = malloc(n * sizeof(int *));  // links
    int *ptr = malloc(n * m * sizeof(int));  // storage
    for (int i = 0; i < n; i++) data[i] = ptr + m * i;
    if (input(data, n, m) == -1)
        *flag = -1;
    else {
        int nmax[n], mmin[m];
        for (int i = 0; i < n; i++) {
            int temp = data[i][0];
            for (int j = 0; j < m; j++)
                if (temp < data[i][j]) temp = data[i][j];
            nmax[i] = temp;
        }
        for (int i = 0; i < m; i++) {
            int temp = data[0][i];
            for (int j = 0; j < n; j++)
                if (temp > data[j][i]) temp = data[j][i];
            mmin[i] = temp;
        }
        output(data, n, m, nmax, mmin);
    }
    free(ptr);
    free(data);
}

int main() {
    printf("1. Static\n2. Dynamic (One buffer)\n");
    printf("3. Dynamic (Links to each string)\n");
    printf("4. Dynamic (Links to each string in one buffer)\n");
    int mode, n, m;
    int flag = 0;
    if (scanf("%d", &mode) != 1 || mode < 1 || mode > 4)
        flag = -1;
    else if (scanf("%d%d", &n, &m) != 2)
        flag = -1;
    else {
        char end = getchar();
        if ((int)end != -1 && end != '\n' && end != ' ')
            flag = -1;
        else {
            if (mode == 1) mode1(n, m, &flag);
            if (mode == 2) mode2(n, m, &flag);
            if (mode == 3) mode3(n, m, &flag);
            if (mode == 4) mode4(n, m, &flag);
        }
    }
    if (flag != 0) printf("n/a");
    return 0;
}
