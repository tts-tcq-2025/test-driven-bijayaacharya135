#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>  // For std::copy_if
#include <numeric>    // For std::accumulate

// Helper for delimiter type
static bool is_long_delimiter(const std::string& delim) {
  return !delim.empty() && delim.front() == '[' && delim.back() == ']';
}

// Main Add method: sums numbers in a string according to TDD requirements
int StringCalculator::Add(const std::string& numbers) {
  if (numbers.empty()) return 0;

  std::string input = numbers;
  std::vector<std::string> delimiters = getDelimiters(input);
  input = stripDelimiterHeader(input);

  // Split long line for inspect-code
  std::string normalized =
    normalizeDelimiters(input, delimiters);

  std::vector<int> nums = parseNumbers(normalized);

  checkNegatives(nums);
  return sumNumbers(nums);
}
// Extracts all delimiters from input string
std::vector<std::string> StringCalculator::getDelimiters(const std::string& input) {
    std::vector<std::string> delimiters = {",", "\n"};
    if (input.substr(0, 2) == "//") {
        size_t pos = input.find('\n');
        std::string delim = input.substr(2, pos - 2);
        if (is_long_delimiter(delim)) {
    delimiters.push_back(delim.substr(1, delim.size() - 2));
  } else if (!delim.empty()) {
    delimiters.push_back(delim);
  }
    return delimiters;
}

// Removes the delimiter header from input string if present
std::string StringCalculator::stripDelimiterHeader(const std::string& input) {
    if (input.substr(0, 2) == "//") {
        size_t pos = input.find('\n');
        return input.substr(pos + 1);
    }
    return input;
}

// Replaces all delimiters in input string with comma
std::string StringCalculator::normalizeDelimiters(
  const std::string& input,
  const std::vector<std::string>& delimiters) {  // Line split for inspect-code
  std::string result = input;
  for (const auto& d : delimiters) {
    size_t idx = 0;
    while ((idx = result.find(d, idx)) != std::string::npos) {
      result.replace(idx, d.length(), ",");
      idx += 1;
    }
  }
  return result;
}

// Parses numbers from comma-separated string
std::vector<int> StringCalculator::parseNumbers(const std::string& input) {
    std::vector<int> nums;
    std::stringstream ss(input);
    std::string item;
    while (std::getline(ss, item, ',')) {
        if (!item.empty()) {
            nums.push_back(std::stoi(item));
        }
    }
    return nums;
}

// Throws if any negative numbers are found
void StringCalculator::checkNegatives(const std::vector<int>& nums) {
    std::vector<int> negatives;
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(negatives),
               [](int n) { return n < 0; });  // Use STL algorithm

    if (!negatives.empty()) {
        std::string msg = "negatives not allowed:";
        for (int n : negatives) msg += " " + std::to_string(n);
        throw std::runtime_error(msg);
    }
}

// Sums numbers, ignoring any >1000
int StringCalculator::sumNumbers(const std::vector<int>& nums) {
  return std::accumulate(
    nums.begin(), nums.end(), 0,
    [](int acc, int n) {
      return acc + (n <= 1000 ? n : 0);
    });  // Use STL algorithm
}
