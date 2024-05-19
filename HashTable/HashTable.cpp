#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<list<pair<int, string>>> table;
    int size;

    // 해시 함수
    int hashFunction(int key) {
        return key % size;
    }

public:
    // 생성자
    HashTable(int _size) : size(_size) {
        table.resize(size);
    }

    // 키-값 쌍 삽입
    void insert(int key, const string& value) {
        int index = hashFunction(key);
        table[index].push_back({ key, value });
    }

    // 키를 이용하여 값 찾기
    string find(int key) {
        int index = hashFunction(key);
        for (auto& p : table[index]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return "Not found";
    }

    // 키를 이용하여 값 삭제
    void erase(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                break;
            }
        }
    }
};

int main() {
    HashTable hashtable(10);

    // 키-값 쌍 삽입
    hashtable.insert(1, "Apple");
    hashtable.insert(2, "Banana");
    hashtable.insert(11, "Cherry"); // 충돌 테스트

    // 키를 이용하여 값 찾기
    cout << "Value at key 1: " << hashtable.find(1) << endl;
    cout << "Value at key 2: " << hashtable.find(2) << endl;
    cout << "Value at key 11: " << hashtable.find(11) << endl;

    // 키를 이용하여 값 삭제
    hashtable.erase(2);

    return 0;
}