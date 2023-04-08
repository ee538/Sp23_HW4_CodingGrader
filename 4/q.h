#include <iostream>
#include <limits.h>
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

//-----------------------------------------------------------------------------
/**
 * This class is given to you. No need to implement it modify it!
 */
class Student {
 public:
  // Parameterized constructor
  Student(std::string name, int grade) : name(name), grade(grade) {}

  // Non-parameterized constructor. Sets the default value for name to "NO_NAME"
  // and grade to INT_MIN.
  Student() : name("NO_NAME"), grade(INT_MIN) {}

  // Copy constructor.
  Student(const Student& rhs) : name(rhs.name), grade(rhs.grade) {}

  // The following operators are overloaded. They only compare the grade part of
  // the class with other objects.

  // Returns true if grade is less than the grade of other Student objects and
  // false otherwise.
  bool operator<(const Student& rhs) const { return (grade < rhs.grade); }

  // Returns true if grade is greater than the grade of other Student objects
  // and false otherwise.
  bool operator>(const Student& rhs) const { return (grade > rhs.grade); }

  // Returns true if grade is equal to the grade of other Student objects and
  // false otherwise.
  bool operator==(const Student& rhs) const { return grade == rhs.grade; }

  friend void PrintTo(const Student& student, std::ostream* os) {
    *os << student.DebugString();
  }

  // This function will be called by testing::PrintToString.
  std::string DebugString() const {
    std::string result;
    return result + "name: " + name + ", grade: " + std::to_string(grade) +
           "\n";
  }

  std::string name;
  int grade;
};
//-----------------------------------------------------------------------------
// TODO: Implement the following class:
// A Max Heap that contains objects of type Student.
// We compare the students only based on their grade, not their names. That
// means the student with the highest grade should always be at the top of the
// heap.
class StudentMaxHeap {
 public:
  // Non-parameterized constructor: already defined. No need to modify.
  StudentMaxHeap() {}

  // Parameterized constructor: creates a max heap from the given input.
  StudentMaxHeap(std::vector<Student>& input);

  // Returns the parent of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student GetParent(int i);

  // Returns the left child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student GetLeft(int i);

  // Returns the right child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student GetRight(int i);

  // Returns the index of the parent of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int GetParentIndex(int i);

  // Returns the index of the left child of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int GetLeftIndex(int i);

  // Returns the index of the right child of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int GetRightIndex(int i);

  // Returns the index of the largest child of a node given its index in the
  // tree. Returns INT_MAX if unsuccessful.
  int GetLargestChildIndex(int i);

  // Returns true if the heap is empty and false otherwise.
  bool empty() { return data_.empty(); };

  // Returns the size of the heap.
  int size() { return data_.size(); }

  // Returns the top of the heap. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student top();

  // Adds a new Student to the heap.
  void push(const Student& student);

  // Removes the top. Returns
  // true if successful and false otherwise.
  bool pop();

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void TrickleUp(int i);

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void TrickleDown(int i);

  // Converts the given input into a max heap and stores that into data_.
  void ConvertToHeap(const std::vector<Student>& input);

  // Already implemented. No need to modify.
  std::vector<Student> GetData() { return data_; }

 private:
  std::vector<Student> data_;
};

//-----------------------------------------------------------------------------
// TODO: Implement this function:
// Sorts the given input vector of students in place. The sort is in ascending
// order based on the grades. Use heap sort!
void HeapSort(std::vector<Student>& input);