#include "StringCalculator.h"
#include <cassert>

int main() {
    StringCalculator calc;
    assert(calc.Add("") == 0);      // Test: empty string returns 0
    assert(calc.Add("1") == 1);     // Test: single number returns itself
    assert(calc.Add("1,2") == 3);   // Test: two numbers summed
    return 0;
}
}
