#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];                // n đỉnh    adj:kề
vector<pair<int, int>> edge;      
vector<int> adj[1001];            

//MA TRẬN KỀ
void MTK() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

// DANH SÁCH CẠNH
void DSC() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] && i < j) {
                edge.push_back({i, j});
            }
        }
    }

    for (auto v : edge) {
        cout << v.first << " " << v.second << endl;
    }
}

// DANH SÁCH KỀ
void DSK() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n;
    MTK();    
    DSK();    
    return 0;
}

