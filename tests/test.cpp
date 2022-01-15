// Copyright 2020 Maria mari.zabrodina.01@mail.ru

#include <gtest/gtest.h>
#include <source.hpp>
#include <vector>

TEST(Sorting, Merge){
    std::vector<int> ar1 = {1, 3, 5, 7, 9, 11, 11, 12};
    std::vector<int> ar2 = {2, 4, 6, 8, 10, 11, 13};
    std::vector<int> ar3(15);
    ar3 = merge(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), ar3, std::less<>{});
    std::vector<int> result = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 11, 11, 12, 13}
    EXPECT_EQ(ar3, result);
    std::vector<double> ar4 = {26.5, 47.05, 54.9, 103.8, 103.9, 372.5};
    std::vector<double> ar5 = {26.5, 27.2, 78.6, 103.8, 257.2, 291};
    std::vector<double> ar6(12), ar7(12);
    ar6 = merge(ar4.begin(), ar4.end(), ar5.begin(), ar5.end(), ar6, std::less<>{});
    ar7 = merge(ar5.begin(), ar5.end(), ar4.begin(), ar4.end(), ar7, std::less<>{});
    std::vector<double> result2 = {26.5, 26.5, 27.2, 47.05, 54.9, 78.6, 103.8, 103.8, 103.9, 257.2, 291, 372.5};
    EXPECT_DOUBLE_EQ(ar6, result2);
    EXPECT_DOUBLE_EQ(ar6, ar7);
    EXPECT_DOUBLE_EQ(ar7, result2);
}
TEST(Sorting, MergeSort){
    std::vector<int> ar1 = {2, 9, 10, 72, 323, 100, 7, 3, 10, 352, 8};
    std::vector<int> ar2(11);
    ar2 = merge_sort(ar1.begin(), ar1.end(), ar2);
    std::vector<int> result = {2, 3, 7, 8, 9, 10, 10, 72, 100, 323, 352};
    EXPECT_EQ(ar2, result);
    std::vector<double> ar4 = {2.3, 9.5, 1.04, 72.8, 323, 10.0, 7.3, 3.2, 10, 352, 8.1};
    std::vector<double> ar5(11);
    ar5 = merge_sort(ar4.begin(), ar4.end(), ar5);
    std::vector<double> result2 = {1.04, 2.3, 3.2, 7.3, 8.1, 9.5, 10, 10, 72.8, 323, 352};
    EXPECT_DOUBLE_EQ(ar5, result2);
}
TEST(Sorting, InplaceMergeSort){
    std::vector<int> arr = {1, 9, 2, 7, 4, 10, 3, 8, 6, 5, 0};
    inplace_merge_sort(arr.begin(), arr.end(), std::less<>{});
    std::vector<int> result = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(arr.size(), result.size());
    EXPECT_EQ(arr, result);
}
TEST(Sorting, HeapSort){
    std::vector<int> arr = {2, 9, 10, 72, 323, 100, 7, 3, 10, 352, 8};
    std::vector<int> result = {2, 3, 7, 8, 9, 10, 10, 72, 100, 323, 352};
    EXPECT_NE(arr,result);
    heap_sort(arr.begin(), arr.end(), std::less<>{});
    EXPECT_EQ(arr, result);
}
TEST(Sorting, QuickSort){
    std::vector<int> ar = {78, 26, 103, 27, 47, 54, 372, 291, 103, 257};
    quick_sort(ar.begin(), ar.end(), std::less<>{});
    std::vector<int> result = {26, 27, 47, 54, 78, 103, 103, 257, 291, 372};
    EXPECT_EQ(ar, result);
}
TEST(Sorting, InsertionSort){
    std::vector<double> arr = {78.6, 26.5, 103.8, 27.2, 47.05, 54.9, 372.5, 291, 103.9, 257.2};
    insertion_sort(arr.begin(), arr.end(), std::less<>{});
    std::vector<double> result = {26.5, 27.2, 47.05, 54.9, 78.6, 103.8, 103.9, 257.2, 291, 372.5};
    EXPECT_EQ(arr.size(), result.size());
    EXPECT_DOUBLE_EQ(arr, result);
}

