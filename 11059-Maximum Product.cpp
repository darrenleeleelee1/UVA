#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, x;
	int cas = 1;
	int arr[25];
	long long ans, temp;
	while(cin >> n){
		ans = 1e18 * -1;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			if(arr[i] > ans) ans = arr[i];
		}
		int i, j, k;
		for(k = 2; k <= n; k++){
			for(i = 0; i <= n - k; i++){
				temp = 1;
				for(j = 0; j < k; j++){
					temp *= arr[i+j];
				}
				if(temp > ans) ans = temp;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", cas++, ans > 0 ? ans : 0);
	}
	return 0;
}