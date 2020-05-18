#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, p, q, temp;
	int T; scanf("%d", &T);
	int cnt = 1;
	map<int, int> mp;
	vector<int> v; 
	while(T--){	
		scanf("%d%d%d", &n, &p, &q);
		p++; q++;
		mp.clear(); v.clear();
		for(int i = 1; i <= p; i++){
			scanf("%d", &temp);
			mp[temp] = i;
		}
		for(int i = 1; i <= q; i++){
			scanf("%d", &temp);
			if(!mp.count(temp)) continue;
			if(v.empty()){
				v.push_back(mp[temp]);
				continue;
			}
			if(mp[temp] > v.back()) {
				v.push_back(mp[temp]);
			}
			else{
				*lower_bound(v.begin(), v.end(), mp[temp]) = mp[temp];
			}
		}
		printf("Case %d: %d\n", cnt++, v.size());

	}
	return 0;
}