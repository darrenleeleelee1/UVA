#include <bits/stdc++.h>
using namespace std;
int n, s, temp1, temp2, maxL, endp, counter, dis[102];
vector<int> v[102];
void bellman_ford(int x)
{
	dis[x] = 0;
	for (int k = 1; k < n; ++k){
	 	for (int i = 1; i <= n; ++i){
	 		for(int j : v[i]){
	 			if(dis[i] != -1){
	 				if(dis[j] < dis[i] + 1)
	 					dis[j] = dis[i] + 1;
	 			}
	 		}
	 	}
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
			dis[i] = -1;
		}
		while(cin >> temp1 >> temp2){
			if(temp1 == 0 && temp2 == 0) break;
			v[temp1].push_back(temp2);
		}
		maxL = -1;
		endp = 1e9;
		bellman_ford(s);
		for (int i = 1; i <= n; ++i)
		{
			if(dis[i] > maxL){
				maxL = dis[i];
				endp = i;
			}
			//printf("%2d :%2d\n", i, dis[i]);
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", counter++, s, maxL, endp);
	}
	return 0;
}