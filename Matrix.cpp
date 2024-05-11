//
// Created by Marwan on 5/12/2024.
//

#include "Matrix.h"
#include <cmath>
#include <iostream>
// we have three constructors to have the ability to initialize the matrix in three different ways

// Constructor that initializes the matrix with the given number of rows and columns
Matrix::Matrix(int rows, int cols) {
    elements = vector<vector<double>>(rows, vector<double>(cols, 0));
}

// Default constructor that initializes an empty matrix
Matrix::Matrix() {
    elements = vector<vector<double>>();

}

// Constructor that initializes the matrix with the given elements of another matrix
Matrix::Matrix(const Matrix &m) {
    elements = m.elements;
}

// Constructor that initializes the matrix with the given elements
Matrix::Matrix(vector<vector<double>> elements) {
    this->elements = elements;
}

int Matrix::getRows() {
    return elements.size();
}

double Matrix::determinant() {
    // implementation of the determinant function using gaussian elimination
    int n = getRows();
    double det = 1;
    vector<vector<double>> copy = elements; // we make a copy of this matrix for manipulation
    for (int i = 0; i < n; i++) {
        // finding the row with the maximum element in the current column
        int max = i;
        for (int j = i + 1; j < n; j++) {// we start from i+1 because we don't need to check the elements above the diagonal
            if (abs(copy[j][i]) > abs(copy[max][i])) {// we use abs to compare the absolute values
                max = j;// updating the maximum element index
            }
        }
        if (max != i) {
            swap(copy[i], copy[max]);
            det *= -1; // flipping the sign of the determinant if we swap two rows
        }

        // if singular matrix, return 0
        if (abs(copy[i][i]) <= 1e-10) { // we use 1e-10 as a threshold for zero because of floating point errors
            return 0;
        }

        det *= copy[i][i]; // multiplying the diagonal elements to get the determinant


        for (int j = i + 1; j < n; j++) {
            double factor = copy[j][i] / copy[i][i]; // the factor to multiply the row by before subtracting
            for (int k = i; k < n; k++) { // subtracting the row from the other row to make the element zero
                copy[j][k] -= factor * copy[i][k]; // subtracting the row
            }
        }




    }
    return det;


}
// prints the matrix using cout
void Matrix::print() {
    for (int i = 0; i < elements.size(); i++) {
        for (int j = 0; j < elements[i].size(); j++) {
            cout << elements[i][j] << " ";
        }
        cout << endl;
    }
}
// sets the element at the given row and column to the given value
void Matrix::setElement(int row, int col, double value) {
    elements[row][col] = value;
}

// returns the element at the given row and column
double Matrix::getElement(int row, int col) {
    return elements[row][col];
}

// returns the number of rows in the matrix
int Matrix::getCols() {
    return elements[0].size();
}





