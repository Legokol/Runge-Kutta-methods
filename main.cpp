#include <iostream>
#include <cmath>
#include "Runge_Kutta.h"

double f(double x, double y) {
    return y;
}

int main() {
    int n = 15;
    std::vector<double> x(n + 1);
    for (int i = 0; i < x.size(); ++i) {
        x[i] = 1. / n * i;
    }
    Runge_Kutta solver(0, 1, 1, f, n);

    auto y = solver.solve();

    for (int i = 0; i < x.size(); ++i) {
        std::cout << "x = " << x[i] << " numerical solution: " << y[i] << " analytical solution: " << exp(x[i]) << std::endl;
    }
    return 0;
}