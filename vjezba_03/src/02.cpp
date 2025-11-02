#include <cstddef>
#include <iomanip>
#include <iostream>

// copied from ./01.cpp

template <typename T>
void sortt(T arr[], std::size_t arr_len, bool (*cmp)(T, T)) {
  for (std::size_t i = 0; i < arr_len; i++) {
    for (std::size_t j = i + 1; j < arr_len; j++) {
      if (cmp(arr[i], arr[j])) {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

template <typename T> inline bool ascending(T a, T b) {
  return (a <= b) ? false : true;
}

template <typename T> inline bool descending(T a, T b) {
  return (a >= b) ? false : true;
}

int main() {
  int arr[]{5, 6, 8, 1, 10, 2, 9, 9, 4, 4, 4, 1, 0};
  int arr_len = sizeof(arr) / sizeof(arr[0]);
  double arr_double[]{5.2, 6, 8, 1, 10, 2, 9, 9, 4, 4, 4, 1, 0};
  int arr_len_double = sizeof(arr_double) / sizeof(arr_double[0]);

  auto print_arr = [&arr, &arr_len]() {
    for (int i = 0; i < arr_len; i++)
      std::cout << arr[i] << " ";
    std::cout << std::endl;
  };
  auto print_arr_double = [&arr_double, &arr_len_double]() {
    for (int i = 0; i < arr_len_double; i++)
      std::cout << std::fixed << std::setprecision(2) << std::setw(3)
                << std::right << arr_double[i] << " ";
    std::cout << std::endl;
  };

  print_arr();
  print_arr_double();

  std::cout << std::endl;

  std::cout << "ascending:" << std::endl;
  sortt(arr, arr_len, ascending);
  sortt(arr_double, arr_len_double, ascending);
  print_arr();
  print_arr_double();

  std::cout << std::endl;

  std::cout << "descending: " << std::endl;
  sortt(arr, arr_len, descending);
  sortt(arr_double, arr_len_double, descending);
  print_arr();
  print_arr_double();
}
