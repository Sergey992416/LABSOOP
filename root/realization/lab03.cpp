#include "lab03.h"
namespace lab03 {
    // Конструктор с параметром размера, инициализирует массив или устанавливает nullptr
    UniqueNumbers::UniqueNumbers(int size) : numbers(size > 0 ? new int[size] : nullptr), N(size) {}
    // Деструктор освобождает память
    UniqueNumbers::~UniqueNumbers() {
        delete[] numbers;
    }
    // Устанавливает число по индексу, если индекс валиден
    void UniqueNumbers::setNumber(int index, int value) {
        if (index >= 0 && index < N) {
            numbers[index] = value;
        }
    }
    // Находит уникальные числа и возвращает их количество
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