#include <iostream>
#include <unordered_map>
#include <map>
#include <set>

int main()
{
    // unordered_map 예제
    std::unordered_map<int, std::string> unorderedMap;
    unorderedMap[1] = "one";
    unorderedMap[2] = "two";
    unorderedMap[3] = "three";

    std::cout << "unordered_map:" << std::endl;
    for (const auto& pair : unorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // map 예제
    std::map<int, std::string> orderedMap;
    orderedMap[3] = "three";
    orderedMap[1] = "one";
    orderedMap[2] = "two";

    std::cout << "map:" << std::endl;
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // set 예제
    std::set<int> uniqueSet;
    uniqueSet.insert(3);
    uniqueSet.insert(1);
    uniqueSet.insert(2);

    std::cout << "set:" << std::endl;
    for (const auto& value : uniqueSet)
    {
        std::cout << value << std::endl;
    }

    return 0;
}