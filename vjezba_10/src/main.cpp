#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cmath>

int main()
{
    std::vector<int> numbers{2, 4, 6, 7, 8, 9, 10, 11, 3, 16};

    auto is_odd = [](int n)
    { return (n % 2 != 0) ? true : false; };

    // 1.A find first odd number
    auto found_odd = std::find_if(numbers.begin(), numbers.end(),
                                  [is_odd](int &e)
                                  { return is_odd(e); });
    std::cout << "first odd number: " << *found_odd << '\n';

    // 1.B count the odd numbers
    int odd_count = std::accumulate(numbers.begin(), numbers.end(), 0,
                                    [is_odd](int acc, auto &elem)
                                    {
                                        if (is_odd(elem))
                                            acc += 1;
                                        return acc;
                                    });
    std::cout << "odd count: " << odd_count << '\n';

    // 1.C avg over odd numbers
    double odd_avg = std::accumulate(numbers.begin(), numbers.end(), 0.0,
                                     [is_odd](double acc, auto &elem)
                                     {
                                         if (is_odd(elem))
                                             acc += elem;
                                         return acc;
                                     })

                     / static_cast<double>(odd_count);

    std::cout << "odd average: " << odd_avg << '\n';

    // 1.D change all numbers that are to power of 2 into 2
    std::for_each(numbers.begin(), numbers.end(),
                  [](auto &elem)
                  {
                      // math algo shenanigans
                      if ((elem != 0) && ((elem & (elem - 1)) == 0))
                          elem = 2;
                  });

    for (auto &i : numbers)
        std::cout << i << ", ";
    std::cout << '\n';

    // 1.E print even numbers (ascending), then odd numbers (ascending)
    std::sort(numbers.begin(), numbers.end());
    std::stable_partition(numbers.begin(), numbers.end(),
                          [](auto elem)
                          { return (elem % 2 == 0) ? true : false; });

    for (auto &i : numbers)
        std::cout << i << ", ";
    std::cout << '\n';
}