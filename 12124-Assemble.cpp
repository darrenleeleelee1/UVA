#include <bits/stdc++.h>
using namespace std;
map<string, int> id;
string type, garbage;
int cnt = 0, temp1, temp2;
int L, R, n, b;
struct Component
{
	int quality, price;
	Component(int p, int q){
		price = p;
		quality = q;
	}
};
vector<Component> v[1010]; 

int ID(string s){
	if(!id.count(s)) {
		id[s] = cnt++;
	}
	
	return id[s];
}
bool ok(int q)
{
	int cheapest, sum = 0;
	for(int i = 0; i < cnt; i++){
		cheapest = b + 1;
		for(auto j : v[i]){
			if(j.quality >= q) {
				if(cheapest > j.price){ 
					cheapest = j.price;
				}
			}
		}
		if(cheapest == b + 1) {
			return false;
		}
		sum += cheapest;

		if(sum > b){ 
			return false;
	}	}
	return true;
}
int main(int argc, char const *argv[])
{
	int T; 
	cin >> T;
	int maxq = -1;
	while(T--){
		cin >> n >> b;
		id.clear();
		cnt = 0;
		maxq = -1;
		for (int i = 0; i < n; ++i)
		{
			v[i].clear();
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> type >> garbage >> temp1 >> temp2;
			if(maxq < temp2) maxq = temp2;
			v[ID(type)].push_back(Component(temp1, temp2));					
		}
		L = 0, R = maxq;
		while(L < R){
			int M = L + (R - L + 1) / 2;
			if(ok(M)) L = M;
			else R = M - 1;
		}
		printf("%d\n", L);
	}
}