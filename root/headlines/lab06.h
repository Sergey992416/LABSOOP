#pragma once
#include <cstdio>
#include <iostream>

namespace lab06 {
    void runDemo();
    // Шаблонный класс для последовательности
    // Класс для комплексных чисел
    class Complex {
    public:
        double real;
        double imag;

        Complex() : real(0.0), imag(0.0) {}
        Complex(double r, double i) : real(r), imag(i) {}

        void input() {
            std::cout << "Введите вещественную часть: ";
            std::cin >> real;
            std::cout << "Введите мнимую часть: ";
            std::cin >> imag;
        }

        inline void display() const {
            std::cout << "(" << real << " + " << imag << "i)";
        }

        inline bool operator>(const double& other) const {
            return real > other;
        }
    };

    // Шаблонный класс Sequence
    template <typename T>
    class Sequence {
    private:
        T* elements;
        int size;
        int capacity;

        void expandCapacity() {
            capacity *= 2;
            T* newElements = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
        }

    public:
        Sequence(int initialCapacity = 10) : size(0), capacity(initialCapacity) {
            elements = new T[capacity];
        }

        ~Sequence() {
            delete[] elements;
        }

        void addElement(const T& element) {
            if (size >= capacity) {
                expandCapacity();
            }
            elements[size++] = element;
        }

        int countElements(double M, double L, double N) const;
        void display() const;
    };

    template <typename T>
    int Sequence<T>::countElements(double M, double L, double N) const {
        std::cerr << "Метод countElements не определён для данного типа.\n";
        return 0;
    }

    template <typename T>
    void Sequence<T>::display() const {
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i];
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    // Специализация для int
    template <>
    inline int Sequence<int>::countElements(double M, double L, double N) const {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if ((elements[i] > M) && !(elements[i] >= L && elements[i] <= N)) {
                count++;
            }
        }
        return count;
    }

    template <>
    inline void Sequence<int>::display() const {
        for (int i = 0; i < size; ++i) {
            std::cout << elements[i];
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    // Специализация для Complex
    template <>
    inline int Sequence<Complex>::countElements(double M, double L, double N) const {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            double imag = elements[i].imag;
            if ((imag > M) && !(imag >= L && imag <= N)) {
                count++;
            }
        }
        return count;
    }

    template <>
    inline void Sequence<Complex>::display() const {
        for (int i = 0; i < size; ++i) {
            elements[i].display();
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}
