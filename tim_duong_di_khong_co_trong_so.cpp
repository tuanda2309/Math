#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;  // Ghi nhận cha của v là u
            dfs(v);
        }
    }
}

void path(int s, int t) {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(s);

    if (!visited[t]) {
        cout << "Khong co duong di tu " << s << " den " << t << ".\n";
    } else {
        // Truy vết đường đi
        vector<int> path;
        // Bắt đầu từ đỉnh t
        while (t != s) {
            path.push_back(t);
            // Làm ngược lại
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;  
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    cin >> s >> t;
    path(s, t);
}
