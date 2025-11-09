#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& residualGraph, int s, int t, vector<int>& parent) {
    int n = residualGraph.size();
    vector<bool> visited(n, false);

    queue<int> q;

    // Đẩy đỉnh nguồn (s) vào hàng đợi và đánh dấu nó là đã thăm
    q.push(s);
    visited[s] = true;

    parent[s] = -1;     // Đặt cha của đỉnh nguồn là -1 vì nó không có cha
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v < n; v++) { 
            // Kiểm tra nếu đỉnh v chưa được thăm và có đường đi từ u đến v trong đồ thị dư
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t) return true;
            }
        }
    }
    return false;
}

// Ford-Fulkerson
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int u, v;
    int n = graph.size();

    // residualGraph là đồ thị dư ban đầu được khởi tạo từ đồ thị gốc
    vector<vector<int>> residualGraph = graph;
    vector<int> parent(n);
    int maxFlow = 0;  // Đại lượng cực đại ban đầu

    // Vòng lặp tiếp tục khi còn tồn tại đường tăng luồng từ s đến t
    while (bfs(residualGraph, s, t, parent)) {
       int pathFlow = INT_MAX;        // Khởi tạo lưu lượng của đường tăng luồng hiện tại là vô cực

        // Duyệt ngược từ đích (t) về nguồn (s) để tìm đường tăng luồng
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}


int main() {
    int n, m, s, t;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));  // n+1 để chỉ số từ 1

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    cout << "Nhap dinh bat dau : ";
    cin >> s;
    cout << "Nhap dinh ket thuc :  ";
    cin >> t;

    cout << "Gia tri luong cuc dai : " << fordFulkerson(graph, s, t) << endl;

    return 0;
}


