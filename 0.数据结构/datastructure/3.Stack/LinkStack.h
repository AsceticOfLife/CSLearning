/*
 * @Author: Guomw
 * @Date: 2023-04-17 11:24:56
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-17 21:58:02
 * @Description: 
 */

#ifndef LINK_STACK_H_
#define LINK_STACK_H_
#include <iostream>

template <typename DataType> class LinkStack;

template <typename T>
std::ostream & operator<<(std::ostream &os, const LinkStack<T> &stack);

template <typename DataType>
class LinkStack {
private:
    struct Node {
        DataType data;
        Node *next;
        Node(DataType e, Node *p = nullptr) : data(e), next(p) {}
    };

    Node *top;
    int length;
protected:
    Node * Get() const { return top; }
public:
    enum Status {ERROR = 0, OK = 1};
    explicit LinkStack() : top(nullptr), length(0) {}
    ~LinkStack();

    // Disabled member function
    LinkStack(const LinkStack &) = delete;
    LinkStack & operator=(const LinkStack &) = delete;

    // inerfaces
    bool IsEmpty() const { return top == nullptr; }
    int Length() const { return length; }
    Status ClearStack();
    Status GetTop(DataType &e) const;
    Status Push(const DataType &e);
    Status Pop();

    // friend function
    friend std::ostream & operator<<<>(std::ostream &os, const LinkStack<DataType> &stack);    

};

// destructor
template <typename DataType> LinkStack<DataType>::~LinkStack() {
    if (!IsEmpty()) ClearStack();
}

// interface implementation
/**
 * @description: clear the stack
 * @return {Status}: 正常或异常状态
 */
template <typename DataType>
typename LinkStack<DataType>::Status
    LinkStack<DataType>::ClearStack() {
    if (!IsEmpty()) {
        Node *temp = top;
        while (top) {
            top = top->next;
            delete temp;
            temp = top;
        }
    }
    return OK;
}

/**
 * @description: get top of stack
 * @return {Status}: OK or ERROR
 */
template <typename DataType>
typename LinkStack<DataType>::Status
    LinkStack<DataType>::GetTop(DataType &e) const {
    if (IsEmpty()) return ERROR;

    e = top->data;

    return OK;
}

/**
 * @description: Push data to stack
 * @return {Status}: OK or ERROR
 */
template <typename DataType>
typename LinkStack<DataType>::Status
    LinkStack<DataType>::Push(const DataType &e) {
    Node *temp = new Node(e, top);

    top = temp;
    length++;
    return OK;
}

/**
 * @description: Pop top data from stack
 * @return {Status}: OK or ERROR
 */
template <typename DataType>
typename LinkStack<DataType>::Status
    LinkStack<DataType>::Pop() {
    if (IsEmpty()) return ERROR;

    Node *temp = top;
    top = temp->next;
    delete temp;
    length--;

    return OK;
}

template <typename T>
std::ostream & operator<<(std::ostream &os, const LinkStack<T> &stack) {
    if (stack.IsEmpty()) return os << "Stack is Empty.";

    typename LinkStack<T>::Node *temp = stack.Get();
    while (temp) {
        os << temp->data << ' ';
        temp = temp->next;
    }

    return os;
}

#endif
