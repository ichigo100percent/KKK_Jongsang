#include "rbTree.h"
#include <stdio.h>
#include <bit>
#include <list>
#include <utility>
#include <iostream>

using namespace std;


enum Color { RED, BLACK };

// ����-�� Ʈ���� �� ��带 ǥ���ϴ� Ŭ����
class Node {
public:
    int data;      // ����� ��
    Color color;   // ����� ����
    Node* left;    // ���� �ڽ� ��� ������
    Node* right;   // ������ �ڽ� ��� ������
    Node* parent;  // �θ� ��� ������

    // ������: ����� �� �ʱ�ȭ �� ������ �ʱ�ȭ
    Node(int value) {
        data = value;
        color = RED;   // ���ο� ���� �⺻������ ����� ����
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class RedBlackTree {
private:
    Node* root;

    // ���� ���� �� ����-�� Ʈ���� ������ �����ϱ� ���� ���� �Լ�
    void fixViolation(Node* newNode) {
        Node* parent = nullptr;
        Node* grandParent = nullptr;

        while (newNode != root && newNode->color == RED && newNode->parent->color == RED) {
            parent = newNode->parent;
            grandParent = parent->parent;

            // Case 1: �θ�� ������ ������ ���
            if (parent == grandParent->left) {
                Node* uncle = grandParent->right;
                if (uncle != nullptr && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    newNode = grandParent;
                }
                else {
                    // Case 2: �θ�� ���������� ������ ���� ���
                    if (newNode == parent->right) {
                        rotateLeft(parent);
                        newNode = parent;
                        parent = newNode->parent;
                    }

                    // Case 3: �θ�� ���������� ������ ���̰�, �θ�� ���� �ڽ��� ���
                    rotateRight(grandParent);
                    swap(parent->color, grandParent->color);
                    newNode = parent;
                }
            }
            else {
                Node* uncle = grandParent->left;
                if (uncle != nullptr && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    newNode = grandParent;
                }
                else {
                    // Case 2: �θ�� ���������� ������ ���� ���
                    if (newNode == parent->left) {
                        rotateRight(parent);
                        newNode = parent;
                        parent = newNode->parent;
                    }

                    // Case 3: �θ�� ���������� ������ ���̰�, �θ�� ������ �ڽ��� ���
                    rotateLeft(grandParent);
                    swap(parent->color, grandParent->color);
                    newNode = parent;
                }
            }
        }
        root->color = BLACK;  // ��Ʈ ���� �׻� ��
    }

    // �������� ȸ���ϴ� �Լ�
    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // ���������� ȸ���ϴ� �Լ�
    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    // ���� ��ȸ�� ����Ͽ� ����-�� Ʈ���� ��Ҹ� ����ϴ� �Լ�
    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // ���� ���� �� ����-�� Ʈ���� ������ �����ϱ� ���� ���� �Լ�
    void fixDoubleBlack(Node* x) {
        while (x != root && (x == nullptr || x->color == BLACK)) {
            if (x == x->parent->left) {
                Node* sibling = x->parent->right;
                if (sibling == nullptr) {
                    x = x->parent;
                    continue;
                }

                if (sibling->color == RED) {
                    // Case 1: ���� ��尡 ������ ���
                    sibling->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    sibling = x->parent->right;
                }

                if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                    (sibling->right == nullptr || sibling->right->color == BLACK)) {
                    // Case 2: ���� ���� �� �ڽ� ������ ��� ���� ���
                    sibling->color = RED;
                    x = x->parent;
                }
                else {
                    if (sibling->right == nullptr || sibling->right->color == BLACK) {
                        // Case 3: ���� ����� ������ �ڽ��� ���̰�, ���� �ڽ��� ������ ���
                        sibling->left->color = BLACK;
                        sibling->color = RED;
                        rotateRight(sibling);
                        sibling = x->parent->right;
                    }

                    // Case 4: ���� ����� ������ �ڽ��� ������ ���
                    sibling->color = x->parent->color;
                    x->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            }
            else {
                Node* sibling = x->parent->left;
                if (sibling == nullptr) {
                    x = x->parent;
                    continue;
                }

                if (sibling->color == RED) {
                    // Case 1: ���� ��尡 ������ ���
                    sibling->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    sibling = x->parent->left;
                }

                if ((sibling->right == nullptr || sibling->right->color == BLACK) &&
                    (sibling->left == nullptr || sibling->left->color == BLACK)) {
                    // Case 2: ���� ���� �� �ڽ� ������ ��� ���� ���
                    sibling->color = RED;
                    x = x->parent;
                }
                else {
                    if (sibling->left == nullptr || sibling->left->color == BLACK) {
                        // Case 3: ���� ����� ���� �ڽ��� ���̰�, ������ �ڽ��� ������ ���
                        sibling->right->color = BLACK;
                        sibling->color = RED;
                        rotateLeft(sibling);
                        sibling = x->parent->left;
                    }

                    // Case 4: ���� ����� ���� �ڽ��� ������ ���
                    sibling->color = x->parent->color;
                    x->parent->color = BLACK;
                    sibling->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        if (x != nullptr) {
            x->color = BLACK;
        }
    }

public:
    RedBlackTree() {
        root = nullptr;
    }

    // ���� ����
    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            root->color = BLACK;  // ��Ʈ ���� �׻� ��
            return;
        }

        // ���� �˻� Ʈ���� ���� ���� ����
        Node* parent = nullptr;
        Node* current = root;
        while (current != nullptr) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        newNode->parent = parent;
        if (value < parent->data) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }

        // ����-�� Ʈ���� ������ �����ϱ� ���� ����
        fixViolation(newNode);
    }

    // ���� ��ȸ�� ����Ͽ� ����-�� Ʈ���� ��Ҹ� ����ϴ� �Լ� ȣ��
    void printInorder() {
        inorderTraversal(root);
    }
    // ���� ����
    void remove(int value) {
        if (root == nullptr) {
            return;
        }

        Node* target = root;
        while (target != nullptr) {
            if (target->data == value) {
                break;
            }
            if (value < target->data) {
                target = target->left;
            }
            else {
                target = target->right;
            }
        }

        if (target == nullptr) {
            cout << "Value not found in the tree." << endl;
            return;
        }

        Node* x, * y;
        if (target->left == nullptr || target->right == nullptr) {
            y = target;
        }
        else {
            y = target->right;
            while (y->left != nullptr) {
                y = y->left;
            }
        }

        if (y->left != nullptr) {
            x = y->left;
        }
        else {
            x = y->right;
        }

        if (x != nullptr) {
            x->parent = y->parent;
        }

        if (y->parent == nullptr) {
            root = x;
        }
        else if (y == y->parent->left) {
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }

        if (y != target) {
            target->data = y->data;
        }

        if (y->color == BLACK) {
            fixDoubleBlack(x);
        }

        delete y;
    }
};

int main() {
    RedBlackTree rbTree;
    rbTree.insert(10);
    rbTree.insert(20);
    rbTree.insert(30);
    rbTree.insert(15);
    rbTree.insert(18);
    rbTree.insert(5);
    rbTree.insert(25);

    cout << "Red-Black Tree after insertion: ";
    rbTree.printInorder();
    cout << endl;

    cout << "Deleting 20..." << endl;
    rbTree.remove(20);
    cout << "Red-Black Tree after deletion: ";
    rbTree.printInorder();
    cout << endl;

    return 0;
}