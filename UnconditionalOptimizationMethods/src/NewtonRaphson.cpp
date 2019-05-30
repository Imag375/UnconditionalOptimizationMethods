#include "NewtonRaphson.h"
#include "Functions.h"

#include <iostream>
#include <stdio.h>

using namespace std;

void NewtonRaphson::newtonRaphsonMethod() {
    Functions functions;
    float x[2] = {1, 1};
    float const e = 0.1; //точность
    int k = 0; //счетчик вершин и итераций

    cout << "____|___1___|___2___|__f(x)__|\n";
    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", k, x[0], x[1], functions.f(x[0], x[1]));

    while(true) {
        if(functions.absGradF(x[0], x[1]) <= e) {
            break;
        }
        float tmp = x[0];
        x[0] -= functions.newH1(x[0], x[1])*functions.newP1X1(x[0], x[1]);
        x[1] -= functions.newH1(tmp, x[1])*functions.newP1X2(tmp, x[1]);
        k++;
        printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", k, x[0], x[1], functions.f(x[0], x[1]));
    }
    //enter result
    cout << "\nx* = (" << x[0] << "; " << x[1] << ")\n";
    cout << "f(x*) = " << functions.f(x[0], x[1]) << endl;
}

