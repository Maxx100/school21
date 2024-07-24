#include <math.h>
#include <stdio.h>

float func(float x) {
    float y = 0.007 * x * x * x * x;
    y += ((22.8 * cbrtf(x) - 1000) * x + 3) / (x * x / 2);
    y -= (float)pow(x * (10 + x), 2 / x);
    y -= 1.01;
    return y;
}

int main() {
    float x;
    if (scanf("%f", &x) != 1)
        printf("n/a\n");
    else
        printf("%0.1f\n", func(x));
    return 0;
}
