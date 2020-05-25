#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+10;
vector<int> adj[maxn];
vector<int> ans;

int refs[maxn];
int n, m, t1, t2;
void TopologyOrder()
{
	for(int i = 1; i <= n; i++){
		int s = 1;
		while(s <= n && refs[s] != 0) {
			s++;
		}
		if(s == n+1) break;
		refs[s] = -1;
		ans.push_back(s);
		for(auto j : adj[s]){
			refs[j]--;
		}
	}
}
int main(int argc, char const *argv[])
{
	while(scanf("%d%d", &n, &m))
	{
		if(n == 0 && m == 0) break;
		for (int i = 1; i <= n; ++i)
			adj[i].clear();
		memset(refs, 0, sizeof(refs));
		ans.clear();
		for(int i = 0; i < m; i++){
			scanf("%d%d", &t1, &t2);
			adj[t1].push_back(t2); refs[t2]++;
		}
		TopologyOrder();
		for(int i = 0; i < ans.size(); i++){
			if(i == ans.size()-1) printf("%d\n", ans[i]);
			else printf("%d ", ans[i]);
		}
	}
	return 0;
}