#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main() {
  {
    const int table[] = {0, 1, 2, 3, 4};
    std::list<int> lst(table, table + 5);
    std::list<int>::const_iterator it = easyfind(lst, 5);
    if (it == lst.end()) {
      std::cout << "not found" << std::endl;
    } else {
      std::cout << *it << std::endl;
    }
  }
  {
    const int table2[] = {0, 1, 2, 3, 4};
    std::vector<int> vec(table2, table2 + 5);
    std::vector<int>::const_iterator it  = easyfind(vec, 2);
    if (it == vec.end()) {
      std::cout << "not found" << std::endl;
    } else {
      std::cout << *it << std::endl;
    }
  }
}
