/*
 * @Author: Guomw
 * @Date: 2023-04-20 09:17:18
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-20 10:56:15
 * @Description: 快速排序
 * 优化1.枢轴的选择采用三数取中法
 * 优化2.对于小序列使用直接插入排序
 * 优化3.利用循环减少递归深度
 */

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_
#include <vector>
#include <utility>
#include "insertsort.h"

// 使用快速排序算法的最小列表长度
// 否则使用直接插入排序
int Min_Length_Use_QuickSort = 50;

template <typename T>
void quick_core(std::vector<T> &L, int low, int high);
template <typename T>
int partition(std::vector<T> &L, int low, int high);

/**
 * @description:  快速排序
 * @param {vector<T>} &L: 待排序列表
 * @param {bool} ascending: default is ture, 默认按照升序排列
 * @return {*}
 */
template <typename T>
void quick_sort(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    quick_core(L, 0, len - 1);
    
    if (!ascending) {
        std::vector<T> L_copy(L.rbegin(), L.rend());
        L = L_copy;
    }
}

template <typename T>
void quick_core(std::vector<T> &L, int low, int high) {
    int pivot;
    // use quick sort only when length is more than Min_Length_Use_QuickSort
    // else use inserte sort which is more efficient in the three simplest sort algorithms
    if ((high - low) >= Min_Length_Use_QuickSort) {
        // 原始递归深度
        // pivot = partition(L, low, high);

        // quick_core(L, low, pivot - 1);
        // quick_core(L, pivot + 1, high);

        // 减少递归深度
        while (low < high) {
            pivot = partition(L, low, high);

            quick_core(L, low, pivot - 1);
            low = pivot - 1;
        }
    } else {
        insert_sort(L);
    }
}

template <typename T>
int partition(std::vector<T> &L, int low, int high) {
    T pivotkey;
    // 优化pivotkey选择：三数取中法
    int mid = (high + low) / 2;
    if (L[low] > L[high]) std::swap(L[low], L[high]);
    if (L[mid] > L[high]) std::swap(L[mid], L[high]);
    // 上面两步保证最大值在high
    if (L[mid] > L[low]) std::swap(L[mid], L[high]);
    // 保证中间的值在low位置

    pivotkey = L[low];
    while (low < high) {
        while (low < high && L[high] >= pivotkey)  high--;
        L[low] = L[high];

        while (low < high && L[low] <= pivotkey) low++;
        L[high] = L[low];
    }
    L[low] = pivotkey;
    return low;
}


#endif
