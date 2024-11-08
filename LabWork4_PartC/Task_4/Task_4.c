#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long long checkMatrix();
unsigned long long checkMaxtrixLast();
unsigned long long checkUnsignedLong();
unsigned long long max(unsigned long long arg_1, unsigned long long arg_2);
unsigned long long sum(unsigned long long *d, unsigned long long n);
void print(unsigned long long * d, unsigned long long n);
void solve();
void repeat();


int main(){
    printf("Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n");
    printf("Задание 4. В трехмерном массиве n на n на n целых неотрицательных чисел найти диагональ с наибольшей суммой чисел\n");
    printf("Решение: \n");
    solve();
    repeat();
}

void solve(){
    unsigned long long n;
    printf("Введите n: ");
    n = checkUnsignedLong();

    unsigned long long ***a = malloc(n * sizeof(unsigned long long**));
    for (int i = 0; i < n; i++){
        a[i] = malloc(n * sizeof(unsigned long long*));
        for (int j = 0; j < n;j++){
            a[i][j] = malloc(n * sizeof(unsigned long long));
        }
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            for (int k = 0; k < n;k++){
                scanf("%llu", &a[i][j][k]);
            }
        }
    }
    printf("\n");

    printf("Введенный массив:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            for (int k = 0; k < n;k++){
                printf("%llu ",a[i][j][k]);
            }
        }
    }
    printf("\n");

    unsigned long long *d_1 = malloc(n * sizeof(unsigned long long));
    unsigned long long *d_2 = malloc(n * sizeof(unsigned long long));
    unsigned long long *d_3 = malloc(n * sizeof(unsigned long long));
    unsigned long long *d_4 = malloc(n * sizeof(unsigned long long));

    for (int i = 0, x = 0, y = 0, z = 0; i < n; i++){
        d_1[i] = a[x][y][z];
        x++;
        y++;
        z++;
    }
    for (int i = 0, x = 0, y = n - 1, z = 0; i < n; i++)
    {
        d_2[i] = a[x][y][z];
        x++;
        y--;
        z++;
    }
    for (int i = 0, x = 0, y = 0, z = n - 1; i < n; i++){
        d_3[i] = a[x][y][z];
        x++;
        y++;
        z--;
    }
    for (int i = 0, x = 0, y = n - 1, z = n - 1; i < n; i++){
        d_4[i] = a[x][y][z];
        x++;
        y--;
        z--;
    }

    unsigned long long sd_1 = sum(d_1, n), sd_2 = sum(d_2, n), sd_3 = sum(d_3, n), sd_4 = sum(d_4, n);
    unsigned long long max_d = max(sd_1, max(sd_2, max(sd_3, sd_4)));

    printf("Максимальная сумма чисел: %llu\n", max_d);
    printf("Диагонали с максимальной суммой чисел:\n");
    if (max_d == sd_1){
        print(d_1, n);
    }
    if (max_d == sd_2){
        print(d_2, n);
    }
    if (max_d == sd_3){
        print(d_3, n);
    }
    if (max_d == sd_4){
        print(d_4, n);
    }

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);
    free(d_1);
    free(d_2);
    free(d_3);
    free(d_4);
}

unsigned long long sum(unsigned long long *d, unsigned long long n){
    unsigned long long res = 0;
    for (int i = 0; i < n;i++){
        res += d[i];
    }

    return res;
}

unsigned long long max(unsigned long long arg_1, unsigned long long arg_2){
    return arg_1 > arg_2 ? arg_1 : arg_2;
}

void print(unsigned long long * d, unsigned long long n){
    for (int i = 0; i < n;i++){
        printf("%llu%c", d[i], ' ');
    }
    printf("\n");
}

unsigned long long checkUnsignedLong(){
    unsigned long long input;
    char next;

    while (1){
        if (scanf("%llu", &input)){
            scanf("%c", &next);
            while (next == ' '){
                scanf("%c", &next);
            }

            if (next == '\n'){
                break;
            }
        }

        printf("Неверный формат ввода! Необходими ввести целое неотрицательное число!\n");
        while (getchar()!='\n');
    }

    return input;
}

unsigned long long checkMatrix(){
    unsigned long long input;
    char next;

    while (1){
        if (scanf("%llu", &input)){
            scanf("%c", &next);
            while (next == ' '){
                scanf("%c", &next);
            }

            if (next == '\n' && next == ' '){
                break;
            }
        }

        printf("Неверный формат ввода! Элементы матрицы должны быть целыми неотрицательными числами! Введите масив занаво, начиная с неверно введенного элемента\n");
        while (getchar()!='\n');
    }

    return input;
}

unsigned long long checkMaxtrixLast(){
    unsigned long long input;
    char next;

    while (1){
        if (scanf("%llu", &input)){
            scanf("%c", &next);

            if (next == '\n'){
                break;
            }
        }

        printf("Неверный формат ввода! Элементы матрицы должны быть целыми неотрицательными числами! Введите занаво последний элемент массива\n");
        while (getchar()!='\n');
    }

    return input;
}

void repeat(){
    while (getchar()!='\n');
    printf("Повторить решение?(y/n)");
    char answer;
    scanf("%c", &answer);

    while (1){
        if (answer == 'y'){
            printf("----------------------\n");
            while (getchar()!='\n');
            main();
            break;
        }
        else if (answer == 'n'){
            break;
        }
        else {
            printf("Неверный символ!\n");
            while (getchar()!='\n');
            scanf("%c", &answer);
        }
    }
}