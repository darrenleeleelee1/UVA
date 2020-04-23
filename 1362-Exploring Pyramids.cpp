#include <bits/stdc++.h>
using namespace std;
const int maxn = 300+10;
long long int d[maxn][maxn];
int length;
char tape[maxn];
long long int dp(int i, int j){
	long long int &ans = d[i][j];
	/*
	for(int k = 0; k < length; k++){
		for(int t = 0; t < length; t++){
			printf("%d ", d[k][t]);
		}
		printf("\n");
	}
	*/
	if(i == j) return ans;
	if(tape[i] != tape[j]) {
		ans = 0;
		return ans;
	}
	if(ans >= 0) {
		//ans %= 1000000000;
		return ans; 
	}
	ans = 0;
	for(int k = i + 2; k <= j; k++)
		ans = (ans + (dp(i + 1, k - 1) * dp(k, j))) % 1000000000;
		//ans += ((dp(i + 1, k - 1)) % 1000000000) * ((dp(k, j)) % 1000000000);
	return ans;
} 

int main(int argc, char const *argv[])
{
	while(scanf("%s", tape) != EOF){
		memset(d, -1, sizeof(d));
		for(int i = 0; i < strlen(tape); i++)
			d[i][i] = 1;
		length = strlen(tape);
		printf("%lld\n", (dp(0, strlen(tape)-1))% 1000000000);
	}
	return 0;
}