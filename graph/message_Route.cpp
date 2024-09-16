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
 
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>>adj(n+1);

    for(int i = 1; i<= m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>vis(n+1, 0);
    vector<int>parent(n+1, -1);

    queue<int>q;
    q.push(1);
    vis[1] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                parent[it] = node;
                q.push(it);
            }
        }
    }

    if(vis[n] == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int>path;

    int curr = n;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
    cout << path.size() << endl;

    for(auto it: path){
        cout << it << " ";
    }
}
 
signed main(){
   Sachin_3059
  
   solve();

}