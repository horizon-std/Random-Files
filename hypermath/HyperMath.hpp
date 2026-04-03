#ifndef HYPERMATH_HPP
#define HYPERMATH_HPP

#include <cmath>
#include <string>
#include <random> // Added for random numbers

namespace hy_m {
    // This sets up the random engine once so it stays "random"
    static std::random_device rd;
    static std::mt19937 gen(rd());

    inline double calculate(const std::string& op, double n1, double n2) {
        if (op == "add") return n1 + n2;
        if (op == "sub") return n1 - n2;
        if (op == "div") return (n2 == 0) ? 0 : n1 / n2;
        if (op == "mul") return n1 * n2;
        if (op == "hypot") return std::sqrt(n1 * n1 + n2 * n2);
        if (op == "pow") return std::pow(n1, n2);
        
        // Logical comparisons: Returns 1.0 for true, 0.0 for false
        if (op == "gt")   return n1 > n2;
        if (op == "lt")   return n1 < n2;
        if (op == "gteq") return n1 >= n2;
        if (op == "lteq") return n1 <= n2;
        
        if (op == "root") return std::pow(n1, 1.0 / n2);

        // Random logic: n1 is min, n2 is max
        if (op == "random") {
            std::uniform_real_distribution<> dis(n1, n2);
            return dis(gen);
        }

        return 0;
    }

    inline double calculate(const std::string& op, double n1) {
        if (op == "inc") return n1 + 1;
        if (op == "dec") return n1 - 1;
        return 0;
    }
}

#endif
