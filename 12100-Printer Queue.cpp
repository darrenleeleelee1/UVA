#include <bits/stdc++.h>
using namespace std;
struct mark
{
	int priority;
	int flag;
	bool operator<(mark const other)const{
		return priority < other.priority;
	}
};
int main(int argc, char const *argv[])
{
	queue<mark> q;
	priority_queue<int> pq;
	int T, n, m, temp;
	cin >> T;
	while(T--)
	{
		while(!q.empty()) q.pop();
		while(!pq.empty()) pq.pop();
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> temp;
			if(i != m) q.push(mark{temp, 0});
			else q.push(mark{temp, 1});
			pq.push(temp);
		}
		int cnt = 0, res;
		while(!q.empty()){
			if(q.front().priority == pq.top()){
				cnt++;
				if(q.front().flag == 1) {
					res = cnt;
					break;
				}
				q.pop();
				pq.pop();
			}
			else{
				q.push(q.front());
				q.pop();
			}
		}
		printf("%d\n", res);
	}
	return 0;
}