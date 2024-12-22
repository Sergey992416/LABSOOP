#include "lab72.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>// ��� ������ � �������
namespace lab72 {
    void runDemo() {
        int i1, i2;
        char c1, c2;
        float f;
        std::cout << "������� ���������� � �������: i1 c1 f i2 c2\n";
        std::cin >> i1 >> c1;

        // ��������� ����� f � �������� ',' �� '.'
        std::string f_str;
        std::cin >> f_str;
        std::replace(f_str.begin(), f_str.end(), ',', '.');
        f = std::stof(f_str);

        std::cin >> i2 >> c2;

        std::ofstream outFile("output.txt");

        // ��������� ������������
        int width = 7;
        int base = 16; // ����������������� ������� ���������
        char fillChar = '*';

        // ������-������� ��� �������������� � ������ ����������
        auto formatAndOutput = [&](auto value, int precision = 0) {
            std::ostringstream oss;

            if constexpr (std::is_same_v<decltype(value), int>) {
                // ��������� ������ �����
                oss << Manip(width, base, 0, fillChar) << value;
            }
            else if constexpr (std::is_same_v<decltype(value), float>) {
                // ��������� ����� � ��������� �������
                std::string formattedFloat = floatToHex(value, precision);
                oss << std::setw(width) << std::setfill(fillChar) << formattedFloat;
            }
            else if constexpr (std::is_same_v<decltype(value), char>) {
                // ��������� �������
                oss << std::setw(width) << std::setfill(fillChar) << value;
            }

            // ����� � ������� � ����
            std::cout << oss.str() << std::endl;
            outFile << oss.str() << std::endl;
        };

        // ������������������ ������: c2 f i2 c1 i1
        formatAndOutput(c2);

        formatAndOutput(f, 2);
        formatAndOutput(f, 3);
        formatAndOutput(f, 2);
        formatAndOutput(i2);
        formatAndOutput(c1);
        formatAndOutput(i1);

        // ��������� ����
        outFile.close();

       
    }
}