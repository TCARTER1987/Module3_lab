#include "Polynomial.h"

Polynomial::Polynomial() : terms(nullptr), numTerms(0) {}

Polynomial::Polynomial(Term* t, int n) {
    numTerms = n;
    terms = new Term[numTerms];
    for (int i = 0; i < numTerms; ++i)
        terms[i] = t[i];
    simplify();
}

Polynomial::Polynomial(const Polynomial& poly) {
    numTerms = poly.numTerms;
    terms = new Term[numTerms];
    for (int i = 0; i < numTerms; ++i)
        terms[i] = poly.terms[i];
}

Polynomial::~Polynomial() {
    delete[] terms;
}

int Polynomial::getNumTerms() const { return numTerms; }
Term* Polynomial::getTerms() const { return terms; }

Polynomial& Polynomial::operator=(const Polynomial& right) {
    if (this != &right) {
        delete[] terms;
        numTerms = right.numTerms;
        terms = new Term[numTerms];
        for (int i = 0; i < numTerms; ++i)
            terms[i] = right.terms[i];
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& right) {
    int size = numTerms + right.numTerms;
    Term* combined = new Term[size];
    for (int i = 0; i < numTerms; ++i) combined[i] = terms[i];
    for (int i = 0; i < right.numTerms; ++i) combined[numTerms + i] = right.terms[i];
    Polynomial result(combined, size);
    delete[] combined;
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& right) {
    int size = numTerms + right.numTerms;
    Term* combined = new Term[size];
    for (int i = 0; i < numTerms; ++i) combined[i] = terms[i];
    for (int i = 0; i < right.numTerms; ++i) {
        Term neg = right.terms[i];
        neg.setCoefficient(-neg.getCoefficient());
        combined[numTerms + i] = neg;
    }
    Polynomial result(combined, size);
    delete[] combined;
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& right) {
    int size = numTerms * right.numTerms;
    Term* resultTerms = new Term[size];
    int idx = 0;
    for (int i = 0; i < numTerms; ++i) {
        for (int j = 0; j < right.numTerms; ++j) {
            double coef = terms[i].getCoefficient() * right.terms[j].getCoefficient();
            int exp = terms[i].getExponent() + right.terms[j].getExponent();
            char var = terms[i].getVariable();
            resultTerms[idx++] = Term(coef, exp, var);
        }
    }
    Polynomial result(resultTerms, size);
    delete[] resultTerms;
    return result;
}

ostream& operator<<(ostream& stream, const Polynomial& poly) {
    for (int i = 0; i < poly.numTerms; ++i) {
        Term t = poly.terms[i];
        if (t.getCoefficient() != 0)
            stream << (t.getCoefficient() >= 0 && i > 0 ? "+" : "") << t.getCoefficient() << t.getVariable() << "^" << t.getExponent() << " ";
    }
    return stream;
}

void Polynomial::simplify() {
    for (int i = 0; i < numTerms; ++i) {
        for (int j = i + 1; j < numTerms; ++j) {
            if (terms[i].compatible(terms[j])) {
                terms[i].setCoefficient(terms[i].getCoefficient() + terms[j].getCoefficient());
                terms[j].setCoefficient(0);
            }
        }
    }
}
