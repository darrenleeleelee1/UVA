#include <bits/stdc++.h>
using namespace std;
long long int p[1000000];
long long int myPow(int base, int power)
{
	if(power == 0) return 1;
	if(power == 1) return base;
	if(power % 2 == 0){
		long long int temp = myPow(base, power/2);
		return temp * temp;
	}
	else{
		long long int temp = myPow(base, power/2);
		return base * temp * temp;
	}
}
int main(int argc, char const *argv[])
{
	long long int x;
	int cnt = 0;
	stringstream ss;
	string str;
	while(~scanf("%lld", &x)){
		cin.ignore();
		cnt = 0;
		ss.clear();
		ss.str("");
		getline(cin, str);
		ss << str;
		while(ss >> p[cnt]){
			cnt++;
		}
		cnt--;
		long long int sum = 0;
		for(int i = 0; i < cnt; i++){
			sum += (cnt - i) * p[i] * myPow(x, cnt - i - 1);
		}
		printf("%lld\n", sum);
	}
	return 0;
}