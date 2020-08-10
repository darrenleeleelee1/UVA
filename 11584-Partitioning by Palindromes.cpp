#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
char str[maxn];
const char null[] = {'\0'};
const int INF = 1e9;
int dp[maxn];
bool solve(int L, int R){
	if(L == R) return true;
	while(L < R){
		if(str[L] == str[R]) L++, R--;
		else return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int T; cin >> T;
	while(T--){
		strcpy(str, null);
		scanf("%s", str);
		int length = strlen(str) + 1;
		for(int i = length; i > 0;i--){
			str[i] = str[i-1];
		}
		fill(dp, dp + length + 1, INF);
		dp[0] = 0;
	
		for(int i = 1; i < length; i++){
			for(int j = 1; j <= i; j++){
				if(solve(j, i)){
					dp[i] = min(dp[i], dp[j-1] + 1);
				}
			}
		}
		printf("%d\n", dp[length-1]);

	}
	return 0;
}