#include <bits/stdc++.h>
using namespace std;
int arr[100000+10];
typedef vector<int> vi;

void ST_Build(vi &ST, const vi &A, int vertex, int L, int R)
{
	if(L == R) ST[vertex] = L;
	else
	{
		int nL = vertex * 2, nR = vertex * 2 + 1;
		ST_Build(ST, A, nL, L, L + (R - L) / 2);
		ST_Build(ST, A, nR, L + (R - L) / 2 + 1, R);
		int indexL = ST[nL], indexR = ST[nR];
		int valueL = A[indexL], valueR = A[indexR];
		ST[vertex] = valueL <= valueR ? indexL : indexR;
	}
}

void ST_Creation(vi &ST, const vi &A)
{
	int len = 4 * A.size();
	ST.assign(len, 0);
	ST_Build(ST, A, 1, 0, A.size()-1);
}
int query(vi &ST, const vi &A, int vertex, int L, int R, int qL, int qR)
{
	int temp, mid = (L + R) / 2;
	if(qL <= L && R <= qR) return ST[vertex];
	if(qR <= mid)
	{
		return query(ST, A, vertex * 2, L, mid, qL, qR);
	}
	if(qL > mid)
	{
		return query(ST, A, vertex * 2 + 1, mid + 1, R, qL, qR);
	}
	return A[query(ST, A, vertex * 2, L, mid, qL, qR)] <= A[query(ST, A, vertex * 2 + 1, mid + 1, R, qL, qR)]
			? query(ST, A, vertex * 2, L, mid, qL, qR) : query(ST, A, vertex * 2 + 1, mid + 1, R, qL, qR);

}
void update(vi &ST, vi &A, int x, int L, int R, int p,int v)
{
	int mid = L + (R - L) / 2;
	if(L == R) A[ST[x]] = v;
	else
	{
		if(p <= mid) update(ST, A, x*2, L, mid, p, v);
		else update(ST, A, x*2+1, mid+1, R, p, v);
		ST[x] = (A[ST[x*2]] <= A[ST[x*2+1]]) ? ST[x*2] : ST[x*2+1];
	}
}
int main(int argc, char const *argv[])
{
	int n, q, x, y, temp;
	char task, trash;
	while(scanf("%d%d", &n, &q) == 2){
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}
		scanf("%c", &trash);

		vi A (arr, arr + n);
		vi ST;
		ST_Creation(ST, A);
		for(int i = 0; i < q; i++){
			scanf("%c", &task);
			for(int j = 0; j < 4; j++) scanf("%c", &trash);
			if(task == 'q'){
				scanf("(%d,%d)\n", &x, &y);
				printf("%d\n", A[query(ST, A, 1, 0, n-1, --x, --y)]);	
			}
			else{
				vector<int> shifts;
				while(scanf("%c", &trash) == 1){
					if(trash == ')') break;
					scanf("%d", &temp);
					shifts.push_back(--temp);
				}
				scanf("\n");
				temp = A[shifts.front()];
				for(int j = 0; j < shifts.size()-1; j++){
					update(ST, A, 1, 0, n-1, shifts[j], A[shifts[j+1]]);
				}				
				update(ST, A, 1, 0, n-1, shifts[shifts.size()-1], temp);
			}
		}
	}
	return 0;
}