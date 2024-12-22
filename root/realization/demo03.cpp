#include "lab03.h"
#include <iostream>
namespace lab03 {
    // Функция для ввода данных
    

    void runDemo() {
        int N;
        std::cout << "Введите количество чисел N: ";
        std::cin >> N;
        if (N <= 0) {
            std::cout << "N должно быть положительным числом.\n";
          
        }
        UniqueNumbers un(N);
        std::cout << "Введите " << N << " чисел:\n";
        for (int i = 0; i < N; ++i) {
            int num;
            std::cin >> num;
            un.setNumber(i, num);
        }
        int* tempUnique = new int[N];
        int uniqueCount = un.findUnique(tempUnique);
        std::cout << "Числа, встречающиеся единожды:\n";
        if (uniqueCount > 0) {
            for (int i = 0; i < uniqueCount; ++i) {
                std::cout << tempUnique[i] << ' ';
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "Нет уникальных чисел.\n";
        }
        delete[] tempUnique;

    }
}
