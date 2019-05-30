#include "QuickGradDescent.h"
#include "Functions.h"

#include <iostream>
#include <stdio.h>

using namespace std;

void QuickGradDescent::quickGradDescentMethod() {
    Functions functions;
    float x[2] = {1, 1};
    float const e = 0.1; //точность
    int const n = 2; //размерность
    float h; //шаг
    int k = 0; //счетчик вершин и итераций

    cout << "____|___1___|___2___|__f(x)__|\n";
    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", k, x[0], x[1], functions.f(x[0], x[1]));

    while(true) {
        //4
        if(functions.absGradF(x[0], x[1]) <= e) {
            break;
        }
        //5
        h = functions.newH(x[0], x[1]);
        //6
        float tmp = x[0];
        x[0] = functions.newX(x[0], h, functions.gradX1(x[0], x[1]));
        x[1] = functions.newX(x[1], h, functions.gradX2(tmp, x[1]));
        k++;
        printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", k, x[0], x[1], functions.f(x[0], x[1]));
    }
    //enter result
    cout << "\nx* = (" << x[0] << "; " << x[1] << ")\n";
    cout << "f(x*) = " << functions.f(x[0], x[1]) << endl;
}
