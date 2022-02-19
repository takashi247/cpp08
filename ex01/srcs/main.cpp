#include "span.hpp"

#include <iostream>
#include <list>
#include <limits>

int main() {
  std::cout << "\n---Subject + error handling test---\n" << std::endl;

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
  std::cout << "\n---Copy constructor and assignation test---\n" << std::endl;
  {
    Span copy(sp);
    std::cout << copy.shortestSpan() << std::endl;
    std::cout << copy.longestSpan() << std::endl;
    Span assign;
    assign = sp;
    std::cout << assign.shortestSpan() << std::endl;
    std::cout << assign.longestSpan() << std::endl;
  }
  std::cout << "\n---addNumber with int array---\n" << std::endl;

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
  std::cout << "\n---addNumber with int vector---\n" << std::endl;

  std::vector<int> vec_arr(arr, arr + 10);
  try {
    Span sp_10 = Span(10);
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
  std::cout << "\n---addNumer with int list---\n" << std::endl;

  std::list<int> lst_arr(arr, arr + 10);
  try {
    Span sp_10 = Span(10);
    sp_10.addNumber(lst_arr.begin(), lst_arr.end());
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
  std::cout << "\n---Span with INT_MAX and INT_MIN---\n" << std::endl;

  std::vector<int> vec_min_max(100, 0);
  std::vector<int>::iterator it_head = vec_min_max.begin();
  *it_head = std::numeric_limits<int>::min();
  std::vector<int>::reverse_iterator it_tail = vec_min_max.rbegin();
  *it_tail = std::numeric_limits<int>::max();
  try {
    Span sp_100 = Span(100);
    sp_100.addNumber(vec_min_max.begin(), vec_min_max.end());
    std::vector<int> vec = sp_100.getVec();
    std::vector<int>::const_iterator it_end = vec.end();
    for (std::vector<int>::const_iterator it = vec.begin(); it < it_end; ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << sp_100.shortestSpan() << std::endl;
    std::cout << sp_100.longestSpan() << std::endl;
  } catch (const std::out_of_range& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "\n---Large vector---\n" << std::endl;

  std::vector<int> vec_long_max(1000, 0);
  try {
    Span sp_100 = Span(100);
    sp_100.addNumber(vec_long_max.begin(), vec_long_max.end());
    std::vector<int> vec = sp_100.getVec();
    std::vector<int>::const_iterator it_end = vec.end();
    for (std::vector<int>::const_iterator it = vec.begin(); it < it_end; ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << sp_100.shortestSpan() << std::endl;
    std::cout << sp_100.longestSpan() << std::endl;
  } catch (const std::out_of_range& e) {
    std::cout << e.what() << std::endl;
  }
  // std::cout << "\n---Span with maximum size---\n" << std::endl;

  // std::vector<int> large_vec(std::numeric_limits<unsigned int>::max(), 0);
  // std::vector<int>::iterator it_head = large_vec.begin();
  // *it_head = std::numeric_limits<int>::min();
  // std::vector<int>::reverse_iterator it_tail = large_vec.rbegin();
  // *it_tail = std::numeric_limits<int>::max();
  // try {
  //   Span sp_max = Span(std::numeric_limits<unsigned int>::max());
  //   sp_max.addNumber(large_vec.begin(), large_vec.end());
  //   std::vector<int> vec = sp_max.getVec();
  //   std::vector<int>::const_iterator it_end = vec.end();
  //   for (std::vector<int>::const_iterator it = vec.begin(); it < it_end; ++it) {
  //     std::cout << *it << " ";
  //   }
  //   std::cout << std::endl;
  //   std::cout << sp_max.shortestSpan() << std::endl;
  //   std::cout << sp_max.longestSpan() << std::endl;
  // } catch (const std::out_of_range& e) {
  //   std::cout << e.what() << std::endl;
  // }
#endif
  std::cout << std::endl;
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void) {
  system("leaks -q a.out");
}
#endif
