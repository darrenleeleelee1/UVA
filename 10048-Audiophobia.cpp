#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
struct Edge
{
	int from, to;
	double cost;
	bool operator<(const Edge other){
		return cost < other.cost;
	}
}E[maxn*maxn];
int p[maxn];	
int maxcost[maxn][maxn];
vector<Edge> G[maxn];
vector<int> visited;
int find(int x){
	int root, trail, lead;
	for (root = x ; p[root] >= 0; root = p[root]);
	for (trail = x ; trail != root; trail = lead) {
        lead = p[trail];
        p[trail]= root;
 	}
 	return root;
}
bool uni(int x ,int y)
{
	int xRoot = find(x), yRoot = find(y);
	if(xRoot != yRoot){
		if(p[xRoot] > p[yRoot]){
			p[xRoot] += p[yRoot];
			p[yRoot] = xRoot;
		}
		else{
			p[yRoot] += p[xRoot];
			p[xRoot] = yRoot;	
		}
		return true;
	}
	else return false;
}
double kruskal(int n, int m)
{
	// n is the numbers of node, m is the numbers of edge.
	for(int i = 0; i <= n; i++){
		G[i].clear();
		p[i] = -1;
	}
	sort(E, E + m);
	double ans = 0;
	for(int i = 0; i < m; i++){
		if(uni(E[i].from, E[i].to)){
			int from = E[i].from, to = E[i].to;
			ans += E[i].cost;
			G[from].push_back(Edge{from, to, E[i].cost});
			G[to].push_back(Edge{to, from, E[i].cost});
		}
	}
	return ans;
}
void dfs(int pre, int now, int w){
	for(auto x : visited){
		maxcost[x][now] = maxcost[now][x] = max(w, maxcost[pre][x]);
	}
	visited.push_back(now);
	for(auto i : G[now]){
		if(pre != i.to) dfs(i.from, i.to, i.cost);
	}
}
void findMaxPtah(int sp, int ep){
	memset(maxcost, 0,  sizeof(maxcost));
	visited.clear();
	dfs(-1, sp, 0);
}
int main(int argc, char const *argv[])
{
	int n, m, q, sp, ep, cas = 1;
	bool first = true;
	while(cin >> n >> m >> q){
		if(n == 0 && m == 0 && q == 0) break;
		if(first) first = false;
		else printf("\n");
		for(int i = 0; i < m; i++){
			cin >> E[i].from >> E[i].to >> E[i].cost;
		}
		double mincost = kruskal(n, m);
		printf("Case #%d\n", cas++);
		for(int i = 0; i < q; i++){
			cin >> sp >> ep;
			findMaxPtah(sp, ep);
			if(maxcost[sp][ep] == 0) printf("no path\n");
			else printf("%d\n", maxcost[sp][ep]);
		}
	}
	return 0;
}