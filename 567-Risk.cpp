#include <bits/stdc++.h>
using namespace std;
int d[25][25];
vector<int> adj[25];
void floyd()
{
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i <= 20; i++){
			for(int j = 1; j <= 20; j++){
				d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int n, q, x, sp, ep, cas = 1;
	bool first = true;
	while(cin >> n){
		for(int i = 0; i <= 20; i++) adj[i].clear();
		memset(d, 0x3f, sizeof(d));
		for(int i = 0; i <= 20; i++) d[i][i] = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			adj[1].push_back(x);
			d[1][x] = d[x][1] = 1;
		}
		for(int i = 2; i <= 19; i++){
			cin >> n;
			for(int j = 0; j < n; j++){
				cin >> x;
				adj[i].push_back(x);
				d[i][x] = d[x][i] = 1;
			}
		}
		
		cin >> q;
		floyd();
		printf("Test Set #%d\n", cas++);
		for(int i = 0; i < q; i++){
			cin >> sp >> ep;
			printf("%2d to %2d: %d\n", sp, ep, d[sp][ep]);
		}
		printf("\n");
	}
	return 0;
}