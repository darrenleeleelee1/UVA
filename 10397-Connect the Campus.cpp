#include <bits/stdc++.h>
using namespace std;
const int maxn = 750+5;
struct Edge
{
	int from, to;
	double cost;
	bool operator<(const Edge other){
		return cost < other.cost;
	}
}E[maxn*maxn];
int p[maxn];
vector<Edge> G[maxn];
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
	int edge_cnt = 0;
	for(int i = 0; i < m; i++){
		if(uni(E[i].from, E[i].to)){
			int from = E[i].from, to = E[i].to;
			ans += E[i].cost;
			G[from].push_back(Edge{from, to, E[i].cost});
			G[to].push_back(Edge{to, from, E[i].cost});
			if(++edge_cnt == n-1) break;
		}
	}
	return ans;
	if(edge_cnt == n-1) return ans;
	else return -1;// means can't found spanning tree
}

struct Coordinate
{
	int x, y;
};

double dis(Coordinate A, Coordinate B)
{
	double temp1 = (A.x - B.x) * (A.x - B.x);
	double temp2 = (A.y - B.y) * (A.y - B.y);
	return sqrt(temp1 + temp2);
}
Coordinate point[maxn];
int main(int argc, char const *argv[])
{
	int n, m, q, sp, ep;
	while(cin >> n){
		for(int i = 1; i <= n; i++){
			cin >> point[i].x >> point[i].y;
		}
		m = 0;
		for(int i = 1; i < n; i++){
			for(int j = i+1; j <= n; j++){
				E[m].from = i;
				E[m].to = j;
				E[m++].cost = dis(point[i], point[j]);
			}
		}
		cin >> q;
		for(int i = 0; i < q; i++){
			cin >> sp >> ep;
			for(int j = 0; j < m; j++){
				if(E[j].from == sp && E[j].to == ep){
					E[j].cost = 0;
				}
				if(E[j].to == sp && E[j].from == ep){
					E[j].cost = 0;
				}
			}
		}
		double mincost = kruskal(n, m);
		printf("%.2lf\n", mincost);
	}
	return 0;
}