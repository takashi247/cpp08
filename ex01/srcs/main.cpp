#include <iostream>
#include "span.hpp"

int main() {
  Span sp = Span(5);

  sp.addNumber(5);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

#ifdef TEST
  // int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // Span sp_10 = Span(10);
#endif
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void) {
  system("leaks -q a.out");
}
#endif
