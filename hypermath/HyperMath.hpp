#ifndef HYPERMATH_HPP
#define HYPERMATH_HPP

#include <cmath>
#include <string>

namespace hy_m {
    // Binary operations
    inline double calculate(std::string&op, double n1, double n2) {
        if (op == "add") return n1 + n2;
        if (op == "sub") return n1 - n2;
        if (op == "div") return (n2 == 0) ? 0 : n1 / n2; // Added safety for div by zero
        if (op == "mul") return n1 * n2;
        if (op == "hypot") return std::sqrt(n1 * n1 + n2 * n2);
        if (op == "pow") return std::pow(n1, n2);
        if (op == "gt") return n1 > n2 ? 1.0 : 0.0;
        if (op == "lt") return n1 < n2 ? 1.0 : 0.0;
        if (op == "root") return std::pow(n1, 1.0 / n2);
        return 0;
    }

    // Unary operations
    inline double calculate(std::string&op, double n1) {
        if (op == "inc") return n1 + 1;
        if (op == "dec") return n1 - 1;
        return 0;
    }
}

#endif
