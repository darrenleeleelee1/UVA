#include <bits/stdc++.h>
using namespace std;
int logLen, numberOfAnts;
int pos[1000000+10];
int main(int argc, char const *argv[])
{
	int T; cin >>T;

	while(T--){
		cin >> logLen >> numberOfAnts;
		int shortest = 0;
		int logest = 0;
		for(int i = 0; i < numberOfAnts; i++){
			cin >> pos[i];
			if(pos[i] <= logLen / 2) {
				shortest = max(shortest, pos[i]);
				logest = max(logest, logLen - pos[i]);
			}
			else {
				shortest = max(shortest, logLen - pos[i]);
				logest = max(logest, pos[i]);
			}
		}
		printf("%d %d\n", shortest, logest);

	}
	return 0;
}