/*
 * @Author: Guomw
 * @Date: 2023-04-19 15:52:38
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-19 17:21:47
 * @Description: 堆排序
 */

#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_
#include <vector>
#include <utility>

template <typename T>
void adjust_heap(std::vector<T> &L, int root, int size);

/**
 * @description: 堆排序算法，使用最大堆，即最大元素作为根结点
 * 注意：这里下标是在运算时是[1, length]，在访问序列时是[0, length - 1]
 * @param {vector<T>} &L: 待排序列表
 * @param {bool} ascending: default = true，默认按升序排列
 * @return {*}
 */
template <typename T>
void heap_sort(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    int branch_index = len / 2;
    // adjust heap
    for (int i = branch_index; i > 0; i--)
        adjust_heap(L, i, len);

    // swap first element and last element of heap
    // then adjust heap
    for (int i = len; i > 1; i--) {
        std::swap(L[1 - 1], L[i - 1]);
        adjust_heap(L, 1, i - 1);
    }

    if (!ascending) {
        std::vector<T> L_copy(L.rbegin(), L.rend());
        L = L_copy;
    }
}

/**
 * @description: 调整列表成为最大堆
 * @param {vector<T>} &L: 待调整堆列表
 * @param {int} root: 堆的根结点下标
 * @param {int} size: 堆的最后一个元素下标
 * @return {*}
 */
template <typename T>
void adjust_heap(std::vector<T> &L, int root, int size) {
    T temp = L[root - 1]; // 保存根结点
    // traverse root tree, not only sons of root
    for (int son = root * 2; son <= size; son *= 2) {
        // find the bigger son
        if (son < size && L[son - 1] < L[son + 1 - 1]) son++;
        // if the bigger son is smaller than root
        // note: compare to temp, not L[root], because index root changed
        if (temp >= L[son - 1]) break;

        // set the bigger son to root
        // and set root to the bigger son
        L[root - 1] = L[son - 1];
        root = son;
    }

    // find right positon for root
    L[root - 1] = temp;
}


#endif
