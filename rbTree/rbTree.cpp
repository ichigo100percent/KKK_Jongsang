#include "rbTree.h"
#include <stdio.h>
#include <bit>
#include <list>
#include <utility>
#include <iostream>

using namespace std;


enum Color { RED, BLACK };

// 레드-블랙 트리의 각 노드를 표현하는 클래스
class Node {
public:
    int data;      // 노드의 값
    Color color;   // 노드의 색상
    Node* left;    // 왼쪽 자식 노드 포인터
    Node* right;   // 오른쪽 자식 노드 포인터
    Node* parent;  // 부모 노드 포인터

    // 생성자: 노드의 값 초기화 및 포인터 초기화
    Node(int value) {
        data = value;
        color = RED;   // 새로운 노드는 기본적으로 레드로 설정
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class RedBlackTree {
private:
    Node* root;

    // 삽입 연산 중 레드-블랙 트리의 성질을 유지하기 위한 보조 함수
    void fixViolation(Node* newNode) {
        Node* parent = nullptr;
        Node* grandParent = nullptr;

        while (newNode != root && newNode->color == RED && newNode->parent->color == RED) {
            parent = newNode->parent;
            grandParent = parent->parent;

            // Case 1: 부모와 삼촌이 레드인 경우
            if (parent == grandParent->left) {
                Node* uncle = grandParent->right;
                if (uncle != nullptr && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    newNode = grandParent;
                }
                else {
                    // Case 2: 부모는 레드이지만 삼촌은 블랙인 경우
                    if (newNode == parent->right) {
                        rotateLeft(parent);
                        newNode = parent;
                        parent = newNode->parent;
                    }

                    // Case 3: 부모는 레드이지만 삼촌은 블랙이고, 부모는 왼쪽 자식인 경우
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
                    // Case 2: 부모는 레드이지만 삼촌은 블랙인 경우
                    if (newNode == parent->left) {
                        rotateRight(parent);
                        newNode = parent;
                        parent = newNode->parent;
                    }

                    // Case 3: 부모는 레드이지만 삼촌은 블랙이고, 부모는 오른쪽 자식인 경우
                    rotateLeft(grandParent);
                    swap(parent->color, grandParent->color);
                    newNode = parent;
                }
            }
        }
        root->color = BLACK;  // 루트 노드는 항상 블랙
    }

    // 왼쪽으로 회전하는 함수
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

    // 오른쪽으로 회전하는 함수
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

    // 중위 순회를 사용하여 레드-블랙 트리의 요소를 출력하는 함수
    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // 삭제 연산 중 레드-블랙 트리의 성질을 유지하기 위한 보조 함수
    void fixDoubleBlack(Node* x) {
        while (x != root && (x == nullptr || x->color == BLACK)) {
            if (x == x->parent->left) {
                Node* sibling = x->parent->right;
                if (sibling == nullptr) {
                    x = x->parent;
                    continue;
                }

                if (sibling->color == RED) {
                    // Case 1: 형제 노드가 레드인 경우
                    sibling->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    sibling = x->parent->right;
                }

                if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                    (sibling->right == nullptr || sibling->right->color == BLACK)) {
                    // Case 2: 형제 노드와 그 자식 노드들이 모두 블랙인 경우
                    sibling->color = RED;
                    x = x->parent;
                }
                else {
                    if (sibling->right == nullptr || sibling->right->color == BLACK) {
                        // Case 3: 형제 노드의 오른쪽 자식이 블랙이고, 왼쪽 자식이 레드인 경우
                        sibling->left->color = BLACK;
                        sibling->color = RED;
                        rotateRight(sibling);
                        sibling = x->parent->right;
                    }

                    // Case 4: 형제 노드의 오른쪽 자식이 레드인 경우
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
                    // Case 1: 형제 노드가 레드인 경우
                    sibling->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    sibling = x->parent->left;
                }

                if ((sibling->right == nullptr || sibling->right->color == BLACK) &&
                    (sibling->left == nullptr || sibling->left->color == BLACK)) {
                    // Case 2: 형제 노드와 그 자식 노드들이 모두 블랙인 경우
                    sibling->color = RED;
                    x = x->parent;
                }
                else {
                    if (sibling->left == nullptr || sibling->left->color == BLACK) {
                        // Case 3: 형제 노드의 왼쪽 자식이 블랙이고, 오른쪽 자식이 레드인 경우
                        sibling->right->color = BLACK;
                        sibling->color = RED;
                        rotateLeft(sibling);
                        sibling = x->parent->left;
                    }

                    // Case 4: 형제 노드의 왼쪽 자식이 레드인 경우
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

    // 삽입 연산
    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            root->color = BLACK;  // 루트 노드는 항상 블랙
            return;
        }

        // 이진 검색 트리의 삽입 연산 수행
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

        // 레드-블랙 트리의 성질을 유지하기 위해 조정
        fixViolation(newNode);
    }

    // 중위 순회를 사용하여 레드-블랙 트리의 요소를 출력하는 함수 호출
    void printInorder() {
        inorderTraversal(root);
    }
    // 삭제 연산
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