#include <iostream>
using namespace std;

int main()
{
	int t;
	long long int s;
	long long int result = 0;
	cin >> t;
	for(int k = 0; k < t; k++){
		cin >> s;
		result = (s + 1) * (s + 1) - 1; 
		cout << result << endl; 
	}	
	return 0;
}