#pragma once
#include <stdio.h>
#include <iostream>
namespace lab05 {
	void runDemo();
    class DATE {
    public:
        // Перечисление для представления месяцев
        enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };
        // Конструктор
        DATE(unsigned dd = 1, month mm = jan, unsigned yy = 2000);
        // Перегруженные функции Print
        void Print(char smb) const;
        void Print(const char* format) const;
        // Перегруженные методы Sub
        DATE Sub(const DATE& what) const;
        DATE Sub(unsigned dd, month mm, unsigned yy) const;
        // Перегрузка операторов
        bool operator==(const DATE& other) const;
        friend std::ostream& operator<<(std::ostream& os, const DATE& date);
    private:
        unsigned day, year;
        month mon;
        // Проверка на корректные значения даты
        bool Valid(unsigned dd, month mm, unsigned yy) const;
        // Функция для получения количества дней в месяце
        unsigned DaysInMonth(month mm, unsigned yy) const;
    };

}