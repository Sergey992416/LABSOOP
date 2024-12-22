#pragma once
#include <iostream>
namespace lab71 {
	void runDemo();
    class DATE {
    public:
        enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

        // Конструктор
        DATE(unsigned dd = 1, month mm = jan, unsigned yy = 2000);

        // Метод для вычисления разности
        DATE Sub(const DATE& what) const;

        // Операторы ввода и вывода
        friend std::ostream& operator<<(std::ostream& os, const DATE& date);
        friend std::istream& operator>>(std::istream& is, DATE& date);

    private:
        unsigned day, year;
        month mon;

        // Проверка валидности даты
        bool Valid(unsigned dd, month mm, unsigned yy) const;

        // Количество дней в месяце
        unsigned DaysInMonth(month mm, unsigned yy) const;
    };

}