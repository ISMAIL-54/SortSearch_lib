#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include <list>
#include <catch2/catch_test_macros.hpp>
#include "algorithms.hpp"



TEST_CASE("Bubble sorting in ASCENDING order", "[vector]") {
    std::vector<int> vec = {1, 44, 4, 23, -13};
    std::vector<int> vec_sorted = {-13, 1, 4, 23, 44};

    sl::bubble_sort(vec.begin(), vec.end());
    REQUIRE(vec == vec_sorted);
}

TEST_CASE("Insertion sorting in ASCENDING order", "[string]") {
    std::string str = "dfdsfkjas";
    std::string str_sorted  = "addffjkss";

    sl::insertion_sort(str.begin(), str.end());
    REQUIRE(str == str_sorted);
}

TEST_CASE("Selection sorting in DESCENDING order", "[list]") {
    std::list<double> _list = {2.14, 4.3, -14.1, 123.00};
    std::list<double> _list_sorted = {123.00, 4.3, 2.14, -14.1};

    sl::insertion_sort(_list.rbegin(), _list.rend());
    REQUIRE(_list == _list_sorted);
}

TEST_CASE("Merge sorting in DESCENDING order", "[C-style string]") {
    char str[] = {'2', 'Z', 'y', 'a', 'b', 'e'};
    char str_sorted[] = {'2', 'Z', 'a', 'b', 'e', 'y'};

    sl::merge_sort(str, str + 6);
    REQUIRE(std::equal(std::begin(str), std::end(str), std::begin(str_sorted)));
}

TEST_CASE("Quick sorting in ASCENDING order", "[array]") {
    int numbers[] = {2, 1, -12, 3, 4, 3};
    int numbers_sorted[] = {-12, 1, 2, 3, 3, 4};

    sl::merge_sort(numbers, numbers + 6);
    REQUIRE(std::equal(std::begin(numbers), std::end(numbers), std::begin(numbers)));
}

TEST_CASE("Linear searching", "[vector]") {
    std::vector<int> numbers = {2, 1, -12, 3, 4, 3};

    REQUIRE(sl::linear_search(numbers.begin(), numbers.end(), -12) == 2);
    REQUIRE(sl::linear_search(numbers.begin(), numbers.end(), 10) == -1);
}

TEST_CASE("Binary searching", "[vector]") {
    std::vector<int> numbers = {2, 1, -12, 3, 4, 3}; // [-12, 1, 2, 3, 3, 4]

    REQUIRE(sl::binary_search(numbers.begin(), numbers.end(), -12) == 0);
    REQUIRE(sl::binary_search(numbers.begin(), numbers.end(), 10) == -1);
}
