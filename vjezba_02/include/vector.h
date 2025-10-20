#ifndef VECTOR
#define VECTOR

struct Vector {
  int *arr;
  int len;
  int alloc_size;
};

void vector_new(Vector &vec, int default_alloc_size = 8);
void vector_delete(Vector &vec);
void vector_push_back(Vector &vec, int element);
void vector_pop_back(Vector &vec);
int vector_front(Vector &vec);
int vector_back(Vector &vec);
int vector_size(Vector &vec);
void vector_print(Vector &vec, bool flag = false);

#endif
