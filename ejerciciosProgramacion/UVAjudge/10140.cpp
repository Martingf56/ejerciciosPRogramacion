#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

unsigned int MAX_PRIME = 2147483646;

bitset<MAX_PRIME + 1> bs; // #include <bitset>
vector<unsigned int> primes; // unsigned int
void sieve() {
	bs.set(); // De momento, todos son primos
	bs[0] = bs[1] = 0; // El 0 y el 1 no lo son.
	for (unsigned int i = 2; i <= MAX_PRIME; ++i) {
		if (bs[i]) {
			// El actual es primo. Tiramos sus m´ultiplos
			for (unsigned int j = i * i; j <= MAX_PRIME; j += i)
				bs[j] = 0;
			primes.push_back(i);
		} // if es primo
	} // for
} // sieve


bool isPrime(unsigned long long n) {
	if (n <= MAX_PRIME)
		return bs[n];
	for (unsigned int i = 0; i < primes.size(); ++i)
		if (!(n % primes[i]))
			return false;
	return true;
}


int main() {
	int a1 , b1 , a2 , b2;
	a1 = 0; b1 = 1000000;
	a2 = b2 = 0;
	int ant;

	int ini,fin;
	sieve();
	cin >> ini;
	while (cin) {
		cin >> fin;
		
		for (int n = ini; n <= fin; n++) {
			ant = -1;
			if (isPrime(n)) {
				if (ant != -1) {
					int nRango = n - ant;
					if (nRango < b1 - a1)
						a1 = ant; b1 = n;
					if (b2 - a2 < nRango)
						a2 = ant; b2 = n;
					ant = n;
				}
				else {
					ant = n;
				}
			}
		}

		if (a1 == 0) {
			cout << a1 << ", "<< b1 <<" are closest, "<< a2 <<", "<< b2 <<" are most distant.\n";
		}
		else {
			cout << "There are no adjacent primes.\n";
		}
		cin >> ini;
	}
	return 0;
}