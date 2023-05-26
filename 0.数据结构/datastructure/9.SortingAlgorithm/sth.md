<!--
 * @Author: Guomw
 * @Date: 2023-04-19 09:15:34
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-19 11:23:36
 * @Description: 
-->

#### 排序算法数据存储结构
使用C++ STL 中的vector容器<br>，位于头文件vector中
vector\<int> L(MaxSize + 1)<br>
下标为0的位置预留出来<br>
遗留的问题是：使用排序算法就必须使用空出一个下标为0的vector
于是更改为不预留一个位置

#### 交换两个数据元素
使用C++ STL 中的swap算法<br>，位于头文件utility中
函数原型为：<br>
template \<class T> void swap(T &a, T &b);
