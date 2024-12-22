#include "lab71.h"
#include <iostream>
#include <iomanip> 
namespace lab71 {
	void runDemo() {
        DATE date1;
        std::cout << "Введите первую дату в формате DD.MM.YYYY: ";
        std::cin >> date1;

        if (std::cin.fail()) {
            std::cout << "Ошибка ввода даты.\n";
            
        }

        DATE date2;
        std::cout << "Введите вторую дату в формате DD.MM.YYYY: ";
        std::cin >> date2;

        if (std::cin.fail()) {
            std::cout << "Ошибка ввода даты.\n";
           
        }

        DATE difference = date1.Sub(date2);

        std::cout << "Разница между " << date1 << " и " << date2 << ": " << difference << std::endl;

     
    }

}