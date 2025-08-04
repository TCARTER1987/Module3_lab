#pragma once
#ifndef TERM_H
#define TERM_H

class Term {
private:
    double coefficient;
    int exponent;
    char variable;

public:
    Term();
    Term(double coef, int exp, char var);
    Term(const Term& term);

    double getCoefficient() const;
    int getExponent() const;
    char getVariable() const;

    void setCoefficient(double coef);
    void setExponent(int exp);
    void setVariable(char var);

    Term& operator=(const Term& right);

    bool operator<=(const Term& right);
    bool operator>=(const Term& right);
    bool operator<(const Term& right);
    bool operator>(const Term& right);
    bool operator==(const Term& right);

    bool compatible(const Term& term);
};

#endif
