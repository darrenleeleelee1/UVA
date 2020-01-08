#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string num1, num2;
	while(cin >> num1 >> num2){
		if(num1 == "0" && num2 == "0") break;
		if(num1.length() > num2.length()){
			string temp = num1;
			num1 = num2;
			num2 = temp;
		}
		int i, j = num1.length() - 1, counter =  0, lend = 0;
		for(i = num2.length() - 1; i >= 0; i--, j--){
			int temp = 0;
			if(j >= 0) temp = num1[j] - 48;
			lend = ((num2[i] - 48) + temp + lend) / 10;
			if(lend > 0) counter++; 
		}

		if(counter == 0) cout << "No carry operation." << endl;
		else if(counter == 1) cout << "1 carry operation." << endl;
		else cout << counter << " carry operations." << endl;
	}
	return 0;
}