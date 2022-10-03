// C++ program to find LCM of First N Natural Numbers.
#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

vector<bool> isPrime (MAX, true);
// utility function for sieve of sieve of Eratosthenes

void sieve()
{
	
	for (int i = 2; i * i <= MAX; i++)
	{
		if (isPrime[i] == true)
			for (int j = i*i; j<= MAX; j+=i)
				isPrime[j] = false;
	}
}

// Function to find LCM of first n Natural Numbers
long long LCM(int n)
{
	long long lcm = 1;
	int i=2;
	while(i<=n) {
		if(isPrime[i]){
			int pp = i;
			while (pp * i <= n)
				pp = pp * i;
			lcm *= pp;
		}
		i++;
	}
	return lcm;
}

// Driver code
int main()
{
	// build sieve
	sieve();
	int N = 7;
	// Function call
	cout << LCM(N);
	return 0;
}
