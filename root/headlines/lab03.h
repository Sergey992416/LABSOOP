#pragma once
#include <cstdio>

namespace lab03 {
	void runDemo();
    class UniqueNumbers {
    private:
        int* numbers;
        int N;
    public:
        // ����������� � ���������� �������, �������������� ������ ��� ������������� nullptr
        UniqueNumbers(int size = 0);
        // ���������� ����������� ������
        ~UniqueNumbers();
        // ������������� ����� �� �������, ���� ������ �������
        void setNumber(int index, int value);

        // ������� ���������� ����� � ���������� �� ����������
        int findUnique(int* uniqueNumbers) const;
    };

}