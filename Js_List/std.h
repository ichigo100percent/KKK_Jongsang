#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node
{
    T* data;
    Node* next;
    Node* prev;

    Node()
    {
        data = nullptr;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class List
{
public:
    List()
        : head(nullptr)
        , tail(nullptr)
    {

    }
    ~List() {}

    void push_back(T* _data)
    {
        if (head == nullptr)
        {
            head = new Node<T>();
            head->data = _data;
            head->next = nullptr;
            head->prev = nullptr;

            tail = head;
        }
        else
        {
            tail->next = new Node<T>();
            tail->next->data = _data;
            tail->next->next = nullptr;
            tail->next->prev = tail;
            tail = tail->next;
        }
    }


    void print()
    {
        Node<T>* current = head;

        while (current != nullptr)
        {
            std::cout << *current->data;
            current = current->next;
        }
    }

public:
    Node<T>* head;
    Node<T>* tail;
};