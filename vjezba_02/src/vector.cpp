#include "../include/vector.h"
#include <iostream>

using namespace std;

void vector_new(Vector &vec, int default_alloc_size) {
  vec.len = 0;
  vec.alloc_size = default_alloc_size;
  vec.arr = new int[vec.alloc_size]();
}
void vector_delete(Vector &vec) {
  delete[] vec.arr;
  vec.arr = nullptr;
}
void vector_push_back(Vector &vec, int element) {
  vec.arr[vec.len] = element;
  vec.len += 1;

  if (vec.len >= vec.alloc_size) {
    // create new bigger block
    vec.alloc_size *= 2;
    int *temp = new int[vec.alloc_size]();

    // copy elements
    for (int i = 0; i < vec.len; i++)
      temp[i] = vec.arr[i];

    // delete old block
    vector_delete(vec);

    // change pointer to new block
    vec.arr = temp;
  }
}
void vector_pop_back(Vector &vec) {
  if (vec.len == 0) {
    cout << "warn: trying to pop_back a vector with no elements" << endl;
    return;
  }
  vec.len -= 1;
  vec.arr[vec.len] = 0;
}
int vector_front(Vector &vec) { return vec.arr[0]; }
int vector_back(Vector &vec) { return vec.arr[(vec.len - 1)]; }
int vector_size(Vector &vec) { return vec.len; }

void vector_print(Vector &vec, bool flag){
  if (!flag) {
    cout << "vector_print[vec.len]: [ ";
    for (int i = 0; i < vec.len; i++)
      cout << vec.arr[i] << " ";
    cout << "]" << endl;
  } else {
    cout << "vector_print[vec.alloc_size]: [ ";
    for (int i = 0; i < vec.alloc_size; i++)
      cout << vec.arr[i] << " ";
    cout << "]" << endl;
  }
}
