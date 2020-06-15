#include <bits/stdc++.h>
using namespace std;
int n, m ,S, T;
int w[20010][20010], dis[20010];
vector<int> v[20000+10];
struct Node
{
	int node, weight;
	Node(int _n, int _w){
		node = _n;
		weight = _w;
	}	
	bool operator<(Node const other)const{
		return weight > other.weight;
	}
};
void dijsktra(int src)
{
	priority_queue<Node> pq;
	pq.push(Node(src, 0));
	while(!pq.empty())
	{
		auto top = pq.top();
		pq.pop();
		if(dis[top.node] != 1e9) continue;
		for(auto i : v[top.node]){
			pq.push(Node(i, top.weight + w[top.node][i]));
		}
		dis[top.node] = top.weight;
	}
}

int main(int argc, char const *argv[])
{
	int N, cnt = 1, temp1, temp2, tempw; 
	cin >> N;
	while(N--){
		cin >> n >> m >> S >> T;
		for(int i = 0; i < n; i++)
		{
			v[i].clear();
			dis[i] = 1e9;
		}
		memset(w, 0, sizeof(w));
		while(m--)
		{
			cin >> temp1 >> temp2 >> tempw;
			v[temp1].push_back(temp2);
			v[temp2].push_back(temp1);
			if(w[temp1][temp2] == 0) w[temp1][temp2] = w[temp2][temp1] = tempw; 
			else{
				w[temp1][temp2] = min(w[temp1][temp2], tempw);
				w[temp2][temp1] = min(w[temp2][temp1], tempw);	
			}

			
		}
		dijsktra(S);
		if(dis[T] != 1e9)	printf("Case #%d: %d\n", cnt++, dis[T]);
		else printf("Case #%d: unreachable\n", cnt++);
	}
	return 0;
}