#include <iostream>
#include <cstring>
#include <string>

class ShallowCopy {
public:
    ShallowCopy(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    void setData(const char* str) {
        strcpy(data, str);
    }

    const char* getData() {
        return data;
    }

private:
    char* data;
};

class DeepCopy {
public:
    DeepCopy(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    DeepCopy(const DeepCopy& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    ~DeepCopy() {
        delete[] data;
    }

    void setData(const char* str) {
        delete[] data;
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    const char* getData() {
        return data;
    }

private:
    char* data;
};

int main() {
    // 얕은 복사
    ShallowCopy shallowObj("Shallow");
    ShallowCopy shallowCopy = shallowObj;
    shallowCopy.setData("Shallow Copy");

    std::cout << "Shallow Original: " << shallowObj.getData() << std::endl;
    std::cout << "Shallow Copy: " << shallowCopy.getData() << std::endl;

    // 깊은 복사
    DeepCopy deepObj("Deep");
    DeepCopy deepCopy = deepObj;
    deepCopy.setData("Deep Copy");

    std::cout << "Deep Original: " << deepObj.getData() << std::endl;
    std::cout << "Deep Copy: " << deepCopy.getData() << std::endl;

    return 0;
}
