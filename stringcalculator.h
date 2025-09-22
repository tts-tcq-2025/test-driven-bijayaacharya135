#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class StringCalculator {
public:
    int Add(const std::string& numbers) {
        if (numbers.empty()) return 0;

        std::string input = numbers;
        std::vector<std::string> delimiters = {",", "\n"};

        // Custom delimiter logic
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
        while (std::getline(ss, item, ',')) {
            if (!item.empty()) {
                int num = std::stoi(item);
                if (num < 0) negatives.push_back(num);
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
};
