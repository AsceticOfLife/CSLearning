/*
 * @Author: Guomw
 * @Date: 2023-04-19 19:35:06
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-20 09:15:56
 * @Description: 2-路归并排序
 */

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_
#include <vector>

template <typename T>
void merge_core(std::vector<T> &L, std::vector<T> &S,  int start, int end);
template <typename T>
void merge(std::vector<T> &SL, std::vector<T> &TL, int start, int m, int end);

/**
 * @description: 归并排序
 * @param {vector<T>} &L: 待排序列表
 * @param {bool} ascending
 * @return {*}
 */
template <typename T>
void merge_sort(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    merge_core(L, L, 0, len - 1);

    if (!ascending) {
        std::vector<T> L_copy(L.rbegin(), L.rend());
        L = L_copy;
    }
}

/**
 * @description: 将列表L[start, ..., end]归并排序到列表S[start, ..., end]中
 * @param {vector<T>} &L: 待排序列表
 * @param {vector<T>} &S: 用于装载排序完成元素的列表，可与L相同
 * @param {int} start: 开始下标
 * @param {int} end: 结尾下标
 * @return {*}
 */
template <typename T>
void merge_core(std::vector<T> &L, std::vector<T> &S,  int start, int end) {
    if (start == end) S[start] = L[start];
    else {
        std::vector<T> temp(L.size());
        int m = (start + end) / 2;
        merge_core(L, temp, start, m);
        merge_core(L, temp, m + 1, end);
        merge(temp, S, start, m, end);
    }
}

/**
 * @description: 将列表SL[start, ..., m]与列表SL[m+1, ..., end]合并到TL[start, ..., end]
 * @param {vector<T>} &SL: 源列表
 * @param {vector<T>} &TL: 目标列表
 * @param {int} start: 开始下标
 * @param {int} m: 中间下标
 * @param {int} end: 结尾下标
 * @return {*}
 */
template <typename T>
void merge(std::vector<T> &SL, std::vector<T> &TL, int start, int m, int end) {
    int i, j;
    int p = start;
    for (i = start, j = m + 1; i <= m && j <= end; p++) {
        if (SL[i] < SL[j]) TL[p] = SL[i++];
        else TL[p] = SL[j++];
    }

    if (i <= m) {
        for (; i <= m; i++) TL[p++] = SL[i];
    }

    if (j <= end) {
        for (; j <= end; j++) TL[p++] = SL[j];
    }
}

template <typename T>
void mergepass(std::vector<T> &SL, std::vector<T> &TL, int k);
template <typename T>
void merge2(std::vector<T> &SL, std::vector<T> &TL, int start, int m, int end);
/**
 * @description: 非递归方式进行2-路归并排序
 * @param {vector<T>} &L: 待排序列表
 * @param {bool} ascending: default is true, 默认按照升序排列
 * @return {*}
 */
template <typename T>
void merge_sort2(std::vector<T> &L, bool ascending = true) {
    int len = L.size();
    if (len == 0) return;

    std::vector<T> temp(len);
    int k = 1;
    while (k < len) {
        mergepass(L, temp, k);
        k *= 2;
        mergepass(temp, L, k);
        k *= 2;
    }

    if (!ascending) {
        std::vector<T> L_copy(L.rbegin(), L.rend());
        L = L_copy;
    }

}

/**
 * @description: 将列表SL中的元素相邻两个元素个数为k的列表归并
 * @param {vector<T>} &SL: 源列表
 * @param {vector<T>} &TL: 目标列表
 * @param {int} k: 参数2-路归并的列表元素个数
 * @return {*}
 */
template <typename T>
void mergepass(std::vector<T> &SL, std::vector<T> &TL, int k) {
    int len = SL.size();
    int i = 1;
    // note: 由于下标需要参与运算，所以下标的范围在运算时是[1, length]
    // 访问列表时需要将下标减一
    while (i <= 1 + len - 2 * k) {
        merge2(SL, TL, i, i + k - 1, i + 2 * k - 1);
        i = i + 2 * k;
    }

    if (i < len - k + 1) merge2(SL, TL, i, i + k - 1, len);
    else {
        for (int j = i; j <= len; j++) 
            TL[j - 1] = SL[j - 1];  
    }
}

/**
 * @description: 将列表SL[start, ..., m]与列表SL[m+1, ..., end]合并到TL[start, ..., end]
 * @param {vector<T>} &SL: 源列表
 * @param {vector<T>} &TL: 目标列表
 * @param {int} start: 开始下标，note: 下标的范围是[1, length]
 * @param {int} m: 中间下标
 * @param {int} end: 结尾下标
 * @return {*}
 */
template <typename T>
void merge2(std::vector<T> &SL, std::vector<T> &TL, int start, int m, int end) {
    int i, j;
    int p = start;
    for (i = start, j = m + 1; i <= m && j <= end; p++) {
        if (SL[i - 1] < SL[j - 1]) {
            TL[p - 1] = SL[i - 1];
            i++;
        }
        else {
            TL[p- 1] = SL[j - 1];
            j++;
        } 
    }

    if (i <= m) {
        for (; i <= m; i++) {
            TL[p - 1] = SL[i - 1];
            p++;
        }
    }

    if (j <= end) {
        for (; j <= end; j++){
            TL[p - 1] = SL[j - 1];
            p++;
        } 
    }    
}

#endif