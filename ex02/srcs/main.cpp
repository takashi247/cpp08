#include "mutantstack.hpp"

#include <iostream>
#include <string>

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
  }
  {
    std::cout << "\n---Copy constructor and assignation test---\n" << std::endl;

    MutantStack<int> mstack;

    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(3);

    MutantStack<int> mstack_copy(mstack);
    MutantStack<int> mstack_assign;
    mstack_assign = mstack;

    mstack_copy.push(42);
    std::cout << "<Copy-constructed MutantStack>\n" << std::endl;
    MutantStack<int>::iterator it_end_copy = mstack_copy.end();
    for (MutantStack<int>::iterator it = mstack_copy.begin(); it < it_end_copy; ++it) {
      std::cout << *it << std::endl;
    }

    mstack_assign.push(-42);
    std::cout << "\n<Assigned MutantStack>\n" << std::endl;
    MutantStack<int>::const_iterator it_end_assign = mstack_assign.end();
    for (MutantStack<int>::iterator it = mstack_assign.begin(); it < it_end_assign; ++it) {
      std::cout << *it << std::endl;
    }
  }
  {
    std::cout << "\n--Const iterator test---\n" << std::endl;

    MutantStack<const int> mstack;

    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(3);

    MutantStack<const int>::const_iterator it_end = mstack.end();
    for (MutantStack<const int>::const_iterator it = mstack.begin(); it < it_end; ++it) {
      std::cout << *it << std::endl;
    }
  }
  {
    std::cout << "\n--Reverse iterator test---\n" << std::endl;

    MutantStack<std::string> mstack;

    mstack.push("one");
    mstack.push("two");
    mstack.push("three");
    mstack.push("four");
    mstack.push("five");

    MutantStack<std::string>::reverse_iterator it_rend = mstack.rend();
    for (MutantStack<std::string>::reverse_iterator it = mstack.rbegin(); it < it_rend; ++it) {
      std::cout << *it << std::endl;
    }
  }
  {
    std::cout << "\n--Const reverse iterator test---\n" << std::endl;

    MutantStack<const std::string> mstack;

    mstack.push("one");
    mstack.push("two");
    mstack.push("three");
    mstack.push("four");
    mstack.push("five");

    MutantStack<const std::string>::const_reverse_iterator it_rend = mstack.rend();
    for (MutantStack<const std::string>::const_reverse_iterator it = mstack.rbegin(); it < it_rend; ++it) {
      std::cout << *it << std::endl;
    }
  }
  std::cout << std::endl;
  return 0;
}
