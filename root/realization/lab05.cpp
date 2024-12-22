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
            day = 1;    // �� ��������� 1, ���� ���������� ����
            mon = jan;  // �� ��������� ������
            year = 2000; // �� ��������� 2000 ���
        }
    }
    // ������������� ������� Print � ������������
    void DATE::Print(char smb) const {
        std::cout << (day < 10 ? "0" : "") << day << smb
            << (mon < 10 ? "0" : "") << mon << smb
            << year << std::endl;
    }
    // ������������� ������� Print � �������� ������
    void DATE::Print(const char* format) const {
        if (format == nullptr) {
            // ���� ������ �� �����, ������������ ����������� '/'
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
            // ����������� ������, ������������ ����������� '/'
            Print('/');
        }
    }
    // ����� Sub ��� ��������� ��� (��������� ������ DATE)
    DATE DATE::Sub(const DATE& what) const {
        int new_day = static_cast<int>(day) - static_cast<int>(what.day);
        int new_mon = static_cast<int>(mon) - static_cast<int>(what.mon);
        int new_year = static_cast<int>(year) - static_cast<int>(what.year);
        // �������������, ���� �������� �������������
        if (new_day < 1) {
            new_mon--;
            new_day += DaysInMonth(static_cast<month>(mon), year);
        }
        if (new_mon < 1) {
            new_year--;
            new_mon += 12;
        }
        if (new_year < 0) new_year = 0; // ����������� ��� 0
        return DATE(static_cast<unsigned>(new_day),
            static_cast<month>(new_mon),
            static_cast<unsigned>(new_year));
    }
    // ������������� ����� Sub (��������� ��������� ��������� ���, ������ � ����)
    DATE DATE::Sub(unsigned dd, month mm, unsigned yy) const {
        DATE other(dd, mm, yy);
        return Sub(other);
    }
    // �������� �� ������������ ����
    bool DATE::Valid(unsigned dd, month mm, unsigned yy) const {
        if (yy >= 0 && mm >= jan && mm <= dek) {
            if (dd >= 1 && dd <= DaysInMonth(mm, yy)) {
                return true; // ���� �������
            }
        }
        return false; // ���� �� �������
    }
    // ��������� ���������� ���� � ������
    unsigned DATE::DaysInMonth(month mm, unsigned yy) const {
        switch (mm) {
        case jan: case mar: case may: case jul: case aug: case okt: case dek:
            return 31;
        case apr: case jun: case sep: case nov:
            return 30;
        case feb:
            return (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0)) ? 29 : 28; // ���������� ���
        default:
            return 0; // �������� �����
        }
    }
    // ���������� ��������� == ��� ��������� ���
    bool DATE::operator==(const DATE& other) const {
        return (day == other.day) &&
            (mon == other.mon) &&
            (year == other.year);
    }
    // ���������� ��������� << ��� ������ ����
    std::ostream& operator<<(std::ostream& os, const DATE& date) {
        os << (date.day < 10 ? "0" : "") << date.day << "-"
            << (date.mon < 10 ? "0" : "") << date.mon << "-"
            << date.year;
        return os;
    }
}