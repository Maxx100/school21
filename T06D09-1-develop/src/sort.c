#include <stdio.h>
#define NMAX 10

int input(int *a, int n) {
    char end = '\n';
    for (int *p = a; p - a < n; p++) {
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
    for (int *i = a; i - a < n; i++) {
        if (i != a) printf(" ");
        printf("%d", *i);
    }
}

void sort(int *a, int n) {
    for (int *i = a; i - a < n - 1; i++) {
        for (int *j = a; j - a < n - 1; j++) {
            if (*j > *(j + 1)) {
                *j += *(j + 1);
                *(j + 1) = *j - *(j + 1);
                *j -= *(j + 1);
            }
        }
    }
}

int main() {
    int n = 10, data[NMAX];
    if (input(data, n) == -1) {
        printf("n/a");
        return 0;
    }
    sort(data, n);
    output(data, n);

    return 0;
}
