/*
 * @Author: Guomw
 * @Date: 2023-04-19 15:09:52
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-19 16:05:28
 * @Description: 希尔排序
 */

#ifndef SHELL_SORT_H__
#define SHELL_SORT_H__
#include <vector>

template <typename T>
void shell_sort(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    int delta = len; // 增量gap
    do {
        delta /= 2;
        // 间隔为delta的序列进行直接插入排序
        for (int i = 0 + delta; i < len; i++) {
            // insert L[i] at ordered list
            if (L[i] < L[i - delta]) {
                int sentinel = L[i];

                // move backward
                int j = i - delta;
                while (L[j] > sentinel && j >= 0) {
                    L[j + delta] = L[j];
                    j -= delta;
                } // end while L[j] > sentinel

                // move sentinel to right position
                L[j + delta] = sentinel;
            } // end if L[j] is smaller

        } // end for 

    } while (delta > 1);

    if (!ascending) {
        std::vector<T> L_copy(L.rbegin(), L.rend());
        L = L_copy;
    }
}

#endif
