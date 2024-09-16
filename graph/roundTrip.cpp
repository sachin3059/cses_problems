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
vector<int>adj[N];
vector<int>vis(N, 0);
vector<int>parent(N, -1);
vector<int>cycle;
bool cycle_found = false;


void dfs(int node, int par){
    vis[node] = 1;
    parent[node] = par;
    for(auto it: adj[node]){ 
        if(!vis[it]){
            dfs(it, node);
            if(cycle_found) return;
        } 
        else if(it != par){
            // cycle present hai:
            cycle_found = true;
            cycle.push_back(it);
            int curr = node;
            while(curr != it){
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(it);
            return;
        }
    }    
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<= m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i<= n; i++){
        if(!vis[i]){
            dfs(i, -1);
            if(cycle_found) break;
        }
    }

    if(cycle_found){
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;

        for(auto it: cycle){
            cout << it <<" ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}
 
signed main(){
   Sachin_3059

   solve();
 

}