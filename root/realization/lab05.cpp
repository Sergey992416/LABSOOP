#include "lab05.h"
#include <math.h>
namespace lab05 {
    DATE::DATE(unsigned dd, month mm, unsigned yy) {
        if (Valid(dd, mm, yy)) {
            day = dd;
            mon = mm;
            year = yy;
        }
        else {
            day = 1;    // По умолчанию 1, если невалидная дата
            mon = jan;  // По умолчанию январь
            year = 2000; // По умолчанию 2000 год
        }
    }
    // Перегруженная функция Print с разделителем
    void DATE::Print(char smb) const {
        std::cout << (day < 10 ? "0" : "") << day << smb
            << (mon < 10 ? "0" : "") << mon << smb
            << year << std::endl;
    }
    // Перегруженная функция Print с форматом строки
    void DATE::Print(const char* format) const {
        if (format == nullptr) {
            // Если формат не задан, использовать разделитель '/'
            Print('/');
            return;
        }
        if (std::strcmp(format, "DD-MM-YYYY") == 0) {
            std::cout << (day < 10 ? "0" : "") << day << "-"
                << (mon < 10 ? "0" : "") << mon << "-"
                << year << std::endl;
        }
        else if (std::strcmp(format, "MM/DD/YYYY") == 0) {
            std::cout << (mon < 10 ? "0" : "") << mon << "/"
                << (day < 10 ? "0" : "") << day << "/"
                << year << std::endl;
        }
        else {
            // Неизвестный формат, использовать разделитель '/'
            Print('/');
        }
    }
    // Метод Sub для вычитания дат (принимает объект DATE)
    DATE DATE::Sub(const DATE& what) const {
        int new_day = static_cast<int>(day) - static_cast<int>(what.day);
        int new_mon = static_cast<int>(mon) - static_cast<int>(what.mon);
        int new_year = static_cast<int>(year) - static_cast<int>(what.year);
        // Корректировка, если значения отрицательные
        if (new_day < 1) {
            new_mon--;
            new_day += DaysInMonth(static_cast<month>(mon), year);
        }
        if (new_mon < 1) {
            new_year--;
            new_mon += 12;
        }
        if (new_year < 0) new_year = 0; // Минимальный год 0
        return DATE(static_cast<unsigned>(new_day),
            static_cast<month>(new_mon),
            static_cast<unsigned>(new_year));
    }
    // Перегруженный метод Sub (принимает отдельные параметры дня, месяца и года)
    DATE DATE::Sub(unsigned dd, month mm, unsigned yy) const {
        DATE other(dd, mm, yy);
        return Sub(other);
    }
    // Проверка на корректность даты
    bool DATE::Valid(unsigned dd, month mm, unsigned yy) const {
        if (yy >= 0 && mm >= jan && mm <= dek) {
            if (dd >= 1 && dd <= DaysInMonth(mm, yy)) {
                return true; // Дата валидна
            }
        }
        return false; // Дата не валидна
    }
    // Получение количества дней в месяце
    unsigned DATE::DaysInMonth(month mm, unsigned yy) const {
        switch (mm) {
        case jan: case mar: case may: case jul: case aug: case okt: case dek:
            return 31;
        case apr: case jun: case sep: case nov:
            return 30;
        case feb:
            return (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0)) ? 29 : 28; // Високосный год
        default:
            return 0; // Неверный месяц
        }
    }
    // Перегрузка оператора == для сравнения дат
    bool DATE::operator==(const DATE& other) const {
        return (day == other.day) &&
            (mon == other.mon) &&
            (year == other.year);
    }
    // Перегрузка оператора << для вывода даты
    std::ostream& operator<<(std::ostream& os, const DATE& date) {
        os << (date.day < 10 ? "0" : "") << date.day << "-"
            << (date.mon < 10 ? "0" : "") << date.mon << "-"
            << date.year;
        return os;
    }
}