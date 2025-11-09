#include<bits/stdc++.h>
  using namespace std;
  
   int n, m;
   vector<pair<int, int>> adj[1001];
   bool visited[1001];
   
   struct canh{
   	int x, y, w;
   };
   
   void nhap(){
   	cin>>n>>m;
   	for(int i=0; i<m; i++){
   		int x, y, w;    cin>>x>>y>>w;
   		adj[x].push_back({y, w});
   		adj[y].push_back({x, w});
	   }
	   memset(visited, false, sizeof(visited));
   }
   
   void prim(int u) {
    vector<canh> MST;  
    int d = 0;  // Tổng trọng số của cây khung nhỏ nhất
    visited[u] = true;  // Đưa đỉnh u vào tập hợp các đỉnh đã được thêm vào MST

    while (MST.size() < n - 1) {
        int min_w = INT_MAX;  // Trọng số nhỏ nhất hiện tại
        int x, y;  // Đỉnh đầu và đỉnh cuối của cạnh nhỏ nhất

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (pair<int, int> c : adj[i]) {
                    int j = c.first, trongso = c.second;
                    if (!visited[j] && trongso < min_w) {
                        min_w = trongso;
                        x = j; y = i;
                    }
                }
            }
        }

        MST.push_back({x, y, min_w});  // Thêm cạnh nhỏ nhất vào MST
        d += min_w;  
        visited[x] = true;  
    }

    cout << d << endl;  
    for (canh e : MST) {  
        cout << e.x << " " << e.y << " " << e.w << endl;  
    }
}
   
   int main(){
   	nhap();
   	prim(1);
   }