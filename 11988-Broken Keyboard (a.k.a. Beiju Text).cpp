#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string str, res;
	int index;
	list<char> ls;
	bool start = false, front;
	auto it = ls.begin();
	while(getline(cin, str)){
		ls.clear();
		it = ls.begin();
		for (int i = 0; i < str.length(); ++i){
			switch(str[i]){
				case'[' :
					it = ls.begin();
					break;
				case']' :
					it = ls.end();
					break;
				default :
					ls.insert(it, str[i]);
					break;
			} 
		}
		while(!ls.empty()){
			printf("%c", ls.front());
			ls.pop_front();
		}
		printf("\n");
	}
	return 0;
}