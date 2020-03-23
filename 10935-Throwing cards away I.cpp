#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	queue<int> q;
	while(cin >> n && n)
	{
		for(int i = 1; i <= n; i++){
			q.push(i);
		}
		printf("Discarded cards:");
		while(q.size() > 1)
		{
			if(q.size() == 2) {
				printf(" %d", q.front());
			}
			else{
				printf(" %d,", q.front());
			} 
			q.pop();
			q.push(q.front());
			q.pop();
		}
		printf("\nRemaining card: %d\n", q.front());
		q.pop();
	}
	return 0;
}