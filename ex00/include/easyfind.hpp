#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::const_iterator easyfind(const T& cont, int num) {
  return std::find(cont.begin(), cont.end(), num);
}

#endif // EASYFIND_HPP
