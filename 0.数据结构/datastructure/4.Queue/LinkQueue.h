/*
 * @Author: Guomw
 * @Date: 2023-04-18 16:49:58
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-18 20:07:18
 * @Description: 
 */

#ifndef LINK_QUEUE_H_
#define LINK_QUEUE_H_
#include <iostream>
template <typename DataType> class LinkQueue;
template <typename T>
std::ostream & operator<<(std::ostream &os, const LinkQueue<T> &queue);

template <typename DataType>
class LinkQueue {
private:
    struct Node {
        DataType data;
        Node *next;
        Node() : next(nullptr) {}
        Node(DataType e, Node *p = nullptr) : data(e), next(p) {}
    };
    typedef Node Queue;

    Queue *head;    // point to head node of queue
    Node *front;
    Node *rear;
    int length;
protected:
    void showall(std::ostream &os) const;
public:
    LinkQueue() : head(new Queue), front(head), rear(head), length(0) {}
    ~LinkQueue();

    // public nested type
    enum Status {ERROR, OK};
    // interface
    bool IsEmpty() const { return length == 0;}
    int Length() const { return length; }
    Status Clear();
    Status GetHead(DataType &e) const;
    Status EnQueue(const DataType &e);
    Status DeQueue(); 

    // friend functions
    friend std::ostream &operator<<<>(std::ostream &os, const LinkQueue<DataType> &queue);

};

// protected method
/**
 * @description: display queue
 * @return {*}
 */
template <typename DataType>
void LinkQueue<DataType>::showall(std::ostream &os) const {
    Node *temp = front;
    
    while (temp) {
        os << temp->data << ' ';
        temp = temp->next;
    }
}

// destructor
template <typename DataType>
LinkQueue<DataType>::~LinkQueue() {
    if (!IsEmpty()) {
        Clear();
        delete head;
    }
}

/**
 * @description: clear the queue
 * @return {Status}: status of operation, ERROR for error and OK for success
 */
template <typename DataType>
typename LinkQueue<DataType>::Status
    LinkQueue<DataType>::Clear() {
    if (IsEmpty()) return OK;

    Node *temp;
    while (front) {
        temp = front;
        front = front->next;
        delete temp;
    }

    length = 0;
    head->next = nullptr;

    return OK;
}

/**
 * @description: get head of queue
 * @return {Status}: status of operation, ERROR for error
 */
template <typename DataType>
typename LinkQueue<DataType>::Status
    LinkQueue<DataType>::GetHead(DataType &e) const {
    if (IsEmpty()) return ERROR;

    e = front->data;

    return OK;
}

/**
 * @description: enter element into queue
 * @return {Status}: status of operation, ERROR for error
 */
template <typename DataType>
typename LinkQueue<DataType>::Status
    LinkQueue<DataType>::EnQueue(const DataType &e) {
    Node *temp = new Node(e);

    rear->next = temp;
    rear = temp;
    if (front == head) front = head->next;
    
    length++;

    return OK;
}

/**
 * @description: delete element from queue
 * @return {Status}: status of operation, ERROR for
 */
template <typename DataType>
typename LinkQueue<DataType>::Status
    LinkQueue<DataType>::DeQueue() {
    if (IsEmpty()) return ERROR;

    Node *temp = front;
    if (front == rear) {
        rear = nullptr;
    } else {
        front = front->next;
    }
    delete temp;

    length--;

    return OK;
}

template <typename T>
std::ostream & operator<<(std::ostream &os, const LinkQueue<T> &queue) {
    if (queue.IsEmpty()) return os << "empty queue.";

    queue.showall(os);

    return os;
}




#endif
