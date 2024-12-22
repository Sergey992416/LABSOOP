#include "lab04.h"

#include <iostream>
namespace lab04 {
    void runDemo() {

        DATE date1(15, 3, 2023);

        // Создаём объект ExtendedDATE
        ExtendedDATE extDate1(20, 4, 2024, 14, 30);

        // Создаём указатели
        DATE* ptrBaseDate = &date1;
        DATE* ptrExtDate = &extDate1;

        // Создаём вторые даты для теста
        DATE date2(10, 1, 2020);
        ExtendedDATE extDate2(5, 2, 2021, 9, 15);

        // Демонстрация: работа с DATE
        std::cout << "=== Использование DATE ===\n";
        ptrBaseDate->PrintSub(date2, '-');
        std::cout << "\n";

        // Демонстрация: работа с ExtendedDATE
        std::cout << "=== Использование ExtendedDATE ===\n";
        ptrExtDate->PrintSub(extDate2, '-');
        std::cout << "\n";
    }
  
}