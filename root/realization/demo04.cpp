#include "lab04.h"

#include <iostream>
namespace lab04 {
    void runDemo() {

        DATE date1(15, 3, 2023);

        // ������ ������ ExtendedDATE
        ExtendedDATE extDate1(20, 4, 2024, 14, 30);

        // ������ ���������
        DATE* ptrBaseDate = &date1;
        DATE* ptrExtDate = &extDate1;

        // ������ ������ ���� ��� �����
        DATE date2(10, 1, 2020);
        ExtendedDATE extDate2(5, 2, 2021, 9, 15);

        // ������������: ������ � DATE
        std::cout << "=== ������������� DATE ===\n";
        ptrBaseDate->PrintSub(date2, '-');
        std::cout << "\n";

        // ������������: ������ � ExtendedDATE
        std::cout << "=== ������������� ExtendedDATE ===\n";
        ptrExtDate->PrintSub(extDate2, '-');
        std::cout << "\n";
    }
  
}