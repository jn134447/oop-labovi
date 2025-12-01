// #include "container.hpp" // c++ moment, jesus christ...
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

template<typename T>
std::size_t
Container<T>::size() const
{
  return n_elements;
}

template<typename T>
std::size_t
Container<T>::capacity() const
{
  return alloc_elem_size;
}

template<typename T>
T&
Container<T>::at(size_t index) const
{
  if (index >= n_elements) {
    throw std::out_of_range("Container::at: index=" + std::to_string(index) +
                            " >= n_elements=" + std::to_string(n_elements));
  }
  return array[index];
}

template<typename T>
void
Container<T>::push_back(T element)
{
  auto grow_array = [this]() {
    T* temp = new T[alloc_elem_size];

    for (std::size_t i = 0; i < n_elements; i++) {
      temp[i] = std::move(array[i]);
    }

    delete[] array;
    array = temp;

    std::cout << "array reallocated, new size: " << alloc_elem_size << '\n';
  };

  if (alloc_elem_size == 0) {
    alloc_elem_size = 1;
    grow_array();
  } else if (n_elements >= alloc_elem_size) {
    alloc_elem_size *= 2;
    grow_array();
  }
  array[n_elements++] = std::move(element);
}

template<typename T>
Container<T>::Container(std::size_t initial_capacity)
  : array((initial_capacity) ? new T[initial_capacity] : nullptr)
  , alloc_elem_size(initial_capacity)
{
  std::cout << "Container constructed." << '\n';
}

template<typename T>
Container<T>::~Container()
{
  delete[] array;
  array = nullptr;
  std::cout << "Container destroyed." << '\n';
}

template<typename T>
void
Container<T>::clear()
{
  n_elements = 0;
}

template<typename T>
Container<T>::Container(const Container<T>& source)
  : n_elements(source.n_elements)
  , alloc_elem_size(source.alloc_elem_size)
{
  if (alloc_elem_size == 0) {
    array = nullptr;
  } else {
    array = new T[alloc_elem_size];
  }

  for (std::size_t i = 0; i < source.n_elements; i++) {
    array[i] = source.at(i);
  }
  std::cout << "Container copied." << '\n';
}

template<typename T>
Container<T>::Container(Container<T>&& source)
  : array(source.array)
  , n_elements(std::move(source.n_elements))
  , alloc_elem_size(std::move(source.alloc_elem_size))
{
  source.array = nullptr;
  source.n_elements = 0;
  source.alloc_elem_size = 0;
  std::cout << "Container moved." << '\n';
}

template<typename T>
void
Container<T>::print() const
{
  if (n_elements == 0)
    std::cout << "empty.";

  for (std::size_t i = 0; i < n_elements; i++)
    std::cout << i << "|" << this->at(i) << '\t';
  std::cout << '\n';
}

template<typename T>
void
Container<T>::print(std::string prefix_str) const
{
  std::cout << prefix_str;
  this->print();
}
