#include<bits/stdc++.h>
using namespace std;

int n, m;                          // n đỉnh , m cạnh
int a[1001][1001];                 
vector<int> adj[1001];
bool visited[1001];

// DANH SÁCH CẠNH
void DANHSACHCANH_DTVOHUONG() {
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        a[x][y] = 1;              
        a[y][x] = 1;
    }
}

//DANH SÁCH KỀ
void DANHSACHKE() {
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// MA TRẬN KỀ
void MATRANKE() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    DANHSACHCANH_DTVOHUONG();
    MATRANKE();
    return 0;
}
