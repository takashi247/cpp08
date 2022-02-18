#include <iostream>
#include <list>

int main() {
  std::list<int> lst;

  for (int i = 0; i < 5; ++i) {
    lst.push_back(i);
  }

  std::cout << lst.max_size() << "\n"
            << lst.size() << std::endl;

  std::list<int>::const_iterator it = lst.begin();
  std::list<int>::const_iterator it_end = lst.end();
  std::cout << std::endl;
  for (int i = 0; i < 10; ++i) {
    std::cout << *it << "\n";
    ++it;
  }
  std::cout << std::endl;

  std::list<int>::const_reverse_iterator rit_end = lst.rend();
  for (std::list<int>::const_reverse_iterator rit = lst.rbegin(); rit != rit_end; ++rit) {
    std::cout << *rit << "\n";
  }
  std::cout << std::endl;
}

