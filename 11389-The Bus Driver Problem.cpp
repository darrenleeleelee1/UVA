#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, d, r;
	vector<int> A, B;
	while(cin >> n >> d >> r){
		if(n == 0 && d == 0 && r == 0) break;
		A.clear(), B.clear();

		for(int i = 0; i < n; i++){
			int temp; cin >> temp;
			A.push_back(temp);
		}
		for(int i = 0; i < n; i++){
			int temp; cin >> temp;
			B.push_back(temp);
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		reverse(B.begin(), B.end());

		long long ans = 0;
		for(int i = 0; i < n; i++){
			ans += (A[i] + B[i] - d) > 0 ? (A[i] + B[i] - d) * r : 0;
		}
		printf("%lld\n", ans);
	}
	return 0;
}