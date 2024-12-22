#ifndef ALGORIHMS
#define ALGORIHMS 
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

namespace sl {

    template<typename iterator, typename Comp = std::less<>>
    void bubble_sort(iterator _first, iterator _last, Comp _comp = Comp()) {
        for (iterator itr1 = _first; itr1 != _last; itr1++)
            for (iterator itr2 = _first; itr2 != (_last-1); itr2++)
                if (!_comp(*itr2, *(itr2 + 1)))
                    std::iter_swap(itr2, itr2 +1);
    }
    
    template<typename iterator, typename Comp = std::less<>>
    void insertion_sort(iterator _first, iterator _last, Comp _comp = Comp()) {
        iterator i = _first;
        for (i = ++i; i != _last; i++) {
            typename std::iterator_traits<iterator>::value_type key = *i;
            iterator j = i;
            while (j != _first && !_comp(*(std::prev(j)), key)) {
                *j = *(std::prev(j));
                --j;
            }
            *j = key;
        }
    }

    template<typename iterator, typename Comp = std::less<>>
    void selection_sort(iterator _first, iterator _last, Comp _comp = Comp()) {
        for (iterator i = _first; i != _last; i++) {
            iterator key = i, j = i;
            typename std::iterator_traits<iterator>::value_type temp = *i;
            for (j = ++j; j != _last; j++)
                if (!_comp(*key, *j))
                    key = j;
            *i = *key;
            *key = temp;
        }
    }

    namespace {
        template<typename iterator, typename Comp = std::less<>>
        void merge_func(iterator _first, iterator _mid, iterator _last, Comp _comp = Comp()) {
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
                if (_comp(L[i], R[j])) {
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
    }

    template<typename iterator, typename Comp = std::less<>>
    void merge_sort(iterator _first, iterator _last, Comp _comp = Comp()) {
        int diff = std::distance(_first, _last);
        if (diff <= 1)
            return;
        iterator _mid = _first;
        std::advance(_mid, diff/2);
        merge_sort(_first, _mid, _comp);
        merge_sort(_mid, _last, _comp);
        merge_func(_first, _mid, _last, _comp);
    }

    template<typename iterator, typename Comp = std::less<>>
    void quick_sort(iterator _first, iterator _last, Comp _comp = Comp()) {
        int diff = std::distance(_first, _last);
        if (diff <= 0)
            return;

        iterator pivot = std::prev(_last);
        iterator i = _first;
        for (iterator j = _first; j != _last; j++) {
            if (_comp(*j, *pivot)) {
                std::iter_swap(j, i);
                i++;
            }
        }
        std::iter_swap(i, pivot);
        quick_sort(_first, i, _comp);
        quick_sort(std::next(i), _last, _comp);
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
        quick_sort(_first, _last);
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
