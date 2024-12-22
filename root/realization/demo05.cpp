#include "lab05.h"
namespace lab05 {
	void runDemo() {

        DATE date1(15, DATE::aug, 2023);
        DATE date2(10, DATE::jul, 2021);
        // ���������� ������������� ������� Print
        std::cout << "���� 1 (����������� '/'): ";
        date1.Print('/');
        std::cout << "���� 2 (������ DD-MM-YYYY): ";
        date2.Print("DD-MM-YYYY");

        std::cout << "���� 1 (������ MM/DD/YYYY): ";
        date1.Print("MM/DD/YYYY");
        // ���������� ���� � ������� �������������� ��������� ==
        if (date1 == date2) {
            std::cout << "���� 1 � ���� 2 ���������.\n";
        }
        else {
            std::cout << "���� 1 � ���� 2 �����������.\n";
        }
        // ���������� ������������� �������� << ��� ������ ����
        std::cout << "���� 1 ����� �������� <<: " << date1 << std::endl;
        std::cout << "���� 2 ����� �������� <<: " << date2 << std::endl;
        // ��������� �������� ���� ��� � ������� Sub, ������������ ������ DATE
        DATE diff1 = date1.Sub(date2);
        std::cout << "������� ����� ����� 1 � ����� 2 (Sub(DATE)): " << diff1 << std::endl;
        // ��������� �������� ���� ��� � ������� Sub, ������������ ��������� ���������
        DATE diff2 = date1.Sub(5, DATE::mar, 2020); // ��������: 5 ����� 2020
        std::cout << "������� ����� ����� 1 � (05-03-2020) (Sub(dd, mm, yy)): " << diff2 << std::endl;
        

	}
}

