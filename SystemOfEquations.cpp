//
// Created by Marwan on 5/12/2024.
//

#include "SystemOfEquations.h"
#include <iostream>
#include <cmath>

SystemOfEquations::SystemOfEquations(Matrix coefficients, vector<double> constants)
        : coefficients(coefficients), constants(constants) {
}

vector<double> SystemOfEquations::solve() {
    int n = coefficients.getRows();
    vector<double> solution(n, 0); // initialize the solution vector with zeros

    double det = coefficients.determinant(); // calculate the determinant of the coefficient matrix

    if (det == 0) { // if the determinant is zero, the system has no unique solution
        std::cout << "The system of equations has no unique solution." << std::endl;
        return solution;
    }

    for (int i = 0; i < n; i++) {
        Matrix temp = coefficients; // create a temporary matrix to replace the i-th column with the constants
        for (int j = 0; j < n; j++) {
            temp.setElement(j, i, constants[j]); // replace the i-th column with the constants
        }
        solution[i] = temp.determinant() / det; // calculate the solution for the i-th variable
    }

    return solution;
}

// print the system of equations
void SystemOfEquations::print() {
    int n = coefficients.getRows();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << coefficients.getElement(i, j) << "x" << j + 1;
            if (j < n - 1) {
                std::cout << " + ";
            }
        }
        std::cout << " = " << constants[i] << std::endl;
    }
}

