/*
 * @Author: Guomw
 * @Date: 2023-04-17 08:29:18
 * @LastEditors: Guomw isguo_mw@163.com
 * @LastEditTime: 2023-04-17 10:01:07
 * @FilePath: \datastructure\3.stack\SequenceStack.h
 * @Description: 
 * Implementation of SequenceStack template
 * Copyright (c) 2023 by Guomw, All Rights Reserved. 
 */
#ifndef SEQUENCE_STACK_H_
#define SEQUENCE_STACK_H_
#include <iostream>

template <typename DataType, int MaxSize> class SqStack;
template <typename T, int C>
std::ostream &operator<<(std::ostream &os, SqStack<T, C> const &stack);

template <typename DataType, int MaxSize = 100>
class SqStack {
private:
    DataType data[MaxSize];
    int top;
protected:
    DataType GetData(int i) const { return data[i]; }
public:
    enum Status {ERROR = 0, OK = 1};
    SqStack() : top(-1) {}
    ~SqStack() {}

    Status ClearStack() { top = -1; return OK;};
    bool IsEmpty() const { return top == -1; };
    int Length() const { return top + 1; };
    Status GetTop(DataType &e) const;
    Status Push(const DataType &e);
    Status Pop();

    friend std::ostream & operator<<<>(std::ostream &os, const SqStack<DataType, MaxSize> &stack);
};

template <typename DataType, int MaxSize>
typename SqStack<DataType, MaxSize>::Status
    SqStack<DataType, MaxSize>::GetTop(DataType &e) const {
    if (IsEmpty()) return ERROR;

    e = data[top];
    return OK;
}

template <typename DataType, int MaxSize>
typename SqStack<DataType, MaxSize>::Status
    SqStack<DataType, MaxSize>::Push(const DataType &e) {
    if (top == MaxSize - 1) return ERROR;

    data[++top] = e;
    return OK;
}

template <typename DataType, int MaxSize>
typename SqStack<DataType, MaxSize>::Status
    SqStack<DataType, MaxSize>::Pop() {
    if (IsEmpty()) return ERROR;

    top--;
    return OK;
}


template <typename T, int C>
std::ostream & operator<<(std::ostream &os, SqStack<T, C> const &stack) {
    if (stack.IsEmpty()) return os << "The stack is empty.";

    for (int i = 0; i < stack.Length(); i++) {
        os << stack.GetData(i) << ' ';
    }

    return os;
}

#endif
