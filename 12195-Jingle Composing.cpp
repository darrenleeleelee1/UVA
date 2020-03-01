#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	char note[7] = {'W', 'H', 'Q', 'E', 'S', 'T', 'X'};
	double beat[7] = {1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625};
	string str;
	while(cin >> str){
		if(str == "*") break;
		float sum = 0;
		int counter = 0;
		for (int i = 0; i < str.length(); ++i){
			for (int j = 0; j < 7; ++j){
				if(str[i] == note[j]) sum += beat[j];
			}
			if(str[i] == '/') {
				if(sum == 1) counter++;
				sum = 0;
			}
		}
		cout << counter << endl;
	}
}