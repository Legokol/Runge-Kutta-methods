#ifndef CLASSICAL_RUNGE_KUTTA_METHOD_RUNGE_KUTTA_H
#define CLASSICAL_RUNGE_KUTTA_METHOD_RUNGE_KUTTA_H

#include <vector>

template<typename T>
struct point {
    double x;
    T y;
};

template<typename T>
class Runge_Kutta {
private:

public:
    Runge_Kutta() {}

    std::vector<point<T>> solve(double a, double b, T y0, T (*f)(double, T), double h) {
        std::vector<point<T>> solution((b - a) / h + 1);
        for (int i = 0; i < solution.size(); ++i) {
            solution[i].x = a + i * h;
        }
        solution[0].y = y0;
        std::vector<T> k(4);
        for (int i = 0; i < solution.size() - 1; ++i) {
            k[0] = (*f)(solution[i].x, solution[i].y);
            k[1] = (*f)(solution[i].x + h / 2, solution[i].y + h * k[0] / 2);
            k[2] = (*f)(solution[i].x + h / 2, solution[i].y + h * k[1] / 2);
            k[3] = (*f)(solution[i].x + h, solution[i].y + h * k[3]);

            solution[i + 1].y = solution[i].y + h / 6 * (k[0] + 2 * k[1] + 2 * k[2] + k[3]);
        }
        return solution;
    }
};

#endif //CLASSICAL_RUNGE_KUTTA_METHOD_RUNGE_KUTTA_H
