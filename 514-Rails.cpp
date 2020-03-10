#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	stack<int> s, stemp;
	int n, temp;
	while(cin >> n && n){
		while(cin >> temp && temp){
			while(!s.empty()){
				s.pop();
			}
			while(!stemp.empty()){
				stemp.pop();
			}
			s.push(temp);
			for(int i = 0; i < n - 1; i++){
				cin >> temp;
				s.push(temp);
			}
			bool res = true;
			for(int i = n; i > 0; i--){
				if(!stemp.empty() && stemp.top() == i){
					stemp.pop();
					continue;
				}
				while(!s.empty() && s.top() != i){
					stemp.push(s.top());
					s.pop();
				}
				if(!s.empty() && s.top() == i) {
					s.pop();
					continue;
				}
				else{
					res = false;
					break;
				}
			}
			if(res) printf("%s\n", "Yes");
			else printf("%s\n", "No");
			/*
			for (int i = 0; i < n; ++i)
			{
				printf("%d ", s.top());
				s.pop();
			}
			printf("\n");
			*/
		}
		printf("\n");
	}
	return 0;
}