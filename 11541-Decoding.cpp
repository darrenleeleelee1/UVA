#include<iostream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count, digit = 1, times = 0;
	bool OutOfDigit = false;
	char temp;
	cin >> count;
	cin.ignore();
	string str;
	for (int test = 0; test < count; ++test)
	{
		getline(cin, str);
		cout << "Case " << test + 1 << ": ";
		for (int i = 0; i < str.length(); ++i){
			for (int j = 0; j < 26; ++j){
				if(str[i] == char(65 + j)) {
					temp = char(65 + j);
					digit = 1;
					times = 0;
				}			
			}
			for (int j = 0; j <= 9; ++j){
				if(str[i] == char(48 + j)){
					times = j + (times * digit);
					digit *= 10;
				} 
			}
			if(i+1 == str.length()){
				for (int k = 0; k < times; ++k)
					cout << temp;
			}
			else if(int(str[i+1]) >= 65 && int(str[i+1]) <= 90){
				for (int k = 0; k < times; ++k){
					cout << temp;
				}
			}	
		}
		cout << endl;
	}
	return 0;
}