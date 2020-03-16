#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int N, Q, temp, cnt = 1;
	vector<int> v;
	while(cin >> N >> Q)
	{
		if(N == 0 && Q == 0) break;
		printf("CASE# %d:\n", cnt++);
		v.clear();
		for(int i = 0; i < N; i++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < Q; ++i)
		{
			cin >> temp;
			int counter = 0;
			for(auto j : v){
				counter++;
				if(j == temp){ 
					printf("%d found at %d\n", temp, counter);
					break;
				} 	
				else if(counter == v.size()) printf("%d not found\n", temp);
			}
		}
	}
	return 0;
}