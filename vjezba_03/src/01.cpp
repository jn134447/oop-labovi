#include <cstddef>
#include <iostream>

void sortt(int arr[], std::size_t arr_len, bool (*cmp)(int, int)) {
  for (std::size_t i = 0; i < arr_len; i++) {
    for (std::size_t j = i + 1; j < arr_len; j++) {
      if (cmp(arr[i], arr[j])) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

inline bool ascending(int a, int b) { return (a <= b) ? false : true; }
inline bool descending(int a, int b) { return (a >= b) ? false : true; }

int main() {
  int arr[]{5, 6, 8, 1, 10, 2, 9, 9, 4, 4, 4, 1, 0};
  int arr_len = sizeof(arr) / sizeof(arr[0]);

  auto print_arr = [&arr, &arr_len]() {
    for (int i = 0; i < arr_len; i++)
      std::cout << arr[i] << " ";
    std::cout << std::endl;
  };

  print_arr();

  std::cout << "ascending: ";
  sortt(arr, arr_len, ascending);
  print_arr();

  std::cout << "descending: ";
  sortt(arr, arr_len, descending);
  print_arr();
}
