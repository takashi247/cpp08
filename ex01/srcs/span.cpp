#include "span.hpp"

#include <iostream>
#include <exception>
#include <algorithm>
#include <functional>

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
    throw std::out_of_range("shortestSpan() requires at least 2 elements");
  } else {
    std::vector<long> vec_long(vec_.size());
    std::copy(vec_.begin(), vec_.end(), vec_long.begin());
    std::sort(vec_long.begin(), vec_long.end());
    std::vector<long> vec_res(vec_.size());
    std::transform(vec_long.begin() + 1, vec_long.end() - 1, vec_long.begin(), vec_res.begin(), std::minus<long>());
    vec_res.push_back(longestSpan());
    std::vector<long>::const_iterator min_it = std::min_element(vec_res.begin(), vec_res.end());
    return *min_it;
  }
}

long Span::longestSpan() const {
  if (num_elem_ <= 1) {
    throw std::out_of_range("longestSpan() requires at least 2 elements");
  } else {
    std::vector<int>::const_iterator min = std::min_element(vec_.begin(), vec_.end());
    std::vector<int>::const_iterator max = std::max_element(vec_.begin(), vec_.end());
    long max_val = static_cast<long>(*max);
    long min_val = static_cast<long>(*min);
    return max_val - min_val;
  }
}
