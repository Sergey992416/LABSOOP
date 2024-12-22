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
        int width;      // ������ ������
        int base;       // ������� ���������
        int precision;  // ��������
        char fill;      // ����������� ������
    };

    // ������� ��� ����������� ����� � ��������� ������� � ����������������� ������� ���������
    std::string floatToHex(double num, int precision);
}
