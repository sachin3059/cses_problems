#include<bits/stdc++.h>
using namespace std;
#define Sachin_3059 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
const int MOD = 1e9 + 7; 
const int N = 1e5 + 1;

int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1};
char direction[] = {'U', 'R', 'D', 'L'};

bool bfs(vector<string>& graph, pair<int, int>& start, pair<int, int>& end, vector<vector<pair<int, int>>>& parent, vector<vector<char>>& path) {
    int n = graph.size();
    int m = graph[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == end.first && y == end.second) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

          
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                parent[nx][ny] = {x, y};    
                path[nx][ny] = direction[i]; 
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> graph(n);
    pair<int, int> start, end;

   
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'A') {
                start = {i, j};
            }
            if (graph[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> path(n, vector<char>(m, 0));

    
    if (bfs(graph, start, end, parent, path)) {
        cout << "YES\n";

        string ans;
        pair<int, int> current = end;

        while (current != start) {
            ans += path[current.first][current.second];
            current = parent[current.first][current.second];
        }

    
        reverse(ans.begin(), ans.end());

        cout << ans.size() << "\n";  
        cout << ans << "\n";         
    } 
    else {
        cout << "NO\n";
    }
}

signed main() {
    Sachin_3059
    solve();
}
