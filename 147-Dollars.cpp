#include <bits/stdc++.h>
using namespace std;
const int maxn = 30000+5;
long long dp[maxn];
int currency[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
int main(int argc, char const *argv[])
{
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 10; i >= 0; i--){
        for(int j = currency[i]; j <= 30000; j++){
            dp[j] += dp[j - currency[i]];
        }
    }
    int ans1, ans2;
    while(scanf("%d.%d", &ans1, &ans2) != EOF){
        if(ans1 == 0 && ans2 == 0) break;
        int A = ans1 * 100 + ans2;
        
        printf("%3d.%02d%17lld\n", ans1, ans2, dp[A]);
    }

    
    return 0;
}