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
	
		std::cout << "�������� ������������ ������:\n";
		std::cout << "-1. �������� �������\n";
		std::cout << "1. �� 1\n";
		std::cout << "2. �� 2\n";
		std::cout << "3. �� 3\n";
		std::cout << "4. �� 4\n";
		std::cout << "5. �� 5\n";
		std::cout << "6. �� 6\n";
		std::cout << "7. �� 7.1\n";
		std::cout << "8. �� 7.2\n";
		std::cout << "0. �����\n";
		std::cout << "��� �����: ";
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
			std::cout << "����� �� ���������.\n";
			return 0;
		default:
			std::cout << "������������ �����. ��������� �������.\n";
		}
	}
}