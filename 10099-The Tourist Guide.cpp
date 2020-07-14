#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
const int INF = 0x3F3F3F3F;
int p[maxn];
struct Edge
{
    int from, to, cost;
    bool operator<(const Edge &other)const{
        return cost > other.cost;
    }
}E[maxn*maxn];
typedef pair<int, int> PII;
vector<PII> adj[maxn];
int find(int x)
{
    return p[x] < 0 ? x : (p[x] = find(p[x]));
}
bool uni(int x, int y)
{
    int xRoot = find(x), yRoot = find(y);
    if(xRoot == yRoot) return false;
    else{
        if(p[xRoot] < p[yRoot]){
            p[xRoot] += p[yRoot];
            p[yRoot] = xRoot;
        }
        else{
            p[yRoot] += p[xRoot];
            p[xRoot] = yRoot;
        }
        return true;
    }
}
int kruskal(int n, int m)
{
    memset(p, -1, sizeof(p));
    for(int i = 0; i <= n; i++) adj[i].clear();
    sort(E, E + m);
    int cost = 0;
    for(int i = 0; i < m; i++){
        if(uni(E[i].from, E[i].to)){
            cost += E[i].cost;  
            adj[E[i].from].push_back(make_pair(E[i].to, E[i].cost));
            adj[E[i].to].push_back(make_pair(E[i].from, E[i].cost));
        }
    }
    return cost;
}
vector<int> vis;
int maxcost[maxn][maxn];
void dfs(int cur, int pre, int cost){
    for(auto i : vis){
        maxcost[cur][i] = maxcost[i][cur] = min(maxcost[pre][i], cost);
    }
    vis.push_back(cur);
    for(auto i : adj[cur]){
        if(i.first != pre) dfs(i.first, cur, i.second);
    }
}
void find_max_path(int sp, int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            maxcost[i][j] = INF;
        }
    }
    vis.clear();
    dfs(sp, -1, 0);
}
int main(int argc, char const *argv[])
{
    int n, m, cas = 1, sp, ep, people;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        for(int i = 0; i <= n; i++) adj[i].clear();
        
        for(int i = 0; i < m; i++){
            cin >> E[i].from >> E[i].to >> E[i].cost;
        }
        cin >> sp >> ep >> people;
        int ans = kruskal(n, m);
        find_max_path(sp, n);
        if(people % (maxcost[sp][ep]-1) == 0) printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", cas++, (people / (maxcost[sp][ep]-1)));
        else printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", cas++, (people / (maxcost[sp][ep]-1)) + 1);
    }
    return 0;
}