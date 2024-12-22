#include "lab72.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>// Для работы с файлами
namespace lab72 {
    void runDemo() {
        int i1, i2;
        char c1, c2;
        float f;
        std::cout << "Введите переменные в порядке: i1 c1 f i2 c2\n";
        std::cin >> i1 >> c1;

        // Считываем число f и заменяем ',' на '.'
        std::string f_str;
        std::cin >> f_str;
        std::replace(f_str.begin(), f_str.end(), ',', '.');
        f = std::stof(f_str);

        std::cin >> i2 >> c2;

        std::ofstream outFile("output.txt");

        // Параметры манипулятора
        int width = 7;
        int base = 16; // Шестнадцатеричная система счисления
        char fillChar = '*';

        // Лямбда-функция для форматирования и вывода переменных
        auto formatAndOutput = [&](auto value, int precision = 0) {
            std::ostringstream oss;

            if constexpr (std::is_same_v<decltype(value), int>) {
                // Обработка целого числа
                oss << Manip(width, base, 0, fillChar) << value;
            }
            else if constexpr (std::is_same_v<decltype(value), float>) {
                // Обработка числа с плавающей запятой
                std::string formattedFloat = floatToHex(value, precision);
                oss << std::setw(width) << std::setfill(fillChar) << formattedFloat;
            }
            else if constexpr (std::is_same_v<decltype(value), char>) {
                // Обработка символа
                oss << std::setw(width) << std::setfill(fillChar) << value;
            }

            // Вывод в консоль и файл
            std::cout << oss.str() << std::endl;
            outFile << oss.str() << std::endl;
        };

        // Последовательность вывода: c2 f i2 c1 i1
        formatAndOutput(c2);

        formatAndOutput(f, 2);
        formatAndOutput(f, 3);
        formatAndOutput(f, 2);
        formatAndOutput(i2);
        formatAndOutput(c1);
        formatAndOutput(i1);

        // Закрываем файл
        outFile.close();

       
    }
}