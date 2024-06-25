//Finds prime #s from 0 to given integer

// Once you loop through the prime list for the integer, if it %!=0 for all primes, then its a prime

struct node {
	int num;
	node* next;
};

#include <iostream>
using namespace std;

int findPrimes(int limit, node*& head, node*& tail, int numPrimes);

int main()
{
	cout << "Welcome. This program finds all prime numbers between 0 and a given integer inclusive. Enter an integer or enter 0 to quit. ";
	int limit;
	node* head = new node{ 2, nullptr };
	node* tail = new node{ 3, nullptr };
	head->next = tail;
	int numPrimes = 2;
	cin >> limit;
	cin.ignore(1000, 10);
	while (limit != 0) {
		
		numPrimes = findPrimes(limit, head, tail, numPrimes);
		cout << "Press 0 to quit, or enter another integer. " << endl;
		cin >> limit;
		cin.ignore(1000, 10);
	}
	cout << "Thanks, come again!";
}

int findPrimes(int limit, node*& head, node *& tail, int numPrimes) {
	int primes = numPrimes;

	if (limit < 5 && limit>0)
	{
		if (limit >= 3)
		{
			cout << "There are two primes between 0 and " << limit <<" inclusine" << endl;
			cout << "2 is a prime." << endl;
			cout << "3 is a prime." << endl;
		}
		else if (limit >= 2)
		{
			cout << "There is one prime between 0 and " << limit <<" inclusive"<<endl;
			cout << "2 is a prime." << endl;
		}
		else
		{
			cout << "There are no primes between 0 and " << limit << " inclusive"<< endl;
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
		node* it = head;
		for (int i = 0; i < primes; i++) {
			cout << it->num << " is a prime." << endl;
			it = it->next;
		}
		cout << "There are " << primes << " prime numbers between 0 and " << limit << " inclusive." << endl;
	}

	return primes;
}
