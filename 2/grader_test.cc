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

TEST(DFSTest, DfsNoPathFromRoot) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {}},
      {1, {3}},
      {2, {5}},
      {3, {1, 4, 5}},
  };
  int root = 0;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.DFS(root);

  EXPECT_THAT(actual, ElementsAreArray({0}));
}

TEST(DFSTest, DfsUnconnected1) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}}, {2, {0, 5}}, {3, {1, 4, 5}}, {4, {3}},
      {5, {2, 3}}, {6, {7, 8}}, {7, {8}},    {8, {7}}};

  int root = 0;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.DFS(root);

  EXPECT_THAT(actual, ElementsAreArray({0, 1, 3, 4, 5, 2}));
}

TEST(DFSTest, DfsUnconnected2) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}}, {2, {0, 5}}, {3, {1, 4, 5}}, {4, {3}},
      {5, {2, 3}}, {6, {7, 8}}, {7, {8}},    {8, {7}}};

  int root = 7;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.DFS(root);

  EXPECT_THAT(actual, ElementsAreArray({7, 8}));
}

TEST(DFSTest, DfsConnected1) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}},    {2, {0, 5}}, {3, {1, 4, 5}},
      {4, {3, 6}}, {5, {2, 3, 6}}, {6, {4, 5}},

  };

  int root = 0;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.DFS(root);

  EXPECT_THAT(actual, ElementsAreArray({0, 1, 3, 4, 6, 5, 2}));
}

TEST(DFSTest, DfsConnected2) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}},    {2, {0, 5}}, {3, {1, 4, 5}},
      {4, {3, 6}}, {5, {2, 3, 6}}, {6, {4, 5}},

  };

  int root = 6;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.DFS(root);

  EXPECT_THAT(actual, ElementsAreArray({6, 4, 3, 1, 0, 2, 5}));
}

//-----------------------------------------------------------------------------
TEST(DFSAllTest, DfsAllUnconnected1) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {}},
      {1, {3}},
      {2, {5}},
      {3, {1, 4, 5}},
  };

  Graph g(adjacency_list);
  g.Print();

  auto actual = g.DFSAll();

  EXPECT_THAT(actual, ElementsAreArray({0, 1, 3, 4, 5, 2}));
}

TEST(DFSAllTest, DfsAllUnconnected2) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {}},
      {1, {3}},
      {2, {5}},
      {3, {1, 4}},
  };

  Graph g(adjacency_list);
  g.Print();
  auto actual = g.DFSAll();

  EXPECT_THAT(actual, ElementsAreArray({0, 1, 3, 4, 2, 5}));
}

TEST(DFSAllTest, DfsAllConnected1) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}},    {2, {0, 5}}, {3, {1, 4, 5}},
      {4, {3, 6}}, {5, {2, 3, 6}}, {6, {4, 5}},

  };

  Graph g(adjacency_list);
  g.Print();
  auto actual = g.DFSAll();

  EXPECT_THAT(actual, ElementsAreArray({0, 1, 3, 4, 6, 5, 2}));
}

//-----------------------------------------------------------------------------
TEST(IsBidirectionalTest, IsBidirectionalEmpty) {
  std::map<int, std::set<int>> adjacency_list{};
  Graph g(adjacency_list);
  g.Print();

  auto actual = g.IsBidirectional();
  EXPECT_TRUE(actual);
}

TEST(IsBidirectionalTest, IsBidirectionalSingleNode) {
  std::map<int, std::set<int>> adjacency_list{{0, {}}};
  Graph g(adjacency_list);
  g.Print();

  auto actual = g.IsBidirectional();
  EXPECT_TRUE(actual);
}

TEST(IsBidirectionalTest, IsBidirectional1) {
  std::map<int, std::set<int>> adjacency_list{//
                                              {0, {1}},
                                              {1, {0}}};
  Graph g(adjacency_list);
  g.Print();

  auto actual = g.IsBidirectional();
  EXPECT_TRUE(actual);
}

TEST(IsBidirectionalTest, IsBidirectional2) {
  std::map<int, std::set<int>> adjacency_list{//
                                              {0, {1, 2}},
                                              {1, {0, 2}},
                                              {2, {0, 1}}};
  Graph g(adjacency_list);
  g.Print();

  auto actual = g.IsBidirectional();
  EXPECT_TRUE(actual);
}

TEST(IsBidirectionalTest, IsBidirectional3) {
  std::map<int, std::set<int>> adjacency_list{//
                                              {0, {1, 2}},
                                              {1, {0, 2}},
                                              {2, {0}}};
  Graph g(adjacency_list);
  g.Print();

  auto actual = g.IsBidirectional();
  EXPECT_FALSE(actual);
}

//-----------------------------------------------------------------------------
TEST(IsConnectedTest, IsConnected1) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {}},
      {1, {3}},
      {2, {5}},
      {3, {1, 4, 5}},
  };

  Graph g(adjacency_list);
  g.Print();

  auto actual = g.IsConnected();

  EXPECT_THAT(actual, false);
}

TEST(IsConnectedTest, IsConnected2) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}}, {2, {0, 5}}, {3, {1, 4, 5}}, {4, {3}},
      {5, {2, 3}}, {6, {7, 8}}, {7, {8}},    {8, {7}}};

  Graph g(adjacency_list);

  auto actual = g.IsConnected();
  g.Print();

  EXPECT_THAT(actual, false);
}

TEST(IsConnectedTest, IsConnected3) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}},    {2, {0, 5}}, {3, {1, 4, 5}},
      {4, {3, 6}}, {5, {2, 3, 6}}, {6, {4, 5}},

  };
  Graph g(adjacency_list);
  g.Print();

  auto actual = g.IsConnected();

  EXPECT_THAT(actual, true);
}
//-----------------------------------------------------------------------------
TEST(BFSTest, BfsNoPathFromRoot) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {}},
      {1, {3}},
      {2, {5}},
      {3, {1, 4, 5}},
  };

  int root = 0;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.BFS(root);

  EXPECT_THAT(actual.distance,
              ElementsAreArray({0, INT_MAX, INT_MAX, INT_MAX}));

  EXPECT_THAT(actual.visited, ElementsAreArray({0}));

  EXPECT_THAT(actual.path, ElementsAreArray(std::map<int, std::vector<int>>{
                               //
                               {0, {0}},
                               {1, {}},
                               {2, {}},
                               {3, {}}
                               //
                           }));
}

TEST(BFSTest, BfsUnconnected1) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}}, {2, {0, 5}}, {3, {1, 4, 5}}, {4, {3}},
      {5, {2, 3}}, {6, {7, 8}}, {7, {8}},    {8, {7}}};

  int root = 0;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.BFS(root);

  EXPECT_THAT(actual.distance,
              ElementsAreArray({0, 1, 1, 2, 3, 2, INT_MAX, INT_MAX, INT_MAX}));

  EXPECT_THAT(actual.visited, ElementsAreArray({0, 1, 2, 3, 5, 4}));

  EXPECT_THAT(actual.path, ElementsAreArray(std::map<int, std::vector<int>>{
                               //
                               {0, {0}},
                               {1, {0, 1}},
                               {2, {0, 2}},
                               {3, {0, 1, 3}},
                               {4, {0, 1, 3, 4}},
                               {5, {0, 2, 5}},
                               {6, {}},
                               {7, {}},
                               {8, {}}
                               //
                           }));
}

TEST(BFSTest, BfsUnconnected2) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}}, {2, {0, 5}}, {3, {1, 4, 5}}, {4, {3}},
      {5, {2, 3}}, {6, {7, 8}}, {7, {8}},    {8, {7}}};

  int root = 6;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.BFS(root);

  EXPECT_THAT(actual.distance,
              ElementsAreArray({INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,
                                INT_MAX, 0, 1, 1}));

  EXPECT_THAT(actual.visited, ElementsAreArray({6, 7, 8}));

  EXPECT_THAT(actual.path, ElementsAreArray(std::map<int, std::vector<int>>{
                               //
                               {0, {}},
                               {1, {}},
                               {2, {}},
                               {3, {}},
                               {4, {}},
                               {5, {}},
                               {6, {6}},
                               {7, {6, 7}},
                               {8, {6, 8}}
                               //
                           }));
}

TEST(BFSTest, BfsConnected1) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}},    {2, {0, 5}}, {3, {1, 4, 5}},
      {4, {3, 6}}, {5, {2, 3, 6}}, {6, {4, 5}},

  };

  int root = 0;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.BFS(root);

  EXPECT_THAT(actual.distance, ElementsAreArray({0, 1, 1, 2, 3, 2, 3}));

  EXPECT_THAT(actual.visited, ElementsAreArray({0, 1, 2, 3, 5, 4, 6}));

  EXPECT_THAT(actual.path, ElementsAreArray(std::map<int, std::vector<int>>{
                               //
                               {0, {0}},
                               {1, {0, 1}},
                               {2, {0, 2}},
                               {3, {0, 1, 3}},
                               {4, {0, 1, 3, 4}},
                               {5, {0, 2, 5}},
                               {6, {0, 2, 5, 6}}
                               //
                           }));
}

TEST(BFSTest, BfsConnected2) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}},    {2, {0, 5}}, {3, {1, 4, 5}},
      {4, {3, 6}}, {5, {2, 3, 6}}, {6, {4, 5}},

  };

  int root = 6;

  Graph g(adjacency_list);
  g.Print();
  std::cout << "root: " << root << std::endl;
  auto actual = g.BFS(root);

  EXPECT_THAT(actual.distance, ElementsAreArray({3, 3, 2, 2, 1, 1, 0}));

  EXPECT_THAT(actual.visited, ElementsAreArray({6, 4, 5, 3, 2, 1, 0}));

  EXPECT_THAT(actual.path, ElementsAreArray(std::map<int, std::vector<int>>{
                               //
                               {0, {6, 5, 2, 0}},
                               {1, {6, 4, 3, 1}},
                               {2, {6, 5, 2}},
                               {3, {6, 4, 3}},
                               {4, {6, 4}},
                               {5, {6, 5}},
                               {6, {6}}
                               //
                           }));
}

//-----------------------------------------------------------------------------

TEST(IsPathBetweenNodesTest, NoPathFromRoot) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {}},
      {1, {3}},
      {2, {5}},
      {3, {1, 4, 5}},
  };

  Graph g(adjacency_list);
  g.Print();

  EXPECT_THAT(g.IsPathBetweenNodes(0, 1), false);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 2), false);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 3), false);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 4), false);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 5), false);

  EXPECT_THAT(g.IsPathBetweenNodes(1, 3), true);
  EXPECT_THAT(g.IsPathBetweenNodes(1, 5), true);
}

TEST(IsPathBetweenNodesTest, DfsUnconnected1) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}}, {2, {0, 5}}, {3, {1, 4, 5}}, {4, {3}},
      {5, {2, 3}}, {6, {7, 8}}, {7, {8}},    {8, {7}}};

  Graph g(adjacency_list);
  g.Print();

  EXPECT_THAT(g.IsPathBetweenNodes(0, 1), true);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 2), true);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 3), true);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 4), true);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 5), true);

  EXPECT_THAT(g.IsPathBetweenNodes(0, 6), false);
  EXPECT_THAT(g.IsPathBetweenNodes(7, 6), false);
  EXPECT_THAT(g.IsPathBetweenNodes(6, 7), true);
}

TEST(IsPathBetweenNodesTest, DfsConnected1) {
  std::map<int, std::set<int>> adjacency_list{
      //
      {0, {1, 2}}, {1, {0, 3}},    {2, {0, 5}}, {3, {1, 4, 5}},
      {4, {3, 6}}, {5, {2, 3, 6}}, {6, {4, 5}},

  };

  Graph g(adjacency_list);
  g.Print();

  EXPECT_THAT(g.IsPathBetweenNodes(0, 1), true);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 2), true);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 3), true);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 4), true);
  EXPECT_THAT(g.IsPathBetweenNodes(0, 5), true);

  EXPECT_THAT(g.IsPathBetweenNodes(0, 6), true);
}

//-----------------------------------------------------------------------------

TEST(ReachesACycle, SingleNode) {
  std::map<int, std::set<int>> adjacency_list{{0, {}}};

  Graph g(adjacency_list);
  g.Print();

  EXPECT_THAT(g.ReachesACycle(0), false);
}

TEST(HasCycle, SingleNode) {
  std::map<int, std::set<int>> adjacency_list{{0, {}}};

  Graph g(adjacency_list);
  g.Print();

  EXPECT_THAT(g.HasCycle(), false);
}

TEST(ReachesACycle, Test1) {
  std::map<int, std::set<int>> adjacency_list{
      {0, {1, 3}}, {1, {0, 3}}, {2, {0, 3}}, {3, {1, 2, 4, 6}},
      {4, {}},     {5, {0}},    {6, {3}}};

  Graph g(adjacency_list);
  g.Print();

  EXPECT_THAT(g.ReachesACycle(0), true);
  EXPECT_THAT(g.ReachesACycle(1), true);
  EXPECT_THAT(g.ReachesACycle(2), true);
  EXPECT_THAT(g.ReachesACycle(3), true);
  EXPECT_THAT(g.ReachesACycle(4), false);
  EXPECT_THAT(g.ReachesACycle(5), true);
  EXPECT_THAT(g.ReachesACycle(6), true);
}

TEST(HasCycle, Test1) {
  std::map<int, std::set<int>> adjacency_list{
      {0, {1, 3}}, {1, {0, 3}}, {2, {0, 3}}, {3, {1, 2, 4, 6}},
      {4, {}},     {5, {0}},    {6, {3}}};
  Graph g(adjacency_list);
  g.Print();

  EXPECT_THAT(g.HasCycle(), true);
}

TEST(ReachesACycle, Test2) {
  std::map<int, std::set<int>> adjacency_list{
      {0, {1, 2, 5}}, {1, {2, 3}}, {2, {0, 1, 3}}, {3, {4, 6}},
      {4, {}},        {5, {0}},    {6, {4}}};

  Graph g(adjacency_list);
  g.Print();

  EXPECT_THAT(g.ReachesACycle(0), true);
  EXPECT_THAT(g.ReachesACycle(1), true);
  EXPECT_THAT(g.ReachesACycle(2), true);
  EXPECT_THAT(g.ReachesACycle(3), false);
  EXPECT_THAT(g.ReachesACycle(4), false);
  EXPECT_THAT(g.ReachesACycle(5), true);
  EXPECT_THAT(g.ReachesACycle(6), false);
}

TEST(HasCycle, Test2) {
  std::map<int, std::set<int>> adjacency_list{
      {0, {1, 2, 5}}, {1, {2, 3}}, {2, {0, 1, 3}}, {3, {4, 6}},
      {4, {}},        {5, {0}},    {6, {4}}};

  Graph g(adjacency_list);
  g.Print();

  EXPECT_THAT(g.HasCycle(), true);
}