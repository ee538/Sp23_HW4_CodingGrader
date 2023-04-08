#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

/**
 * This function is used by Google Test. Don't touch!
 */
template <class T>
void PrintCollection(std::string_view name, T input, bool add_new_line = true) {
  if (!name.empty()) {
    std::cout << name << ": ";
  }
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }";
  if (add_new_line) {
    std::cout << std::endl;
  }
}

/**
 * Given a vector of integers, we want to produce the product of the current 
 * highest k > 0 of these numbers. If the input vector size is less than k,
 * then the output should be empty. The size of the output vector is equal to
 *  `input.size() - k + 1`.
 *
 * Example:
 *
 * input = {1, 10, 5, 4, 8, 9}, k = 3
 * Output: {50, 200, 400, 720}
 * explanation: 
 * 
 * 1 * 10 * 5 = 50, (1, 10, 5 are the larggest ones in {1, 10, 5})
 * 10 * 5 * 4 = 200, (10, 5, 4 are the larggest ones in {1, 10, 5, 4})
 * 10 * 5 * 8 = 400, (10, 5, 8 are the larggest ones in {1, 10, 5, 4, 8})
 * 10 * 8 * 9 = 720 (10, 8, 9 are the larggest ones in {1, 10, 5, 4, 8, 9})
 *
 * input = {1, 10, 5, 4, 8, 9}, k = 13
 * Output: {}
 */

std::vector<int> ProductOfKHighestNumbers(const std::vector<int> &input, int k);
