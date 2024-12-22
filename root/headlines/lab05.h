#pragma once
#include <stdio.h>
#include <iostream>
namespace lab05 {
	void runDemo();
    class DATE {
    public:
        // ������������ ��� ������������� �������
        enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };
        // �����������
        DATE(unsigned dd = 1, month mm = jan, unsigned yy = 2000);
        // ������������� ������� Print
        void Print(char smb) const;
        void Print(const char* format) const;
        // ������������� ������ Sub
        DATE Sub(const DATE& what) const;
        DATE Sub(unsigned dd, month mm, unsigned yy) const;
        // ���������� ����������
        bool operator==(const DATE& other) const;
        friend std::ostream& operator<<(std::ostream& os, const DATE& date);
    private:
        unsigned day, year;
        month mon;
        // �������� �� ���������� �������� ����
        bool Valid(unsigned dd, month mm, unsigned yy) const;
        // ������� ��� ��������� ���������� ���� � ������
        unsigned DaysInMonth(month mm, unsigned yy) const;
    };

}