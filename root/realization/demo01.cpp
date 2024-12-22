#include "lab01.h"
namespace lab01 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        DATE date1(15, DATE::jun, 2023);
        DATE date2(10, DATE::may, 2022);

        date1.Print('*');
        date2.Print('.');

        DATE date_diff = date1.Sub(date2);
        date_diff.Print('/');

    }
}
