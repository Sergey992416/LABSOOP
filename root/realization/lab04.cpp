#include "lab04.h"
#include <math.h>
namespace lab04 {
    DATE::DATE(unsigned int day, unsigned int mon, unsigned int year)
        : day(day), mon(mon), year(year) {}

    DATE::~DATE() {}

    void DATE::Print(char smb) const {
        printf("%02u%c%02u%c%04u\n", day, smb, mon, smb, year);
    }

    DATE DATE::Sub(const DATE& what) const {
        printf("Вычисление разности с использованием DATE::Sub\n");

        int res_day = day - what.day;
        int res_mon = mon - what.mon;
        int res_year = year - what.year;

        if (res_day < 0) {
            res_day += 30;
            res_mon -= 1;
        }
        if (res_mon < 0) {
            res_mon += 12;
            res_year -= 1;
        }

        return DATE(res_day, res_mon, res_year);
    }

    void DATE::PrintSub(const DATE& other, char smb) const {
        DATE diff = this->Sub(other);
        printf("Разность: %02u%c%02u%c%04u\n", diff.GetDay(), smb, diff.GetMonth(), smb, diff.GetYear());
    }

    // Реализация класса ExtendedDATE

    ExtendedDATE::ExtendedDATE(unsigned int day, unsigned int mon, unsigned int year,
        unsigned int hours, unsigned int minutes)
        : DATE(day, mon, year), hours(hours), minutes(minutes) {}

    ExtendedDATE::~ExtendedDATE() {}

    void ExtendedDATE::Print(char smb) const {
        printf("ExtendedDATE: %02u%c%02u%c%u %02u:%02u\n", day, smb, mon, smb, year, hours, minutes);
    }

    DATE ExtendedDATE::Sub(const DATE& what) const {
        printf("Вычисление разности с использованием ExtendedDATE::Sub\n");

        // Используем базовый метод для вычисления разницы дат
        DATE base_diff = DATE::Sub(what);

        int total_minutes_1 = hours * 60 + minutes;
        int total_minutes_2 = 0;

        // Если объект what — это тоже ExtendedDATE, выполняем преобразование
        if (const ExtendedDATE* extWhat = dynamic_cast<const ExtendedDATE*>(&what)) {
            total_minutes_2 = extWhat->hours * 60 + extWhat->minutes;
        }

        int time_diff = total_minutes_1 - total_minutes_2;

        if (time_diff < 0) {
            time_diff += 24 * 60; // Добавляем сутки
            base_diff = base_diff.Sub(DATE(1, 0, 0)); // Вычитаем 1 день через Sub
        }

        unsigned int new_hours = time_diff / 60;
        unsigned int new_minutes = time_diff % 60;
        return ExtendedDATE(base_diff.GetDay(), base_diff.GetMonth(), base_diff.GetYear(), new_hours, new_minutes);
    }
}