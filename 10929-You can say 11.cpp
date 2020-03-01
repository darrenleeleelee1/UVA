#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string num;
	while(cin >> num){
		if(num == "0") break;
		int temp = 0;
		for(int i = 0; i < num.length(); i++){
			if(i % 2 == 0) temp += (num[i] - 48);
			else temp -= (num[i] - 48);
		}
		if(temp % 11 == 0)cout << num << " is a multiple of 11." << endl;
		else cout << num << " is not a multiple of 11." << endl;
	}
	return 0;
}