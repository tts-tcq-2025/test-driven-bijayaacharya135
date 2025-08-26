#pragma once
#include <string>
#include <sstream>

class StringCalculator {
public:
    int Add(const std::string& numbers) {
        if (numbers.empty()) return 0;
        int sum = 0;
        std::stringstream ss(numbers);
        std::string item;
        while (std::getline(ss, item, ',')) {
            sum += std::stoi(item);
        }
        return sum;
    }
};
