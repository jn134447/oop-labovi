#include <iostream>

// funkcija koja parne elemente prepolovi, a neparne udvostruči,
void process_elements(int arr[], int arr_len) {
  auto even = [](int n) { return (n % 2 == 0) ? true : false; };
  auto times_2 = [](int n) { return n * 2; };
  auto half = [](int n) { return (n / 2); };

  for (int i = 0; i < arr_len; i++)
    arr[i] = (even(arr[i])) ? half(arr[i]) : times_2(arr[i]);

  return;
}

// funkcija koja računa sumu i produkt članova niza,
void calc_array_product_sum(int arr[], int arr_len, int &product, int &sum) {
  auto add_to_sum = [&sum](int n) { return sum + n; };
  auto add_to_product = [&product](int n) { return product * n; };

  for (int i = 0; i < arr_len; i++) {
    sum = add_to_sum(arr[i]);
    product = add_to_product(arr[i]);
  }

  return;
}

// funkcija koja računa sumu brojeva većih od nekog praga.
int calc_array_sum_with_threshold(int arr[], int arr_len, int threshold) {
  int sum = 0;

  auto add_to_sum_threshold = [threshold, &sum](int n) {
    if (n > threshold)
      return sum + n;
    return sum;
  };

  for (int i = 0; i < arr_len; i++)
    sum = add_to_sum_threshold(arr[i]);

  return sum;
}

int main() {
  int arr[]{5, 6, 8, 1, 10, 2, 9, 9, 4, 4, 4, 1};
  int arr_len = sizeof(arr) / sizeof(arr[0]);

  auto print_arr = [&arr]() {
    for (int e : arr)
      std::cout << e << " ";
    std::cout << std::endl;
  };

  int sum = 0, product = 1;

  print_arr();
  process_elements(arr, arr_len);
  print_arr();

  calc_array_product_sum(arr, arr_len, product, sum);
  int threshold_sum = calc_array_sum_with_threshold(arr, arr_len, 5);

  std::cout << std::endl;

  std::cout << "product: " << product << std::endl;
  std::cout << "sum: " << sum << std::endl;
  std::cout << "threshold_sum: " << threshold_sum << std::endl;

  std::cout << std::endl;
}
