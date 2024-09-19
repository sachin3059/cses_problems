//jai bajrang bali
#include<bits/stdc++.h>
using namespace std;
#define Sachin_3059                       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int                            long long
const int MOD = 1e9 + 7; 
const int N = 1e5 +1;
const int INF = 1e18;
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int>adj[N];
vector<int>vis(N, 0);
stack<int>st;
vector<int>path;
vector<int>dist(N, 0);
int n, m;

void dfs(int node){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }

    st.push(node);
}

 
void solve(){
    cin >> n >> m;
    
    for(int i = 1; i<= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i<= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    while(!st.empty()){
        path.push_back(st.top());
        st.pop();
    }

    // for(auto it: path){
    //     cout << it << " ";
    // }
    // cout << endl;

    dist[1] = 1;

    for(auto node: path){
        for(auto it: adj[node]){
            dist[it] %= MOD;
            dist[it] += dist[node];
            dist[it] %= MOD;
        }
    }
    cout << dist[n] << endl;



 
}
 
signed main(){
   Sachin_3059
   solve();
}