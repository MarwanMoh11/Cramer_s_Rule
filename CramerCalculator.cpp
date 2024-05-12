//
// Created by Marwan on 5/12/2024.
//

#include "CramerCalculator.h"
using namespace std;
#include <sstream>


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
    cin.ignore(); // to clear the newline character from the input buffer

    vector<vector<double>> coefficients(n, vector<double>(n)); // initialize a 2D vector to store the coefficients
    vector<double> constants(n); // initialize a vector to store the constants

    cout << "Enter the equations (format with NO SPACES: a1x1+a2x2+...+anxn=c):" << endl;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line); // read the entire line

        stringstream ss(line); // create a stringstream from the line

        // extract the coefficients from the line
        for (int j = 0; j < n; j++) {
            string token;
            getline(ss, token, 'x'); // read the coefficient before 'x'
            coefficients[i][j] = stod(token); // convert the token to double and store it

            // skip the variable number
            ss.ignore();
        }

        // skip the '=' character
        ss.ignore();

        // extract the constant from the line
        string token;
        getline(ss, token);
        constants[i] = stod(token);
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
