#pragma once
#include <iostream>
namespace lab01 {
	void runDemo();
    class DATE {
    public:
        enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

        DATE(unsigned dd, month mm, unsigned yy);
        void Print(char smb);
        DATE Sub(const DATE& what);

    private:
        unsigned day, year;
        month mon;
        unsigned Valid(unsigned dd, month mm, unsigned yy);
        unsigned DaysInMonth(month mm, unsigned yy);
    };
}
