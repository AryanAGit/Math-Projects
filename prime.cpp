//Finds prime #s from 0 to given integer

// Once you loop through the prime list for the integer, if it %!=0 for all primes, then its a prime

struct node {
	int num;
	node* next;
};

#include <iostream>
#include <vector>

using namespace std;
void primeFactorization(int limit, int& numPrimes, node*& head, node*& tail);
int main()
{
	cout << "Welcome.This program does prime factor decomposition of integers.Enter an integer to factorize or enter 0 to quit: ";
	int limit;
	cin >> limit;
	cin.ignore(1000, 10);
	node* head = new node{ 2, nullptr };
	node* tail = new node{ 3, nullptr };
	head->next = tail;
	int numPrimes = 2;
	while (limit != 0) {
		primeFactorization(limit, numPrimes, head, tail);
		cout << "Press 0 to quit, or enter another integer. " << endl;
		cin >> limit;
		cin.ignore(1000, 10);
	}
	cout << "Thanks, come again!";
}

void primeFactorization(int limit, int& numPrimes, node *& head, node *& tail) {
	int primes = numPrimes;
	bool neg = false;
	if (limit < 0) {
		limit *= -1;
		neg = true;

	}
	
	int num =limit;
	vector<int> factors(2, 0);
	while (true) {
		if (num % 2 == 0) {
			num /= 2;
			factors[0]++;
		}
		else if (num % 3 == 0) {
			num /= 3;
			factors[1]++;
		}
		else break;
	}
	int index = 2;
	factors.push_back(0);
	if (limit < 5 && limit>0)
	{

		switch (limit) {
		case 1: {
			if (neg) limit *= -1;
			cout << "Prime factors of " << limit << ": " << endl;
			cout << "\t" << limit << " to the power of 1"<<endl;
			return;
		}
		case 2: {
			if (neg) limit *= -1;
			cout << "Prime factors of " << limit << ": " << endl;
			cout << "\t" << "2 to the power of 1" << endl;
			if (neg) cout << "\t-1 to the power of 1" << endl;
			return;
		}
		case 3: {
			if (neg) limit *= -1;
			cout << "Prime factors of " << limit << ": " << endl;
			cout << "\t" << "3 to the power of 1" << endl;
			if (neg) cout << "\t-1 to the power of 1" << endl;
			return;
		}
		case 4: {
			if (neg) limit *= -1;
			cout << "Prime factors of " << limit << ": " << endl;
			cout << "\t" << "2 to the power of 2" << endl;
			if (neg) cout << "\t-1 to the power of 1" << endl;
			return;
		}
		case 5: {
			if (neg) limit *= -1;
			cout << "Prime factors of " << limit << ": " << endl;
			cout << "\t" << "5 to the power of 1" << endl;
			if (neg) cout << "\t-1 to the power of 1" << endl;
			return;
		}
		case 0: {
			cout << "Prime factorization for 0 is not defined." << endl;
			return;
		}
		}
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
				while (true) {
					if (num % i == 0) {
						num /= i;
						factors[index]++;
					}
					else {
						index++;
						factors.push_back(0);
						break;
					}
				}
			}

			if (num == 1) {
				if (neg)limit *= -1;
				cout << "Prime factors of " << limit << ": " << endl;
				node* it = head;
				for (int i = 0; i < primes; i++) {
					if (factors[i] != 0) {
						cout<<"\t" << it->num << " to the power of " << factors[i] << endl;
					}
					it = it->next;
				}
				if (neg) cout << "-1 to the power of 1" << endl;
				return;
			}
		}
	
	}

}
