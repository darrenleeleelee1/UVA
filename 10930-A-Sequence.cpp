#include <bits/stdc++.h>
using namespace std;
int arr[40];
int main(int argc, char const *argv[])
{
	int n, cnt = 1;
	while(cin >> n){
		printf("Case #%d:", cnt++);
		bool Asequence = true;
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			printf(" %d", arr[i]);
			if(i > 0 && arr[i] < arr[i-1]) Asequence = false;
			sum += arr[i];

		}
		if(Asequence){
			bool exist[sum];
			memset(exist, false, sizeof(exist));
			for(int i = 0; i < n; i++){
				if(exist[arr[i]]){
					Asequence = false;
					break;
				}
				else exist[arr[i]] = true;
				for(int j = 0; j < arr[i]; j++){
					if(exist[j]) exist[j + arr[i]] = true;
				}
			}
		}
		if(Asequence) printf("\nThis is an A-sequence.\n");
		else printf("\nThis is not an A-sequence.\n");

	}
	return 0;
}