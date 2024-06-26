//prime decomposition
//Decomposes an integer into its prime factors
// Once you loop through the prime list for the integer, if it %!=0 for all primes, then its a prime

struct node {
	int num;
	node* next;
};

#include <iostream>
#include <cstring>
using namespace std;

int findPrimes(int limit, node*& head, node*& tail, int numPrimes);
void primeDecomp(int num);
int main()
{
	cout << "Welcome. This program does prime factor decomposition of integers. Enter an integer to factorize:  ";
	int limit;
	cin >> limit;
	cin.ignore(1000, 10);
	while (limit != 0) {
		primeDecomp(limit);
		cout << "Press 0 to quit, or enter another integer. " << endl;
		cin >> limit;
		cin.ignore(1000, 10);
	}
	cout << "Thanks, come again!";
}

int findPrimes(int limit, node*& head, node*& tail, int numPrimes) {
	int primes = numPrimes;

	if (limit < 5 && limit>0)
	{
		if (limit >= 3)
		{
			cout << "There are two primes between 0 and " << limit << " inclusine" << endl;
			cout << "2 is a prime." << endl;
			cout << "3 is a prime." << endl;
		}
		else if (limit >= 2)
		{
			cout << "There is one prime between 0 and " << limit << " inclusive" << endl;
			cout << "2 is a prime." << endl;
		}
		else
		{
			cout << "There are no primes between 0 and " << limit << " inclusive" << endl;
		}
	}

	else if (limit <= 0) {
		cout << "Invalid input entered. Please enter an integer value greater than 0." << endl;

	}

	else {
		for (int i = 5; i <= limit; i += 2) {
			int count = 0;
			node* it = head;
			for (int j = 0; j < primes; j++) {
				if (i % it->num == 0) break;

				else {
					count++;
					it = it->next;
				}
			}
			if (count == primes) {
				node* newPrime = new node{ i, nullptr };
				tail->next = newPrime;
				tail = newPrime;
				primes++;
			}
		}
	}

	return primes;
}

void primeDecomp( int num) {
	int number = num;
	bool neg = false;
	if (num == 1) {
		cout << "Prime factors of 1: \n1." << endl;
		return;
	}
	else if (num < 0) {
		neg = true;
	}
	else if (num == 0) {
		cout << " Prime factorization isn't defined for 0." << endl;
		return;
	}
	node* head = new node{ 2, nullptr };
	node* tail = new node{ 3, nullptr };
	head->next = tail;
	int numPrimes = 2;
	numPrimes = findPrimes(num, head, tail, numPrimes);
	int* factors = new int[numPrimes];
	memset(factors, 0, numPrimes * sizeof(int));
	bool loop = true;
	while (loop) {
		node* it = head;
		for (int i = 0; i < numPrimes; i++) {
			if (num % it->num == 0) {
				num /= it->num;
				factors[i]++;
			}
			it = it->next;
		}
		if (num == 1) loop = false;
		
	}
	node* it = head;
	cout << "Prime factors of " << number <<": "<<endl;
	for (int i = 0; i < numPrimes; i++) {
		if (factors[i] != 0) {
			cout << it->num << " to the power of " << factors[i] << endl;;
		}
		it = it->next;
	}
	if (neg) cout << "-1 to the power of 1" << endl;
}
