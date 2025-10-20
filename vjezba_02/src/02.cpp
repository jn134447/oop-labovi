#include "../include/vector.h"
#include <iostream>

using namespace std;

void vector_new(Vector &vec, int default_alloc_size = 4) {
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
    vec.alloc_size *= 2;
    int *temp = new int[vec.alloc_size]();
    vector_delete(vec);
    vec.arr = temp;
  }
}

void vector_pop_back(Vector &vec) {
  vec.len -= 1;
  vec.arr[vec.len] = 0;
}

int vector_font(Vector &vec) { return vec.arr[0]; }
int vector_back(Vector &vec) { return vec.arr[(vec.len - 1)]; }
int vector_size(Vector &vec) { return vec.len; }

int main() {
  Vector vec;
  vector_new(vec);
  vector_delete(vec);
}
