#include <iostream>
#include <cmath>
#include "Runge_Kutta.h"

double f(double x, double y) {
    return y;
}

int main() {
    int n = 10;

    Runge_Kutta solver(0, 1, 1, f, 1. / n);

    auto solution = solver.solve();

    for (int i = 0; i < solution[0].size(); ++i) {
        std::cout << "x = " << solution[0][i] << " numerical solution: " << solution[1][i] << " analytical solution: " << exp(solution[0][i]) << std::endl;
    }
    return 0;
}