#pragma once
#include <cstdio>

namespace lab03 {
	void runDemo();
    class UniqueNumbers {
    private:
        int* numbers;
        int N;
    public:
        // Конструктор с параметром размера, инициализирует массив или устанавливает nullptr
        UniqueNumbers(int size = 0);
        // Деструктор освобождает память
        ~UniqueNumbers();
        // Устанавливает число по индексу, если индекс валиден
        void setNumber(int index, int value);

        // Находит уникальные числа и возвращает их количество
        int findUnique(int* uniqueNumbers) const;
    };

}