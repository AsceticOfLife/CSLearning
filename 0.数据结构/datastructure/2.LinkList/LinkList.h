#ifndef LINKLIST_H_
#define LINKLIST_H_
#include <iostream>

template <class T> class LinkList;
template <typename T>
std::ostream & operator<<(std::ostream &os, const LinkList<T> &ll);

template <class T>
class LinkList {
private:
    struct Node {
        T data;
        Node *next;
        // constructor
        Node() : next(nullptr) {}
    };

    Node *linklist;
    int length;

public:
    enum Status {ERROR = false, OK = true, TRUE = true, FALSE = false};

    LinkList();
    LinkList(const LinkList &other);
    ~LinkList();

    auto IsEmpty() const -> Status;
    int Length() const;
    Status Clear();
    Status Get(int i, T &val) const;
    Status Set(int i, T &val);
    int Find(T &val) const;
    Status Insert(int i, T &val);
    Status Delete(int i);

    LinkList & operator=(const LinkList &other);

    friend std::ostream & operator<<<>(std::ostream &os, const LinkList<T> &other);
};

// constructor and destructor
template <class T>
LinkList<T>::LinkList() : length(0) {
    linklist = new Node; // head node
}

template <class T>
LinkList<T>::LinkList(const LinkList &other) {
    length = other.length;

    linklist = new Node; // head node
    Node *rear = linklist;   // aid points to the last node

    Node *temp;
    Node *p = other.linklist->next;    // travelling points to every node
    while (p) {
        temp = new Node;
        temp->data = p->data; // create new node

        rear->next = temp;  // link temp node to the last node
        rear = temp;    // keep rear points to end

        p = p->next;
    }

    std::cout << "copy constructor!\n";
}

template <class T>
LinkList<T>::~LinkList() {
    Node *p;
    while (linklist) {
        p = linklist;
        linklist = linklist->next;

        delete p;
    }
}

//* 1.is empty or not
template <class T>
auto LinkList<T>::IsEmpty() const -> LinkList<T>::Status {
    if (length == 0) return TRUE;
    else return FALSE;
}

//* 2.length
template <class T>
int LinkList<T>::Length() const {
    return length;
}

//* 3.clear linklist
template <class T>
typename LinkList<T>::Status LinkList<T>::Clear() {
    Node *p;
    Node *rear = linklist->next;
    while (rear) {
        p = rear;
        rear = rear->next;

        delete p;
    }
    length = 0;

    return TRUE;
}

//* 4.get th i-th element
template <class T>
typename LinkList<T>::Status LinkList<T>::Get(int i, T &val) const {
    if (i < 1 || i > length) return ERROR;

    Node *p = linklist->next;
    for (int j = 1; j < i; j++) {
        p = p->next;
    }

    val = p->data; // get the value
    return OK;
}

//*5 set th i-th element to val
template <class T>
typename LinkList<T>::Status LinkList<T>::Set(int i, T &val) {
    if (i < 1 || i > length) return ERROR;

    Node *s = linklist->next;
    // find the (i-1)th element
    for (int k = 1; k < i; k++) {
        s = s->next;
    }

    s->data = val;  // mpdify the value
    return OK;
}

//* 6.return index if finf element which is equal to val
//* else return -1
template <class T>
int LinkList<T>::Find(T &val) const {
    int i;
    Node *s = linklist->next;
    for (i = 0; i < length; i++) {
        if (s->data == val) return i + 1;

        s = s->next;
    }

    return -1;
}

//* 6.insert new element at index
template <class T>
typename LinkList<T>::Status LinkList<T>::Insert(int i, T &e) {
    if (i < 1 || i > length + 1) return ERROR;

    Node *temp = new Node;
    temp->data = e;
    Node *s = linklist;
    for (int k = 0; k < i - 1; k++) {
        s = s->next;
    }

    temp->next = s->next; // link to the old i-th element
    s->next = temp; // link to the new i-th element

    length++;
    return OK;
}

//* 7.delete the i-th element
template <class T>
typename LinkList<T>::Status LinkList<T>::Delete(int i) {
    if (i < 1 || i > length) return ERROR;

    Node *s = linklist;
    for (int k = 0; k < i - 1; k++) {
        s = s->next;
    }

    Node *temp = s->next;
    s->next = temp->next;
    delete temp;

    length--;
    return OK;
}

template <class T>
LinkList<T> & LinkList<T>::operator=(const LinkList<T> &other) {
    if (&other == this) return *this;
    this->Clear();

    length = other.length;
    Node *rear = linklist;   // aid points to the last node

    Node *temp;
    Node *p = other.linklist->next;    // travelling points to every node
    while (p) {
        temp = new Node;
        temp->data = p->data; // create new node

        rear->next = temp;
        rear = temp;    // keep rear points to end

        p = p->next;
    }
    std::cout << "assignment operator !\n";
    return *this;
}

template <typename T>
std::ostream & operator<<(std::ostream &os, const LinkList<T> &ll) {
    if (ll.IsEmpty()) os << "LinkList is empty!";
    else {
        // typename LinkList<T>::Node *s = ll.linklist->next;
        decltype(ll.linklist) s = ll.linklist->next;
        while (s) {
            os << s->data << ' ';
            s = s->next;
        }
    }

    return os;
}

#endif