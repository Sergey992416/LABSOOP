#include "lab02.h"
#include <cstdio>
namespace lab02 {
    //  онструктор, принимающий массив строк и их размер
    // ќпределение конструктора узла
    Node::Node(double value) : data(value), next(nullptr) {}

    //  онструктор по умолчанию дл€ инициализации пустого списка
    LinkedList::LinkedList() : head(nullptr) {}

    // ƒеструктор дл€ очистки пам€ти
    LinkedList::~LinkedList() {
        deleteList();
    }

    void LinkedList::append(double value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void LinkedList::insertAtPosition(double value, int position) {
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else {
            append(value);
        }
    }

    void LinkedList::printList() const {
        Node* temp = head;
        while (temp) {
            printf("%.2f -> ", temp->data);
            temp = temp->next;
        }
        printf("nullptr\n");
    }

    void LinkedList::deleteList() {
        Node* current = head;
        Node* nextNode;
        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
}