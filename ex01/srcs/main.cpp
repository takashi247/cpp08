#include <iostream>
#include "span.hpp"

int main() {
  Span sp = Span(5);

  try {
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    sp.addNumber(42);
  } catch (const std::out_of_range& e) {
    std::cout << e.what() << std::endl;
  }

#ifdef TEST
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  try {
    Span sp_10 = Span(10);
    sp_10.addNumber(arr, arr + 10);
    std::vector<int> vec = sp_10.getVec();
    std::vector<int>::const_iterator it_end = vec.end();
    for (std::vector<int>::const_iterator it = vec.begin(); it < it_end; ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << sp_10.shortestSpan() << std::endl;
    std::cout << sp_10.longestSpan() << std::endl;
  } catch (const std::out_of_range& e) {
    std::cout << e.what() << std::endl;
  }
  std::vector<int> vec_arr(arr, arr + 10);
  try {
    Span sp_10 = Span(5);
    sp_10.addNumber(vec_arr.begin(), vec_arr.end());
    std::vector<int> vec = sp_10.getVec();
    std::vector<int>::const_iterator it_end = vec.end();
    for (std::vector<int>::const_iterator it = vec.begin(); it < it_end; ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << sp_10.shortestSpan() << std::endl;
    std::cout << sp_10.longestSpan() << std::endl;
  } catch (const std::out_of_range& e) {
    std::cout << e.what() << std::endl;
  }
#endif
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void) {
  system("leaks -q a.out");
}
#endif
