#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int a, A, L, cnt, n;
	cnt = 1;
	while(cin >> A >> L){
		a = A;
		if(A < 0 && L < 0) break;
		n = 0;
		while(A <= L){
			n++;
			if(A == 1) break;
			if(A % 2 == 0) A /= 2;
			else A = 3 * A + 1;
		}
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", cnt++, a, L, n);
	}
	return 0;
}