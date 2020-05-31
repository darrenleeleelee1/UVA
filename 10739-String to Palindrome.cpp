#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
char str[maxn];
int dp[maxn][maxn];
int main(int argc, char const *argv[])
{
	int T; scanf("%d", &T);
	int cas = 1;
	while(T--)
	{
		scanf("%s", &str);
		memset(dp, 0, sizeof(dp));
		int n = strlen(str);
		for(int i = 0; i <= n; i++){
			dp[i][i] = 0;
		}
		
		for(int i = 1;  i < n; i++){
			for(int j = 0; j < n; j++){
				if(i+j >= n) continue;	
				if(str[0+j] != str[i+j]) {
					dp[0+j][i+j] = min(dp[0+j+1][i+j], min(dp[0+j+1][i+j-1], dp[0+j][i+j-1])) + 1;
				}
				else{
					dp[0+j][i+j] = dp[0+j+1][i+j-1];
				}
			}
		}
		
		printf("Case %d: %d\n", cas++, dp[0][n-1]);
	}
	
	return 0;
}