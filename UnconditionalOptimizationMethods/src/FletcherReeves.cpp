#include "FletcherReeves.h"
#include "Functions.h"

#include <iostream>
#include <stdio.h>

using namespace std;

void FletcherReeves::fletcherReevesMethod() {
    Functions functions;
    float x[2][2] = {{1, 1}, {0, 0}};
    float const e = 0.1; //точность
    int const n = 2; //размерность
    float h = 0.2; //шаг
    float p[2];
    int k = 0; //счетчик вершин и итераций
    bool flag; //флаг перехода по пунктам алгоритма

    cout << "____|___1___|___2___|__f(x)__|\n";
    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", k, x[0][0], x[0][1], functions.f(x[0][0], x[0][1]));

    while(true) {
        //5
        if (k != 0) {
        //6 and 7
            p[0] = -1*functions.gradX1(x[1][0], x[1][1]) + functions.beta(x[0][0], x[0][1], x[1][0], x[1][1]) * p[0];
            p[1] = -1*functions.gradX2(x[1][0], x[1][1]) + functions.beta(x[0][0], x[0][1], x[1][0], x[1][1]) * p[1];

            x[0][0] = x[1][0];
            x[0][1] = x[1][1];

        }
        else {
        //5
            p[0] = -1*functions.gradX1(x[0][0], x[0][1]);
            p[1] = -1*functions.gradX2(x[0][0], x[0][1]);

        }
        //8
        h = functions.newH2(x[0][0], x[0][1], p[0], p[1]);
        //9
        x[1][0] = functions.newX1(x[0][0], h, p[0]);
        x[1][1] = functions.newX1(x[0][1], h, p[1]);
        k++;
        printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", k, x[1][0], x[1][1], functions.f(x[1][0], x[1][1]));
        //4
        if(functions.absGradF(x[1][0], x[1][1]) <= e) {
            break;
        }
    }
    //enter result
    cout << "\nx* = (" << x[1][0] << "; " << x[1][1] << ")\n";
    cout << "f(x*) = " << functions.f(x[1][0], x[1][1]) << endl;
}
