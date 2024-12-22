#include "lab03.h"
#include <iostream>
namespace lab03 {
    // ������� ��� ����� ������
    

    void runDemo() {
        int N;
        std::cout << "������� ���������� ����� N: ";
        std::cin >> N;
        if (N <= 0) {
            std::cout << "N ������ ���� ������������� ������.\n";
          
        }
        UniqueNumbers un(N);
        std::cout << "������� " << N << " �����:\n";
        for (int i = 0; i < N; ++i) {
            int num;
            std::cin >> num;
            un.setNumber(i, num);
        }
        int* tempUnique = new int[N];
        int uniqueCount = un.findUnique(tempUnique);
        std::cout << "�����, ������������� ��������:\n";
        if (uniqueCount > 0) {
            for (int i = 0; i < uniqueCount; ++i) {
                std::cout << tempUnique[i] << ' ';
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "��� ���������� �����.\n";
        }
        delete[] tempUnique;

    }
}
