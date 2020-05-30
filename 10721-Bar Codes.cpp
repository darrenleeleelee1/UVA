#include <bits/stdc++.h>
using namespace std;
const int maxn = 50+5;
long long dp[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n, k, m;
	while(~scanf("%d%d%d", &n, &k, &m))
	{
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= n; i++) dp[0][i] = 0;
		for(int i = 0; i <= k; i++) dp[i][0] = 0;
		dp[0][0] = 1;
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				for(int t = 0; t < m; t++){
					if(j-1-t >= 0) dp[i][j] += dp[i-1][j-1-t];
				}
			}
		}
		
		printf("%lld\n", dp[k][n]);

	}
	return 0;
}