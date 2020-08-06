#include <bits/stdc++.h>
using namespace std;
const int maxn = 100*500+5;
int dp[maxn];
int main(int argc, char const *argv[])
{
    int T; cin >> T;
    int n;
    vector<int> v;
    while(T--){
        cin >> n;
        v.clear();
        int x, sum = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            v.push_back(x);
            sum += x;
        }
        int cap = sum / 2;
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++){
            for(int j = cap; j - v[i] >= 0; j--){
                dp[j] = max(dp[j-v[i]] + v[i], dp[j]);
            }
        }
        printf("%d\n", abs(sum - dp[cap] - dp[cap]));
    }
    
    return 0;
}