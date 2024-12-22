#pragma once
#include <iostream>
namespace lab71 {
	void runDemo();
    class DATE {
    public:
        enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

        // �����������
        DATE(unsigned dd = 1, month mm = jan, unsigned yy = 2000);

        // ����� ��� ���������� ��������
        DATE Sub(const DATE& what) const;

        // ��������� ����� � ������
        friend std::ostream& operator<<(std::ostream& os, const DATE& date);
        friend std::istream& operator>>(std::istream& is, DATE& date);

    private:
        unsigned day, year;
        month mon;

        // �������� ���������� ����
        bool Valid(unsigned dd, month mm, unsigned yy) const;

        // ���������� ���� � ������
        unsigned DaysInMonth(month mm, unsigned yy) const;
    };

}