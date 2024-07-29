#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n) {
    char end = '\n';
    if (scanf("%d", n) != 1 || getchar() != '\n') return -1;
    if (*n > NMAX) return -1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            return -1;
        } else {
            end = getchar();
            if (end != ' ' && end != '\n') return -1;
        }
    }
    if (end != '\n') return -1;
    return 0;
}

double mean(int *a, int n) {
    double temp = 0;
    for (int *i = a; i - a < n; i++) {
        temp += *i;
    }
    return temp / n;
}

double variance(int *a, int n) {
    double temp = 0;
    double mn = mean(a, n);
    for (int *i = a; i - a < n; i++) {
        temp += (*i - mn) * (*i - mn);
    }
    return temp / n;
}

int search(int *a, int n) {
    double mn = mean(a, n);
    for (int *i = a; i - a < n; i++) {
        if (*i % 2 == 1) continue;
        if (*i < mn) continue;
        if (*i > mn + 3 * sqrt(variance(a, n))) continue;
        if (*i == 0) continue;
        return *i;
    }
    return 0;
}

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1 || n < 0) {
        printf("n/a");
        return 0;
    }
    if (n == 0) return 0;
    printf("%d", search(data, n));
    return 0;
}

/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
