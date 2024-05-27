#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <assert.h>
#include <random>
#include <numeric>
using namespace std;

#define Check(b)  assert(b > 0)

/*
	for_each					범위 내의 각 요소에 대해 지정된 함수를 적용합니다.
	find						범위 내에서 특정 값을 찾습니다.
	find_if						조건을 만족하는 첫 번째 요소를 찾습니다.
	min_element					범위 내에서 최소 요소를 찾습니다.
	max_element					범위 내에서 최대 요소를 찾습니다.
	sort						범위를 정렬합니다.	
	count						범위 내에서 특정 값의 개수를 셉니다.
	count_if					조건을 만족하는 요소의 개수를 셉니다.
	all_of						모든 요소가 조건을 만족하는지 확인합니다.
	none_of						모든 요소가 조건을 만족하지 않는지 확인합니다.
	any_of						하나 이상의 요소가 조건을 만족하는지 확인합니다.	
	fill						범위의 모든 요소를 지정된 값으로 채웁니다.
	copy						한 범위의 요소를 다른 범위로 복사합니다.
	copy_if						조건을 만족하는 요소만을 복사합니다.
	generate					범위를 함수의 반환 값으로 채웁니다.
	transform					범위의 각 요소를 변환합니다.
	remove(erase)				범위에서 특정 값을 제거합니다.
	remove_if(erase_if)			조건을 만족하는 요소를 제거합니다.
	replace						범위 내의 특정 값을 다른 값으로 바꿉니다.
	replace_if					조건을 만족하는 요소를 다른 값으로 바꿉니다.
	shuffle						범위를 무작위로 섞습니다.
	accumulate					범위의 요소를 누적합니다.
	unique						연속된 중복 요소를 제거합니다.
	reverse						범위를 역순으로 바꿉니다.
*/


struct Person
{
    Person() = default;
    Person(const std::string& _name) : Name(_name) {}

    bool operator<(const Person& _p) const
    {
        return this->Name < _p.Name;
    }

    std::string Name;
};

// Print function for use with algorithms
void print(const Person& person)
{
    std::cout << person.Name << " ";
}

int main()
{
    random_device rd;
    mt19937 mt(rd());


    // Initialize a vector of Person objects
    std::vector<Person> people = { Person("Alice"), Person("Bob"), Person("Charlie"), Person("Dave"), Person("Eve") };

    // 1. std::for_each
    std::cout << "Using std::for_each: ";
    std::for_each(people.begin(), people.end(), print);
    std::cout << std::endl;

    // 2. std::find
    auto it = std::find_if(people.begin(), people.end(), [](const Person& person) { return person.Name == "Charlie"; });
    if (it != people.end()) {
        std::cout << "Found: " << it->Name << std::endl;
    }

    // 3. std::find_if
    it = std::find_if(people.begin(), people.end(), [](const Person& person) { return person.Name == "Eve"; });
    if (it != people.end()) {
        std::cout << "Found with std::find_if: " << it->Name << std::endl;
    }

    // 4. std::min_element
    auto minIt = std::min_element(people.begin(), people.end());
    std::cout << "Min element: " << minIt->Name << std::endl;

    // 5. std::max_element
    auto maxIt = std::max_element(people.begin(), people.end());
    std::cout << "Max element: " << maxIt->Name << std::endl;

    // 6. std::sort
    std::sort(people.begin(), people.end());
    std::cout << "Sorted: ";
    std::for_each(people.begin(), people.end(), print);
    std::cout << std::endl;

    // 7. std::count
    int count = std::count_if(people.begin(), people.end(), [](const Person& person) { return person.Name.length() > 3; });
    std::cout << "Count of names longer than 3 characters: " << count << std::endl;

    // 8. std::count_if
    count = std::count_if(people.begin(), people.end(), [](const Person& person) { return person.Name[0] == 'A'; });
    std::cout << "Count of names starting with 'A': " << count << std::endl;

    // 9. std::all_of
    bool allLongNames = std::all_of(people.begin(), people.end(), [](const Person& person) { return person.Name.length() > 3; });
    std::cout << "All names longer than 3 characters: " << std::boolalpha << allLongNames << std::endl;

    // 10. std::none_of
    bool noneLongNames = std::none_of(people.begin(), people.end(), [](const Person& person) { return person.Name.length() < 3; });
    std::cout << "No names shorter than 3 characters: " << std::boolalpha << noneLongNames << std::endl;

    // 11. std::any_of
    bool anyLongNames = std::any_of(people.begin(), people.end(), [](const Person& person) { return person.Name.length() > 4; });
    std::cout << "Any names longer than 4 characters: " << std::boolalpha << anyLongNames << std::endl;

    // 12. std::fill
    std::fill(people.begin(), people.begin() + 2, Person("Zoe"));
    std::cout << "After fill: ";
    std::for_each(people.begin(), people.end(), print);
    std::cout << std::endl;

    // Reset people vector
    people = { Person("Alice"), Person("Bob"), Person("Charlie"), Person("Dave"), Person("Eve") };

    // 13. std::copy
    std::vector<Person> copyPeople(people.size());
    std::copy(people.begin(), people.end(), copyPeople.begin());
    std::cout << "After copy: ";
    std::for_each(copyPeople.begin(), copyPeople.end(), print);
    std::cout << std::endl;

    // 14. std::copy_if
    std::vector<Person> filteredPeople;
    std::copy_if(people.begin(), people.end(), std::back_inserter(filteredPeople), [](const Person& person) { return person.Name.length() > 3; });
    std::cout << "After copy_if: ";
    std::for_each(filteredPeople.begin(), filteredPeople.end(), print);
    std::cout << std::endl;

    // 15. std::generate
    int counter = 1;
    std::generate(people.begin(), people.end(), [&counter]() { return Person("Person" + std::to_string(counter++)); });
    std::cout << "After generate: ";
    std::for_each(people.begin(), people.end(), print);
    std::cout << std::endl;

    // Reset people vector
    people = { Person("Alice"), Person("Bob"), Person("Charlie"), Person("Dave"), Person("Eve") };

    // 16. std::transform
    std::transform(people.begin(), people.end(), people.begin(), [](Person& person) { person.Name = "Mr. " + person.Name; return person; });
    std::cout << "After transform: ";
    std::for_each(people.begin(), people.end(), print);
    std::cout << std::endl;

    // Reset people vector
    people = { Person("Alice"), Person("Bob"), Person("Charlie"), Person("Dave"), Person("Eve") };

    // 17. std::remove
    people.erase(std::remove_if(people.begin(), people.end(), [](const Person& person) { return person.Name == "Charlie"; }), people.end());
    std::cout << "After remove: ";
    std::for_each(people.begin(), people.end(), print);
    std::cout << std::endl;

    // 18. std::replace
    std::replace_if(people.begin(), people.end(), [](const Person& person) { return person.Name == "Dave"; }, Person("Daniel"));
    std::cout << "After replace: ";
    std::for_each(people.begin(), people.end(), print);
    std::cout << std::endl;

    // Reset people vector
    people = { Person("Alice"), Person("Bob"), Person("Charlie"), Person("Dave"), Person("Eve") };

    // 19. std::random_shuffle
    std::shuffle(people.begin(), people.end(), mt);
    std::cout << "After random_shuffle: ";
    std::for_each(people.begin(), people.end(), print);
    std::cout << std::endl;

    // Reset people vector
    people = { Person("Alice"), Person("Bob"), Person("Charlie"), Person("Dave"), Person("Eve") };

    // 20. std::accumulate
    std::string concatenatedNames = std::accumulate(people.begin(), people.end(), std::string(), [](const std::string& acc, const Person& person) { return acc + person.Name + " "; });
    std::cout << "Concatenated names: " << concatenatedNames << std::endl;

    return 0;   
}
