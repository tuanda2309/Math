#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int n, m, s;
vector<pair<int, int>> adj[maxn];

void nhap(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
}

const int INF = 1e9;
vector<int> d(maxn, INF);

void bellmanFord(int s){
    // Khởi tạo khoảng cách từ nguồn s đến tất cả các đỉnh là INF
    d[s] = 0;

    // Relaxation tất cả các cạnh (n-1) lần
    for(int i = 1; i <= n - 1; i++){
        for(int u = 1; u <= n; u++){
            for(auto it : adj[u]){
                int v = it.first;
                int w = it.second;
                if(d[u] != INF && d[v] > d[u] + w){
                    d[v] = d[u] + w;
                }
            }
        }
    }

    // In ra khoảng cách từ s đến tất cả các đỉnh
    for(int i = 1; i <= n; i++){
        cout << d[i] << ' ';
    }
}

int main(){
    nhap();
    bellmanFord(s);
    return 0;
}
