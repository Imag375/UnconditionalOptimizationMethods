cmake_minimum_required(VERSION 3.14)
project(UnconditionalOptimizationMethods)

set(CMAKE_CXX_STANDARD 14)
SET (CMAKE_C_COMPILER_WORKS 1) 
SET (CMAKE_CXX_COMPILER_WORKS 1)

add_executable(UnconditionalOptimizationMethods
        src/main.cpp
        src/FletcherReeves.h        src/FletcherReeves.cpp
        src/GradDesWithConstStep.h  src/GradDesWithConstStep.cpp
        src/HukGivs.h               src/HukGivs.cpp
        src/NelderMid.h             src/NelderMid.cpp
        src/Newton.h                src/Newton.cpp
        src/NewtonRaphson.h         src/NewtonRaphson.cpp
        src/QuickGradDescent.h      src/QuickGradDescent.cpp
        src/Simpleks.h              src/Simpleks.cpp
        src/CoordinateDescent.h     src/CoordinateDescent.cpp
        src/Functions.h             src/Simpleks.cpp src/Functions.cpp
        )