#include "lab06.h"

namespace lab06 {
    void workWithIntegers() {
        int n;
        std::cout << "Введите количество целых чисел: ";
        std::cin >> n;
        Sequence<int> intSeq;
        std::cout << "Введите " << n << " целых чисел:\n";
        for (int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            intSeq.addElement(num);
        }
        double M, L, N;
        std::cout << "Введите значения M, L, N: ";
        std::cin >> M >> L >> N;

        int count = intSeq.countElements(M, L, N);
        std::cout << "Количество целых чисел, больших " << M
            << " и не в промежутке [" << L << ", " << N << "]: "
            << count << "\n\n";
    }
    // Функция для работы с комплексными числами
    void workWithComplex() {
        int n;
        std::cout << "Введите количество комплексных чисел: ";
        std::cin >> n;

        Sequence<Complex> complexSeq;
        std::cout << "Введите " << n << " комплексных чисел:\n";
        for (int i = 0; i < n; ++i) {
            Complex c;
            std::cout << "Комплексное число " << i + 1 << ":\n";
            c.input();
            complexSeq.addElement(c);
        }
        double M, L, N;
        std::cout << "Введите значения M, L, N для мнимой части: ";
        std::cin >> M >> L >> N;
        int count = complexSeq.countElements(M, L, N);
        std::cout << "Количество комплексных чисел, у которых мнимая часть больше "
            << M << " и не в промежутке [" << L << ", " << N << "]: "
            << count << "\n\n";

    }

    void runDemo() {
        int choice;
        do {
            std::cout << "Выберите тип последовательности:\n";
            std::cout << "1. Целые числа\n";
            std::cout << "2. Комплексные числа\n";
            std::cout << "0. Выход\n";
            std::cout << "Ваш выбор: ";
            std::cin >> choice;
            switch (choice) {
            case 1:
                workWithIntegers();
                break;
            case 2:
                workWithComplex();
                break;
            case 0:
                std::cout << "Завершение программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n\n";
            }

        } while (choice != 0);

        
    


       

	}
}

