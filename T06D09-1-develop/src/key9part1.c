/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

int input(int *buffer, int *length);
void output(int *buffer, int length, int sum);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[10], new[10], len_new = 0;
    if (input(data, &n) == -1) {
        printf("n/a");
        return 0;
    }
    int sum = sum_numbers(data, n);
    len_new = find_numbers(data, n, sum, new);
    output(new, len_new, sum);
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (*(buffer + i) % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int *pos = numbers;
    for (int i = 0; i < length; i++) {
        if (*(buffer + i) != 0 && number % buffer[i] == 0) {
            *pos = buffer[i];
            pos++;
        }
    }
    return pos - numbers;
}

int input(int *a, int *n) {
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
    return 0;
}

void output(int *a, int n, int sum) {
    printf("%d\n", sum);
    for (int *i = a; i - a < n; i++) {
        if (i != a) printf(" ");
        printf("%d", *i);
    }
}
