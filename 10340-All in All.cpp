#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s, t;
	while(cin >> s >> t){
		int index = 0;
		bool loop;
		for(int i = 0; i < s.length(); i++){
			loop = true;
			for(int j = index; j < t.length(); j++){
				if(s[i] == t[j]){
					index = j + 1;
					loop = false;
					break;
				}
			}
			if(loop == true) break;
		}
		if(loop) printf("No\n");
		else printf("Yes\n");
	}	
	return 0;
}