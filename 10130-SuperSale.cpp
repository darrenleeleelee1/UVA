#include <bits/stdc++.h>
using namespace std;
int dp[1000+5][30+5];
int main(int argc, char const *argv[])
{
	int T; cin >> T;
	int n, m, x, y;
	vector<pair<int, int>> v;
	while(T--){
		v.clear(); v.push_back(make_pair(0, 0));
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			v.push_back(make_pair(y, x));
		}
		sort(v.begin(), v.end());
		cin >> m;
		int ans = 0;
		for(int i = 0; i < m; i++){
			cin >> x;
			memset(dp, 0, sizeof dp);
			for(int i = 1; i <= n; i++){
				for(int j = 0; j <= x; j++){
					dp[i][j] = j - v[i].first >= 0 ? max(dp[i-1][j-v[i].first] + v[i].second, dp[i-1][j]) : dp[i-1][j];
				}
			}
			ans += dp[n][x];
		}
		printf("%d\n", ans);
	}
	return 0;
}