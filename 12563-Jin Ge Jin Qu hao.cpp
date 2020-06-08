#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int dp[maxn];
int cnt[maxn];
int song[maxn];
int main(int argc, char const *argv[])
{
	int Tes; scanf("%d", &Tes);
	int n, t, cas = 1;
	while(Tes--)
	{
		scanf("%d%d", &n, &t);
		for(int i = 0; i < n; i++){
			scanf("%d", &song[i]);
		}
		memset(dp, 0, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		t = t - 1;
		for(int i = 0; i < n; i++){
			for(int j = t; j >= song[i]; j--){
				if(cnt[j] < cnt[j - song[i]] + 1){
					cnt[j] = cnt[j - song[i]] + 1;
					dp[j] = dp[j - song[i]] + song[i];
				}
				else if(cnt[j] == cnt[j - song[i]] + 1){
					dp[j] = max(dp[j - song[i]] + song[i], dp[j]);
				}
			}
		}
		printf("Case %d: %d %d\n", cas++, cnt[t] + 1, dp[t] + 678);

	}
	return 0;
}