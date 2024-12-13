#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include "sort.hpp"

bool comp(std::string a, std::string b) {
    if (a < b)
        return true;
    return false;
}

int main() {
    std::vector<std::string> numbers {"ab", "cc", "4b", "de", "ba"};
    sl::bubble_sort(numbers.begin(), numbers.end(), comp);
    for (int i=0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}
