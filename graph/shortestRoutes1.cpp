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
 
vector<pair<int, int>>adj[N];
vector<int>dist(N);
 
 
void reset(int n) {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dist[i] = INF;
    }
}
 
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    reset(n);
 
    
    for(int i = 1; i<= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }    
 
 
    priority_queue< pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>> >pq;
    pq.push({0, 1});
    dist[1] = 0;
 
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
 
        if(dis > dist[node]) continue;
 
        for(auto [adjNode, edW]: adj[node]){
            if(dis + edW < dist[adjNode]){
                dist[adjNode] = dis + edW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
 
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
 
    
 
}
 
signed main(){
   Sachin_3059
 
   solve();
}