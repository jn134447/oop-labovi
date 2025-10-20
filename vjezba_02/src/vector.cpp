#include "../include/vector.h"

void Vector::vector_new() {
	Vector::alloc_size = 10;
	Vector::arr = new int[Vector::alloc_size];
	Vector::size = 0;
}

void Vector::vector_delete() {
	delete[] Vector::arr;
}

void Vector::vector_push_back(int elem) {
	Vector::arr[Vector::size] = elem;
	Vector::size += 1;
}
