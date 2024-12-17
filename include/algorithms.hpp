#ifndef ALGORIHMS
#define ALGORIHMS 
#include <algorithm>
#include <cstddef>
#include <exception>
#include <iterator>
#include <iostream>
#include <optional>
#include <vector>

namespace sl {

    template<typename iterator>
    void bubble_sort(iterator _first, iterator _last) {
        for (iterator itr1 = _first; itr1 != _last; itr1++)
            for (iterator itr2 = _first; itr2 != (_last-1); itr2++)
                if (*itr2 > *(itr2 + 1))
                    std::iter_swap(itr2, itr2 + 1);
    }

    template<typename iterator, typename Comp>
    void bubble_sort(iterator _first, iterator _last, Comp _comp) {
        for (iterator itr1 = _first; itr1 != _last; itr1++)
            for (iterator itr2 = _first; itr2 != (_last-1); itr2++)
                if (_comp(*itr2, *(itr2 + 1)))
                    std::iter_swap(itr2, itr2 +1);
    }
    
    template<class iterator>
    void insertion_sort(iterator _first, iterator _last) {
        iterator i = _first;
        for (i = ++i; i != _last; i++) {
            typename std::iterator_traits<iterator>::value_type key = *i;
            iterator j = i;
            while (j != _first && *(std::prev(j)) > key) {
                *j = *(std::prev(j));
                --j;
            }
            *j = key;
        }
    }

    template<typename iterator, typename Comp>
    void insertion_sort(iterator _first, iterator _last, Comp _comp) {
        iterator i = _first;
        for (i = ++i; i != _last; i++) {
            typename std::iterator_traits<iterator>::value_type key = *i;
            iterator j = i;
            while (j != _first && _comp(*(std::prev(j)), key)) {
                *j = *(std::prev(j));
                --j;
            }
            *j = key;
        }
    }

    template<typename iterator>
    void selection_sort(iterator _first, iterator _last) {
        for (iterator i = _first; i != _last; i++) {
            iterator min_itr = i, j = i;
            typename std::iterator_traits<iterator>::value_type temp = *i;
            for (j = ++j; j != _last; j++)
                if (*j < *min_itr)
                    min_itr = j;
            *i = *min_itr;
            *min_itr = temp;
        }
    }

    template<typename iterator, typename Comp>
    void selection_sort(iterator _first, iterator _last, Comp _comp) {
        for (iterator i = _first; i != _last; i++) {
            iterator key = i, j = i;
            typename std::iterator_traits<iterator>::value_type temp = *i;
            for (j = ++j; j != _last; j++)
                if (_comp(*key, *j))
                    key = j;
            *i = *key;
            *key = temp;
        }
    }

    template<typename iterator>
    void merge_func(iterator _first, iterator _mid, iterator _last) {
        std::vector<typename std::iterator_traits<iterator>::value_type> L;
        std::vector<typename std::iterator_traits<iterator>::value_type> R;

        iterator it1;
        iterator it2;
        for (it1 = _first; it1 != _mid; it1++)
            L.push_back(*it1);
        for (it2 = _mid; it2 != _last; it2++)
            R.push_back(*it2);

        int i=0, j=0;
        iterator beg = _first;
        while (i < L.size() && j < R.size()) {
            if (L[i] < R[j]) {
                *beg = L[i];
                i++;
            } else {
                *beg = R[j];
                j++;
            }
            beg++;
        }

        while (i < L.size()) {
            *beg = L[i];
            beg++, i++;
        }
        
        while (j < R.size()) {
            *beg = R[j];
            beg++, j++;
        }
    }

    template<typename iterator>
    void merge_sort(iterator _first, iterator _last) {
        int diff = std::distance(_first, _last);
        if (diff <= 1)
            return;
        iterator _mid = _first;
        std::advance(_mid, diff/2);
        merge_sort(_first, _mid);
        merge_sort(_mid, _last);
        merge_func(_first, _mid, _last);
    }

    template<typename iterator, typename Comp>
    void merge_func(iterator _first, iterator _mid, iterator _last, Comp _comp) {
        std::vector<typename std::iterator_traits<iterator>::value_type> L;
        std::vector<typename std::iterator_traits<iterator>::value_type> R;

        iterator it1;
        iterator it2;
        for (it1 = _first; it1 != _mid; it1++)
            L.push_back(*it1);
        for (it2 = _mid; it2 != _last; it2++)
            R.push_back(*it2);

        int i=0, j=0;
        iterator beg = _first;
        while (i < L.size() && j < R.size()) {
            if (!_comp(L[i], R[j])) {
                *beg = L[i];
                i++;
            } else {
                *beg = R[j];
                j++;
            }
            beg++;
        }

        while (i < L.size()) {
            *beg = L[i];
            beg++, i++;
        }
        
        while (j < R.size()) {
            *beg = R[j];
            beg++, j++;
        }
    }

    template<typename iterator, typename Comp>
    void merge_sort(iterator _first, iterator _last, Comp _comp) {
        int diff = std::distance(_first, _last);
        if (diff <= 1)
            return;
        iterator _mid = _first;
        std::advance(_mid, diff/2);
        merge_sort(_first, _mid, _comp);
        merge_sort(_mid, _last, _comp);
        merge_func(_first, _mid, _last, _comp);
    }

    template<typename iterator>
    iterator get_pivot(iterator _first, iterator _last) {
        int diff = std::distance(_first, _last);
        iterator pivot = _first;
        std::advance(pivot, diff-1);
        iterator i = _first;
        for (iterator j = _first; j != _last; j++) {
            if (*j < *pivot) {
                std::iter_swap(i, j);
                i++;
            }
        }
        std::iter_swap(++i, pivot);
        return i;
    }

    template<typename iterator>
    void quick_sort(iterator _first, iterator _last) {
        int diff = std::distance(_first, std::prev(_last));
        if (diff <= 1)
            return;

        iterator pivot = _last;
        iterator i = _first;
        for (iterator j = _first; j != _last; j++) {
            if (*j < *pivot) {
                std::iter_swap(i, j);
                i++;
            }
        }
        std::iter_swap(++i, pivot);
        pivot = i;

        quick_sort(_first, std::prev(pivot));
        quick_sort(std::next(pivot), _last);
    }

    template<typename iterator, typename dataType>
    int linear_search(iterator _first, iterator _last, dataType value) {
       for (iterator i = _first; i != _last; i++) {
            if (*i == value)
                return std::distance(_first, i);
        }
        return -1;
    }

    template<typename iterator, typename dataType>
    int binary_search(iterator _first, iterator _last, dataType value) {
        merge_sort(_first, _last);
        iterator low = _first;
        iterator high = _last;
        while (std::distance(low, high) >= 0) {
            iterator mid = low;
            std::advance(mid, std::distance(low, high) / 2);
            if (*mid == value)
                return std::distance(_first, mid);

            if (*mid < value)
                low = std::next(mid);
            else
                high = std::prev(mid);
        }
        return -1;
    }
};


#endif
