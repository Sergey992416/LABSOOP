#include "lab05.h"
namespace lab05 {
	void runDemo() {

        DATE date1(15, DATE::aug, 2023);
        DATE date2(10, DATE::jul, 2021);
        // Используем перегруженные функции Print
        std::cout << "Дата 1 (разделитель '/'): ";
        date1.Print('/');
        std::cout << "Дата 2 (формат DD-MM-YYYY): ";
        date2.Print("DD-MM-YYYY");

        std::cout << "Дата 1 (формат MM/DD/YYYY): ";
        date1.Print("MM/DD/YYYY");
        // Сравниваем даты с помощью перегруженного оператора ==
        if (date1 == date2) {
            std::cout << "Дата 1 и Дата 2 совпадают.\n";
        }
        else {
            std::cout << "Дата 1 и Дата 2 различаются.\n";
        }
        // Используем перегруженный оператор << для вывода даты
        std::cout << "Дата 1 через оператор <<: " << date1 << std::endl;
        std::cout << "Дата 2 через оператор <<: " << date2 << std::endl;
        // Вычисляем разность двух дат с помощью Sub, принимающего объект DATE
        DATE diff1 = date1.Sub(date2);
        std::cout << "Разница между Датой 1 и Датой 2 (Sub(DATE)): " << diff1 << std::endl;
        // Вычисляем разность двух дат с помощью Sub, принимающего отдельные параметры
        DATE diff2 = date1.Sub(5, DATE::mar, 2020); // Например: 5 марта 2020
        std::cout << "Разница между Датой 1 и (05-03-2020) (Sub(dd, mm, yy)): " << diff2 << std::endl;
        

	}
}

