#include <iostream>
#include <vector>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // 옵저버를 찾아 제거
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers(const std::string& message) {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Received message: " << message << std::endl;
    }
};

int main() {
    Subject subject;

    ConcreteObserver observer1;
    ConcreteObserver observer2;

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.notifyObservers("Hello, observers!");

    // observer1을 제거
    subject.removeObserver(&observer1);

    // 다시 알림 전송
    subject.notifyObservers("After removal");

    return 0;
}