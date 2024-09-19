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

int n, m;
vector<pair<int, int>>adj[N];
vector<int>vis(N, 0);
 
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue< pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>> >pq;
    pq.push({0, 1});

    int sum = 0;
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt; 

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edw = it.second;
            if(!vis[adjNode]){
                pq.push({edw, adjNode});
            }
        }
    }

    for(int i = 1; i<= n; i++){
        if(!vis[i]){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << sum << endl;
    
 
}
 
signed main(){
   Sachin_3059
   solve();
}