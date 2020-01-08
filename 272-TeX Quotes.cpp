#include<iostream>
using namespace std;

int  main(int argc, char const *argv[])
{
	string str;
	bool first = true;
	while(getline(cin, str)){
		for(int i = 0; i < str.length(); i++)
			if(str[i] ==  '\"'  && first){
				cout << "``";
				first = false;
			}
			else if(str[i] ==  '\"'  && !first){
				cout << "''";
				first = true;
			}
			else cout << str[i]; 
		cout << endl;
	}
	return 0;
}