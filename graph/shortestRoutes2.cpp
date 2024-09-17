//jai bajrang bali
#include<bits/stdc++.h>
using namespace std;
#define Sachin_3059 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
const int INF = 1e18;
const int N = 501;

int dist[N][N]; 


void floyd_warshall(int n) {
    for (int via = 1; via <= n; via++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][via] < INF && dist[via][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0; 
            else dist[i][j] = INF;
        }
    }

   
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); 
        dist[b][a] = min(dist[b][a], c); 
    }

    floyd_warshall(n);

   
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }
}

signed main() {
    Sachin_3059
    solve();
}
