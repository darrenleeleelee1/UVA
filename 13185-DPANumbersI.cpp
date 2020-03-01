#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, n, sum = 0;
	cin >> t;
	for (int k = 0; k < t; ++k)	{
		cin >> n;
		sum = 0;
		for (int i = 1; i < n; ++i)
			if(n % i == 0) sum += i;
		if(sum > n) cout << "abundant" << endl;
		else if(sum == n) cout << "perfect" << endl;
		else if(sum < n) cout << "deficient" << endl;
	}
	return 0;
}
