#include "lab03.h"
namespace lab03 {
    
    UniqueNumbers::UniqueNumbers(int size) : numbers(size > 0 ? new int[size] : nullptr), N(size) {}
    
    UniqueNumbers::~UniqueNumbers() {
        delete[] numbers;
    }
    // Óñòàíàâëèâàåò ÷èñëî ïî èíäåêñó, åñëè èíäåêñ âàëèäåí
    void UniqueNumbers::setNumber(int index, int value) {
        if (index >= 0 && index < N) {
            numbers[index] = value;
        }
    }
    // Íàõîäèò óíèêàëüíûå ÷èñëà è âîçâðàùàåò èõ êîëè÷åñòâî
    int UniqueNumbers::findUnique(int* uniqueNumbers) const {
        int uniqueCount = 0;
        for (int i = 0; i < N; ++i) {
            bool isUnique = true;
            for (int j = 0; j < N; ++j) {
                if (i != j && numbers[i] == numbers[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                uniqueNumbers[uniqueCount++] = numbers[i];
            }
        }
        return 0;
    }

}
