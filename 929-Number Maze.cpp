#include <bits/stdc++.h>
using namespace std;
int row, column, weight[1002][1002], dis[1002][1002];
int dirI[4] = {1, 0, -1, 0};
int dirJ[4] = {0, 1, 0, -1};
struct Node
{
	int i, j, w;
	Node(int _i, int _j, int _w){
		i = _i;
		j = _j;
		w = _w;
	}
	bool operator <(const Node other) const{
		return w > other.w;
	}
};
bool isInside(int i, int j, int offsetI, int offsetJ)
{
	if(i + offsetI < 0 || i + offsetI == row) return false;
	if(j + offsetJ < 0 || j + offsetJ == column) return false;
	return true;
}
void dij(int x, int y)
{
	priority_queue<Node> pq;
	pq.push(Node(x, y, weight[x][y]));
	while(!pq.empty()){
		Node top = pq.top();
		pq.pop();
		if(dis[top.i][top.j] != 1e9) continue;
		for (int i = 0; i < 4; ++i)
		{
			if(isInside(top.i, top.j, dirI[i], dirJ[i])) {
				pq.push(Node(top.i + dirI[i], top.j + dirJ[i], top.w + weight[top.i + dirI[i]][top.j + dirJ[i]]));
			}
		}
		dis[top.i][top.j] = top.w;
	}
}
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int times = 0; times < count; ++times)
	{
		cin >> row >> column;
		for (int i = 0; i < row; ++i){
			for(int j = 0; j < column; ++j){
				cin >> weight[i][j];
				dis[i][j] = 1e9;
			}
		}
		dij(0, 0);
		printf("%d\n", dis[row-1][column-1]);
	}

	return 0;
}