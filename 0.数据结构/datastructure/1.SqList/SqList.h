#ifndef SQLIST_H_
#define SQLIST_H_
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>

template <class Type>
class SqList;

template <typename T>
std::ostream &operator<<(std::ostream &os, const SqList<T> &sq);

template <class Type>
class SqList {
private:
    class SqError : public std::logic_error {
    public:
        SqError(const std::string what_msg) : std::logic_error(what_msg) {}
    };
    enum {MaxSize = 100};
    Type data[MaxSize];
    int length; // number of elements
protected:
    Type get(int inded) const;
    void set(int index, Type &value);
public:
    enum Status {ERROR = false, OK = true, TRUE = true, FALSE = false};
    SqList();

    bool IsEmpty() const;
    int Length() const;
    bool Clear();
    Type Get(int index) const;
    void Set(int index, Type &value);
    int Find(Type &value) const;
    bool Insert(int index, Type &value);
    bool Delete(int index);

    Type & operator[](int index);

    friend std::ostream &operator<<<>(std::ostream &os, const SqList<Type> &sq);
};

// protected methods
    // try to find element at index
template <class Type>
Type SqList<Type>::get(int index) const {
    if (index < 1 || index > length) {
        throw SqError("Invalid Index for Class SqList! return value 0 instead.");
    } else {
        return data[index - 1];
    }
}
    // try to modify element at index
template <class Type>
void SqList<Type>::set(int index, Type &value) {
    if (index < 1 || index > length) {
        throw SqError("Invalid Index! Modificaton is Failed!");
    } else {
        data[index - 1] = value;
    }
}

// public methods
    //* 1.initialization
template <class Type>
SqList<Type>::SqList() : length(0) {}

    //* 2.empty or not
template <class Type>
inline bool SqList<Type>::IsEmpty() const {
    return length == 0;
}

    //* 3.length
template <class Type>
inline int SqList<Type>::Length() const {
    return length;
}

    //* 4.clear the list
template <class Type>
inline bool SqList<Type>::Clear() {
    length = 0;
    return true;
}

    //* 5.get element at index
template <class Type>
Type SqList<Type>::Get(int index) const {
    try {
        return get(index);
    } catch (std::logic_error &e) {
        std::cerr << e.what() << '\n';
        return 0;
    }
}

    //* 6.set value to elements at index
template <class Type>
void SqList<Type>::Set(int index, Type &value) {
    try {
        set(index, value);
    } catch (std::logic_error &e) {
        std::cerr << e.what() << '\n';
    }
}

    //* 7.try to find which element is equal to value
    //* return index if sucessfully found
    //* else return 0
template <class Type>
int SqList<Type>::Find(Type &value) const {
    for (int i = 0; i < length; i++) {
        if (data[i] == value) return i + 1;
    }

    return 0;
}

    //* 8. insert value at index
template <class Type>
bool SqList<Type>::Insert(int index, Type &value) {
    if (index < 1 || index > length + 1) return false;
    if (length + 1 > MaxSize) return false;

    // if index is not at the end of the list
    if (index <= length) {
        for (int i = length - 1; i > index - 2; i--) {
            data[i + 1] = data[i];
        }
    }
    data[index - 1] = value;
    length++;
    return true;
}

    //* 9. delete value at index
template <class Type>
bool SqList<Type>::Delete(int index) {
    if (index < 1 || index > length) return false;
    for (int i = index - 1; i < length; i++) {
        data[i] = data[i + 1];
    }

    length--;
    return true;
}

template <class Type>
Type & SqList<Type>::operator[](int index) {
    if (index < 0 || index > length) {
        std::cerr << "Index out of range" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return data[index - 1];
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const SqList<T> &sq) {
    if (sq.IsEmpty()) {
        os << "SqList is empty!";
        return os;
    } else {
        for (int i = 0; i < sq.length; i++) {
            os << std::left;
            os << std::setw(5) << sq.data[i];
            os << std::right;
        }

        return os;
    }
}


#endif