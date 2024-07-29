#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1 || n < 0) {
        printf("n/a");
        return 0;
    }
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    char end = '\n';
    if (scanf("%d", n) != 1 || getchar() != '\n') {
        return -1;
    }
    if (*n > NMAX) {
        *n = NMAX;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            return -1;
        } else {
            end = getchar();
            if (end != ' ' && end != '\n') {
                return -1;
            }
        }
    }
    if (end != '\n') {
        return -1;
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}
