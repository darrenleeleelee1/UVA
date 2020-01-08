#include <iostream>
using namespace std;
int findRoot(int x, int parent[]){
	int xRoot = x;
	while(parent[xRoot] >=0){
		xRoot = parent[xRoot];
	}
	return xRoot;
}
bool unions(int x, int y, int parent[], int rank[]){
	int xRoot = findRoot(x, parent);
	int yRoot = findRoot(y, parent);
	if(xRoot == yRoot){
		return true;
	}
	else{
		if(rank[xRoot] == rank[yRoot]){
				parent[xRoot] = yRoot;
				rank[yRoot]++;			}
			else if(rank[xRoot] > rank[yRoot]){
				parent[yRoot] = x;
			}
			else if(rank[xRoot] < rank[yRoot]){
				parent[xRoot] = y;
		}
		return false;
	}
}
void initialize(int parent[], int rank[], int counter){
	for(int i = 0; i < counter; i++){
		parent[i] = -1;
		rank[i] = 0;
	}
}
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int times = 0; times < count; ++times){
		int n, m; // n is how many people, m is	how many are still friends
		cin >> n >> m;
		int friends[m][2];
		int owe[n];
		int parent[n], rank[n];
		initialize(parent, rank, n);
		bool findCircle = false;
		for(int i = 0; i < n; i++){
			cin >> owe[i];
		}
		for(int i = 0; i < m; i++){
			cin >> friends[i][0] >> friends[i][1];
			if(unions(friends[i][0], friends[i][1], parent, rank)){
				findCircle = true;
			}
		}
		bool possible = true;

		for (int i = 0; i < n; ++i){
			if(findRoot(i, parent) != i) owe[findRoot(i, parent)] += owe[i];
		}
		for(int i = 0; i < n; ++i){
			owe[i] = owe[findRoot(i, parent)];
		}
		for (int i = 0; i < n; ++i){
			if(owe[i] != 0){ 
				possible = false;
				break;
			}
		}
		if(!possible){ 
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			cout << "POSSIBLE" << endl;
		}	
	}
	return 0;
}
/*
for (int i = 0; i < n; ++i)
{
	cout << i << " : "<< findRoot(i, parent) << " " <<parent[i] <<endl; 
}
for (int i = 0; i < n; ++i)
{
	cout << owe[i] << " ";
}
cout << endl;
*/