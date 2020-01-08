#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	int arr1[10] = {1 ,66, 56, 96, 36, 76, 16, 56, 96, 36};
	int arr2[11] = {76, 16, 56, 96, 36, 76, 16, 56, 96, 36, 76};
	int len;
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; ++i){
		while(getline(cin, str)){
			len = str.length();
			if(len == 1) cout << arr1[(int(str[len - 1]) - 48)] << endl;
			else cout << arr2[(int(str[len - 1]) - 48)] << endl;
		}
	}
	return 0;
}