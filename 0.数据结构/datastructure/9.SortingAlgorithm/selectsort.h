/*
 * @Author: Guomw
 * @Date: 2023-04-19 11:09:42
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-19 16:05:14
 * @Description: 简单选择排序算法
 */

#ifndef SELECT_SORT_H_
#define SELECT_SORT_H_
#include <vector>
#include <utility>

template <typename T>
void select_sort(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    int min_index;
    for (int i = 0; i < len; i++) {
        min_index = i; 
        // traverse through rest part to find the min_index
        for (int j = i + 1; j < len; j++) {
            (L[min_index] > L[j]) ? min_index = j : min_index;
        }
        // swap element at i and element at min_index
        std::swap(L[min_index], L[i]);
    }

    if (!ascending) {
        std::vector<T> L_copy(L.rbegin(), L.rend());
        L = L_copy;
    }
}

#endif
