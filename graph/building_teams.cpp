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

bool bfs(int i, vector<int>&color, vector<vector<int>>&adj){
    queue<int>q;
    q.push(i);
    color[i] = 0;

    while(!q.empty()){
        int node = q.front();
        int nodeColor = color[node];
        q.pop();

        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = !nodeColor;
                q.push(it);
            }
            else if(color[it] == nodeColor){
                return false;
            }
        }
    }
    return true;
}
 
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>>adj(n+1);

    for(int i = 1; i<= m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>color(n+1, -1);
    for(int i = 1; i<= n; i++){
        if(color[i] == -1){
            if( bfs(i, color, adj) == false){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    for(int i = 1; i<= n; i++){
        if(color[i] == 0){
            cout << 1 <<" ";
        }
        else{
            cout << 2 <<" ";
        }
    }
    cout << endl;

 
}
 
signed main(){
   Sachin_3059
  
   solve();
 

}