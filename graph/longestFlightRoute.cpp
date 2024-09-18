#include<bits/stdc++.h>
using namespace std;
#define Sachin_3059 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
const int MOD = 1e9 + 7; 
const int N = 1e5 + 10;
const int INF = -1e18; 

vector<int> adj[N];
vector<int> vis(N, 0);
stack<int> st;
vector<int>parent(N, -1);
vector<int>dist(N, INF);
int n, m;

void dfs(int node) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
    st.push(node); 
}

void findLongestPath(int src, int dest) {
    dist[src] = 0; 

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INF) {
            for (auto it : adj[node]) {
                if (dist[it] < dist[node] + 1) {
                    dist[it] = dist[node] + 1;  
                    parent[it] = node;
                }
            }
        }
    }

   
    if (dist[dest] == INF) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (auto node : path) {
        cout << node << " ";
    }
    cout << endl;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }


    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    findLongestPath(1, n);
}

signed main() {
    Sachin_3059
    solve();
}
