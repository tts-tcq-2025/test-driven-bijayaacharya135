#include "StringCalculator.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

int main() {
    StringCalculator calc;

    // TDD Cases
    assert(calc.Add("") == 0);                       // Empty string
    assert(calc.Add("1") == 1);                      // Single number
    assert(calc.Add("1,2") == 3);                    // Two numbers
    assert(calc.Add("1,2,3,4") == 10);               // Unknown amount of numbers
    assert(calc.Add("1\n2,3") == 6);                 // New lines as delimiter
    assert(calc.Add("//;\n1;2") == 3);               // Custom delimiter
    assert(calc.Add("2,1001") == 2);                 // Ignore numbers > 1000
    assert(calc.Add("//[***]\n12***3") == 15);       // Delimiter of any length

    // Negative numbers throw exception
    try {
        calc.Add("1,-2,3");
        assert(false); // Should not reach here
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl; // negatives not allowed: -2
    }

    // Multiple negatives
    try {
        calc.Add("-1,-2,3");
        assert(false);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl; // negatives not allowed: -1 -2
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
