/*
 * @Author: Guomw
 * @Date: 2023-04-18 09:06:39
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-18 09:49:38
 * @Description: 
 */

#ifndef SEQUENCE_QUEUE_H_
#define SEQUENCE_QUEUE_H_
#include <iostream>

template <typename, int> class SqQueue;
template <typename T, int C>
std::ostream &operator<<(std::ostream &os, const SqQueue<T, C> &queue);

template <typename DataType, int MaxSize = 10>
class SqQueue {
private:
    static const int max_size = MaxSize + 1;
    DataType data[max_size];
    int front;
    int rear;
protected:
    void showall(std::ostream &os) const;
public:
    SqQueue() : front(0), rear(0) {}
    ~SqQueue() {}

    // public nested type
    enum Status {ERROR, OK};
    // interface
    bool IsEmpty() const { return front == rear; }
    int Length() const { return (rear - front + max_size) % max_size; }
    Status Clear() { front = rear = 0; return OK; }
    Status GetHead(DataType &e) const;
    Status EnQueue(const DataType &e);
    Status DeQueue();

    // friend functions
    friend std::ostream &operator<<<>(std::ostream &os, const SqQueue<DataType, MaxSize> &queue);
};

// protected method
template <typename DataType, int MaxSize>
void SqQueue<DataType, MaxSize>::showall(std::ostream &os) const {
    int i = front;
    while (i != rear) {
        os << data[i] << ' ';

        i = (i + 1) % max_size;
    }
}

// interface implementation
/**
 * @description: get head of queue
 * @return {Status}: status of operation, ERROR for error
 * and OK for success
 */
template <typename DataType, int MaxSize>
typename SqQueue<DataType, MaxSize>::Status
    SqQueue<DataType, MaxSize>::GetHead(DataType &e) const {
    if (IsEmpty()) return ERROR;

    e = data[front];
    
    return OK;
}

/**
 * @description: enter element into queue
 * @return {Status}: status of operation, ERROR for error
 * and OK for success
 */
template <typename DataType, int MaxSize>
typename SqQueue<DataType, MaxSize>::Status
    SqQueue<DataType, MaxSize>::EnQueue(const DataType &e) {
    if ((rear + 1) % max_size == front) {
        std::cerr << "queue is full" << std::endl;
        return ERROR;
    }
    data[rear] = e;
    rear = (rear + 1) % max_size;
    
    return OK;
}

/**
 * @description: delete element from queue
 * @return {Status}: status of operation, ERROR for error
 * and OK for success
 */
template <typename DataType, int MaxSize>
typename SqQueue<DataType, MaxSize>::Status
    SqQueue<DataType, MaxSize>::DeQueue() {
    if (IsEmpty()) return ERROR;

    front = (front + 1) % max_size;

    return OK;
}

template <typename T, int C>
std::ostream &operator<<(std::ostream &os, const SqQueue<T, C> &queue) {
    if (queue.IsEmpty()) return os << "Queue is empty.";

    queue.showall(os);
    return os;
}

#endif