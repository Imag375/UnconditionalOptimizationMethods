//
// Created by Анастасия on 28.05.2019.
//

#ifndef UNCONDITIONALOPTIMIZATIONMETHODS_FUNCTIONS_H
#define UNCONDITIONALOPTIMIZATIONMETHODS_FUNCTIONS_H


class Functions {
public:
    float f(float x1, float x2);

    float d1(int n, float m);

    float d2(int n, float m);

    float gradX1(float x1, float x2);

    float gradX2(float x1, float x2);

    float absGradF(float x1, float x2);

    float absVector(float x1, float x2);

    float scalar(float x1, float x2, float y1, float y2);

    float newH1(float x1, float x2);

    float newX(float x, float h, float gradF);

    float newH(float x1, float x2);

    float newH01(float x1, float x2);

    float newH02(float x1, float x2);

    float newH2(float x1, float x2, float p1, float p2);

    float newX1(float x, float h, float p);

    float beta(float old1, float old2, float now1, float now2);

    float newPX1(float x1, float x2);

    float newPX2(float x1, float x2);

    float newP1X1(float x1, float x2);

    float newP1X2(float x1, float x2);
};


#endif //UNCONDITIONALOPTIMIZATIONMETHODS_FUNCTIONS_H
