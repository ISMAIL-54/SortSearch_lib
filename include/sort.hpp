#ifndef ALGORITHMS
#define ALGORITHMS 
#include <cstddef>
#include <iterator>
#include <iostream>

namespace sl {

    template<typename T>
    inline void swap(T firstValue, T secondValue) {
        typename std::iterator_traits<T>::value_type temp = *firstValue;
        *firstValue = *secondValue;
        *secondValue = temp;
    }

    template<typename T>
    void bubble_sort(T _first, T _last) {
        size_t _size = std::distance(_first, _last);
        for (T itr1 = _first; itr1 != _last; itr1++) {
            for (T itr2 = _first; itr2 != (_last-1); itr2++) {
                if (*itr2 > *(itr2 + 1)) {
                    swap(itr2, itr2 + 1);
                }   
            }
        }
    }

    template<typename T, typename Comp>
    void bubble_sort(T _first, T _last, Comp _comp) {
        size_t _size = std::distance(_first, _last);
        for (T iter1 = _first + 1; iter1 != _last; iter1++) {
            for (T iter2 = _first; iter2 != (_last-1); iter2++) {
                if (_comp(*iter2, *(iter2 + 1))) {
                    swap(iter2, iter2 + 1);
                }   
            }
        }
    }
};

#endif
