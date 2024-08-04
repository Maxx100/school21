#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n) {
    int flag = 0;
    for (int *p = a; flag == 0 && p - a < n; p++) {
        if (scanf("%d", p) != 1) flag = -1;
    }
    char end = getchar();
    if (end != '\n' && (int)end != -1) flag = -1;
    return flag;
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
    int n;
    int flag = 0;
    if (scanf("%d", &n) != 1)
        flag = -1;
    else {
        char end = getchar();
        if ((int)end != -1 && end != '\n' && end != ' ') flag = -1;
    }
    if (flag == 0) {
        int *data = malloc(n * sizeof(int));
        if (data == NULL || input(data, n) == -1)
            printf("n/a");
        else {
            sort(data, n);
            output(data, n);
            free(data);
        }
    } else {
        printf("n/a");
    }
    return 0;
}
