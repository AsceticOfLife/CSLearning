/*
 * @Author: Guomw
 * @Date: 2023-04-22 19:41:58
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-16 21:42:19
 * @Description: 字符串模式匹配算法实现
 */

#include "5.String/index.h"

/**
 * @description: 朴素字符串匹配算法
 * @param {string} &S: 源字符串
 * @param {string} &T: 子字符串
 * @param {int} pos: S字符串起点
 * @return {int} index: T在S中首次出现的下标 
 */
int Index(const std::string &S, const std::string &T, int pos) {
    int s_len = S.length();
    int t_len = T.length();

    int i = pos, j = 0;
    while (i < s_len && j < t_len) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1; // back to next char of beginning last time
            j = 0;
        }
    }

    if (j == t_len) return i - t_len;
    else return -1;
}


void get_next(const std::string &T, std::vector<int> &next) {
    int i = 1, j = 0;
    next[0] = 0;
    int len  = T.length();

    while (i < len) {
        if (T[i] == T[j]) {
            // 第i个相等对应第i+1不匹配时的情况
            ++i; // i增加表示这是第i+1个字符的next值
            ++j; // j增加表示next值指向相等前缀的后一个字符
            // 原始
            // next[i] = j;

            // 改进：这个过程描述的是当出现不匹配时，要根据next数组选择 j 的位置
            // 即当前字符不与S串匹配，那么考虑next指向的字符（也就是前缀字符）是否与当前字符相同
            // 如果相同说明两个字符都不会与这个S串中的字符相等，因此可以把next指向的字符（前缀字符）对应next值给这个字符
            if (T[i] != T[j]) next[i] = j;
            else next[i] = next[j];
            
        } else if (j == 0) {
            // 对应前缀第一个字符就不等的情况
            ++i;
            next[i] = j;
        } else {
            // j回溯，与字符串匹配时类似
            j = next[j];
        }
    }

}

int Index_KMP(const std::string &S, const std::string &T, int pos) {
    int s_len = S.length();
    int t_len = T.length();
    // 创建next列表
    std::vector<int> next(t_len);
    get_next(T, next);
    
    int i = pos;
    int j = 0;
    while (i < s_len && j < t_len) {
        if (S[i] == T[j]) {
            ++i;
            ++j;
        } else if (j == 0) {
            ++i;
        } else {
            j = next[j];
        }
    }

    if (j == t_len) return i - t_len;
    else return -1;
}

