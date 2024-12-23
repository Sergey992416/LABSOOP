#include "lab72.h"
#include <sstream>
#include <iomanip> 
namespace lab72 {
    Manip::Manip(int w, int b, int p, char f)
        : width(w), base(b), precision(p), fill(f) {}

    std::ostream& operator<<(std::ostream& os, const Manip& m) {
        os << std::setw(m.width)
            << std::setfill(m.fill)
            << std::fixed;

        if (m.base == 8)
            os << std::oct;
        else if (m.base == 10)
            os << std::dec;
        else if (m.base == 16)
            os << std::hex;

        os << std::setprecision(m.precision);

        return os;
    }

    // Ðåàëèçàöèÿ ôóíêöèè äëÿ êîíâåðòàöèè ÷èñëà ñ ïëàâàþùåé òî÷êîé
    std::string floatToHex(double num, int precision) {
        int integerPart = static_cast<int>(num);
        double fractionalPart = num - integerPart;

        // Êîíâåðòèðóåì öåëóþ ÷àñòü
        std::ostringstream integerStream;
        integerStream << std::hex << integerPart;
        std::string integerStr = integerStream.str();

        // Êîíâåðòèðóåì äðîáíóþ ÷àñòü
        std::string fractionalStr;
        double tempFrac = fractionalPart;
        for (int i = 0; i < precision; ++i) {
            tempFrac *= 16;
            int digit = static_cast<int>(tempFrac);
            fractionalStr += (digit < 10 ? '0' + digit : 'a' + digit - 10);
            tempFrac -= digit;
        }

        return integerStr + "," + fractionalStr;
    }
}
