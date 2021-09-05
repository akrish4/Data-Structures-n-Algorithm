// C++ code to find the Binomial Coefficient
// Description: Given two parameters n and r, find the value of the Binomial Coefficient i.e. C(n, r)
// Method: Change r to n-r if r is greater than n-r and store it in a variable. Run a loop from 0 to r-1 and in every iteration update result to be (ans*(n-i))/(i+1). Hence, the result will be ((n/1)*((n-1)/2)*…*((n-r+1)/r!) i.e. nCr.
// Time Complexity: O(r)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int findBinCoeff(int n, int r)
{
	int result = 1;

	if (r > n - r)
	{
		r = n - r; // C(n, r) = C(n, n-r)
	}

	// Find [n*(n-1)*...*(n-r+1)]/[r*(r-1)*...*1]
	for (int i = 0; i < r; ++i)
	{
		result = result * (n - i);
		result = result / (i + 1);
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	int r;
	cin >> r;
	cout << findBinCoeff(n, r) << endl;
	return 0;
}