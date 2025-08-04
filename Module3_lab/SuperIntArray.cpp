#include "SuperIntArray.h"

SuperIntArray::SuperIntArray() {
    nums = nullptr;
    numberOfNums = 0;
}

SuperIntArray::SuperIntArray(int arr[], int size) {
    numberOfNums = size;
    nums = new int[size];
    for (int i = 0; i < size; ++i)
        nums[i] = arr[i];
}

SuperIntArray::SuperIntArray(int num) {
    numberOfNums = 1;
    nums = new int[1];
    nums[0] = num;
}

SuperIntArray::SuperIntArray(const SuperIntArray& other) {
    numberOfNums = other.numberOfNums;
    nums = new int[numberOfNums];
    for (int i = 0; i < numberOfNums; ++i)
        nums[i] = other.nums[i];
}

SuperIntArray::~SuperIntArray() {
    delete[] nums;
}

int* SuperIntArray::getNums() const { return nums; }
int SuperIntArray::getSize() const { return numberOfNums; }

void SuperIntArray::add(int num) {
    int* newArray = new int[numberOfNums + 1];
    for (int i = 0; i < numberOfNums; ++i)
        newArray[i] = nums[i];
    newArray[numberOfNums++] = num;
    delete[] nums;
    nums = newArray;
}

int SuperIntArray::get(int index) const { return nums[index]; }

void SuperIntArray::change(int index, int value) { nums[index] = value; }

SuperIntArray& SuperIntArray::operator=(const SuperIntArray& right) {
    if (this != &right) {
        delete[] nums;
        numberOfNums = right.numberOfNums;
        nums = new int[numberOfNums];
        for (int i = 0; i < numberOfNums; ++i)
            nums[i] = right.nums[i];
    }
    return *this;
}

SuperIntArray SuperIntArray::operator+(const SuperIntArray& right) {
    SuperIntArray result;
    result.numberOfNums = numberOfNums + right.numberOfNums;
    result.nums = new int[result.numberOfNums];
    for (int i = 0; i < numberOfNums; ++i)
        result.nums[i] = nums[i];
    for (int i = 0; i < right.numberOfNums; ++i)
        result.nums[numberOfNums + i] = right.nums[i];
    return result;
}

int& SuperIntArray::operator[](int index) { return nums[index]; }

ostream& operator<<(ostream& stream, const SuperIntArray& right) {
    for (int i = 0; i < right.numberOfNums; ++i) {
        stream << right.nums[i];
        if (i < right.numberOfNums - 1)
            stream << ", ";
    }
    return stream;
}

int SuperIntArray::getMax(int nums[], int size) {
    int max = nums[0];
    for (int i = 1; i < size; ++i)
        if (nums[i] > max) max = nums[i];
    return max;
}

int SuperIntArray::getMin(int nums[], int size) {
    int min = nums[0];
    for (int i = 1; i < size; ++i)
        if (nums[i] < min) min = nums[i];
    return min;
}

double SuperIntArray::getMean(int nums[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i)
        total += nums[i];
    return static_cast<double>(total) / size;
}
