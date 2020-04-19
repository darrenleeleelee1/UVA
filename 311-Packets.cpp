#include <bits/stdc++.h>
using namespace std;
const int threetwo[4] = {0, 5, 3, 1};
const int threeone[4] = {0, 7, 6, 5};
int main(int argc, char const *argv[])
{
	int arr[7];
	while(true){
		bool flag = true;
		for(int i = 1; i <= 6; i++){
			cin >> arr[i];
			if(arr[i] != 0 && flag) flag = false;
		}
		if(flag) break;
		int packs = arr[6] + arr[5] + arr[4] + ((arr[3] + 3) / 4);
		int twoSpace = arr[4] * 5 + threetwo[arr[3] % 4];
		int oneSpace = arr[5] * 11 + threeone[arr[3] % 4];
		if(twoSpace >= arr[2]){
				twoSpace -= arr[2];
				oneSpace += twoSpace * 4;
		}
		else{
			arr[2] -= twoSpace;
			packs += (arr[2] + 8) / 9;
			if(arr[2] % 9 != 0) oneSpace += 36 - (arr[2] % 9) * 4; 
		}
		if(oneSpace < arr[1]){
			arr[1] -= oneSpace;
			packs += (arr[1] + 35) / 36;
		}	
		printf("%d\n", packs);
	}
	return 0;
}