#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	stringstream s1;
	string str;
	while(getline(cin, str)){
		if(str == "0") break;
		while(str.length() != 1){
			s1.str("");
    		s1.clear();
			int sum = 0;
			for (int i = 0; i < str.length(); ++i){
				sum += int(str[i]) - 48;
			}
			s1 << sum;
			s1 >> str;
		}
		cout << str << endl;
	}
	return 0;
}