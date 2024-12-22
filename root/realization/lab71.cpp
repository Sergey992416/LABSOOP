#include "lab71.h"
#include <iostream>
#include <iomanip> 
namespace lab71 {
    // �����������
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

    // ����� ��� ���������� �������� ���� ���
    DATE DATE::Sub(const DATE& what) const {
        int d1 = day, m1 = static_cast<int>(mon), y1 = year; // ������� ����
        int d2 = what.day, m2 = static_cast<int>(what.mon), y2 = what.year; // ������ ����

        // ���������� ��� � ���� �������
        if (d1 < d2) {
            if (m1 == 1) {
                m1 = 12;
                y1 -= 1;
            }
            else {
                m1 -= 1;
            }
            d1 += DaysInMonth(static_cast<month>(m1), y1);
        }

        if (m1 < m2) {
            y1 -= 1;
            m1 += 12;
        }

        // ��������� ������� �� ����, ������� � �����
        int diff_day = d1 - d2;
        int diff_month = m1 - m2;
        int diff_year = y1 - y2;

        return DATE(diff_day, static_cast<month>(diff_month), diff_year);
    }

    // �������� �� ������������ ����
    bool DATE::Valid(unsigned dd, month mm, unsigned yy) const {
        if (yy >= 0 && mm >= jan && mm <= dek) {
            if (dd >= 1 && dd <= DaysInMonth(mm, yy)) {
                return true;
            }
        }
        return false;
    }

    // ������� ��� ��������� ���������� ���� � ������
    unsigned DATE::DaysInMonth(month mm, unsigned yy) const {
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

    // ��������������� ��������� ������ <<
    std::ostream& operator<<(std::ostream& os, const DATE& date) {
        os << std::setw(2) << std::setfill('0') << date.day << '.'
            << std::setw(2) << std::setfill('0') << static_cast<unsigned>(date.mon) << '.'
            << date.year;
        return os;
    }

    // ��������������� ��������� ����� >>
    std::istream& operator>>(std::istream& is, DATE& date) {
        unsigned dd, mm, yy;
        char sep1, sep2;

        is >> dd >> sep1 >> mm >> sep2 >> yy;

        if (sep1 == '.' && sep2 == '.') {
            DATE temp(dd, static_cast<DATE::month>(mm), yy);
            if (temp.Valid(dd, static_cast<DATE::month>(mm), yy)) {
                date = temp;
            }
            else {
                std::cerr << "������� ���������� ����. ����������� �������� �� ���������.\n";
                date = DATE();
            }
        }
        else {
            std::cerr << "�������� ������ ����� ����. ��������� ������ DD.MM.YYYY.\n";
            is.setstate(std::ios::failbit);
        }

        return is;
    }

}