#ifndef CLASSICAL_RUNGE_KUTTA_METHOD_RUNGE_KUTTA_H
#define CLASSICAL_RUNGE_KUTTA_METHOD_RUNGE_KUTTA_H

#include <vector>

class Runge_Kutta {
private:
    double h;
    double y0;
    std::vector<double> x;

    double (*f)(double, double);

public:
    Runge_Kutta(double a, double b, double _y0, double (*_f)(double, double), int n) {
        f = _f;
        x.resize(n + 1);
        h = (b - a) / n;
        for (int i = 0; i < x.size(); ++i) {
            x[i] = a + i * h;
        }
        y0 = _y0;
    }

    std::vector<double> solve() {
        std::vector<double> y(x.size());
        std::vector<double> k(4);
        y[0] = y0;
        for (int i = 0; i < x.size() - 1; ++i) {
            k[0] = (*f)(x[i], y[i]);
            k[1] = (*f)(x[i] + h / 2, y[i] + h * k[0] / 2);
            k[2] = (*f)(x[i] + h / 2, y[i] + h * k[1] / 2);
            k[3] = (*f)(x[i] + h, y[i] + h * k[3]);

            y[i + 1] = y[i] + h / 6 * (k[0] + 2 * k[1] + 2 * k[2] + k[3]);
        }
        return y;
    }
};


#endif //CLASSICAL_RUNGE_KUTTA_METHOD_RUNGE_KUTTA_H
