#include <math.h>
#include <stdio.h>

int main() {
    float a, b;
    if (scanf("%f %f", &a, &b) != 2) {
        printf("n/a\n");
    } else if (getchar() != '\n') {
        printf("n/a\n");
    } else {
        if (a * a + b * b - 25 < 0) {
            printf("GOTCHA\n");
        } else {
            printf("MISS\n");
        }
    }
    return 0;
}
