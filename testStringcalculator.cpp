#include "StringCalculator.h"
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>  // Added for inspect-code

// Helper to check negative exception and avoid code duplication
void assert_negative_exception(const std::string& input, const std::string& expected_msg) {
    StringCalculator calc;
    try {
        calc.Add(input);
        assert(false);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;  //  negatives not allowed: ...
        assert(std::string(e.what()).find(expected_msg) != std::string::npos);
    }
}

// TDD Case 1: Empty string returns 0
void test_empty_string() {
    StringCalculator calc;
    assert(calc.Add("") == 0);
}

// TDD Case 2: Single number returns itself
void test_single_number() {
    StringCalculator calc;
    assert(calc.Add("1") == 1);
}

// TDD Case 3: Two numbers, comma-separated
void test_two_numbers() {
    StringCalculator calc;
    assert(calc.Add("1,2") == 3);
}

// TDD Case 4: Unknown amount of numbers
void test_unknown_amount() {
    StringCalculator calc;
    assert(calc.Add("1,2,3,4") == 10);
}

// TDD Case 5: New lines as delimiter
void test_newline_delimiter() {
    StringCalculator calc;
    assert(calc.Add("1\n2,3") == 6);
}

// TDD Case 6: Custom delimiter
void test_custom_delimiter() {
    StringCalculator calc;
    assert(calc.Add("//;\n1;2") == 3);
}

// TDD Case 7: Ignore numbers > 1000
void test_ignore_large_numbers() {
    StringCalculator calc;
    assert(calc.Add("2,1001") == 2);
}

// TDD Case 8: Negative numbers throw exception
void test_negative_numbers() {
    assert_negative_exception("1,-2,3", "negatives not allowed: -2");
    assert_negative_exception("-1,-2,3", "negatives not allowed: -1 -2");
}

// TDD Case 9: Delimiter of any length
void test_long_delimiter() {
    StringCalculator calc;
    assert(calc.Add("//[***]\n12***3") == 15);
}

int main() {
    test_empty_string();
    test_single_number();
    test_two_numbers();
    test_unknown_amount();
    test_newline_delimiter();
    test_custom_delimiter();
    test_ignore_large_numbers();
    test_negative_numbers();
    test_long_delimiter();
    std::cout << "All TDD cases passed!" << std::endl;
    return 0;
}
