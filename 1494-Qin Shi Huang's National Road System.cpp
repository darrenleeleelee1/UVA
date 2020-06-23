#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int from, to;
	double weight;
	bool operator< (const Edge other) const{
		return weight < other.weight;
	}
};
int n, m; // n is number of nodes, m is number of edges
const int maxn = 1000 + 5;
Edge E[maxn * maxn];
vector<Edge> G[maxn];
vector<int> visit;
int parent[maxn];
int x[maxn], y[maxn], p[maxn];
double maxcost[maxn][maxn];
void init()
{
	for(int i = 0; i < n; i ++){
		parent[i] = -1;
		G[i].clear();
	}
}
int find(int x)
{
	int xParent = x;
	while(parent[xParent] >= 0){
		xParent = parent[xParent];
	}
	return xParent;
}
bool connect(int x ,int y)
{
	int xParent = find(x);
	int yParent = find(y);
	if(xParent != yParent){
		parent[xParent] = yParent;
		return true;
	}
	else return false;
}
double dist(int i, int j)
{
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
double kruskal()
{
	init();
	m = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			E[m++] = Edge{i, j, dist(i, j)};
		}
	}
	sort(E, E + m);
	double minCost = 0.0;
	for(int i = 0; i < m; i++){
		if(connect(E[i].from, E[i].to)){ 
			int from = E[i].from, to = E[i].to;
			minCost += E[i].weight;
			G[from].push_back(Edge{from, to, E[i].weight});
			G[to].push_back(Edge{to, from, E[i].weight});
		}
	}
	return minCost;
}
void dfs(int pre, int now, double w)
{
	for(auto x: visit){
		maxcost[x][now] = maxcost[now][x] = max(maxcost[x][pre], w);
	}
	visit.push_back(now);

	for(auto i : G[now]){
		if(pre == i.to) continue;
		dfs(now, i.to, i.weight);
	}
}
void find_Max_Path()
{
	memset(maxcost, 0, sizeof(maxcost));
	visit.clear();
	dfs(-1, 0, 0.0);
}
int main(int argc, char const *argv[])
{
	int T; cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i] >> p[i];
		}
		double kru = kruskal();
		find_Max_Path();
		double ans = -1;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				ans = max(ans, (p[i] + p[j]) / (kru - maxcost[i][j]));
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}