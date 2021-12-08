#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include "Runge_Kutta.h"

using Eigen::Vector2d;

Vector2d f(double x, Vector2d y) {
    return Vector2d(y(1), x * sqrt(y(0)));
}

int main() {
    double h = 0.01;

    Runge_Kutta<Vector2d> solver;

    auto solution = solver.solve(0, 1, Vector2d(0, 1.865234375), f, h);

    for (int i = 0; i < solution.size(); ++i) {
        std::cout << "x = " << solution[i].x << " numerical solution: " << solution[i].y(0) << std::endl;
    }
    return 0;
}