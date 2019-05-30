#include "Simpleks.h"
#include "NelderMid.h"
#include "HukGivs.h"
#include "GradDesWithConstStep.h"
#include "QuickGradDescent.h"
#include "CoordinateDescent.h"
#include "FletcherReeves.h"
#include "Newton.h"
#include "NewtonRaphson.h"

#include <iostream>

using namespace std;

int main() {
    cout << "\nSimplex method:" << endl;
    Simpleks s;
    s.simpleksMethod();
    cout << "\nNelder-Mid method:" << endl;
    NelderMid nm;
    nm.nelderMidMethod();
    cout << "\nHuk-Givs method:" << endl;
    HukGivs hg;
    hg.hukGivsMethod();
    cout << "\nGradient descent with const step method:" << endl;
    GradDesWithConstStep gdwcs;
    gdwcs.gradDesWithConstStepMethod();
    cout << "\nQuick gradient descent method:" << endl;
    QuickGradDescent qgd;
    qgd.quickGradDescentMethod();
    cout << "\nCoordinate descent method:" << endl;
    CoordinateDescent cd;
    cd.coordinateDescentMethod();
    cout << "\nFletcher-Reeves method:" << endl;
    FletcherReeves fr;
    fr.fletcherReevesMethod();
    cout << "\nNewton method:" << endl;
    Newton n;
    n.newtonMethod();
    cout << "\nNewton-Raphson method:" << endl;
    NewtonRaphson nr;
    nr.newtonRaphsonMethod();
    return 0;
}