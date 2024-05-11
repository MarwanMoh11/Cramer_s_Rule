//
// Created by Marwan on 5/12/2024.
//

#ifndef CRAMER_S_RULE_CRAMERCALCULATOR_H
#define CRAMER_S_RULE_CRAMERCALCULATOR_H

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "SystemOfEquations.h"



class CramerCalculator {
public:
    CramerCalculator();
    ~CramerCalculator();
    void run();

private:
    void menu();
    void readInput();
    SystemOfEquations system; // SystemOfEquations object





};


#endif //CRAMER_S_RULE_CRAMERCALCULATOR_H
