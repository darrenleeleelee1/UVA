#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
int lw[maxn], rw[maxn];

int main(int argc, char const *argv[])
{
	int left, right, L, R, LH, RH, LTi, RTi;
	while(scanf("%d%d", &left, &right)){
		if(left == 0 && right == 0) break;
		L = abs((left - 1) / 2); R = (right + 1) / 2;
		LH = RH = -1;
		for(int i = L - 1; i >= 0; i--){
			scanf("%d", &lw[i]);
			LH = max(LH, lw[i]);
		}
		for(int i = 0; i < R; i++){
			scanf("%d", &rw[i]);
			RH = max(RH, rw[i]);
		}
		int T = min(LH, RH);
		for(int i = 0; i < L; i++){
			if(lw[i] >= T) {
				LTi = i;
				break;
			}
		}
		for(int i = 0; i < R; i++){
			if(rw[i] >= T) {
				RTi = i;
				break;
			}
		}
		int ans;
		if(LH > RH){
			int V = ((LTi + RTi) + 1) * T;
			int lt = 0, rt = 0, h = 0;
			for(int i = R-1, h = rw[R-1]; i > RTi; i--){
				rt += h;
				h = max(h, rw[i-1]);
			}
			for(int i = LTi, h = T; lw[i] <= T; i++){
				lt += h;
				h = max(h, lw[i+1]);
			}
			if(rt > lt){
				ans = V + (lt + rt);
			}
			else{
				ans = V + rt * 2;
			}
		}
		else if(LH < RH){
			int V = ((LTi + RTi) + 1) * T;
			int lt = 0, rt = 0, h = 0;
			for(int i = L-1, h = lw[L-1]; i > LTi; i--){
				lt += h;
				h = max(h, lw[i-1]);
			}
			for(int i = RTi, h = T; rw[i] <= T; i++){
				rt += h;
				h = max(h, rw[i+1]);
			}
			if(lt > rt){
				ans = V + (rt + lt);
			}
			else{
				ans = V + lt * 2;
			}	
		}
		else{
			int V = ((LTi + RTi) + 1) * T;
			int lt = 0, rt = 0, h = 0;
			for(int i = L-1, h = lw[L-1]; i > LTi; i--){
				lt += h;
				h = max(h, lw[i-1]);
			}
			for(int i = R-1, h = rw[R-1]; i > RTi; i--){
				rt += h;
				h = max(h, rw[i-1]);
			}
			ans = V + min(lt, rt) * 2;
		}
		printf("%d\n", ans * 2);
	}
	return 0;
}