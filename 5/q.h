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

template <class T>
void Print2dVector(std::string_view name, std::vector<std::vector<T>> input) {
  std::cout << name << ": {" << std::endl;
  for (size_t i = 0; i < input.size(); i++) {
    std::cout << "  {";
    for (size_t j = 0; j < input[0].size(); j++) {
      std::cout << input[i][j];
      if (j < input[0].size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "}" << std::endl;
  }
  std::cout << "}" << std::endl;
}

//-----------------------------------------------------------------------------
// TODO:
/**
 * Given a maze, represented by a matrix of bits (values 0 and 1),
 * a rat must find a path from index [0][0] to [n-1][m-1].
 *
 * The rat can only travel to the right or down.
 *
 * It can only travel on 0 values. 1 values represent walls.
 *
 * If there are multiple paths, you should return the path in which
 * going down has precedence over going right. Return empty if
 * there is no path.
 *
 * Input:   maze (Matrix of elements with values either 0 or 1)
 * Output:  Array of two-item arrays indicating the path.
 * Example
Input:   [[0, 0, 0, 1],
          [0, 1, 0, 1],
          [0, 1, 0, 0],
          [0, 0, 1, 0]]

Output:  [[0, 0],
          [0, 1],
          [0, 2],
          [1, 2],
          [2, 2],
          [2, 3],
          [3, 3]]

*/
std::vector<std::pair<int, int>> RatPath(
    const std::vector<std::vector<int>>& grid);