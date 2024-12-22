#pragma once
#include <iostream>

#include <iomanip>
#include <string>
namespace lab72 {
	void runDemo();
    class Manip {
    public:
        Manip(int w, int b, int p, char f);

        friend std::ostream& operator<<(std::ostream& os, const Manip& m);

    private:
        int width;      // Ширина вывода
        int base;       // Система счисления
        int precision;  // Точность
        char fill;      // Заполняющий символ
    };

    // Функция для конвертации числа с плавающей запятой в шестнадцатиричную систему счисления
    std::string floatToHex(double num, int precision);
}
