#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Trace.h"
#include <iostream>
#include <vector>

template <class T>
class vector
{
public:
    vector(int i) : v(i)
    {
        TRACE(dummy, "vector<T>::vector(int)");
        ++count;
        COUNT()
    }
    ~vector()
    {
        TRACE(dummy, "vector<T>::~vector");
        COUNT()
        --count;
    }
    T &elem(int i) { return v[i]; }
    T &operator[](int i) { return elem(i); }

    void swap(vector &);

private:
    static int count;
    std::vector<T> v;
    int sz;
};

template <>
class vector<void *>
{
public:
    vector()
    {
        TRACE(dummy, "vector<void*>::vector()");
        ++count;
        COUNT()
    }
    ~vector()
    {
        TRACE(dummy, "vector<void*>::~vector");
        COUNT()
        --count;
    }
    vector(int i) : v(i)
    {
        TRACE(dummy, "vector<void*>::vector(int)");
        ++count;
        COUNT()
    }
    void *&operator[](int i) { return v[i]; }
    void *&elem(int i) { return operator[](i); }

private:
    static int count;
    std::vector<void *> v;
};

template <class T>
class vector<T *> : private vector<void *>
{
public:
    typedef vector<void *> Base;
    vector() : Base() { TRACE(dummy, "vector<T*>::vector()"); }
    explicit vector(int i) : Base(i) { TRACE(dummy, "vector<T*>::vector(int)"); }
    ~vector() { TRACE(dummy, "vector<T*>::~vector"); }

    T *&elem(int i) { return (T *&)(Base::elem(i)); }
    T *&operator[](int i) { return (T *&)(Base::operator[](i)); }
};

template <class T>
int vector<T>::count = 0;

#endif