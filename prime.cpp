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
	cout << "Welcome. This program finds all prime numbers between 0 and a given integer inclusive. Enter an integer or enter 0 to quit. ";
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
