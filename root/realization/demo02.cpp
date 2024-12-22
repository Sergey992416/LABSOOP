#include "lab02.h"
#include <iostream>
namespace lab02 {
    void runDemo() {
        // Настройка кодировки консоли для работы с русским языком
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        int n;
        std::cout << "Введите количество элементов (n): ";
        std::cin >> n;

        if (n <= 0) {
            std::cout << "Количество элементов должно быть положительным.\n";
            
        }

        LinkedList list;
        double value;

        for (int i = 0; i < n; ++i) {
            std::cout << "Введите элемент " << i + 1 << ": ";
            std::cin >> value;
            list.append(value);
        }

        std::cout << "\nИсходный список:\n";
        list.printList();

        int insertPos = n / 2;

        list.insertAtPosition(0.0, insertPos);

        std::cout << "\nСписок после вставки 0 на позиции " << insertPos + 1 << ":\n";
        list.printList();

    }
}