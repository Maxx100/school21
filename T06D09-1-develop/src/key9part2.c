#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

int input(int *a, int *n) {
    char end = ' ';
    while (end != '\n') {
        if (scanf("%d", a + *n) != 1) {
            return -1;
        }
        if (*(a + *n) > 9) return -1;
        end = getchar();
        if (end != ' ' && end != '\n') {
            return -1;
        }
        if (*n != 0 || *(a + *n) != 0) *n += 1;
    }

    return 0;
}

void output(int *buff, int len) {
    if (len == -1)
        printf("n/a");
    else if (len == 0)
        printf("0");
    else {
        for (int i = 0; i < len; i++) {
            if (i != 0) printf(" ");
            printf("%d", *(buff + i));
        }
    }
}

int main() {
    int buff1[LEN], n1 = 0;
    int buff2[LEN], n2 = 0;
    int buff3[LEN], n3 = 0;
    int buff4[LEN], n4 = 0;
    if (input(buff1, &n1) == -1 || input(buff2, &n2) == -1) {
        printf("n/a");
        return 0;
    }
    sum(buff1, n1, buff2, n2, buff3, &n3);
    sub(buff1, n1, buff2, n2, buff4, &n4);
    output(buff3, n3);
    printf("\n");
    output(buff4, n4);
    return 0;
}

void mv_left(int *buff, int len) {
    for (int i = LEN - 1; i >= 0; i--) {
        if (LEN - i - 1 < len)
            *(buff + i) = *(buff + i - LEN + len);
        else
            *(buff + i) = 0;
    }
}

void mv_right(int *buff, int len) {
    for (int i = 0; i < LEN; i++) {
        if (i < len)
            *(buff + i) = *(buff + LEN + i - len);
        else
            *(buff + i) = 0;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    mv_left(buff1, len1);
    mv_left(buff2, len2);
    if (len1 < len2) {
        *result_length = -1;
        return;
    } else if (len1 == len2) {
        int temp = 0;
        while (*(buff1 + temp) == *(buff2 + temp) && temp < LEN) temp++;
        if (temp < LEN && *(buff1 + temp) < *(buff2 + temp)) {
            *result_length = -1;
            return;
        }
    }
    int iter = LEN - 1;
    int mem = 0;
    while (iter >= 0) {
        *(result + iter) = (*(buff1 + iter) - *(buff2 + iter) - mem);
        if (*(result + iter) < 0) {
            *(result + iter) += 10;
            mem = 1;
        } else {
            mem = 0;
        }
        iter--;
    }
    *result_length = LEN - 1;
    while (*result_length > 0 && *(result + LEN - *result_length) == 0) *result_length -= 1;
    mv_right(result, *result_length);
    mv_right(buff1, len1);
    mv_right(buff2, len2);
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    mv_left(buff1, len1);
    mv_left(buff2, len2);

    int iter = LEN - 1;
    int mem = 0;
    while (iter >= 0) {
        *(result + iter) = (mem + *(buff1 + iter) + *(buff2 + iter)) % 10;
        if (mem + *(buff1 + iter) + *(buff2 + iter) > 9)
            mem = 1;
        else
            mem = 0;
        iter--;
    }

    *result_length = LEN - 1;
    while (*result_length > 0 && *(result + LEN - *result_length) == 0) *result_length -= 1;
    mv_right(result, *result_length);
    mv_right(buff1, len1);
    mv_right(buff2, len2);
}
