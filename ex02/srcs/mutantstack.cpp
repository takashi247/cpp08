#include "mutantstack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {
  // std::cout << "mutantstack's default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &other) {
  // std::cout << "mutantstack's copy constructor called" << std::endl;
  *this = other;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other) {
  // std::cout << "mutantstack's assignation operator called" << std::endl;
  if (this != &other) {
  }
  return *this;
}

template<typename T>
MutantStack<T>::~MutantStack() {
  // std::cout << "mutantstack's destructor called" << std::endl;
}
