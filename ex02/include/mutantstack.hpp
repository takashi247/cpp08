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

   public:
    iterator() : index_(0), stack_(NULL) {};
    iterator(MutantStack* stack, size_t index) : index_(index), stack_(stack) {};
    iterator(const iterator& other) { *this = other; };
    iterator& operator=(const iterator &other) {
      if (this != &other) {
        index_ = other.index_;
        stack_ = other.stack_;
      }
      return *this;
    };
    iterator& operator++() {
      ++index_;
      return *this;
    };
    iterator operator++(int) {
      iterator tmp = *this;
      ++(*this);
      return tmp;
    };
    iterator& operator--() {
      if (0 < index_) {
        --index_;
      }
      return *this;
    };
    iterator operator--(int) {
      iterator tmp = *this;
      --(*this);
      return tmp;
    };
    T& operator*() {
      std::stack<T> tmp = *(this->stack_);
      for (size_t i = 0; i < this->stack_->size() - index_ - 1; ++i) {
        tmp.pop();
      }
      return tmp.top();
    };
    bool operator==(const iterator& iterator) {
      return this->stack_ == iterator.stack_ && this->index_ == iterator.index_;
    };
    bool operator!=(const iterator& iterator) {
      return !(*this == iterator);
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
  iterator begin() {
    return iterator(this, 0);
  }
  iterator end() {
    return iterator(this, this->size());
  }

 private:

};

#endif // MUTANTSTACK_HPP
