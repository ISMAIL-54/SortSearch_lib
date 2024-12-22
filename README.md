# SortSearch library
An efficient implementation of sorting and searching algorithms.

# Features
## Sorting algorithms
    - [x] Bubble sort
    - [x] Insertion sort
    - [x] Selection sort
    - [x] Merge sort
    - [x] Quick sort

## Searching algorithms
    - [x] Linear search
    - [x] Binary search


# Usage
## Installation

1. Clone the repository:

    git clone https://github.com/ISMAIL-54/SortSearch_lib.git

2. Include the library in your project by adding the header and source files to your build system.

3. Compilation with CMake

- Navigate to the project directory:

    cd SortSearch_lib

- Create a build directory and run CMake:
    
    mkdir build && cd build
    cmake ..
    cmake --build .

## Example Usage
### Sorting example

    #include "algorithms.hpp"
    #include <vector>
    #include <iostream>

    int main() {
        std::vector<int> arr = {5, 2, 9, 1, 5, 6};
        sl::quick_sort(arr.begin(), arr.end());

        std::cout << "Sorted array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        return 0;
    }

### Searching example

    #include <iostream>
    #include "algorithms.hpp"
    #include <vector>

    int main() {
        std::vector<int> arr = {5, 2, 9, 1, 5, 6};
        sl::quick_sort(arr.begin(), arr.end());

        std::cout << "Sorted array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        return 0;
    }

# Tests
The library includes units tests with Catch2. To run tests:
    
    cd build
    ctest

