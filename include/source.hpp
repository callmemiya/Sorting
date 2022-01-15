// Copyright 2020 Maria mari.zabrodina.01@mail.ru

#ifndef INCLUDE_SOURCE_HPP_
#define INCLUDE_SOURCE_HPP_

#include <algorithm>
#include <vector>

template <class It, class Out, class Compare=std::less<>>
Out merge(It first1, It last1, It first2, It last2, Out out, Compare cmp=Compare{}){
    auto t = 0;
    for (; first1 != last1; ++t) {
        if (first2 == last2) {
            for (auto i=first1; i < last1; i++) {
                out[t] = *i;
                t++;
            }
            return out;
        }
        if (cmp(*first2, *first1)) {
            out[t] = *first2;
            first2++;
        } else {
            out[t] = *first1;
            first1++;
        }
    }
    for (auto i = first2; i < last2; i++){
        out[t] = *i;
        t++;
    }
    return out;
}

template <class It, class Out, class Compare=std::less<>>
Out merge_sort(It first, It last, Out out, Compare cmp=Compare{}){
    if (out.size() <= 1) {
        return out;
    }
    int mid = static_cast<int>(out.size() / 2);
    Out l(first, first + mid);
    Out r(first+mid, last);
    Out left = merge_sort(l.begin(), l.end(), l, cmp);
    Out right = merge_sort(r.begin(), r.end(), r, cmp);
    out = merge(left.begin(), left.end(), right.begin(), right.end(), out, cmp);
    return out;
}

template <class It, class Compare = std::less<>>
void inplace_merge_sort(It first, It last, Compare cmp = Compare()){
    if (last-first <= 1) return;
    inplace_merge_sort(first, first + std::distance(first, last) / 2, cmp);
    inplace_merge_sort(first + std::distance(first, last) / 2, last, cmp);
    std::inplace_merge(first, first + std::distance(first, last) / 2, last, cmp);
}
    
template <class It, class Compare=std::less<>>
void insertion_sort(It first, It last, Compare cmp=Compare{}){
    for (auto i = first; i < last; i++){
        auto m = i;
        while (m > first && cmp(*m, *(m-1))){
            iter_swap((m-1), m);
            m--;
        }
    }
}

template<class It, class Compare=std::less<>>
void max_heapify(It first, It i, It last, Compare cmp=Compare{}){
    It largest = i;
    It left = i + std::distance(first, i) + 1;
    It right = i + std::distance(first, i) + 2;
    if (left < last && cmp(*largest, *left)) largest = left;
    if (right < last && cmp(*largest, *right)) largest = right;
    if (largest != i){
        std::iter_swap(i, largest);
        max_heapify(first, largest, last);
    }
}

template<class It, class Compare=std::less<>>
void heap_sort(It first, It last, Compare cmp=Compare{}){
    for (auto i = first + (std::distance(first, last) / 2) - 1; i >= first; i--){
        max_heapify(first, i, last, cmp);
    }
    for (auto i = last - 1 ; i >= first; i--){
        iter_swap(first, i);
        max_heapify(first, first, i , cmp);
    }
}

template <class It, class Compare=std::less<>>
void quick_sort(It first, It last, Compare cmp=Compare{}){
    if (first < last){
        It i = first, j = last - 1;
        auto x = *(first + std::distance(first, last) / 2);
        while (i <= j){
            while (cmp(*i, x)) i++;
            while (cmp(x, *j)) j--;
            if (i <= j){
                std::iter_swap(i, j);
                x = *(first + std::distance(first, last) / 2);
                i++;
                j--;
            }
        }
        if (first < j) quick_sort(first, j + 1, cmp);
        if (i < last) quick_sort(i, last, cmp);
    }
}

template <class T>
constexpr bool less(const T &lhs, const T &rhs) {
    return lhs < rhs;
}

#endif // INCLUDE_SOURCE_HPP_
