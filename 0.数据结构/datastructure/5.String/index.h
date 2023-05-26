/*
 * @Author: Guomw
 * @Date: 2023-04-22 19:39:46
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-23 09:16:04
 * @Description: 字符串模式匹配算法
 */

#ifndef INDEX_H_
#define INDEX_H_
#include <string>
#include <vector>

int Index(const std::string &S, const std::string &T, int pos = 0);
void get_next(const std::string &T, std::vector<int> &next);
int Index_KMP(const std::string &S, const std::string &T, int pos = 0);

#endif
