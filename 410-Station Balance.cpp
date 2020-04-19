#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int C, S, cases = 0;
    while(scanf("%d %d", &C, &S) == 2) {
        int x[20] = {};
        int n = 2*C, i, j, k;
        double avg = 0;
        for(i = 0; i < S; i++) {
            scanf("%d", &x[i]);
            avg += x[i];
        }
        avg /= C;
        sort(x, x+n);
        printf("Set #%d\n", ++cases);
        double IMBALANCE = 0;
        for(i = 0; i < C; i++) {
            printf("%2d:", i);
            if(x[i])    printf(" %d", x[i]);
            if(x[n-i-1])printf(" %d", x[n-i-1]);
            puts("");
            IMBALANCE += fabs(x[i] + x[n-i-1] - avg);
        }
        printf("IMBALANCE = %.5lf\n\n", IMBALANCE);
    }
    return 0;
}