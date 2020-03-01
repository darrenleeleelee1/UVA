#include <iostream>
using namespace std;
void initialize(int parent[], int MaxFriends, int counter[]){
	for (int i = 1; i <= MaxFriends; ++i){
		parent[i] = -1;
		counter[i] = 1;
	}
}
int findRoot(int x, int parent[]){
	int xRoot = x;
	while(parent[xRoot] >= 0){
		xRoot = parent[xRoot];
	}
	return xRoot;
}
void unions(int x, int y, int parent[], int counter[]){
	int xRoot = findRoot(x, parent);
	int yRoot = findRoot(y, parent);
	if(xRoot != yRoot){	
		if(counter[xRoot] <= counter[yRoot]){
			counter[yRoot] += counter[xRoot];
			parent[xRoot] = yRoot;
		}
		else if(counter[xRoot] > counter[yRoot]){
			counter[xRoot] += counter[yRoot];
			parent[yRoot] = xRoot;
		}
	}
}
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int times = 0; times < count; ++times){
		int MaxFriends, relationships;
		cin >> MaxFriends >> relationships;
		int parent[MaxFriends+1];
		int counter[MaxFriends+1];
		int temp1, temp2;
		initialize(parent, MaxFriends, counter);
		for (int i = 0; i < relationships; ++i){
			cin >> temp1 >> temp2;
			unions(temp1, temp2, parent, counter);
		}
		int maxResult = 0;
		for(int i = 1; i <= MaxFriends; ++i){
			if(maxResult < counter[i]) maxResult = counter[i];
		}
		cout << maxResult << endl;


	}
	return 0;
}