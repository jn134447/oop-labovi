#include <iostream>

//1. Napisati funkciju koja vraca niz int vrijednosti velicine n u kojem je svaki
//element zbroj svoja dva prethodnika(Fibonacci).Prvi i drugi element u nizu
//su jedinice.U main funkciji ispisati dobiveni niz i osloboditi memoriju.

using namespace std;

int* fibonacci_array(int n) {
	int* arr;

	arr = new int[n] {1, 1}; // beucase the task says first and second element should be 1's (not [0, 1, ...])
	
	for (int i = 2; i < n; i++)
		arr[i] = arr[i - 2] + arr[i - 1];

	return arr;
}

int main() {
	int* sequence_a = fibonacci_array(10);
	int* sequence_b = fibonacci_array(15);

	cout << "n = 10; ";
	for (int i = 0; i < 10; i++)
		cout << sequence_a[i] << " ";
	cout << endl;

	cout << "n = 15; ";
	for (int i = 0; i < 15; i++)
		cout << sequence_b[i] << " ";
	cout << endl;

	delete[] sequence_a;
	sequence_a = nullptr;
	delete[] sequence_b;
	sequence_b = nullptr;
}