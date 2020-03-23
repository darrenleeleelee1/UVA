#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, command, temp;
	priority_queue<int> pq;
	queue<int> q;
	stack<int> s;
	bool isS, isQ, isPQ;
	while(cin >> n)
	{
		while(!s.empty()) s.pop();
		while(!q.empty()) q.pop();
		while(!pq.empty()) pq.pop();
		isPQ = isQ = isS = true;
		for(int i = 0; i < n; i++)
		{
			cin >> command >> temp;
			if(command == 1){
				s.push(temp);
				q.push(temp);
				pq.push(temp);
			}
			else{
				if(s.empty()) isS = false;
				if(q.empty()) isQ = false;
				if(pq.empty()) isPQ = false;
				if(isS && s.top() != temp) isS = false;
				else {
					if(!s.empty()) s.pop();
				}
				if(isQ && q.front() != temp) isQ = false;
				else{
					if(!q.empty()) q.pop();
				}
				if(isPQ && pq.top() != temp) isPQ = false;
				else{
					if(!pq.empty()) pq.pop();
				}
			}
		}
		if((isS && isQ) || (isS && isPQ) || (isQ && isPQ)) printf("%s\n", "not sure");
		else if(isS) printf("%s\n", "stack");
		else if(isQ) printf("%s\n", "queue");
		else if(isPQ) printf("%s\n", "priority queue");
		else if(!isS && !isQ && !isPQ) printf("%s\n", "impossible");
		
	}
	return 0;
}