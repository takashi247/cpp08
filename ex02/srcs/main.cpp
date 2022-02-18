#include "mutantstack.hpp"

#include <iostream>

int main() {
  {
    std::cout << "\n---Subject test---\n" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(3);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }

    std::stack<int> s(mstack);

    size_t size = s.size();
    std::cout << "current size of s: " << size << std::endl;
    for (size_t i = 0; i < size; ++i) {
      std::cout << s.top() << std::endl;
      s.pop();
    }
  }
  {
    std::cout << "\n--Const iterator test---\n" << std::endl;

    MutantStack<const int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(3);

    MutantStack<const int>::iterator it = mstack.begin();
    MutantStack<const int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }

    std::stack<const int> s(mstack);

    size_t size = s.size();
    std::cout << "current size of s: " << size << std::endl;
    for (size_t i = 0; i < size; ++i) {
      std::cout << s.top() << std::endl;
      s.pop();
    }
  }
  return 0;
}

