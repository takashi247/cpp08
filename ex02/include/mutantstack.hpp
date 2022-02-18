#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  class iterator : public std::iterator<std::forward_iterator_tag, T> {
   private:
    size_t index_;
    MutantStack* stack_;
    iterator() : index_(SIZE_MAX), stack_(NULL) {};
    iterator(MutantStack* stack, size_t index) : index_(index), stack_(stack) {}

   public:
    iterator(const iterator& other) { *this = other; };
    iterator& operator=(const iterator &other) {
      if (this != &other) {
        index_ = other.index_;
        stack_ = other.stack_;
      }
      return *this;
    }
    iterator& operator++() {
      ++index_;
      return *this;
    };
    iterator operator++(int) {
      iterator tmp = *this;
      ++(*this);
      return tmp;
    };
    int& operator*() {
      // neee to implement
    };
    bool operator==(const iterator& iterator) {
      // need to implement
    };
    bool operator!=(const iterator& iterator) {
      // need to implement
    };
  };
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
