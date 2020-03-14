#include <bits/stdc++.h>
using namespace std;
char depo[110][110];
bool oil[110][110];
int n, m, cnt;
int dirj[8] = {1,  1,  0, -1,  -1, -1, 0, 1};
int diri[8] = {0, -1, -1, -1,   0,  1, 1, 1};
bool inORout(int i, int j, int offset)
{
	if(i + diri[offset] >= n || i + diri[offset] < 0) return false;
	if(j + dirj[offset] >= m || j + dirj[offset] < 0) return false;
	else return true;
}
void dfs(int i, int j)
{
	oil[i][j] = false;
	for(int k = 0; k < 8; k++){
		if(inORout(i, j, k) && oil[i + diri[k]][j + dirj[k]]) dfs(i + diri[k], j + dirj[k]);
	}
}
int main(int argc, char const *argv[])
{
	while(cin >> n >> m){
		if(m == 0 && n == 0) break;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0;j < m; j++)
			{
				cin >> depo[i][j];
				if(depo[i][j] == '*') oil[i][j] = false;
				else oil[i][j] = true;
			}
		}
		
		cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0;j < m; j++)
			{
				if(oil[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);

	}
	return 0;
}