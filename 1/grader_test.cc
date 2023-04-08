#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

template <class T>
void Print2dVector(std::string name, std::vector<std::vector<T>> input) {
  std::cout << name << ": {" << std::endl;
  for (int i = 0; i < input.size(); i++) {
    std::cout << "  {";
    for (int j = 0; j < input[0].size(); j++) {
      std::cout << input[i][j];
      if (j < input[0].size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "}" << std::endl;
  }
  std::cout << "}" << std::endl;
}

template <class T>
void PrintPair(std::string name, std::pair<T, T> input) {
  std::cout << name << "\t:(" << input.first << " , " << input.second << ")"
            << std::endl;
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(FindNumberOfUniquePathsTest, Empty) {
  std::vector<std::vector<int>> grid = {};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(0, 0);

  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 0);
}

TEST(FindNumberOfUniquePathsTest, OneRowOpen) {
  std::vector<std::vector<int>> grid = {{1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(0, 2);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 1);
}

TEST(FindNumberOfUniquePathsTest, OneRowBlocked1) {
  std::vector<std::vector<int>> grid = {{1, 0, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(0, 2);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 0);
}

TEST(FindNumberOfUniquePathsTest, OneRowBlocked2) {
  std::vector<std::vector<int>> grid = {{1, 1, 1, 0, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(0, 4);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 0);
}

TEST(FindNumberOfUniquePathsTest, OneRowBlocked3) {
  std::vector<std::vector<int>> grid = {{1, 1, 1, 1, 0}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(0, 4);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 0);
}

TEST(FindNumberOfUniquePathsTest, OneRowBlocked4) {
  std::vector<std::vector<int>> grid = {{1, 1, 1, 1, 0}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(0, 3);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 1);
}

TEST(FindNumberOfUniquePathsTest, TwoRowsOpen1) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(1, 4);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 5);
}

TEST(FindNumberOfUniquePathsTest, TwoRowsOpen11) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 1},
                                        {1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(1, 2);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 3);
}

TEST(FindNumberOfUniquePathsTest, TwoRowsOpen2) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 1, 1, 0},
                                        {1, 1, 1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(1, 4);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 4);
}

TEST(FindNumberOfUniquePathsTest, TwoRowsOpen3) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 0, 1, 1, 0},
                                        {1, 1, 1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(1, 4);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 1);
}

TEST(FindNumberOfUniquePathsTest, TwoRowsOpen4) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 0, 1, 0},
                                        {1, 1, 1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(1, 4);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 2);
}

TEST(FindNumberOfUniquePathsTest, TwoRowsBlocked1) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 0, 1, 0},
                                        {1, 1, 0, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(1, 4);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 0);
}

TEST(FindNumberOfUniquePathsTest, TwoRowsBlocked2) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 0, 1, 0},
                                        {1, 1, 1, 0, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(1, 4);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 0);
}

TEST(FindNumberOfUniquePathsTest, TwoRowsBlocked3) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 1, 1, 1},
                                        {1, 1, 1, 1, 0}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(1, 4);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 0);
}

TEST(FindNumberOfUniquePathsTest, ThreeRowsOpen1) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 1, 1},
                                        {1, 1, 1, 1},
                                        {1, 1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(2, 3);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 10);
}

TEST(FindNumberOfUniquePathsTest, ThreeRowsOpen2) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 0, 1},
                                        {1, 1, 0, 1},
                                        {1, 1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(2, 3);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 3);
}

TEST(FindNumberOfUniquePathsTest, ThreeRowsOpen3) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 1, 1},
                                        {1, 1, 0, 1},
                                        {1, 1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(2, 3);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 4);
}


TEST(FindNumberOfUniquePathsTest, EndOutOfGrid) {
  std::vector<std::vector<int>> grid = {//
                                        {1, 1, 1, 1},
                                        {1, 1, 0, 1},
                                        {1, 1, 1, 1}};
  auto start = std::make_pair(0, 0);
  auto end = std::make_pair(2, 10);
  Print2dVector("Input grid", grid);
  PrintPair("start", start);
  PrintPair("end", end);

  auto actual = FindNumberOfUniquePaths(grid, start, end);
  EXPECT_EQ(actual, 0);
}