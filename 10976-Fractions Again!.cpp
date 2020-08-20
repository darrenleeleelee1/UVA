#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	stack<pair<int, int>> st;
	while(cin >> n){
		int A = n+n;
		st.push(make_pair(A, A));
		for(int i = A - 1; i > n; i--){
			int top = n * i, bot = (i - n);
			if(top % bot == 0){
				st.push(make_pair(top/bot, i));
			}
		}
		printf("%d\n", st.size());
		
		while(!st.empty()){
			auto top = st.top(); st.pop();
			printf("1/%d = 1/%d + 1/%d\n", n, top.first, top.second);
		}
		
	}
	return 0;
}