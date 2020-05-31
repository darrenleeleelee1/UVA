#include <bits/stdc++.h>
using namespace std;
bool visit[20];
vector<int> primeRing;
bool isPrime[40];
int n;
bool detectPrime(int src)
{
	if(src == 1 || src == 0) return false;
	for(int i = 2; i <= sqrt(src); i++)
		if(src % i == 0) return false;
	return true;
}
void dfs(int src, int layer)
{
	visit[src] = true;
	primeRing.push_back(src);

	for(int i = 1; i <= n; i++){
		if(!visit[i] && isPrime[src + i]) dfs(i, layer+1);
	}
	if(layer == n){
		if(isPrime[primeRing[primeRing.size()-1] + 1]){
			for(int i = 0; i < primeRing.size(); i++){
				if(i == n-1) printf("%d\n", primeRing[i]);
				else printf("%d ", primeRing[i]);
			}
		}
	}
	visit[primeRing.back()] = false;
	primeRing.pop_back();


}
int main(int argc, char const *argv[])
{

	int cnt = 1;
	memset(isPrime, false, sizeof(isPrime));
	for(int i = 1; i < 40; i++){
		if(detectPrime(i)) isPrime[i] = true;
	}
	bool first = true;
	while(~scanf("%d", &n))
	{
		
		memset(visit, false, sizeof(visit));
		primeRing.clear();
		if(first) first = false;
		else printf("\n");
		printf("Case %d:\n", cnt++);
		dfs(1, 1);
		
	}
	
	return 0;
}