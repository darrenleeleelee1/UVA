#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	long long int now = 0, digit = 0, count = 0, temp, next = -1, i = 1;
	while(getline(cin, str)){
		i = 1;
		count = 1;
		bool start = true;
		if(str == "END") break;
		if(str == "1") {
			cout << i << endl;
			start = false;
		}
		now = str.length();
		while(start){
			count = 1;
			i++;
			temp = now;
			while(temp >= 10){
				temp /= 10;
				count++;
			}
			next = count;
			if(now == next) {
				cout << i << endl;
				break;
			}
			else now = next;
		}
	}
	return 0;
}