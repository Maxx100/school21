#include <stdio.h>

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2)
        printf("n/a\n");
    else if (getchar() != '\n')
        printf("n/a\n");
    else
        printf("%d\n", max(a, b));
    return 0;
}
