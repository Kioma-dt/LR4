#include <stdio.h>
#include <stdlib.h>

unsigned long long checkUnsignedLongFirst();
unsigned long long checkUnsignedLongSecond();
char checkSaper();
void solve();
void repeat();

int main(){
    printf("Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n");
    printf("Задание 5. На вход подаётся поле для игры в сапёр размером n на m символов, где символ '.' означает пустое место, а символ '*' - бомбу. Требуется дополнить это поле числами, как в оригинальной игре\n");
    printf("Решение: \n");
    solve();
    repeat();
}

void solve(){
    printf("Введите n и m:\n");
    unsigned long long n, m;
    n = checkUnsignedLongFirst();
    m = checkUnsignedLongSecond();

    printf("Введите поле для игры сапер:\n");
    char **field = malloc((n + 2) * sizeof(char *));
    for (int i = 0; i < n + 2; i++){
        field[i] = malloc((m + 2) * sizeof(char));
    }
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            field[i][j] = checkSaper();
        }
        if (getchar() != '\n'){
            printf("Строка должна содержать только %llu символов! Все лишние символы были удалены\n", m);
            while (getchar() !='\n');
        }
    }

    long long up, down, left, right, mines = 0;
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1;j++){
           if (field[i][j] == '.'){ 
                up = i + 1;
                down = i - 1;
                right = j + 1;
                left = j - 1;

                if (field[up][left] == '*'){
                    mines++;
                }
                if (field[up][j] == '*'){
                    mines++;
                }
                if (field[up][right] == '*'){
                    mines++;
                }
                if (field[i][right] == '*'){
                    mines++;
                }
                if (field[down][right] == '*'){
                    mines++;
                }
                if (field[down][j] == '*'){
                    mines++;
                }
                if (field[down][left] == '*'){
                    mines++;
                }
                if (field[i][left] == '*'){
                    mines++;
                }

                if (mines != 0){
                    field[i][j] = (char) 48 + mines;
                }
                mines = 0;
            }
        }
    }

    printf("\n");
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1;j++){
            printf("%c", field[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n + 2;i++){
        free(field[i]);
    }
    free(field);
}

char checkSaper(){
    char input;

    while (1){
        scanf("%c", &input);
        if (input == '.' || input == '*') {
            break;
        }

        printf("Неверный формат ввода! Введите строку занаво, начиная с неверно введенного символа\n");
        while (getchar() !='\n');
    }
}

unsigned long long checkUnsignedLongFirst(){
    unsigned long long input;
    char next;

    while (1){
        if (scanf("%llu", &input)){
            scanf("%c", &next);

            if (next == '\n' || next == ' '){
                break;
            }
        }

        printf("Неверный формат ввода!\n");
        while (getchar()!='\n');
    }

    return input;
}

unsigned long long checkUnsignedLongSecond(){
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