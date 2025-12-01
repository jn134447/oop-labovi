#ifndef CONTAINER
#define CONTAINER

#include <cstddef>
#include <string>

template<typename T>
class Container
{
  T* array = nullptr;
  std::size_t n_elements = 0;
  std::size_t alloc_elem_size = 0;

public:
  T& at(size_t index) const;
  void push_back(T element);
  std::size_t size() const;
  std::size_t capacity() const;
  void clear();
  void print() const;
  void print(std::string prefix_str) const;

  Container() = default;
  explicit Container(std::size_t initial_capacity);
  ~Container();
  Container(const Container<T>& source);
  Container(Container<T>&& source);

  Container& operator=(const Container<T>& source) = delete;
  Container& operator=(Container<T>&& source) = delete;
};

#include "container.cpp"

#endif
