#include <iostream>
#include <bitset>
#include <string>
#include <vector>

namespace bit {
    // Calculates the bit representation of an integer or character
    template <typename T>
    std::string val(T input) {
        // sizeof(T) * 8 gives the total bits (e.g., 8 for char, 32 for int)
        return std::bitset<sizeof(T) * 8>(input).to_string();
    }

    // Calculates the bit representation of every character in a string
    std::string text(const std::string& input) {
        std::string result;
        for (char c : input) {
            result += std::bitset<8>(c).to_string() + " ";
        }
        return result;
    }
}