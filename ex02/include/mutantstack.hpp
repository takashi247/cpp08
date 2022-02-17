#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack(){};
  MutantStack(const MutantStack &other){ *this = other; };
  MutantStack &operator=(const MutantStack &other){
    if (this != &other) {
    }
    return *this;
  };
  virtual ~MutantStack(){};

 private:

};

#endif // MUTANTSTACK_HPP
