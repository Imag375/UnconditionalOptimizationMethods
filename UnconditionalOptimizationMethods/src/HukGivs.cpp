#include "HukGivs.h"
#include "Functions.h"

#include <iostream>
#include <stdio.h>

using namespace std;

void HukGivs::hukGivsMethod() {
    Functions functions;
    float x[3][2];
    x[0][0] = 1;
    x[0][1] = 1;
    float const e = 0.1; //точность
    int const n = 2; //размерность
    float h = 0.2; //шаг
    float d = 2; //коэффициент уменьшения шага
    float m = 0.5; //ускоряющий множитель
    int count = 0; //счетчик вершин
    int i;
    bool flag;
    int step = 0; //флаг перехода по пунктам алгоритма
    float xp[2];
    float tmp[2];

    cout << "___|___1___|___2___|__f(x)__|\n";
    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", count, x[0][0], x[0][1], functions.f(x[0][0], x[0][1]));
    tmp[0] = x[0][0];
    tmp[1] = x[0][1];

    do {
        flag = false;
        do {
            //3
            x[1][0] = x[0][0];
            x[1][1] = x[0][1];
            //4
            i = 1;
            //5
            do {
                x[i][0] = x[i-1][0];
                x[i][1] = x[i-1][1];

                x[i][i-1] = x[i][i-1] + h;
                //6
                if(functions.f(x[i][0], x[i][1]) >= functions.f(x[i-1][0], x[i-1][1])) { //если шаг был неудачен
                    x[i][i-1] = x[i][i-1] - 2 * h;
                    //7
                    if(functions.f(x[i][0], x[i][1]) >= functions.f(x[i-1][0], x[i-1][1])) { //если шаг опять был неудачен
                        x[i][i-1] = x[i][i-1] + h;
                    }
                }
                if (functions.f(x[i][0], x[i][1]) != functions.f(tmp[0], tmp[1])){
                    count++;
                    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", count, x[i][0], x[i][1], functions.f(x[i][0], x[i][1]));
                    tmp[0] = x[i][0];
                    tmp[1] = x[i][1];
                }
                //8
                if (i < n){
                    i++;
                    step = 5;
                }
                else
                    step = 9;
            } while(step != 9);
            //9
            if((x[i][0] == x[0][0]) && (x[i][1] == x[0][1])) {
                h /= d;
                step = 4;
            }
            else {
                step = 10;
            }
        } while(step == 4);
        //10
        xp[0] = x[2][0] + m * (x[2][0] - x[0][0]);
        xp[1] = x[2][1] + m * (x[2][1] - x[0][1]);
        //11
        if (functions.f(xp[0], xp[1]) < functions.f(x[2][0], x[2][1])){ //если поиск успешен
            x[0][0] = xp[0];
            x[0][1] = xp[1];
        }
        else {
            x[0][0] = x[2][0];
            x[0][1] = x[2][1];
        }
        if ((functions.f(x[0][0], x[0][1]) < functions.f(tmp[0], tmp[1])) && !(tmp[0] == x[0][0] && tmp[1] == x[0][1])){
                    count++;
                    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", count, x[0][0], x[0][1], functions.f(x[0][0], x[0][1]));
                    tmp[0] = x[0][0];
                    tmp[1] = x[0][1];
        }
        //12
        if (h > e) {
            flag = true;
        }

    }while(flag);

    printf("\nx* = (%.3f; %.3f)\nf(x*) = %.3f.\n", x[i][0], x[i][1], functions.f(x[i][0], x[i][1]));
}
