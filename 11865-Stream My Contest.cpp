#include <bits/stdc++.h>
using namespace std;

const int maxn = 60+5;
const int INF = 0x3f3f3f3f;
struct Edge
{
	int from, to, cap, cost;
};
const int maxnn = 1e4+5;
Edge E[maxnn], e[maxnn];
int n, m, c;
int in[maxn], pre[maxn], id[maxn], vis[maxn];
int CLE(int root, int n, int m, int lowest_b)
{
	int res = 0;
	while(1)
	{
		for(int i = 0; i < n; i++){
			in[i] = INF;
		}
		for(int i = 0; i < m; i++){
			int from = e[i].from, to = e[i].to;
			if(from != to && e[i].cap >= lowest_b && e[i].cost < in[to]){
				in[to] = e[i].cost;
				pre[to] = from;
			}	
		}
		
		for(int i = 0; i < n; i++){
			if(i == root) continue;
			if(in[i] == INF) return -1;
		}

		int num = 0;
		memset(id, -1, sizeof(id));
		memset(vis, -1, sizeof(vis));
		in[root] = 0;
		for(int i = 0; i < n; i++){
			res += in[i];
			int v = i;
			while(vis[v] != i && id[v] == -1 && v != root)
			{
				vis[v] = i;
				v = pre[v];
			}			
			if(v != root && id[v] == -1)
			{
				for(int j = pre[v]; j != v; j = pre[j]){
					id[j] = num;
				}
				id[v] = num++;
			}
		}
		if(num == 0) break;
		for(int i = 0; i < n; i++){
			if(id[i] == -1) id[i] = num++;
		}
		for(int i = 0; i < m; i++){
			int from = e[i].from, to = e[i].to;
			e[i].from = id[from]; e[i].to = id[to];
			if(id[from] != id[to]) e[i].cost -= in[to];
		}
		n = num;
		root = id[root];
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &m, &c);
		int L = 0x3f3f3f3f, R = -1;
		for(int i = 0; i < m; i++){
			scanf("%d%d%d%d", &E[i].from, &E[i].to, &E[i].cap, &E[i].cost);
			R = max(R, E[i].cap);
			L = min(L, E[i].cap);
		}
		int res = -1;
		while(L <= R){
			int M = (L + R) / 2;
			for(int i = 0; i < m; i++)
				e[i] = E[i];
			int tmp = CLE(0, n, m, M);
			if(tmp == -1 || tmp > c){
				R = M - 1;
			}
			else{
				L = M + 1; res = M;
			}
		}
		if(res == -1){
			printf("streaming not possible.\n");
		}
		else{
			printf("%d kbps\n", res);
		}
	}

	return 0;
}