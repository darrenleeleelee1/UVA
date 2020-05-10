#include <bits/stdc++.h>
using namespace std;
string arr[50+10];
bool cmp(string n1, string n2)
{
	return (n1 + n2) > (n2 + n1);
}
int main(int argc, char const *argv[])
{
	int N;
	long long n1, n2;
	while(cin >> N && N){
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		sort(arr, arr+ N, cmp);	
		for (int i = 0; i < N; ++i){
			cout << arr[i];
		}
		printf("\n");
	}
	return 0;
}