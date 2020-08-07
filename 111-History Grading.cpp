#include <bits/stdc++.h>
using namespace std;
int A[25], B[25], correct[25], correctB[25], dp[25][25];
int main(int argc, char const *argv[])
{
	string str;
	stringstream ss;
	int n = 0;
	bool first = true;
	while(getline(cin, str)){
		int cnt = 0;
		ss.clear(); ss.str("");
		ss << str;
		while(ss >> A[cnt]){
			cnt++;
		}

		if(n == 0 || cnt == 1){
			n = A[0];
			first = true;
			continue;
		}
		else{
			if(first){
				for(int i = 0; i < cnt; i++){
					correct[i] = A[i];
				}
				first = false;
			}
			else{
				int ans1 = 0;
				for(int i = 0; i < cnt; i++){
					B[A[i]-1] = i + 1;
					correctB[correct[i]-1] = i + 1;
					if(correct[i] == A[i]) ans1++;
				} 
				memset(dp, 0, sizeof dp);
				for(int i = 1; i <= cnt; i++){
					for(int j = 1; j <= cnt; j++){
						if(B[i-1] == correctB[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
						else{
							dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
						}
					}
				}

				printf("%d\n", max(ans1, dp[cnt][cnt]));
			}
		}


	}
	return 0;
}