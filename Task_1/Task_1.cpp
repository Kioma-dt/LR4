#include <iostream>

unsigned long long checkUnsignedLong();
long double checkDouble();
long double checkLast();
void solve();
void repeat();

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\nВариант 1\n";
    std::cout << "Задание 1. Перенести все отрицательные элементы массива из k чисел в начало, сохраняя исходное взаимное расположение как среди отрицательных, так и среди положительных\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve (){
    std::cout << "Введите k: ";
    unsigned long long k;
    k = checkUnsignedLong();

    std::cout << "Введите массив: ";
    long double a[1000];
    long long l = 0;
    for (int i = 0; i < k;i++){
        if (i == k - 1){
            a[i] = checkLast();
        }
        else {
            a[i] = checkDouble();
        }
    }
    
    std::cout << "Введенный массив:\n";
    for (int i = 0; i < k; i++){
        std::cout << a[i] << '\t';
    }
    
    for (int i = 0; i < k; i++){
        if (a[i] < 0){
            for (int j = i; j > l;j--){
                std::swap(a[j], a[j - 1]);
            }
            l++;
        }
    }


    std::cout << "\nПреобразованный массив:\n";
    for (int i = 0; i < k; i++){
        std::cout << a[i] << '\t';
    }
    std::cout << '\n';
}

unsigned long long checkUnsignedLong(){
    unsigned long long input;
    char next;

    while (true){
        if (std::cin >> input){
            std::cin.get(next);
            while (next == ' '){
               std::cin.get(next); 
            }

            if (next == '\n'){
                break;
            }
        }

        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Неверный формат ввода! Необходими ввести целое неотрицательное число! \n";
    }

    return input;
}

long double checkDouble(){
    long double input;
    char next;

    while (true){
        if (std::cin >> input){
            std::cin.get(next);

            if (next == '\n' || next == ' '){
                break;
            }
        }

        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Неверный формат ввода! Элементы массива должны быть числами! Введите массив занаво, начиная с неверно введенного элемента\n";
    }
    return input;
}

long double checkLast(){
    long double input;
    char next;

    while (true){
        if (std::cin >> input){
            std::cin.get(next);
            while (next == ' '){
               std::cin.get(next); 
            }

            if (next == '\n'){
                break;
            }
        }

        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Неверный формат ввода! Элементы массива должны быть числами! Введите занаво последний элемент массива\n";
    }
    return input;
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