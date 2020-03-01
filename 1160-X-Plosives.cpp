#include<bits/stdc++.h>
using namespace std;
int parent[100002], refuse;
int findRoot(int x)
{
	int xRoot = x;
	while(parent[xRoot] > 0){
		xRoot = parent[xRoot];
	}
	return xRoot;	
}
void unions(int x, int y){
	int xRoot = findRoot(x);
	int yRoot = findRoot(y);
	if(xRoot == yRoot) {
		refuse++;
		return;
	}
	else {
		if(parent[xRoot] < parent[yRoot]){
			parent[xRoot] += parent[yRoot];
			parent[yRoot] = xRoot;
		}
		else{
			parent[yRoot] += parent[xRoot];
			parent[xRoot] = yRoot;
		}
	}

}
int main(int argc, char const *argv[])
{
	memset(parent, -1, 100002);
	refuse = 0;
	int temp1, temp2;
	while(cin >> temp1){
		if(temp1 == -1){
			cout << refuse << endl;
			refuse = 0;
			memset(parent, -1, 100002);
			continue;
		}
		cin >> temp2;
		unions(temp1, temp2);
	}
}