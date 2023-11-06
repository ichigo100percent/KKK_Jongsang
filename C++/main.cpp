#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print() {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // ���� �Լ�
    void sort() {
        if (!head || head == tail) {
            return; // ��尡 0�� �Ǵ� 1���� ��� �̹� ���ĵǾ� ����
        }

        bool swapped;
        Node<T>* temp;

        do {
            swapped = false;
            Node<T>* current = head;

            while (current->next) {
                if (current->data > current->next->data) {
                    // �� ����� �����͸� ��ȯ
                    temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

private:
    Node<T>* head;
    Node<T>* tail;
};

int main() {
    DoublyLinkedList<int> list;

    // ������ �߰�
    list.push_back(5);
    list.push_back(3);
    list.push_back(8);
    list.push_back(1);
    list.push_back(6);

    std::cout << "Before sorting: ";
    list.print();

    // ����Ʈ ����
    list.sort();

    std::cout << "After sorting: ";
    list.print();

    return 0;
}