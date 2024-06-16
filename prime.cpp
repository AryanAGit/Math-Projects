//Finds prime #s from 0 to given integer

// Once you loop through the prime list for the integer, if it %!=0 for all primes, then its a prime

#include <iostream>
using namespace std;
int findPrimes(int lim, int* listPrimes) {
	
	int primes = 2;
	if (lim < 5 && lim>0) 
	{
		if (lim >= 3) 
		{
			cout << "There are two primes between 0 and " << lim << endl;
			cout << "2 is a prime." << endl;
			cout << "3 is a prime." << endl;
		}
		else if (lim >= 2) 
		{
			cout << "There is one prime between 0 and " << lim << endl;
			cout << "2 is a prime." << endl;
		}
		else 
		{
			cout << "There are no primes between 0 and " << lim << endl;
		}
	}
	else if (lim >= 5) 
	{
		for (int i = 5; i <= lim; i = i + 2) 
		{
			int primeCount = 0;

			for (int j = 0; j < primes; j++) 
			{
				if (i % listPrimes[j] == 0 ) 
				{
					break;
				}
				else 
				{
					primeCount++;
				}
			}

			if (primeCount == primes && primes < 1000) 
			{
				listPrimes[primes] = i;
				primes++;
			}
		}
		for (int i = 0; i < primes; i++) 
		{
			cout << listPrimes[i] << " is a prime." << endl;
		}
		cout << "There are " << primes << " prime numbers between 0 and " << lim << " inclusive. " << endl;
		
	}

	else 
	{
		cout << "Invalid input entered. Please enter an integer value greater than 0." << endl;
	}
	return primes;
}

int main()
{
	cout << "Welcome. This program finds all prime numbers between 0 and a given integer inclusive. Enter an integer or enter 0 to quit. Currently goes up to 7919";
	int limit;
	int listPrimes[1000] = { 2, 3 };
	int numOfPrimes = 2;
	cin >> limit;
	cin.ignore(1000, 10);
	while (limit != 0) {
		
		numOfPrimes =findPrimes(limit, listPrimes);
		cout << "Press 0 to quit, or enter another integer. " << endl;
		cin >> limit;
		cin.ignore(1000, 10);
	}

}

