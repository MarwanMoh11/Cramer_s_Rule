//
// Created by Marwan on 5/12/2024.
//

#include "CramerCalculator.h"
using namespace std;


// Constructor that initializes the system of equations object
CramerCalculator::CramerCalculator() : system(Matrix(), vector<double>()) {

}

// run the calculator
void CramerCalculator::run() {
    menu();
}

// display the menu and handle user input
void CramerCalculator::menu() {
    int choice;
    do {
        cout << "1. Solve a system of equations" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) { // switch statement to handle user input
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


// read the input from the user and solve the system of equations
void CramerCalculator::readInput() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> coefficients(n, vector<double>(n)); // initialize a 2D vector to store the coefficients
    vector<double> constants(n); // initialize a vector to store the constants

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

    Matrix m(coefficients); // create a matrix object with the coefficients
    SystemOfEquations system(m, constants); // create a system of equations object with the matrix and constants
    system.print(); // print the system of equations
    vector<double> solution = system.solve(); // solve the system of equations


    // print the solution
    cout << "The solution is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

// Destructor
CramerCalculator::~CramerCalculator() {

}
