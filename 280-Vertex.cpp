#include<bits/stdc++.h>
using namespace std;
vector<int> myVector[102];
bool isVisit[102];
void dfs(int x, int size){
	for (auto i : myVector[x])
	{
		if(!isVisit[i]) {
			isVisit[i] = true;
			dfs(i, size);
		}
	}
}
int main(int argc, char const *argv[])
{
	int size, temp, start, ans, count;
	while(cin >> size){
		if(size == 0) break;
		for (int i = 1; i <= size; ++i){
			myVector[i].clear();
			isVisit[i] = false;
		}
		
		while(cin >> start && start){
			while(cin >> temp && temp){
				myVector[start].push_back(temp);
			}
		}
		cin >> ans;
		for (int i = 0; i < ans; ++i)
		{
			cin >> temp;
			memset(isVisit, false, size+1);
			count = 0;
			dfs(temp, size);
			for (int i = 1; i <= size; ++i)
			{
				if(!isVisit[i]) count++;
			}
			cout << count;
			for (int i = 1; i <= size; ++i)
			{
				if(!isVisit[i]) cout << " " << i;
			}
			cout << endl;
		}
	}
	return 0;
}