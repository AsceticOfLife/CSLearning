/*
 * @Author: Guomw
 * @Date: 2023-04-19 11:29:35
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-19 15:10:48
 * @Description: 直接插入排序
 */

#ifndef SELECT_SORT_H_
#define SELECT_SORT_H_
#include <vector>

/**
 * @description: 直接插入排序，每次选择待排序部分的第一个元素插入到有序列表中
 * @param {vector<T>} &L: 待排序列表
 * @param {bool} ascending: default=true, 默认按升序排列
 * @return {*}
 */
template <typename T>
void insert_sort(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    T sentinel;
    // the first element is ordered so i in range [1, len)
    for (int i = 1; i < len; i++) {
        sentinel = L[i]; // set sentinel
        
        // move backward element for sentinel
        int j = i - 1;
        while (L[j] > sentinel && j >= 0) {
            L[j + 1] = L[j];
            j--;
        }

        // move sentinel
        L[j + 1] = sentinel;
    }

    if (!ascending) {
        std::vector<T> L_copy(L.rbegin(), L.rend());
        L = L_copy;
    }

}

#endif