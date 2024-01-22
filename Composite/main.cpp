#include "Leaf.h"
#include "Composite.h"

int main()
{
    std::unique_ptr<Leaf1> file1 = std::make_unique<Leaf1>(L"file1");
    std::unique_ptr<Leaf1> file2 = std::make_unique<Leaf1>(L"file2");

    std::unique_ptr<Composite> test = std::make_unique<Composite>(L"test1");
    test->addComponent(std::move(file1));
    test->addComponent(std::move(file2));

    std::unique_ptr<Leaf1> file3 = std::make_unique<Leaf1>(L"file3");
    Composite test2(L"Test2");
    test2.addComponent(std::move(test));
    test2.showInfo();
}