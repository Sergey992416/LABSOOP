#pragma once
#include <cstdio>
#include <windows.h>
namespace lab02 {
	void runDemo();
    class Node {
    public:
        double data;    // Данные узла
        Node* next;     // Указатель на следующий узел

        Node(double value); // Конструктор
    };

    // Класс LinkedList для управления связанным списком
    class LinkedList {
    private:
        Node* head; // Указатель на голову списка

    public:
        LinkedList();  // Конструктор по умолчанию
        ~LinkedList(); // Деструктор для очистки памяти

        void append(double value);              // Метод для добавления узла в конец
        void insertAtPosition(double value, int position); // Метод для вставки узла на позицию
        void printList() const;                 // Метод для вывода списка
        void deleteList();                      // Метод для удаления списка
    };

}