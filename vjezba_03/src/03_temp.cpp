#include <functional>
#include <iostream>

// funkcija koja parne elemente prepolovi, a neparne udvostruči
void process_elements(int arr[], int arr_len, std::function<bool(int)> even,
                      std::function<int(int)> times_2,
                      std::function<int(int)> half) {
  for (int i = 0; i < arr_len; i++)
    arr[i] = (even(arr[i])) ? half(arr[i]) : times_2(arr[i]);
}

// funkcija koja računa sumu i produkt članova niza
void calc_array_product_sum(int arr[], int arr_len, int &product, int &sum,
                            std::function<void(int)> add_to_sum,
                            std::function<void(int)> add_to_product) {
  for (int i = 0; i < arr_len; i++) {
    add_to_sum(arr[i]);
    add_to_product(arr[i]);
  }
}

// funkcija koja računa sumu brojeva većih od nekog praga
int calc_array_sum_with_threshold(
    int arr[], int arr_len, int threshold,
    std::function<void(int)> add_to_sum_threshold) {
  int sum = 0;
  for (int i = 0; i < arr_len; i++) {
    add_to_sum_threshold(arr[i]);
  }
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
  int threshold = 5;
  int threshold_sum = 0;

  // Lambde su sada definisane u main()
  auto even = [](int n) { return n % 2 == 0; };
  auto times_2 = [](int n) { return n * 2; };
  auto half = [](int n) { return n / 2; };

  // lambde sada *ažuriraju* vrijednosti direktno
  auto add_to_sum = [&sum](int n) { sum += n; };
  auto add_to_product = [&product](int n) { product *= n; };
  auto add_to_sum_threshold = [threshold, &threshold_sum](int n) {
    if (n > threshold)
      threshold_sum += n;
  };

  print_arr();
  process_elements(arr, arr_len, even, times_2, half);
  print_arr();

  calc_array_product_sum(arr, arr_len, product, sum, add_to_sum,
                         add_to_product);
  calc_array_sum_with_threshold(arr, arr_len, threshold, add_to_sum_threshold);

  std::cout << "\nproduct: " << product << std::endl;
  std::cout << "sum: " << sum << std::endl;
  std::cout << "threshold_sum: " << threshold_sum << std::endl;

  std::cout << std::endl;
}
