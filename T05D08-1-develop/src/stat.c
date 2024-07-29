#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1 || n < 0) {
        printf("n/a");
        return 0;
    }
    if (n == 0) return 0;
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int max(int *a, int n) {
    int temp = *a;
    for (int *i = a; i - a < n; i++) {
        if (temp < *i) temp = *i;
    }
    return temp;
}

int min(int *a, int n) {
    int temp = *a;
    for (int *i = a; i - a < n; i++) {
        if (temp > *i) temp = *i;
    }
    return temp;
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
    printf("\n");
}

void output_result(int max_v, int min_v, double mean_v, double var) {
    printf("%d %d %lf %lf", max_v, min_v, mean_v, var);
}
