/*
 * @Author: Guomw
 * @Date: 2023-04-18 21:42:49
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-04-18 22:03:23
 * @Description: 
 */

#ifndef MY_STRING_H_
#define MY_STRING_H_
#include <ostream>

class MyString {
private:
    char *data;
    int length;
public:
    // public nested type
    enum Status {ERROR, OK};

    // default constructor
    MyString() : data(nullptr), length(0) {};
    // constructor
    MyString(const char *str);
    MyString(int len, char ch);
    // copy constructor
    MyString(const MyString &other);
    // destructor
    ~MyString();

    // interface
    bool IsEmpty() const;
    int Length() const;
    bool Compare(const MyString &other) const;
    Status Concat(const MyString &other);
    Status SubString(int pos, int len, MyString &res);
    int Index(const MyString &other, int pos = 0) const;
    Status Replace(const MyString &other, const MyString &place);
    Status Insert(int pos, const MyString &other);
    Status Delete(int pos, int len);

    // operator overloading
    bool operator<(const MyString &rhs) const;
    bool operator==(const MyString &rhs) const;
    bool operator!=(const MyString &rhs) const;
    bool operator>(const MyString &rhs) const;
    bool operator<=(const MyString &rhs) const;
    bool operator>=(const MyString &rhs) const;

    bool operator+=(const MyString &rhs) const;

    char operator[](int i) const;
    char & operator[](int i);

    // friend functions
    friend std::ostream & operator<<(std::ostream &os, const MyString &str);
};


#endif