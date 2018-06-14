#include <iostream>
#include <math.h>

#define MAX 2000000
using namespace std;


/*
Prime number Sieve based on the Sieve of Eratosthenes.

Generates all prime numbers up to specified limit argument.

Returns the sum of those numbers.


*/
long long int Esieve_sum(int limit) {
	int *arr = new int[limit];
	for (int i = 2; i < limit; i++)
	{
		arr[i] = 1;
	}

	for (int k = 2; k < sqrt(limit); k++) {
		if ( arr[k] == 1) {
			for (int j = k*k; j < limit; j = j + k) {
				arr[j] = 0;

			}
		}
	}
	long long int summation = 0;

	for (int i = 1; i < limit; i++) {
		if (arr[i] == 1) {
			summation += i;
		}
	}


	delete arr;
	return summation;






}




int main(void) {

	cout << "Result at 2M: " << Esieve_sum(MAX) << endl;

	system("PAUSE");

	return 0;

}
