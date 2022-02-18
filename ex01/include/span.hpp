#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>

class Span {
 public:
  Span();
  explicit Span(unsigned size);
  Span(const Span &other);
  Span& operator=(const Span &other);
  virtual ~Span();

  unsigned getSize() const;
  unsigned getNumElem() const;
  const std::vector<int>& getVec() const;
  void addNumber(const int num);

  template <typename InputIterator>
  void addNumber(InputIterator first, InputIterator last) {
    unsigned int len = std::distance(first, last);
    unsigned int remained_slot = size_ - num_elem_;
    if (len <= remained_slot) {
      vec_.insert(vec_.begin() + num_elem_, first, last);
      num_elem_ += len;
    } else {
      throw std::out_of_range("addNumber out of range");
    }
  }

  int shortestSpan() const;
  int longestSpan() const;

 private:
  unsigned int size_;
  unsigned int num_elem_;
  std::vector<int> vec_;
};

#endif // SPAN_HPP
