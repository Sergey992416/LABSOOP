#include "lab01.h"
namespace lab01 {
	
    DATE::DATE(unsigned dd, month mm, unsigned yy) {
        if (Valid(dd, mm, yy)) {
            day = dd;
            mon = mm;
            year = yy;
        }
        else {
            day = 1;
            mon = jan;
            year = 2000;
        }
    }

    void DATE::Print(char smb) {
        std::cout << (day < 10 ? "0" : "") << day << smb
            << (mon < 10 ? "0" : "") << mon << smb
            << year << std::endl;
    }

    DATE DATE::Sub(const DATE& what) {
        unsigned new_day = this->day - what.day;
        unsigned new_mon = this->mon - what.mon;
        unsigned new_year = this->year - what.year;

        if (new_day < 1) {
            new_mon--;
            new_day += DaysInMonth(this->mon, this->year);
        }
        if (new_mon < 1) {
            new_year--;
            new_mon += 12;
        }

        return DATE(new_day, (month)new_mon, new_year);
    }

    unsigned DATE::Valid(unsigned dd, month mm, unsigned yy) {
        if (yy >= 0 && mm >= jan && mm <= dek) {
            if (dd >= 1 && dd <= DaysInMonth(mm, yy)) {
                return 1;
            }
        }
        return 0;
    }

    unsigned DATE::DaysInMonth(month mm, unsigned yy) {
        switch (mm) {
        case jan: case mar: case may: case jul: case aug: case okt: case dek:
            return 31;
        case apr: case jun: case sep: case nov:
            return 30;
        case feb:
            return (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0)) ? 29 : 28;
        default:
            return 0;
        }
    }
}
