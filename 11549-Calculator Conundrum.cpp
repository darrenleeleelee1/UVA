#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int T, n, res;
	int tens;
	cin >> T;
	long long int k;
	set<int> s;
	set<int>::iterator it;
	while(T--)
	{
		cin >> n >> k;
		s.clear();
		tens = 10;
		res = 0;
		for(int i = 0; i < n - 1; i++)
			tens *= 10;
		while(true)
		{
			while(k >= tens){
				k /= 10;
			}
			if(!s.count(k)){ 
				if(k > res) res = k;
				s.insert(k);
				k *= k;
			}
			else break;
		}
		printf("%d\n", res);
	}
	return 0;
}