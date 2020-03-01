#include <iostream>
using namespace std;
void initialize(int n, int parent[], int rank[]){
	for (int i = 1; i <= n; ++i){
		parent[i] = -1;
		rank[i] = 1;
	}
}
int findRoot(int x, int parent[]){
	int xRoot = x;
	while(parent[xRoot] != -1){
		xRoot = parent[xRoot];
	}
	return xRoot;
}
void unions(int x, int y, int parent[], int rank[]){
	int xRoot = findRoot(x, parent);
	int yRoot = findRoot(y, parent);
	if(xRoot != yRoot){
		if(rank[xRoot] > rank[yRoot]){
			parent[yRoot] = xRoot;
			rank[xRoot] += rank[yRoot];
		}
		else{
			parent[xRoot] = yRoot;
			rank[yRoot] += rank[xRoot];	
		}
	}
}
int main(int argc, char const *argv[])
{
	int n, m, temp1, temp2, counter = 1;
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		int parent[n+1];
		int rank[n+1];	
		initialize(n ,parent, rank);
		for (int i = 0; i < m; ++i)	{
			cin >> temp1 >> temp2;
			unions(temp1, temp2, parent, rank);
		}
		int ctr = 0;
		for (int i = 1; i <= n; ++i){
			if(parent[i] == -1) ctr++;
		}
		cout << "Case " << counter++ << ": "<< ctr <<endl;


	}
	return 0;
}