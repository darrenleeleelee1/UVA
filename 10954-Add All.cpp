#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int n, temp, cost;
	while(cin >> n && n)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> temp;
			pq.push(temp);
		}
		cost = 0;
		while(pq.size() > 1){
			temp = pq.top();
			pq.pop();
			temp += pq.top();
			cost += temp;
			pq.pop();
			pq.push(temp); 
		}
		printf("%d\n", cost);
		pq.pop();
	}
	return 0;
}