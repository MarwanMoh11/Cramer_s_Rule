//
// Created by Marwan on 5/12/2024.
//

#ifndef CRAMER_S_RULE_SYSTEMOFEQUATIONS_H
#define CRAMER_S_RULE_SYSTEMOFEQUATIONS_H
#include "Matrix.h"
#include <vector>

class SystemOfEquations {
private:
    Matrix coefficients; // the matrix of coefficients used to solve the system
    vector<double> constants; // the vector of constants used to solve the system

public:
    SystemOfEquations(Matrix coefficients, vector<double> constants); // constructor that initializes the system of equations
    vector<double> solve(); // solves the system of equations using Cramer's rule
    void print(); // prints the system of equations

};


#endif //CRAMER_S_RULE_SYSTEMOFEQUATIONS_H
