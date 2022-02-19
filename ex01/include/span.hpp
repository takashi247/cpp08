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
    typedef typename std::iterator_traits<InputIterator>::difference_type diff_type;
    diff_type len = std::distance(first, last);
    diff_type remained_slot = static_cast<diff_type>(size_ - num_elem_);
    if (len <= remained_slot) {
      vec_.insert(vec_.begin() + num_elem_, first, last);
      num_elem_ += static_cast<unsigned int>(len);
    } else {
      throw std::out_of_range("addNumber out of range");
    }
  }

  long shortestSpan() const;
  long longestSpan() const;

 private:
  unsigned int size_;
  unsigned int num_elem_;
  std::vector<int> vec_;
};

#endif // SPAN_HPP
