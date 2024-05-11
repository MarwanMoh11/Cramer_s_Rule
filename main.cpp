#include "Matrix.h"
#include <iostream>

int main() {
    // Create a 3x3 matrix
    vector<vector<double>> elements = {{2, 1, -1,1}, {3, 2, 2, 13}, {4, -2, 3,9}};
    Matrix m(elements);

    // Calculate the determinant
    double det = m.determinant();

    // Print the determinant
    std::cout << "The determinant of the matrix is: " << det << std::endl;

    return 0;
}