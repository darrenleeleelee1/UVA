#include <bits/stdc++.h>
using namespace std;
string ori;
const int maxn = 1000+5;
int dp[maxn][maxn];
string bt[maxn][maxn];
int main(int argc, char const *argv[])
{
	while(cin >> ori){
		int n = ori.length();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) {
					dp[i][j] = 1;
					bt[i][j] = ori[i];
				}
				else {
					dp[i][j] = 0;
					bt[i][j] = "";
				}
			}
		}
		int i, j, k = 0;
		for(k = 0; k < n - 1; k++){
			i = 0, j = 1 + k;
			while(i < n && j < n){
				if(ori[i] == ori[j]) {
					dp[i][j] = dp[i+1][j-1] + 2;
					bt[i][j] = ori[i] + bt[i+1][j-1] + ori[i];
				}
				else {
					dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
					if(dp[i+1][j] == dp[i][j-1]){
						bt[i][j] = min(bt[i+1][j], bt[i][j-1]);
					}
					else bt[i][j] = dp[i+1][j] > dp[i][j-1] ? bt[i+1][j] : bt[i][j-1];
				}
				i++, j++;
			}
		}
		
		cout << bt[0][n-1] << endl;
	}
	return 0;
}