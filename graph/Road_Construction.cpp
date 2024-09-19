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

vector<int> parent(N, -1);
vector<int> Size(N, 0);
int n, m;

void make_set(int v){
    Size[v] = 1;
    parent[v] = v;
}

int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(Size[a] < Size[b]){
            swap(a, b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}

void solve(){
    cin >> n >> m;

    for(int i = 1 ; i<= n; i++){
        make_set(i);
    }

    int total_component = n;
    int max_size = 1;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;

        if(find_set(a) != find_set(b)){
            total_component--;
        }
        union_sets(a, b);

        
        max_size = max(max_size, Size[find_set(a)]);

        cout << total_component << " " << max_size << endl; 

    }


}




 
signed main(){
   Sachin_3059
   solve();

}

/*

9 2
8 3
7 3
6 4
5 4
4 4
3 5
2 6
1 10

*/