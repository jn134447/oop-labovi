#include "../include/vector.h"
#include <iostream>

using namespace std;

int main() {
  Vector vec;
  vector_new(vec, 2);

  for (int i = 0; i <= 15; i++)
    vector_push_back(vec, i);

  vector_print(vec);
  vector_print(vec, true);

  cout << "vector_front: " << vector_front(vec) << endl;
  cout << "vector_back: " << vector_back(vec) << endl;
  cout << "vector_size: " << vector_size(vec) << endl;

  for (int i = 0; i < 5; i++)
    vector_pop_back(vec);

  vector_print(vec);

  cout << "cleaned array with pop_back, falsly on purpose" << endl;
  int temp = vector_size(vec) + 1;
  for (int i = 0; i < temp; i++)
    vector_pop_back(vec);

  vector_print(vec);
  vector_print(vec, true);

  vector_delete(vec);
}
