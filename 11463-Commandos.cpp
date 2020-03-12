#include <bits/stdc++.h>
using namespace std;
int n, m, sp, ep, temp1, temp2, dis[102][102], minL, res;
vector<int> v[102];
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int times = 0; times < count; ++times)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i){
			v[i].clear();
		}
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; j++){
				if(i == j) dis[i][j] = 0;
				else dis[i][j] = 1e9;
			}
		}
		while(m--){
			cin >> temp1 >> temp2;
			v[temp1].push_back(temp2);
			v[temp2].push_back(temp1);
			dis[temp1][temp2] = 1;
			dis[temp2][temp1] = 1;
		}
		cin >> sp >> ep;
		//floyd warshall
		for (int k = 0; k < n; ++k){
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j){
					if(dis[i][j] > dis[i][k] + dis[k][j]){
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
		res = 0;
		for (int i = 0; i < n; ++i)
		{
			printf("sp  : %2d i : %2d ep : %2d\n", sp, i, ep);
			printf("res : %2d dis[%d][%d] : %2d dis[%d][%d] : %2d\n", res, sp, i, dis[sp][i], i, ep, dis[i][ep]);
			if(res < dis[sp][i] + dis[i][ep]) res = dis[sp][i] + dis[i][ep];//為什麼是這樣 不太懂
		}
		printf("Case %d: %d\n", times + 1, res);		
	}
	return 0;
}