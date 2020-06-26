#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
struct Coordinate
{
	double x, y;
}c[maxn];
struct Edge
{
	int from, to;
	double cost;
	bool operator<(const Edge other){
		return cost < other.cost;
	}
}E[maxn*maxn];
vector<Edge> G[maxn];
int p[maxn];
int find(int x){
	int xRoot = x;
	while(p[xRoot] >= 0){
		xRoot = p[xRoot];
	}
	return xRoot;
}
bool uni(int x, int y){
	int xRoot = find(x), yRoot = find(y);
	if(xRoot == yRoot) return false;
	else{
		p[yRoot] = xRoot;
		return true;
	}
}
double kruskal(int n, int m)
{
	for(int i = 0; i < n; i++){
		G[i].clear();
		p[i] = -1;
	}
	sort(E, E + m);
	double ans = 0;
	for(int i = 0; i < m; i++){
		if(uni(E[i].from, E[i].to)){
			ans += E[i].cost;
		}
	}
	return ans;
}
double dis(Coordinate A, Coordinate B){
	double temp1 = (A.x - B.x) * (A.x - B.x);
	double temp2 = (A.y - B.y) * (A.y - B.y);
	return sqrt(temp1 + temp2);
}
int main(int argc, char const *argv[])
{
	int T; cin >> T;	
	int n;
	bool first = true;
	while(T--)
	{
		if(first) first = false;
		else printf("\n");
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> c[i].x >> c[i].y;
		}
		int m = 0;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				E[m].from = i;
				E[m].to = j;
				E[m++].cost =  dis(c[i], c[j]);

			}
		}
		double mincost = kruskal(n, m);
		printf("%.2lf\n", mincost);

	}
	return 0;
}