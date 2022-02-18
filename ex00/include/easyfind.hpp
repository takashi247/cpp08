#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::iterator easyfind(T& cont, int num) {
  return std::find(cont.begin(), cont.end(), num);
}

template <typename T>
typename T::const_iterator easyfind(const T& cont, int num) {
  return std::find(cont.begin(), cont.end(), num);
}

template <typename T>
void testEasyFind(T& cont, int num) {
  typename T::iterator it = easyfind(cont, num);
  typename T::iterator it_end = cont.end();
  if (it == it_end) {
    std::cout << "not found" << std::endl;
  } else {
    std::cout << *it << std::endl;
  }
}

template <typename T>
void testEasyFind(const T& cont, int num) {
  typename T::const_iterator it = easyfind(cont, num);
  typename T::const_iterator it_end = cont.end();
  if (it == it_end) {
    std::cout << "not found" << std::endl;
  } else {
    std::cout << *it << std::endl;
  }
}

#endif // EASYFIND_HPP
