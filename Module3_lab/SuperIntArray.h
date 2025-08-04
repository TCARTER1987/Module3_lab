#pragma once
#ifndef SUPERINTARRAY_H
#define SUPERINTARRAY_H

#include <iostream>
using namespace std;

class SuperIntArray {
private:
    int* nums;
    int numberOfNums;

public:
    SuperIntArray();
    SuperIntArray(int arr[], int size);
    SuperIntArray(int num);
    SuperIntArray(const SuperIntArray& other);
    ~SuperIntArray();

    int* getNums() const;
    int getSize() const;
    void add(int num);
    int get(int index) const;
    void change(int index, int value);

    SuperIntArray& operator=(const SuperIntArray& right);
    SuperIntArray operator+(const SuperIntArray& right);
    int& operator[](int index);
    friend ostream& operator<<(ostream& stream, const SuperIntArray& right);

    static int getMax(int nums[], int size);
    static int getMin(int nums[], int size);
    static double getMean(int nums[], int size);
};

#endif
