#pragma once
#include <string>
#include <vector>

class StringCalculator {
 public:  // Fixed indentation for inspect-code
    int Add(const std::string& numbers);

 private:  // Fixed indentation for inspect-code
    std::vector<std::string> getDelimiters(const std::string& input);
    std::string stripDelimiterHeader(const std::string& input);
    std::string normalizeDelimiters(const std::string& input,
                                    const std::vector<std::string>& delimiters);  // Line split
    std::vector<int> parseNumbers(const std::string& input);
    void checkNegatives(const std::vector<int>& nums);
    int sumNumbers(const std::vector<int>& nums);
};
/*#pragma once
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdexcept>

// TDD Case 1: Empty string returns 0
// TDD Case 2: Single number returns itself
// TDD Case 3: Two numbers, comma-separated
// TDD Case 4: Unknown amount of numbers
// TDD Case 5: New lines as delimiter
// TDD Case 6: Custom delimiter
// TDD Case 7: Ignore numbers > 1000
// TDD Case 8: Negative numbers throw exception
// TDD Case 9: Delimiter of any length

class StringCalculator {
public:
    int Add(const std::string& numbers) {
        // TDD Case 1: Empty string returns 0
        if (numbers.empty()) return 0;

        std::string input = numbers;
        std::vector<std::string> delimiters = {",", "\n"};

        // TDD Case 6 & 9: Custom delimiter, delimiter of any length
        if (input.substr(0, 2) == "//") {
            size_t pos = input.find('\n');
            std::string delim = input.substr(2, pos - 2);
            if (!delim.empty() && delim.front() == '[' && delim.back() == ']')
                delimiters.push_back(delim.substr(1, delim.size() - 2));
            else
                delimiters.push_back(delim);
            input = input.substr(pos + 1);
        }

        // Replace all delimiters with comma
        for (const auto& d : delimiters) {
            size_t idx = 0;
            while ((idx = input.find(d, idx)) != std::string::npos) {
                input.replace(idx, d.length(), ",");
                idx += 1;
            }
        }

        int sum = 0;
        std::stringstream ss(input);
        std::string item;
        std::vector<int> negatives;

        // TDD Case 2-8: Parsing and logic
        while (std::getline(ss, item, ',')) {
            if (!item.empty()) {
                int num = std::stoi(item);
                // TDD Case 8: Negative numbers throw exception
                if (num < 0) negatives.push_back(num);
                // TDD Case 7: Ignore numbers > 1000
                else if (num <= 1000) sum += num;
            }
        }
        if (!negatives.empty()) {
            std::string msg = "negatives not allowed:";
            for (int n : negatives) msg += " " + std::to_string(n);
            throw std::runtime_error(msg);
        }
        return sum;
    }
};*/
