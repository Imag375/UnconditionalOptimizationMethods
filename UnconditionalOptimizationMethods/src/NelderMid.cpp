#include "NelderMid.h"
#include "Functions.h"

#include <iostream>
#include <stdio.h>
#include <c++/cmath>

using namespace std;

void NelderMid::nelderMidMethod() {
    Functions functions;
    float x[3][2];
    x[0][0] = 1;
    x[0][1] = 1;
    float const e = 0.1; //точность
    int const n = 2; //размерность
    float m = 0.25; //длина ребра
    float B = 2.8;//параметр растяжения
    float Y = 0.4; //параметр сжатия
    float S = 0; //сигма - критерий окончания процесса поиска
    int count = 0; //счетчик вершин
    float F[] = {-99, 99, -99}; //максимальная, наименьшая и следующая за максимальной
    int k[3]; //индексы вершин для соотв. знач. функций
    float xc[2]; //координаты центра тяжести
    float tmp[2];
    bool flag; //поднимается, когда итоговое условие не выполнено
    int flag1 = 0; //флаг перехода по пунктам алгоритма

    cout << "____|___1___|___2___|__f(x)__|\n";

    for (int i = 0; i < 2; i++) {
        printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", count, x[count][0], x[count][1], functions.f(x[count][0], x[count][1]));
        count += 1;
        if (count == 1) {
            x[count][0] = x[0][0] + functions.d1(n, m);
            x[count][1] = x[0][1] + functions.d2(n, m);
        }
        if (count == 2) {
            x[count][0] = x[0][0] + functions.d2(n, m);
            x[count][1] = x[0][1] + functions.d1(n, m);
        }
    }

    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", count, x[count][0], x[count][1], functions.f(x[count][0], x[count][1]));

    do {
        flag = false;
        //3
        F[0] = -98;
        F[1] = 99;
        F[2] = -99;
        for (int i = 0; i <= n; i++) {
            if (functions.f(x[i][0], x[i][1]) > F[0]) {
                F[2] = F[0];
                k[2] = k[0];
                F[0] = functions.f(x[i][0], x[i][1]);
                k[0] = i;
            } else if ((functions.f(x[i][0], x[i][1]) < F[0]) && (functions.f(x[i][0], x[i][1]) > F[2])) {
                F[2] = functions.f(x[i][0], x[i][1]);
                k[2] = i;
            }
            if (functions.f(x[i][0], x[i][1]) < F[1]) {
                F[1] = functions.f(x[i][0], x[i][1]);
                k[1] = i;
            }
        }
        //4
        xc[0] = 0;
        xc[1] = 0;
        for (int i = 0; i <= n; i++) {
            if (i != k[0]) {
                xc[0] += x[i][0];
                xc[1] += x[i][1];
            }
        }
        xc[0] *= (1.0 / n);
        xc[1] *= (1.0 / n);
        //5
        tmp[0] = 2 * xc[0] - x[k[0]][0];
        tmp[1] = 2 * xc[1] - x[k[0]][1];
        //6
        if (functions.f(tmp[0], tmp[1]) < functions.f(x[k[0]][0], x[k[0]][1])) {
            x[k[0]][0] = tmp[0];
            x[k[0]][1] = tmp[1];
            count++;
            printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", count, tmp[0], tmp[1], functions.f(tmp[0], tmp[1]));
            //7
            if (functions.f(x[k[0]][0], x[k[0]][1]) < F[1]) {
                tmp[0] = xc[0] + B * (x[k[0]][0] - xc[0]);
                tmp[1] = xc[1] + B * (x[k[0]][1] - xc[1]);
                //8
                if (functions.f(tmp[0], tmp[1]) < functions.f(x[k[0]][0], x[k[0]][1])) {
                    x[k[0]][0] = tmp[0];
                    x[k[0]][1] = tmp[1];
                    count++;
                    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", count, tmp[0], tmp[1], functions.f(tmp[0], tmp[1]));
                    flag1 = 12;
                } else flag1 = 9;
            } else flag1 = 9;
        } else flag1 = 9;
        //9
        if (flag1 == 9) {
            if ((F[2] < functions.f(x[k[0]][0], x[k[0]][1])) && (functions.f(x[k[0]][0], x[k[0]][1]) < F[0])) {
                tmp[0] = xc[0] + Y * (x[k[0]][0] - xc[0]);
                tmp[1] = xc[1] + Y * (x[k[0]][1] - xc[1]);
                //10
                if (functions.f(tmp[0], tmp[1]) < functions.f(x[k[0]][0], x[k[0]][1])) {
                    x[k[0]][0] = tmp[0];
                    x[k[0]][1] = tmp[1];
                    count++;
                    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", count, tmp[0], tmp[1], functions.f(tmp[0], tmp[1]));
                    flag1 = 12;
                } else flag1 = 11;
            } else flag1 = 11;
        }
        //11
        if (flag1 == 11) {
            F[1] = functions.f(x[0][0], x[0][1]);
            k[1] = 0;
            for (int i = 1; i <= n; i++) {
                if (functions.f(x[i][0], x[i][1]) < F[1]) {
                    F[1] = functions.f(x[i][0], x[i][1]);
                    k[1] = i;
                }
            }
            for (int i = 0; i <= n; i++) {
                if (i != k[1]) {
                    x[i][0] = x[k[1]][0] + 0.5 * (x[i][0] - x[k[1]][0]);
                    x[i][1] = x[k[1]][1] + 0.5 * (x[i][1] - x[k[1]][1]);
                    count++;
                    printf("_%2d_|%6.3f |%6.3f |%7.3f |\n", count, x[i][0], x[i][1], functions.f(x[i][0], x[i][1]));
                }
            }
        }
        //12
        if (flag1 == 12) {
            xc[0] = 0;
            xc[1] = 0;
            for (int i = 0; i <= n; i++) {
                xc[0] += x[i][0];
                xc[1] += x[i][1];
            }
            xc[0] *= (1.0 / (n + 1));
            xc[1] *= (1.0 / (n + 1));
            S = 0;
            for (int i = 0; i <= n; i++) {
                S += pow(functions.f(x[i][0], x[i][1]) - functions.f(xc[0], xc[1]), 2);
            }
            S *= 1.0 / (n + 1);
            S = pow(S, 1.0 / 2);
        }
        //13
        if (!(S < e)) {
            flag = true;
        }
    } while (flag);

    F[1] = functions.f(x[0][0], x[0][1]);
    k[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (functions.f(x[i][0], x[i][1]) < F[1]) {
            F[1] = functions.f(x[i][0], x[i][1]);
            k[1] = i;
        }
    }
    printf("\nx* = (%.3f; %.3f)\nf(x*) = %.3f.\n", x[k[1]][0], x[k[1]][1], F[1]);
}

