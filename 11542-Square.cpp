#include <bits/stdc++.h>
using namespace std;
const int maxn = 500+10;
typedef int Matrix[maxn][maxn]; 
bool visit[maxn];
int primes[maxn];
Matrix A;
void sieve(int src)
{
	memset(visit, false, sizeof(visit));
	for(int i = 2; i <= sqrt(src + 0.5); i++){
		if(!visit[i]){
			for(int j = i * i; j <= src; j += i){
				visit[j] = true;
			}
		}
	}
	int cnt = 0;
	for(int i = 2; i <= src; i++){
		if(!visit[i]) primes[cnt++] = i;
	}
	return cnt;
}
int ranks(Matrix A, int m, int n)
{
	int i = 0, j = 0, k, r, u;
	while(i < m && j < n)
	{
		r = i;
		for(k = i; k < m; k++){
			if(A[k][j] != 0) {
				r = k;
				break;
			}
		}
		if(A[r][j]){
			if(r != i){
				for(int k = 0; k <= n; k++) swap(A[r][k], A[i][k]);
			}
			for(u = i+1; u < m; u++){
				if(A[u][j]){
					for(k = i; k <= n; k++){
						A[u][k] ^= A[i][k];
					}
				}
			}
			i++;
		}
		j++;
	}
	return i;
}
int main(int argc, char const *argv[])
{
	int T; cin >> T;
	int n, maxp;
	int m = sieve(500);
	long long int x;
	while(T--){
		cin >> n;
		maxp = 0;
		memset(A, 0, sizeof(A));
		for(int i = 0; i < n; i++){
			cin >> x;
			for(int j = 0; j < m; j++){
				while(x % primes[j] == 0){
					maxp = max(maxp, j);
					A[j][i] ^= 1;
					x /= primes[j];
				}
			}
		}
		int r = ranks(A, maxp+1, n);
		cout << (1LL << (n-r)) - 1 << endl;
	}
	return 0;
}