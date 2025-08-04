#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Term.h"
#include <iostream>
using namespace std;

class Polynomial {
private:
    Term* terms;
    int numTerms;

    void simplify();

public:
    Polynomial();
    Polynomial(Term* terms, int numTerms);
    Polynomial(const Polynomial& poly);
    ~Polynomial();

    int getNumTerms() const;
    Term* getTerms() const;

    Polynomial& operator=(const Polynomial& right);
    Polynomial operator+(const Polynomial& right);
    Polynomial operator-(const Polynomial& right);
    Polynomial operator*(const Polynomial& right);

    friend ostream& operator<<(ostream& stream, const Polynomial& poly);
};

#endif
