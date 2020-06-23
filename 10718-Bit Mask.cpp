#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long M, N, L, U, temp, t;
	while(cin >> N >> L >> U)
	{
		M = 0;
		for(int i = 31; i >= 0; i--){
			t = (long long)1 << i;
			temp = (M | t);
			if((N & t) == 0){
				if(temp <= U) M = temp;
			} 
			else{
				if(M + t - 1 < L) M = temp;
			}
		}
		printf("%lld\n", M);
	}
	return 0;
}