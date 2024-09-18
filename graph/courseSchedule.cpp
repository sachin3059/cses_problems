//jai bajrang bali
#include<bits/stdc++.h>
using namespace std;
#define Sachin_3059                       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int                            long long
const int MOD = 1e9 + 7; 
const int N = 1e5 +10;
const int INF = 1e18;
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int>adj[N];
vector<int>vis(N, 0);
vector<int>recStack(N, 0);
stack<int>st;
int n, m;

bool  dfs(int node){
    vis[node] = 1;
    recStack[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if( dfs(it) == false) return false;
        }
        else{
            if(recStack[it]){
                return false;
            }
        }
    }
    recStack[node] = 0;
    st.push(node);
    return true;
}
 
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i<= n; i++){
        if(!vis[i]){
            if(dfs(i) == false){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    for(auto it: ans){
        cout << it <<" ";
    }
    cout << endl;


}
 
signed main(){
   Sachin_3059
   solve();
}