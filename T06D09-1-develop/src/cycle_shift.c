#include <stdio.h>

int input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void shifting(int *buffer, int length, int shift);

int main() {
    int n, data[10], shift;
    if (input(data, &n, &shift) == -1) {
        printf("n/a");
        return 0;
    }
    shifting(data, n, shift);
    output(data, n);
}

void shifting(int *buffer, int length, int shift) {
    int temp[10];
    for (int i = 0; i < length; i++) {
        temp[(i - (shift % length) + length) % length] = *(buffer + i);
    }
    for (int i = 0; i < length; i++) buffer[i] = temp[i];
}

int input(int *a, int *n, int *shift) {
    if (scanf("%d", n) != 1) return -1;
    if (getchar() != '\n') return -1;
    char end = '\n';
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
    if (scanf("%d", shift) != 1) return -1;
    if (getchar() != '\n') return -1;
    return 0;
}

void output(int *a, int n) {
    for (int *i = a; i - a < n; i++) {
        if (i != a) printf(" ");
        printf("%d", *i);
    }
}
