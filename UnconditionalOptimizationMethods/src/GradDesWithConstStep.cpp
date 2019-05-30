#include "GradDesWithConstStep.h"
#include "Functions.h"

#include <iostream>
#include <stdio.h>

using namespace std;

void GradDesWithConstStep::gradDesWithConstStepMethod() {
    Functions functions;
    float x[2][2];
    x[0][0] = 1;
    x[0][1] = 1;
    float const e = 0.1; //точность
    float h = 0.2; //шаг
    int k = 0; //счетчик вершин и итераций
    bool flag; //флаг перехода по пунктам алгоритма

    cout << "____|___1___|___2___|__f(x)__|\n";
    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", k, x[0][0], x[0][1], functions.f(x[0][0], x[0][1]));

    while(true) {
        //4 and 5
        if(functions.absGradF(x[0][0], x[0][1]) <= e) {
            break;
        }
        //6
        do {
            x[1][0] = functions.newX(x[0][0], h, functions.gradX1(x[0][0], x[0][1]));
            x[1][1] = functions.newX(x[0][1], h, functions.gradX2(x[0][0], x[0][1]));
            //7
            if(functions.f(x[1][0], x[1][1]) < functions.f(x[0][0], x[0][1])) {
                k++;
                x[0][0] = x[1][0];
                x[0][1] = x[1][1];
                printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", k, x[0][0], x[0][1], functions.f(x[0][0], x[0][1]));
                flag = false;
            }
            else {
                h /= 2.0;
                flag = true;
            }
        } while(flag);
    }
    //8 - enter result
    cout << "\nx* = (" << x[0][0] << "; " << x[0][1] << ")\n";
    cout << "f(x*) = " << functions.f(x[0][0], x[0][1]) << endl;
}
