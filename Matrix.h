//
// Created by Marwan on 5/12/2024.
//

#ifndef CRAMER_S_RULE_MATRIX_H
#define CRAMER_S_RULE_MATRIX_H
using namespace std;
#include <vector>

class Matrix {
private:
    vector<vector<double>> elements;

public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix &m);
    Matrix(vector<vector<double>> elements);
    double determinant();
    void print();
    void setElement(int row, int col, double value);
    double getElement(int row, int col);
    int getRows();
    int getCols();

};


#endif //CRAMER_S_RULE_MATRIX_H
