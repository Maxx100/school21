#include <stdio.h>
#define NMAX 10

int temp[10];

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

void merge(int *a, int l, int mid, int r) {
    int *it1 = a + l, *it2 = a + mid;
    while (it1 < a + mid && it2 < a + r) {
        if (*it1 < *it2) {
            temp[it1 - a + it2 - a - mid] = *it1;
            it1++;
        } else {
            temp[it1 - a + it2 - a - mid] = *it2;
            it2++;
        }
    }
    while (it1 < a + mid) {
        temp[it1 - a + it2 - a - mid] = *it1;
        it1++;
    }
    while (it2 < a + r) {
        temp[it1 - a + it2 - a - mid] = *it2;
        it2++;
    }

    for (int *i = a + l; i < a + r; i++) {
        *i = temp[i - a];
    }
}

void merge_sort(int *a, int n, int l, int r) {
    if (r - l < 2) return;
    int mid = (l + r) / 2;
    merge_sort(a, n, l, mid);
    merge_sort(a, n, mid, r);
    merge(a, l, mid, r);
}

void sort1(int *a, int n) { merge_sort(a, n, 0, n); }

int part(int *a, int l, int r) {
    int mid = a[(l + r) / 2];
    int i1 = l, i2 = r;
    while (i1 <= i2) {
        while (a[i1] < mid) i1++;
        while (a[i2] > mid) i2--;
        if (i1 >= i2) break;
        a[i1] += a[i2];
        a[i2] = a[i1] - a[i2];
        a[i1] -= a[i2];
        i1++;
        i2--;
    }
    return i2;
}

void sort2(int *a, int n, int l, int r) {
    if (r - l > 1) {
        int mid = part(a, l, r);
        sort2(a, n, l, mid);
        sort2(a, n, mid + 1, r);
    }
}

int main() {
    int n = 10, data[NMAX];
    if (input(data, n) == -1) {
        printf("n/a");
        return 0;
    }
    // merge sort
    sort1(data, n);
    output(data, n);
    printf("\n");
    // optimized quick sort
    sort2(data, n, 0, n);
    output(data, n);

    return 0;
}
