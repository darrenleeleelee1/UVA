#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int T, n, type[1010], sum;
	vector<int> v;
	cin >> T;
	while(T--)
	{
		cin >> n;
		v.clear();
		for(int i = 0; i < n; i++)
		{
			cin >> type[i];
		}
		sum = type[0];
		v.push_back(type[0]);
		for(int i = 1; i < n; i++){
			if(sum < type[i]){
				sum += type[i];
				v.push_back(type[i]);
			}
			else{
				sum -= v[v.size()-1];
				sum += type[i];
				v.pop_back();
				v.push_back(type[i]);
			}
		}
		printf("%d\n", v.size());


	}
	return 0;
}