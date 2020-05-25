#include <bits/stdc++.h>
using namespace std;
const int maxn = 750+10;
int A[maxn], B[maxn], k;
struct Item
{
	int sum, b;
	bool operator< (const Item &other) const{
		return sum > other.sum;
	}
};
void Merge()
{
	priority_queue<Item> pq;
	for(int i = 0; i < k; i++){
		pq.push(Item{(A[i] + B[0]), 0});
	}
	for(int i = 0; i < k; i++){
		auto top = pq.top(); pq.pop();
		A[i] = top.sum;
		if(top.b + 1 < k) pq.push(Item{(top.sum + B[top.b+1] - B[top.b]), top.b+1}); 
	}
}
int main(int argc, char const *argv[])
{
	bool first = true;
	while(scanf("%d", &k) == 1){
		for(int i = 1; i < k; i++){
			if(first){
				for (int j = 0; j < k; ++j){
					scanf("%d", &A[j]);
				}
				first = false;
			}
			sort(A, A + k);
			for(int j = 0; j < k; j++){
				scanf("%d", &B[j]);
			}
			sort(B, B + k);
			Merge();
		}
		for(int i = 0; i < k; i++){
			if(i == k-1) printf("%d\n", A[i]);
			else printf("%d ", A[i]);
		}
		first = true;
	}
	return 0;
}