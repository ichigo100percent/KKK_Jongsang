#pragma once

#include <iostream>

inline MyClass::MyClass() {
    std::cout << "Constructor called" << std::endl;
}

inline void MyClass::doSomething() {
    std::cout << "Doing something" << std::endl;
}