#include "span.hpp"

#include <iostream>
#include <exception>
#include <algorithm>

Span::Span() : size_(0), num_elem_(0) {}

Span::Span(unsigned size) : size_(size), num_elem_(0) {}

Span::Span(Span const &other) {
  *this = other;
}

Span &Span::operator=(Span const &other) {
  if (this != &other) {
    size_ = other.getSize();
    num_elem_ = other.getNumElem();
    vec_ = other.getVec();
  }
  return *this;
}

Span::~Span() {}

unsigned Span::getSize() const { return size_; }

unsigned Span::getNumElem() const { return num_elem_; }

const std::vector<int>& Span::getVec() const { return vec_; }

void Span::addNumber(const int num) {
  if (num_elem_ < size_) {
    vec_.push_back(num);
    ++num_elem_;
  } else {
    throw std::out_of_range("addNumber out of range");
  }
}

long Span::shortestSpan() const {
  if (num_elem_ <= 1) {
    throw std::exception();
  } else {
    long res = longestSpan();
    std::vector<int> vec(vec_);
    std::sort(vec.begin(), vec.end());
    std::vector<int>::const_iterator end_it = vec.end();
    for (std::vector<int>::const_iterator it = vec.begin(); it + 1 < end_it; ++it) {
      long first = static_cast<long>(*it);
      long second = static_cast<long>(*(it + 1));
      long tmp = second - first;
      if (tmp < res) {
        res = tmp;
      }
    }
    return res;
  }
}

long Span::longestSpan() const {
  if (num_elem_ <= 1) {
    throw std::exception();
  } else {
    std::vector<int>::const_iterator min = std::min_element(vec_.begin(), vec_.end());
    std::vector<int>::const_iterator max = std::max_element(vec_.begin(), vec_.end());
    long max_val = static_cast<long>(*max);
    long min_val = static_cast<long>(*min);
    return max_val - min_val;
  }
}
