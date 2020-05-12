#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int from, to, weight;
	bool operator< (const Edge other) const{
		return weight < other.weight;
	}
};
Edge edge[250000+10];
int parent[1000+10];
int n, m;
void init(){
	for(int i = 0; i < n; i++){
		parent[i] = -1;
	}
}
int find(int src){
	int xParent = src;
	while(parent[xParent] != -1){
		xParent= parent[xParent];
	}
	return xParent;
}
bool connect(int x, int y){
	int xParent = find(x);
	int yParent = find(y);
	//printf("%d %d\n", xParent, yParent);
	if(xParent != yParent){
		parent[xParent] = yParent;
		return true;
	}
	else return false;
}
int main(int argc, char const *argv[])
{
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		for(int i = 0; i < m; i++){
			cin >> edge[i].from >> edge[i].to >> edge[i].weight;
		}
		init();
		sort(edge, edge + m);
		vector<int> w;
		for(int i = 0; i < m; i++){
			if(!connect(edge[i].from, edge[i].to)){ 
				w.push_back(edge[i].weight);
			}
		}
		if(w.size() == 0) printf("forest\n");
		else{
			sort(w.begin(), w.end());
			for(int i = 0; i < w.size(); i++){
				if(i == w.size()-1) printf("%d\n", w[i]);
				else printf("%d ", w[i]);
			}
			
		}
	}
	return 0;
}