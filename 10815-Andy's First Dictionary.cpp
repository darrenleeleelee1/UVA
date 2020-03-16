#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string str, temp;
	set<string> s;
	bool start;
	while(getline(cin, str)){
		for(int i = 0; i < str.length(); i++){
			if(int(str[i]) >= 'A' && int(str[i]) <= 'Z') str[i] = int(str[i]) + 'z' - 'Z';
		}
		start = false;
		temp = "";
		for(int i = 0; i < str.length(); i++){
			if(isalpha(str[i]) && !start){ 
				temp = "";
				temp += str[i];
				start = true;
				continue;
			}
			else if(isalpha(str[i]) && start){ 
				temp += str[i];
			}
			else{
				if(temp != "") s.insert(temp);
				start = false;
			}
			
		}
		if(temp != "") s.insert(temp);
	}
	for(auto i : s){
			cout << i << endl;
	}
	return 0;
}