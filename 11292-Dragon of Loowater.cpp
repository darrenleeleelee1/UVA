#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, m, tmp;
	vector<int> A, B;
	while(cin >> n >> m ){
		if(n == 0 && m == 0) break;
		A.clear(); B.clear();
		for(int i = 0; i < n; i++){
			cin >> tmp;
			A.push_back(tmp);
		}
		for(int i = 0; i < m; i++){
			cin >> tmp;
			B.push_back(tmp);
		}
		if(n > m){
			printf("Loowater is doomed!\n");
		}
		else if(n == m){
			bool ok = true;
			sort(A.begin(), A.end());
			sort(B.begin(), B.end());
			long long ans = 0;
			for(int i = 0; i < n; i++){
				ans += B[i];
				if(B[i] < A[i]) {
					ok = false;
					break;
				}
			}
			if(ok) printf("%lld\n", ans);
			else printf("Loowater is doomed!\n");
		}
		else{
			sort(A.begin(), A.end());
			sort(B.begin(), B.end());
			priority_queue<int, vector<int>, greater<int>> pq;
			long long ans = 0;
			for(auto i : A) pq.push(i);
			for(int i = 0; i < m; i++){
				if(!pq.empty() && pq.top() <= B[i]) {
					ans += B[i];
					pq.pop();
				}
				if(pq.empty()) break;
			}
			if(pq.empty()) printf("%lld\n", ans);
			else printf("%s\n", "Loowater is doomed!");
		}
	}
	return 0;
}