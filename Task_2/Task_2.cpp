#include <iostream>

void solve();
void repeat();

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\nВариант 1\n";
    std::cout << "Задание 2. Определить количество положительных элементов ниже побочной диагонали в матрице m на n\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    unsigned long long m = 3, n = 4;
    long long a[200][200] = {{3, 4, -4, 2},{ -3, -10, 15, 22}, {33, -4, -5, 1}};

    long long k = 0;
    for (int i = 0; i < m;i++){
        for (int j = n - 1; j >= 0; j--){
            if (i + j <= m - 1){
                break;
            }
            if (a[i][j] > 0){
                k++;
            }    
        }
    }

    std::cout << "m = " << m << "\tn = " << n << '\n' << "Матрица:\n";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n;j++){
            std::cout << a[i][j] << '\t';
        }
        std::cout << '\n';
    }
    std::cout << "Количество положительных элементов ниже побочной диагонали: " << k << '\n';
}

void repeat(){
    std::cout << "Повторить решение?(y/n) ";
    char answer;
    std::cin >> answer;

    while (true){
        if (answer == 'y'){
            std::cout << "----------------------\n";
            std::cin.ignore(10000,'\n');
            main();
            break;
        }
        else if (answer == 'n'){
            break;
        }
        else {
            std::cout << "Неверный символ!\n";
            std::cin.ignore(10000,'\n');
            std::cin >> answer;
        }
    }
}