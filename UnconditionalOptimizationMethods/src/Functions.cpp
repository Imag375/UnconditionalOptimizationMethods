//
// Created by Анастасия on 28.05.2019.
//

#include <c++/cmath>
#include "Functions.h"

float Functions::f(float x1, float x2) {
    return 1.1 * pow(x2, 2) + 2.2 * pow(x1, 2) - 1.3 * x2 - 2.8 * x2 - 1.6 * x1;
}

float Functions::d1(int n, float m) {
    return ((pow((n+1), 0.5) - 1) / (n * pow(2, 0.5))) * m;
}

float Functions::d2(int n, float m) {
    return ((pow((n+1), 0.5) + n - 1) / (n * pow(2, 0.5))) * m;
}

float Functions::gradX1(float x1, float x2) {
    return 4.4 * x1 - 1.6;
}

float Functions::gradX2(float x1, float x2) {
    return 2.2 * x2 - 4.1;
}

float Functions::absGradF(float x1, float x2) {
    return pow((pow(gradX1(x1, x2), 2) + pow(gradX2(x1, x2), 2)), 0.5);
}

float Functions::absVector(float x1, float x2) {
    return pow((pow(x1, 2) + pow(x2, 2)), 0.5);
}

float Functions::scalar(float x1, float x2, float y1, float y2) {
    return absVector(x1, x2) * absVector(y1, y2) * (x1 * y1 + x2 * y2) / (absVector(x1, x2) + absVector(y1, y2));
}

float Functions::newPX1(float x1, float x2) {
    float h[2][2] = {{2.2f / 9.68f, 0}, {0, 4.4f / 9.68f}};
    float x[2] = {gradX1(x1, x2), gradX2(x1, x2)};
    float y[2] = {0, 0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            y[i] += h[i][j] * x[j];
        }
    }
    return y[0];
}

float Functions::newPX2(float x1, float x2) {
    float h[2][2] = {{2.2f / 9.68f, 0}, {0, 4.4f / 9.68f}};
    float x[2] = {gradX1(x1, x2), gradX2(x1, x2)};
    float y[2] = {0, 0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            y[i] += h[i][j] * x[j];
        }
    }
    return y[1];
}

float Functions::newP1X1(float x1, float x2) {
    float h[2][2] = {{-2.2f/9.68f, 0}, {0, -4.4f/9.68f}};
    float x[2] = {gradX1(x1, x2), gradX2(x1, x2)};
    float y[2] = {0, 0};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            y[i] += h[i][j] * x[j];
        }
    }
    return y[0];
}

float Functions::newP1X2(float x1, float x2) {
    float h[2][2] = {{-2.2f/9.68f, 0}, {0, -4.4f/9.68f}};
    float x[2] = {gradX1(x1, x2), gradX2(x1, x2)};
    float y[2] = {0, 0};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            y[i] += h[i][j] * x[j];
        }
    }
    return y[1];
}

float Functions::newH(float x1, float x2) {
    float h[2][2] = {{4.4, 0}, {0, 2.2}};
    float x[2] = {gradX1(x1, x2), gradX2(x1, x2)};
    float y[2] = {0, 0};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            y[i] += h[i][j] * x[j];
        }
    }
    return scalar(x[0], x[1], x[0], x[1]) / scalar(y[0], y[1], x[0], x[1]);
}

float Functions::newH1(float x1, float x2) {
    float h[2][2] = {{4.4, 0}, {0, 2.2}};
    float x[2] = {newP1X1(x1, x2), newP1X2(x1, x2)};
    float y[2] = {0, 0};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            y[i] += h[i][j] * x[j];
        }
    }
    return scalar(gradX1(x1, x2), gradX2(x1, x2), x[0], x[1]) / scalar(y[0], y[1], x[0], x[1]);
}

float Functions::newH01(float x1, float x2) { //нахождение нового шага h
    return (2.2*2*x1-1.6)*gradX1(x1, x2) / (2.2*2*pow(gradX1(x1, x2), 2));
}

float Functions::newH02(float x1, float x2) { //нахождение нового шага h
    return (2.2*x2-4.1)*gradX2(x1, x2) / (2.2*pow(gradX2(x1, x2), 2));
}

float Functions::newH2(float x1, float x2, float p1, float p2) {
    return (p1*(1.6-4.4*x1)+(4.1-2.2*x2)*p2) / (2*pow(p1, 2)+2*pow(p2, 2));
}

float Functions::newX(float x, float h, float gradF) {
    return x - h * gradF;
}

float Functions::newX1(float x, float h, float p) {
    return x + h * p;
}

float Functions::beta(float old1, float old2, float now1, float now2) {
    return pow(absGradF(now1, now2), 2) / pow(absGradF(old1, old2), 2);
}