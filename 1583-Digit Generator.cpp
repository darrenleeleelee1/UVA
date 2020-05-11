#include <bits/stdc++.h>
using namespace std;
int digitSum(int src)
{
	int temp = src;
	int ans =  0;
	int divisor = 10;
	while(temp != 0){
		ans += temp % divisor;
		temp = temp / divisor;
	}
	return ans;
}
int arr[100000+10];
int main(int argc, char const *argv[])
{
	int T; scanf("%d", &T);
	int n;
	memset(arr, 0, sizeof(arr));
	for(int i = 0; i < 100000; i++){
		if(arr[digitSum(i) + i] == 0) arr[digitSum(i) + i] = i;
	}
	while(T--){
		scanf("%d", &n);	
		printf("%d\n", arr[n]);
	
	}
	return 0;
}