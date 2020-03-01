#include <iostream>
using namespace std;
int gcd(int m, int n){
    if(m > n){
        int temp = n;
        n = m;
        m = temp;
    }
    int result = m;
    if(n % result == 0) return result;
    else gcd(n % result, result);
}
int main(int argc, char const *argv[])
{
    int n;
    while(cin >> n){
        if(n == 0) break;
        int sum = 0;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                sum += gcd(i, j);
        cout << sum << endl;    
        
    }
    return 0;
}
