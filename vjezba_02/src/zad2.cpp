#include <iostream>
#include "../include/vector.h"

using namespace std;

int main() {
	Vector vec;
	vec.vector_new;
	for (int i = 0; i < 5; i++)
	{
		vec.vector_push_back(i);
	}

	for (int i = 0; i < vec.alloc_size; i++)
	{
		cout << vec.arr[i] << endl;
	}
}
