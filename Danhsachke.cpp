#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++) {
        cout << i << " : ";
                   //  for(int j = 0; j < adj[i].size(); j++) {
                  //  int x = adj[i][j];
                 //      cout << x << " ";
                //  }
        for(int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}
