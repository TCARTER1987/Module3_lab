#include <iostream>
#include "SuperIntArray.h"
#include "Time.h"
#include "Term.h"
#include "Polynomial.h"

using namespace std;

int main() {
    cout << "=== SuperIntArray Demo ===" << endl;
    int data[] = { 1, 2, 3, 4 };
    SuperIntArray arr(data, 4);
    arr.add(5);
    arr.change(0, 10);
    cout << "Array: " << arr << endl;
    cout << "Max: " << SuperIntArray::getMax(arr.getNums(), arr.getSize()) << endl;
    cout << "Min: " << SuperIntArray::getMin(arr.getNums(), arr.getSize()) << endl;
    cout << "Mean: " << SuperIntArray::getMean(arr.getNums(), arr.getSize()) << endl;

    cout << "\\n=== Time Demo ===" << endl;
    Time t1(1, 23, 59, 59);
    Time t2(0, 0, 0, 2);
    Time t3 = t1 + t2;
    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;
    cout << "t1 + t2: " << t3 << endl;
    cout << "t1 in seconds: " << int(t1) << endl;
    cout << "t1 > t2? " << (t1 > t2) << endl;

    cout << "\\n=== Polynomial Demo ===" << endl;
    Term terms1[] = { Term(2, 2, 'x'), Term(3, 1, 'x') };
    Term terms2[] = { Term(1, 1, 'x'), Term(4, 0, 'x') };
    Polynomial p1(terms1, 2);
    Polynomial p2(terms2, 2);
    Polynomial p3 = p1 + p2;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1 + p2: " << p3 << endl;

    return 0;
}
