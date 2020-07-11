#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
const int INF = 0x3F3F3F3F;
struct Edge
{
    int from, to, rf, label;
};
vector<Edge> adj[maxn];
int n, s, t;
int now[maxn], level[maxn];

void addEdge(int u, int v, int cap)
{
    adj[u].push_back({u, v, cap, (int)adj[v].size()});
    adj[v].push_back({v, u, cap, (int)adj[u].size()-1});
}
bool bfs(){
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while(!q.empty()){
        auto u = q.front(); q.pop();
        for(auto i : adj[u]){
            if(level[i.to] == -1 && i.rf > 0){
                level[i.to] = level[u] + 1;
                q.push(i.to);
            }
        }
    }

    return level[t] != -1;
}
int dfs(int cur, int limit)
{   

    if(cur == t) return limit;
    int res = 0;
    while(now[cur] < adj[cur].size()){
        Edge &it = adj[cur][now[cur]];
        if(level[cur] + 1 == level[it.to] && it.rf > 0){
            int f = dfs(it.to, min(limit, it.rf));
            res += f;
            limit -= f;
            it.rf -= f;
            adj[it.to][it.label].rf += f;    
            if(limit == 0) return res;
        }
        else{
            now[cur]++;
        }
        
    }
    if(!res) level[cur] = -1;
    return res;
}
int dinic()
{
    int maxFlow = 0, newFlow;
    while(bfs()){
        memset(now, 0, sizeof(now));
        do{
            newFlow = dfs(s, INF);
            maxFlow += newFlow;
        }while(newFlow != 0);
    }

    return maxFlow;
}
int cnt = 1;
int main(int argc, char const *argv[])
{
    int con, x, y, z;
    while(cin >> n && n){
        cin >> s >> t >> con;
        for(int i = 0; i <= n; i++) adj[i].clear();
        for(int i = 0; i < con; i++){
            cin >> x >> y >> z;
            addEdge(x, y, z);
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", cnt++, dinic());
    }



    return 0;
}