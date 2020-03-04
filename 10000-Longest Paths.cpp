#include <bits/stdc++.h>
using namespace std;
int n, s, temp1, temp2, maxL, endp, counter;
vector<int> v[102];
void dfs1(int now, int fa, int layer)
{
	if(maxL < layer) maxL = layer;
	for (auto i : v[now])
	{
		if(i != fa) dfs1(i, now, layer + 1);
	}
}
void dfs2(int now, int fa, int layer)
{
	if(layer == maxL){
		if(now < endp) endp = now;
	}
	for (auto i : v[now])
	{
		if(i != fa) dfs2(i, now, layer + 1);
	}
}
int main(int argc, char const *argv[])
{
	counter = 1;
	while(cin >> n && n){
		cin >> s;
		for (int i = 1; i <= n; ++i)
		{
			v[i].clear();
		}
		while(cin >> temp1 >> temp2){
			if(temp1 == 0 && temp2 == 0) break;
			v[temp1].push_back(temp2);
		}
		maxL = -1;
		endp = 1e9;
		dfs1(s, -1, 0);
		dfs2(s, -1, 0);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", counter++, s, maxL, endp);
	}
	return 0;
}