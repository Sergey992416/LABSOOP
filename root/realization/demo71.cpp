#include "lab71.h"
#include <iostream>
#include <iomanip> 
namespace lab71 {
	void runDemo() {
        DATE date1;
        std::cout << "������� ������ ���� � ������� DD.MM.YYYY: ";
        std::cin >> date1;

        if (std::cin.fail()) {
            std::cout << "������ ����� ����.\n";
            
        }

        DATE date2;
        std::cout << "������� ������ ���� � ������� DD.MM.YYYY: ";
        std::cin >> date2;

        if (std::cin.fail()) {
            std::cout << "������ ����� ����.\n";
           
        }

        DATE difference = date1.Sub(date2);

        std::cout << "������� ����� " << date1 << " � " << date2 << ": " << difference << std::endl;

     
    }

}