#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <map>

#include "easyfind.hpp"

int main() {
  int arr[] = {0, 1, 2, 3, 4};
  {
    std::cout << "\n---lst test---\n" << std::endl;
    std::list<int> cont(arr, arr + 5);
    std::list<int>::iterator it = cont.begin();
    *it = 42;
    testEasyFind(cont, 3);
    testEasyFind(cont, 42);
  }
  {
    std::cout << "\n---const lst test---\n" << std::endl;
    const std::list<int> cont(arr, arr + 5);
    // std::list<int>::const_iterator it = cont.begin();
    // *it = 42;
    testEasyFind(cont, 3);
    testEasyFind(cont, 42);
  }
  {
    std::cout << "\n---deque test---\n" << std::endl;
    std::deque<int> cont(arr, arr + 5);
    testEasyFind(cont, 3);
    testEasyFind(cont, 42);
  }
  {
    std::cout << "\n---set test---\n" << std::endl;
    std::set<int> cont(arr, arr + 5);
    testEasyFind(cont, 3);
    testEasyFind(cont, 42);
  }
  {
    std::cout << "\n---multiset test---\n" << std::endl;
    std::multiset<int> cont(arr, arr + 5);
    testEasyFind(cont, 3);
    testEasyFind(cont, 42);
  }
  std::cout << std::endl;
}
