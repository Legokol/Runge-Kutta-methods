#include <iostream>
#include <fstream>
#include <cmath>
#include <Eigen/Dense>
#include "Runge_Kutta.h"

using Eigen::Vector2d;

Vector2d f(double x, const Vector2d &y) {
    return Vector2d(y(1), x * sqrt(y(0)));
}

double F(double x, const double &y) {
    return y;
}

double norm(const Vector2d &x) {
    return x.cwiseAbs().maxCoeff();
}

int main() {
    double h = 0.1;
    double epsilon = 1e-8;
    Vector2d y0(1, 1.86);
    Runge_Kutta<Vector2d> solver;

    auto solution1 = solver.classicalRungeKutta(0, 1, y0, f, h);
    auto solution2 = solver.DormandPrince45(0, 1, y0, f, norm, epsilon, h);

    std::ofstream sol1;
    sol1.open("solution1.txt");
    for (int i = 0; i < solution1.size(); ++i) {
        sol1 << solution1[i].x << ',' << solution1[i].y << '\n';
    }
    sol1.close();

    std::ofstream sol2;
    sol2.open("solution2.txt");
    for (int i = 0; i < solution2.size(); ++i) {
        sol2 << solution2[i].x << ',' << solution2[i].y << '\n';
    }
    sol2.close();
    return 0;
}