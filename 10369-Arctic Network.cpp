#include <bits/stdc++.h>
using namespace std;
const int maxn = 500+5;
typedef pair<int, int> Coordinate;
Coordinate cor[maxn];
struct Edge
{
    int from, to;
    double cost;
    bool operator<(const Edge other) const{
        return cost < other.cost;
    }
}E[maxn*maxn];
double dis(Coordinate x, Coordinate y)
{
    double tmp1 = (x.first - y.first) * (x.first - y.first);
    double tmp2 = (x.second - y.second) * (x.second - y.second);
    return sqrt(tmp1 + tmp2);
}
int p[maxn];
int find(int x)
{
    return p[x] < 0 ? x : (p[x] = find(p[x]));
}
bool uni(int x, int y)
{
    int xRoot = find(x);
    int yRoot = find(y);
    if(xRoot == yRoot) return false;
    else{
        if(p[yRoot] < p[xRoot]){
            p[yRoot] += p[xRoot];
            p[xRoot] = yRoot;
        }
        else{
            p[xRoot] += p[yRoot];   
            p[yRoot] = xRoot;
        }
    }
    return true;
}
vector<double> ans;
double kruskal(int n, int m)
{
    memset(p, -1, sizeof(p));
    double mincost = 0;
    sort(E, E + m);
    ans.clear();
    for(int i = 0; i < m; i++){
        if(uni(E[i].from, E[i].to)){
            mincost += E[i].cost;
            ans.push_back(E[i].cost);
        }
    }
    return mincost;
}
int main(int argc, char const *argv[])
{
    int T; cin >> T;
    int S, P;
    while(T--){
        cin >> S >> P;
        for(int i = 0; i < P; i++){
            cin >> cor[i].first >> cor[i].second;
        }
        int cnt = 0;
        for(int i = 0; i < P; i++){
            for(int j = i + 1; j < P; j++){
                E[cnt].from = i;
                E[cnt].to = j;
                E[cnt].cost = dis(cor[i], cor[j]);
                cnt++;
            }
        }
        kruskal(P, cnt);
        reverse(ans.begin(), ans.end());
        if(S < 1) printf("%.2lf\n", ans[0]);
        else printf("%.2lf\n", ans[S-1]);
    }
    return 0;
}