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

    Runge_Kutta<Vector2d> solver(0, 1, Vector2d(0, 1.865234375), f, h);

    auto x = solver.getGrid();
    auto solution = solver.solve();

    for (int i = 0; i < x.size(); ++i) {
        std::cout << "x = " << x[i] << " numerical solution: " << solution[i](0) << std::endl;
    }
    return 0;
}