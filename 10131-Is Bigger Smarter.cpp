#include <bits/stdc++.h>
using namespace std;
struct Elephant
{
	int weight, IQ, order;
	bool operator<(const Elephant other) const{
		return ((weight < other.weight) || ((weight == other.weight) && IQ < other.IQ));
	}
};
Elephant e[1000+5];
int LDS[1000+5];
int pre[1000+5];
int main(int argc, char const *argv[])
{
	int cnt = 0;
	while(scanf("%d%d", &e[cnt].weight, &e[cnt].IQ) == 2){
		e[cnt].order = cnt+1;
		cnt++;
	}
	sort(e, e + cnt);
	memset(LDS, 0, sizeof(LDS));
	for(int i = 0; i < cnt; i++){
		pre[i] = -1;
	}
	int ans = -1, backtrack = -1;
	for(int i = 0; i < cnt; i++){
		int maxl = 0, temp;
		for(int j = 0; j <= i-1; j++){
			if(e[i].IQ < e[j].IQ && LDS[j] > maxl){
				maxl = LDS[j];
				temp = j;
			}
		}
		LDS[i] = maxl + 1;
		if(ans < LDS[i]){
			ans = LDS[i];
			backtrack = i;
		}
		if(maxl != 0){
			pre[i] = temp;
		}
	}
	printf("%d\n", ans);
	vector<int> v;
	while(true){
		v.push_back(e[backtrack].order);
		if(pre[backtrack] == -1) break;
		else backtrack = pre[backtrack];
	}	
	reverse(v.begin(), v.end());
	for(auto i : v) printf("%d\n", i);
	return 0;
}