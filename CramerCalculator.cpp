//
// Created by Marwan on 5/12/2024.
//

#include "CramerCalculator.h"
using namespace std;

CramerCalculator::CramerCalculator() : system(Matrix(), vector<double>()) {

}

void CramerCalculator::run() {
    menu();
}

void CramerCalculator::menu() {
    int choice;
    do {
        cout << "1. Solve a system of equations" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readInput();
                break;
            case 2:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 2);
}

void CramerCalculator::readInput() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> coefficients(n, vector<double>(n));
    vector<double> constants(n);

    cout << "Enter the coefficients of the equations:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter the coefficient of x" << j + 1 << " in equation " << i + 1 << ": ";
            cin >> coefficients[i][j];
        }
    }

    cout << "Enter the constants of the equations:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter the constant in equation " << i + 1 << ": ";
        cin >> constants[i];
    }

    Matrix m(coefficients);
    SystemOfEquations system(m, constants);
    system.print();
    vector<double> solution = system.solve();

    cout << "The solution is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}


CramerCalculator::~CramerCalculator() {

}
