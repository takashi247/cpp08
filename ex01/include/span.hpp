#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

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
  int shortestSpan() const;
  int longestSpan() const;

 private:
  unsigned size_;
  unsigned num_elem_;
  std::vector<int> vec_;
};

#endif // SPAN_HPP
