#include "lab02.h"
#include <iostream>
namespace lab02 {
    void runDemo() {
        // ��������� ��������� ������� ��� ������ � ������� ������
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        int n;
        std::cout << "������� ���������� ��������� (n): ";
        std::cin >> n;

        if (n <= 0) {
            std::cout << "���������� ��������� ������ ���� �������������.\n";
            
        }

        LinkedList list;
        double value;

        for (int i = 0; i < n; ++i) {
            std::cout << "������� ������� " << i + 1 << ": ";
            std::cin >> value;
            list.append(value);
        }

        std::cout << "\n�������� ������:\n";
        list.printList();

        int insertPos = n / 2;

        list.insertAtPosition(0.0, insertPos);

        std::cout << "\n������ ����� ������� 0 �� ������� " << insertPos + 1 << ":\n";
        list.printList();

    }
}