#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int x, y;
	int xarr[10000+10], yarr[10000+10];
	set<int> sx, sy;
	while(cin >> x >> y){
		if(x == 0 && y == 0) break;
		sx.clear();
		sy.clear();
		for (int i = 0; i < x; ++i){
			cin >> xarr[i];
			sx.insert(xarr[i]);
		}
		for (int i = 0; i < y; ++i){
			cin >> yarr[i];
			sy.insert(yarr[i]);
		}
		int ans = 0;
		if(sx.size() < sy.size()){
			for(auto i : sx){
				if(!sy.count(i)) ans++;
			}
		}
		else{
			for(auto i : sy){
				if(!sx.count(i)) ans++;
			}	
		}
		printf("%d\n", ans);
	}
	return 0;

}