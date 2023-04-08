#include <climits>
#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"

using ::testing::ElementsAreArray;
using ::testing::Eq;
using ::testing::Pair;
using ::testing::UnorderedElementsAre;

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(ProductOfKHighestNumbers, Empty) {
  vector<int> input = {};
  const int k = 3;
  auto actual = ProductOfKHighestNumbers(input, k);

  PrintCollection("input", input, /*add_new_line=*/true);
  std::cout << "k: " << k << std::endl;
  EXPECT_THAT(actual, ::testing::IsEmpty());
}

TEST(ProductOfKHighestNumbers, Size6K2) {
  vector<int> input = {1, 10, 5, 4, 8, 9};
  const int k = 2;
  PrintCollection("input", input, /*add_new_line=*/true);
  std::cout << "k: " << k << std::endl;
  auto actual = ProductOfKHighestNumbers(input, k);

  EXPECT_THAT(actual, ElementsAreArray({10, 50, 50, 80, 90}));
}

TEST(ProductOfKHighestNumbers, Size6K4) {
  vector<int> input = {1, 10, 5, 4, 8, 9};
  const int k = 4;
  PrintCollection("input", input, /*add_new_line=*/true);
  std::cout << "k: " << k << std::endl;
  auto actual = ProductOfKHighestNumbers(input, k);

  EXPECT_THAT(actual, ElementsAreArray({200, 1600, 3600}));
}

TEST(ProductOfKHighestNumbers, Size6K3Negative) {
  vector<int> input = {1, -10, 5, 4, 8, 9};
  const int k = 3;
  PrintCollection("input", input, /*add_new_line=*/true);
  std::cout << "k: " << k << std::endl;
  auto actual = ProductOfKHighestNumbers(input, k);

  EXPECT_THAT(actual, ElementsAreArray({-50, 20, 160, 360}));
}

TEST(ProductOfKHighestNumbers, Size6K3Negative2) {
  vector<int> input = {1, -10, -5, 4, 8, 9};
  const int k = 3;
  PrintCollection("input", input, /*add_new_line=*/true);
  std::cout << "k: " << k << std::endl;
  auto actual = ProductOfKHighestNumbers(input, k);

  EXPECT_THAT(actual, ElementsAreArray({50, -20, 32, 288}));
}