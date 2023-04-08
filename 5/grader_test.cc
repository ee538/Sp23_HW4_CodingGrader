#include <climits>
#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::Eq;
using ::testing::Pair;
using ::testing::UnorderedElementsAre;
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(RatPath, Test1) {
  std::vector<std::vector<int>> input{//
                                      {0, 0, 0, 1},
                                      {0, 1, 0, 1},
                                      {0, 1, 0, 0},
                                      {0, 0, 1, 0}};

  Print2dVector("input", input);
  auto actual = RatPath(input);

  EXPECT_THAT(actual,
              ElementsAreArray({Pair(0, 0), Pair(0, 1), Pair(0, 2), Pair(1, 2),
                                Pair(2, 2), Pair(2, 3), Pair(3, 3)}));
}

TEST(RatPath, Test2) {
  std::vector<std::vector<int>> input{//
                                      {0, 0, 1, 1},
                                      {0, 1, 0, 1},
                                      {0, 1, 0, 0},
                                      {0, 0, 0, 0}};

  Print2dVector("input", input);
  auto actual = RatPath(input);

  EXPECT_THAT(actual,
              ElementsAreArray({Pair(0, 0), Pair(1, 0), Pair(2, 0), Pair(3, 0),
                                Pair(3, 1), Pair(3, 2), Pair(3, 3)}));
}

TEST(RatPath, TestMultiplePaths1) {
  std::vector<std::vector<int>> input{//
                                      {0, 0, 0, 0},
                                      {0, 1, 1, 0},
                                      {0, 1, 0, 0},
                                      {0, 0, 0, 0}};

  Print2dVector("input", input);
  auto actual = RatPath(input);

  EXPECT_THAT(actual,
              ElementsAreArray({Pair(0, 0), Pair(1, 0), Pair(2, 0), Pair(3, 0),
                                Pair(3, 1), Pair(3, 2), Pair(3, 3)}));
}


TEST(RatPath, TestMultiplePaths2) {
  std::vector<std::vector<int>> input{//
                                      {0, 0, 0, 0},
                                      {0, 0, 1, 0},
                                      {0, 0, 0, 0},
                                      {0, 0, 0, 0}};

  Print2dVector("input", input);
  auto actual = RatPath(input);

  EXPECT_THAT(actual,
              ElementsAreArray({Pair(0, 0), Pair(1, 0), Pair(2, 0), Pair(3, 0),
                                Pair(3, 1), Pair(3, 2), Pair(3, 3)}));
}

TEST(RatPath, Impossible1) {
  std::vector<std::vector<int>> input{//
                                      {0, 0, 1, 1},
                                      {0, 1, 0, 1},
                                      {0, 1, 0, 0},
                                      {0, 0, 0, 1}};

  Print2dVector("input", input);
  auto actual = RatPath(input);

  EXPECT_THAT(actual, ::testing::IsEmpty());
}

TEST(RatPath, Impossible2) {
  std::vector<std::vector<int>> input{//
                                      {0, 0, 1, 1},
                                      {0, 0, 0, 1},
                                      {0, 1, 1, 0},
                                      {0, 0, 1, 0}};

  Print2dVector("input", input);
  auto actual = RatPath(input);

  EXPECT_THAT(actual, ::testing::IsEmpty());
}
