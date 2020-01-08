#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int arr[80];
	arr[0] = 1;
	arr[1] = 2;
	for(int i = 2; i < 80; ++i)
		arr[i] = arr[i - 1] + arr[i - 2]; 
	int n;
	while(cin >> n){
		if(n == 0) break;
		else cout << arr[n - 1] << endl;;
	}
	return 0;
}