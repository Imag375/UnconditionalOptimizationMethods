#include "Simpleks.h"
#include "Functions.h"

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

void Simpleks::simpleksMethod() {
    Functions functions;
    float x[3][2];
    x[0][0] = 1;
    x[0][1] = 1;
    float const e = 0.1; //точность
    int const n = 2; //размерность
    float m = 0.25; //длина ребра
    int count = 0;
    float fmax;
    float fmin;
    int k = 0;
    int r = 0;
    float xc[2]; //координаты центра тяжести
    float tmp[2];
    bool flag;

    cout << "___|___1___|___2___|__f(x)__|\n";

    for(int i = 0; i < 2; i++) {
        printf("_%d_|%6.3f |%6.3f |%7.3f |\n", count, x[count][0], x[count][1], functions.f(x[count][0], x[count][1]));
        count += 1;
        if(count == 1) {
            x[count][0] = x[0][0] + functions.d1(n, m);
            x[count][1] = x[0][1] + functions.d2(n, m);
        }
        if(count == 2) {
            x[count][0] = x[0][0] + functions.d2(n, m);
            x[count][1] = x[0][1] + functions.d1(n, m);
        }
    }

    printf("_%d_|%6.3f |%6.3f |%7.3f |\n", count, x[count][0], x[count][1], functions.f(x[count][0], x[count][1]));

    do{
        flag = false;
        //3
        fmax = functions.f(x[0][0], x[0][1]);
        k = 0;
        for(int i = 1; i <= n; i++) {
            if(functions.f(x[i][0], x[i][1]) > fmax) {
                fmax = functions.f(x[i][0], x[i][1]);
                k = i;
            }
        }
        //4
        xc[0] = 0;
        xc[1] = 0;
        for(int i = 0; i <= n; i++) {
            if(i != k) {
                xc[0] += x[i][0];
                xc[1] += x[i][1];
            }
        }
        xc[0] *= (1.0/n);
        xc[1] *= (1.0/n);
        //5
        tmp[0] = 2 * xc[0] - x[k][0];
        tmp[1] = 2 * xc[1] - x[k][1];
        //7
        if(!(functions.f(tmp[0], tmp[1]) < functions.f(x[k][0], x[k][1]))) {
            fmin = functions.f(x[0][0], x[0][1]);
            r = 0;
            for(int i = 1; i <= n; i++) {
                if(functions.f(x[i][0], x[i][1]) < fmin) {
                    fmin = functions.f(x[i][0], x[i][1]);
                    r = i;
                }
            }
            for(int i = 0; i <= n; i++) {
                if(i != r) {
                    x[i][0] = x[r][0] + 0.5 * (x[i][0] - x[r][0]);
                    x[i][1] = x[r][1] + 0.5 * (x[i][1] - x[r][1]);
                    count++;
                    printf("_%d_|%6.3f |%6.3f |%7.3f |\n", count, x[i][0], x[i][1], functions.f(x[i][0], x[i][1]));
                }
            }
        }
        //6
        else {
            if(functions.f(tmp[0], tmp[1]) < functions.f(x[k][0], x[k][1])) {
                x[k][0] = tmp[0];
                x[k][1] = tmp[1];
                count++;
                printf("_%d_|%6.3f |%6.3f |%7.3f |\n", count, tmp[0], tmp[1], functions.f(tmp[0], tmp[1]));
            }
        }
        //8
        xc[0] = 0;
        xc[1] = 0;
        for(int i = 0; i <= n; i++) {
            xc[0] += x[i][0];
            xc[1] += x[i][1];
        }
        xc[0] *= (1.0/(n + 1));
        xc[1] *= (1.0/(n + 1));
        //9
        for(int i = 0; i <= n; i++){
            if(!(abs(functions.f(x[i][0], x[i][1]) - functions.f(xc[0], xc[1])) < e)){
                flag = true;
            }
        }
    }while(flag);

    fmin = functions.f(x[0][0], x[0][1]);
    r = 0;
    for(int i = 1; i <= n; i++) {
        if(functions.f(x[i][0], x[i][1]) < fmin) {
            fmin = functions.f(x[i][0], x[i][1]);
            r = i;
        }
    }
    printf("\nx* = (%.3f; %.3f)\nf(x*) = %.3f.\n", x[r][0], x[r][1], fmin);
}
