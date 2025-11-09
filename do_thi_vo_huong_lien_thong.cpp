# include<bits/stdc++.h>
    using namespace std;
    
    int n,m;
    vector<int> adj[1001];
    bool visited[1001];
    
    void dfs(int u){
      visited[u] = true;
	cout<<u<<" ";
      for(int v : adj[u]){
      	if(!visited[v]){
      		dfs(v);
      	}
    }
}
      		
    void connectedcomponent(){
    	int cnt =  0;
    memset(visited, false, sizeof(visited));
     for(int i=1; i<=n; i++){
     	if(!visited[i]){
     		++cnt;
		cout<<"Cac dinh thuoc thanh phan lien thong thu :  "<< cnt << endl;
     		dfs(i);
		  cout<<endl;
     	}
       }
      cout<< cnt <<endl;
    }
    
      int main(){
      	cin>>n>>m;
      	for(int i=0; i<m; i++){
      		int x, y;   cin>>x>>y;
      		adj[x].push_back(y);
      		adj[y].push_back(x);
      	}
      	connectedcomponent();
    }