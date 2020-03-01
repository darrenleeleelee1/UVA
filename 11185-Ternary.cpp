#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	int arr[100001];
	while(cin >> n){
		if(n < 0) break;
		int counter = 0;
		while(n / 3 != 0){
			arr[counter++] = n % 3;
			n /= 3;
		}
		cout << n;
		for(int i = counter - 1; i >= 0; i--){
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}