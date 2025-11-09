#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int v = q.front();  
        q.pop();
        for (int x : adj[v]) {
            if (!visited[x]) { // Sửa lỗi: Chỉ thăm các đỉnh chưa được thăm
                q.push(x);
                visited[x] = true;
                parent[x] = v;
            }
        }
    }
}

void path(int s, int t) {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    bfs(s);

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
        adj[y].push_back(x);
    }
    cin >> s >> t;
    path(s, t);
}
