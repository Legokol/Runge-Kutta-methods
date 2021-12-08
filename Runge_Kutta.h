#ifndef CLASSICAL_RUNGE_KUTTA_METHOD_RUNGE_KUTTA_H
#define CLASSICAL_RUNGE_KUTTA_METHOD_RUNGE_KUTTA_H

#include <vector>
#include <array>

template <typename T>
class Runge_Kutta {
private:
    double h;
    T y0;
    std::vector<double> x;

    T (*f)(double, T);

public:
    Runge_Kutta(double a, double b, T _y0, T (*_f)(double, T), double _h) {
        f = _f;
        h = _h;
        x.resize((b - a) / h + 1);
        for (int i = 0; i < x.size(); ++i) {
            x[i] = a + i * h;
        }
        y0 = _y0;
    }

    std::vector<double> getGrid() {
        return x;
    }

    std::vector<T> solve() {
        std::vector<T> y(x.size());
        std::vector<T> k(4);
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
