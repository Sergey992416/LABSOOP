#pragma once
#include <cstdio>
#include <windows.h>
namespace lab02 {
	void runDemo();
    class Node {
    public:
        double data;    // ������ ����
        Node* next;     // ��������� �� ��������� ����

        Node(double value); // �����������
    };

    // ����� LinkedList ��� ���������� ��������� �������
    class LinkedList {
    private:
        Node* head; // ��������� �� ������ ������

    public:
        LinkedList();  // ����������� �� ���������
        ~LinkedList(); // ���������� ��� ������� ������

        void append(double value);              // ����� ��� ���������� ���� � �����
        void insertAtPosition(double value, int position); // ����� ��� ������� ���� �� �������
        void printList() const;                 // ����� ��� ������ ������
        void deleteList();                      // ����� ��� �������� ������
    };

}