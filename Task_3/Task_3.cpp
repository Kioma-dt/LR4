#include <iostream>

unsigned long long checkUnsignedLong();
long double checkDouble();
long double checkLast();
void solve();
void repeat();


int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\nВариант 1\n";
    std::cout << "Задание 3. В матрице n на n найти максимальный и минимальный элементы, и поменять местами строки, на которых они находятся\n";
    std::cout << "Решение: \n";
    solve();
    repeat();
}

void solve(){
    unsigned long long n;
    std::cout << "Введите n:";
    n = checkUnsignedLong();

    long double **a = new long double *[n];
    for (int i = 0; i < n;i++){
        a[i] = new long double[n];
    }
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++)
            if (i == n - 1 && j == n - 1){
                a[i][j] = checkLast();
            }
            else {
                a[i][j] = checkDouble();
            }
    }

    long double max = a[0][0], min = a[0][0];
    long long i_max = 0, i_min = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            if (a[i][j] > max){
                max = a[i][j];
                i_max = i;
            }
            if (a[i][j] < min){
                min = a[i][j];
                i_min = i;
            }
        }
    }

    std::cout << "Введенная матрица:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            std::cout << a[i][j] << '\t';
        }
        std::cout << '\n';
    }

    std::cout << "Максимальный элемент матрицы: " << max << "\tМинимальный элемент матрицы: " << min << '\n';
    if (i_max == i_min)
        std::cout << "Максимальный и минимальный элементы находятся в одной строке!\n";
    else{
        for (int j = 0; j < n;j++){
            std::swap(a[i_max][j], a[i_min][j]);
        }
    }

    std::cout << "Преобразованная матрица:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            std::cout << a[i][j] << '\t';
        }
        std::cout << '\n';
    }

    for (int i = 0; i < n; i++){
            delete[] a[i];
    }
    delete[] a;
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
        std::cout << "Неверный формат ввода! Необходими ввести целое неотрицательное число!\n";
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
        std::cout << "Неверный формат ввода! Элементы матрицы должны быть числами! Введите матрицу занаво, начиная с неверно введенного элемента\n";
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
        std::cout << "Неверный формат ввода! Элементы матрицы должны быть числами! Введите занаво последний элемент матрицы\n";
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