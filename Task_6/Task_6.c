#include <stdio.h>
#include <stdlib.h>

unsigned long long checkUnsignedLong();
void swap(unsigned long long* a, unsigned long long* b);
void odd(unsigned long long **magSquare, unsigned long long n, long long number);
void doubly_even(unsigned long long **magSquare, unsigned long long n);
void singly_even(unsigned long long **magSquare, unsigned long long n);
void solve();
void repeat();

int main(){
    printf("Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n");
    printf("Задание 6. Вывести магический квадрат размера n на n\n");
    printf("Решение: \n");
    solve();
    repeat();
}

void solve(){
    printf("Введите n:\n");
    unsigned long long n;
    scanf("%llu", &n);
    unsigned long long **magSquare = malloc(sizeof(unsigned long long *) * n);
    for (unsigned long long i = 0; i < n; i++){
        magSquare[i] = malloc(sizeof(unsigned long long) * n);
    }

    if (n % 2 == 1){
        odd(magSquare, n, 1);
    }
    else if (n % 4 == 0){
        doubly_even(magSquare, n);
    }
    else{
        singly_even(magSquare, n);
    }

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            printf("%llu\t", magSquare[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n;i++){
        free(magSquare[i]);
    }
    free(magSquare);
}

void odd(unsigned long long **magSquare, unsigned long long n, long long number){
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            magSquare[i][j] = 0;
        }
    }

    long long i = 0, j = n / 2, next_i = 0, next_j = 0, end = n * n + number - 1;
    while (number <= end){
        magSquare[i][j] = number;
        number++;
        next_i = i - 1;
        next_j = j + 1;
        if (next_i < 0){
            next_i = n - 1;
        }
        if (next_j >= n){
            next_j = 0;
        }
        if (magSquare[next_i][next_j] == 0){
            i = next_i;
            j = next_j;
        }
        else {
            i = (i + 1) % n;
        }
    }
}

void doubly_even(unsigned long long **magSquare, unsigned long long n){
    long long number = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            magSquare[i][j] = number;
            number++;
        }
    }

    // Up Left
    for (int i = 0; i < n / 4;i++){
        for (int j = 0; j < n / 4;j++){
            magSquare[i][j] = n * n - magSquare[i][j] + 1;
        }
    }
    // Up Right
    for (int i = 3 * n / 4; i < n;i++){
        for (int j = 0; j < n / 4;j++){
            magSquare[i][j] = n * n - magSquare[i][j] + 1;
        }
    }
    // Down Left
    for (int i = 0; i < n / 4;i++){
        for (int j = 3 * n / 4; j < n;j++){
            magSquare[i][j] = n * n - magSquare[i][j] + 1;
        }
    }
    // Down Right
    for (int i = 3 * n / 4; i < n;i++){
        for (int j = 3 * n / 4; j < n;j++){
            magSquare[i][j] = n * n - magSquare[i][j] + 1;
        }
    }
    //Centre
    for (int i = n / 4; i < 3 * n / 4;i++){
        for (int j = n / 4; j < 3 * n / 4;j++){
            magSquare[i][j] = n * n - magSquare[i][j] + 1;
        }
    }
}

void singly_even(unsigned long long **magSquare, unsigned long long n){
    unsigned long long **sub_magSquare = malloc(sizeof(unsigned long long *) * n / 2);
    for (unsigned long long i = 0; i < n/2;i++){
        sub_magSquare[i] = malloc(sizeof(unsigned long long) * n / 2);
    }
    // Up Left
    odd(magSquare, n / 2, 1);
    // Down Right
    odd(sub_magSquare, n / 2, n * n / 4 + 1);
    for (int i = 0; i < n / 2;i++){
        for (int j = 0; j < n / 2;j++){
            magSquare[i + n / 2][j + n / 2] = sub_magSquare[i][j];
        }
    }
    // Up Right
    odd(sub_magSquare, n / 2, n * n / 2 + 1);
    for (int i = 0; i < n / 2;i++){
        for (int j = 0; j < n / 2;j++){
            magSquare[i][j + n / 2] = sub_magSquare[i][j];
        }
    }
    // Down Left
    odd(sub_magSquare, n / 2, 3 * n * n / 4 + 1);
    for (int i = 0; i < n / 2;i++){
        for (int j = 0; j < n / 2;j++){
            magSquare[i + n / 2][j] = sub_magSquare[i][j];
        }
    }

    for (int i = 0; i < n / 2;i++){
        for (int j = 0; j < n / 4;j++){
            if (j == 0 && i == n / 4){
                swap(&magSquare[i][j + n / 4], &magSquare[i + n / 2][j + n / 4]);
            }
            else {
                swap(&magSquare[i][j], &magSquare[i + n / 2][j]);
            }
        }
    }

    for (int i = 0; i < n / 2;i++){
        for (int j = n - (n / 4 - 1); j < n / 4; j++){
                swap(&magSquare[i][j], &magSquare[i + n / 2][j]);
        }
    }

    for (int i = 0; i < n / 2;i++){
        free(sub_magSquare[i]);
    }
    free(sub_magSquare);
}

void swap(unsigned long long* a, unsigned long long* b){
    unsigned long long c;
    c = *a;
    *a = *b;
    *b = c;
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

        printf("Неверный формат ввода!\n");
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