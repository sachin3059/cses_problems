// jai bajrang bali
#include<bits/stdc++.h>
using namespace std;
#define Sachin_3059 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e5 +1;
const int INF = 1e18;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Edge {
    int a, b, cost;
};

//wrong on some test cases-> i can't figure out right now
void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<int> dist(n + 1, INF);  
    dist[1] = 0;  
    vector<int> prev(n + 1, -1);  
    int x = -1;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (dist[e.a] < INF && dist[e.a] + e.cost < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.cost;
                prev[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    }
    else {
        for (int i = 0; i < n; ++i) {
            x = prev[x];  
        }

        vector<int> cycle;
        for (int v = x;; v = prev[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle) {
            cout << v << ' ';
        }
        cout << "\n";
    }
}

signed main() {
    Sachin_3059
    solve();
    return 0;
}
