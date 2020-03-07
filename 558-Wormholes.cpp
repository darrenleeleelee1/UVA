#include <bits/stdc++.h>
using namespace std;
vector<int> v[1002];
int n, m, w[1002][1002], temp1, temp2, dis[1002];
void bellman_ford(int source)
{
	dis[source] = 0;
	for (int k = 0; k < n - 1; ++k){
		for(int i = 0; i < n; ++i){
			for(auto j : v[i]){
				if(dis[i] != 1e9){
					if(dis[i] + w[i][j] < dis[j]){
						dis[j] = dis[i] + w[i][j];
					}
				} 
			}
		}
	}
}
bool hasNegativeCycle(){
	for (int i = 0; i < n; ++i){
		for (auto j : v[i]){
			if(dis[i] + w[i][j] < dis[j]) return true;
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int times = 0; times < count; ++times)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			v[i].clear();
			dis[i] = 1e9;
		}
		while(m--){
			cin >> temp1 >> temp2 >> w[temp1][temp2];
			v[temp1].push_back(temp2);
		}
		bellman_ford(0);
		if(hasNegativeCycle()) printf("possible\n");
		else printf("not possible\n");

	}
	return 0;
}