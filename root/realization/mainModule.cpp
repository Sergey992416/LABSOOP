#include <iostream>
#include <limits>  
#include "lab01.h"
#include "lab02.h"
#include "lab03.h"
#include "lab04.h"
#include "lab05.h"
#include "lab06.h"
#include "lab71.h"
#include "lab72.h"

int main() {
	setlocale(LC_ALL, "Rus");

	int choice{ 0 };
	while (true) {
	
		std::cout << "Выберите лабораторную работу:\n";
		std::cout << "-1. Очистить консоль\n";
		std::cout << "1. ЛР 1\n";
		std::cout << "2. ЛР 2\n";
		std::cout << "3. ЛР 3\n";
		std::cout << "4. ЛР 4\n";
		std::cout << "5. ЛР 5\n";
		std::cout << "6. ЛР 6\n";
		std::cout << "7. ЛР 7.1\n";
		std::cout << "8. ЛР 7.2\n";
		std::cout << "0. Выход\n";
		std::cout << "Ваш выбор: ";
		std::cin >> choice;

		switch (choice) {
		case -1:
			system("cls");
			break;
		case 1:
			lab01::runDemo();
			break;
		case 2:
			lab02::runDemo();
			break;
		case 3:
			lab03::runDemo();
			break;
		case 4:
			lab04::runDemo();
			break;
		case 5:
			lab05::runDemo();
			break;
		case 6:
			lab06::runDemo();
			break;
		case 7:
			lab71::runDemo();
			break;
		case 8:
			lab72::runDemo();
			break;
		case 0:
			std::cout << "Выход из программы.\n";
			return 0;
		default:
			std::cout << "Некорректный выбор. Повторите попытку.\n";
		}
	}
}