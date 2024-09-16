//jai bajrang bali
#include<bits/stdc++.h>
using namespace std;
#define Sachin_3059                       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int                            long long
const int MOD = 1e9 + 7; 
const int N = 1e5 +1;
const int INF = 1e9;
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, vector<int>&vis, vector<vector<int>>&adj){
    vis[i] = 1;
    queue<int>q;
    q.push(i);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        } 
    }
}
 
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>>adj(n+1);
    
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>vis(n+1, 0);
    vector<int>ans;
    for(int i = 1; i<= n; i++){
        if(!vis[i]){
            ans.push_back(i);
            bfs(i, vis, adj);
        }
    }

    if(ans.size() < 2){
        cout << 0 << endl;
        return;
    }

    cout << ans.size() -1 << endl;
    for(int i = 0; i< ans.size() -1; i++){
        cout << ans[i] << " " << ans[i+1] << endl;
    }
 
}
 
signed main(){
   Sachin_3059
   solve();
}