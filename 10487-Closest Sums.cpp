#include <bits/stdc++.h>
using namespace std;
int arr[1000+10], query;
int main(int argc, char const *argv[])
{
	int N, M, cas = 1;
	while(cin >> N && N){
		printf("Case %d:\n", cas++);
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		cin >> M;
		for (int i = 0; i < M; ++i){
			cin >> query;
			int mina = 0x7fffffff, ans;
			for(int i = 0; i < N - 1; i++){
				for(int j = i + 1; j < N; j++){
					if(mina > abs(query - (arr[i] + arr[j]))){
						mina = abs(query - (arr[i] + arr[j]));
						ans = arr[i] + arr[j];
					}
				}
			}
			printf("Closest sum to %d is %d.\n", query, ans);
		}
	}
	return 0;
}