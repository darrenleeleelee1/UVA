#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8 + 5;
const int INF = 0x80000000;
int A[maxn], dp[maxn], bt[maxn];
int main(int argc, char const *argv[])
{
	int cnt = 0;
	int ans = 1;
	while(cin >> A[cnt]){
		dp[cnt] = INF;
		cnt++;
	}
	dp[1] = 0;
	bt[0] = -1;
	int temp;
	for(int i = 1; i < cnt; i++){
		temp = 1;
		for(int j = 1; j <= ans; j++){
			if(A[i] > A[dp[j]]) {
				temp++;
			}
			else{
				if(A[i] < A[dp[j]]) dp[j] = i;
				if(j == 1) bt[i] = -1;
				else bt[i] = dp[j-1];
				break;
			}
		}
		if(temp > ans){
			bt[i] = dp[ans];
			ans = temp;
			dp[temp] = i;
		}
	}
	printf("%d\n-\n", ans);
	int index = dp[ans];	
	stack<int> s;
	do{
		s.push(A[index]);
		index = bt[index];
	}while(bt[index] != -1);
	s.push(A[index]);
	while(!s.empty()){
		printf("%d\n", s.top());
		s.pop();
	}

	return 0;
}