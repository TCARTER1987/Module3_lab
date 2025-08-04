#include "Term.h"
using namespace std;


Term::Term() : coefficient(0), exponent(0), variable('x') {}
Term::Term(double coef, int exp, char var) : coefficient(coef), exponent(exp), variable(var) {}
Term::Term(const Term& term) : coefficient(term.coefficient), exponent(term.exponent), variable(term.variable) {}

double Term::getCoefficient() const { return coefficient; }
int Term::getExponent() const { return exponent; }
char Term::getVariable() const { return variable; }

void Term::setCoefficient(double coef) { coefficient = coef; }
void Term::setExponent(int exp) { exponent = exp; }
void Term::setVariable(char var) { variable = var; }

Term& Term::operator=(const Term& right) {
    if (this != &right) {
        coefficient = right.coefficient;
        exponent = right.exponent;
        variable = right.variable;
    }
    return *this;
}

bool Term::operator<=(const Term& right) { return exponent <= right.exponent; }
bool Term::operator>=(const Term& right) { return exponent >= right.exponent; }
bool Term::operator<(const Term& right) { return exponent < right.exponent; }
bool Term::operator>(const Term& right) { return exponent > right.exponent; }
bool Term::operator==(const Term& right) { return exponent == right.exponent; }

bool Term::compatible(const Term& term) {
    return exponent == term.exponent && variable == term.variable;
}
