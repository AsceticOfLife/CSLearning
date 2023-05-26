/*
 * @Author: Guomw
 * @Date: 2023-04-19 09:25:19
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-19 11:28:34
 * @Description: 冒泡排序算法
 */

#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_
#include <vector>
#include <utility>

/**
 * @description: 最简单排序，每次遍历后面待排序序列部分并交换较小值
 * @param {vector<T>} &L: 待排序列表
 * @param {bool} ascending: deault=true
 * 默认升序排列
 * @return {*}
 */
template <typename T>
void bubble_sort0(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    for (int i = 0; i < len; i++) {
        // traverse the rest part
        for (int j = i + 1; j < len; j++) {
            // swap element at i and j if L[j] is smaller than L[i]
            if (L[j] < L[i]) std::swap(L[i], L[j]);
        }
    } // end for i in range [1, len)

    if (!ascending) {
        std::vector<T> L_copy(L.rbegin(), L.rend());
        L = L_copy;
    }
}

/**
 * @description: 冒泡排序，每次从待排序部分从后向前不断交换较小值
 * @param {vector<T>} &L: 待排序列表
 * @param {bool} ascending: deault=true
 * 默认升序排列
 * @return {*}
 */
template <typename T>
void bubble_sort1(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    for (int i = 0; i < len; i++) {
        // reversely traverse the rest part
        for (int j = len - 1; j > i; j--) {
            // swap two elements if front is bigger than back
            if (L[j - 1] > L[j]) std::swap(L[j-1], L[j]);
        }
    }

    if (!ascending) {
    std::vector<T> L_copy(L.rbegin(), L.rend());
    L = L_copy;
    }
}


/**
 * @description: 冒泡排序优化，当某一次发现没有数据交换时则提前结束排序
 * @param {vector<T>} &L: 待排序列表
 * @param {bool} ascending: deault=true
 * 默认升序排列
 * @return {*}
 */
template <typename T>
void bubble_sort2(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    bool flag = true;
    for (int i = 0; i < len && flag; i++) {
        flag = false;   // set to true if swap is happen in this time, else set to false
        // reversely traverse the rest part
        for (int j = len - 1; j > i; j--) {
            // swap two elements if front is bigger than back
            if (L[j - 1] > L[j]) {
                std::swap(L[j-1], L[j]);
                flag = true;
            }
        }
    }

    if (!ascending) {
    std::vector<T> L_copy(L.rbegin(), L.rend());
    L = L_copy;
    }
}

#endif