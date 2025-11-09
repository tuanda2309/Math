#include<bits/stdc++.h>
 using namespace std;
 
  int n,m;
  int a[1001][1001] ;
  vector<int> adj[1001];
  bool visited[1001];
  
  //Đồ thị vô hướng
  void input(){
  	cin>>n>>m;
  	for(int i=0; i<m; i++){
  		int x,y;   cin>>x>>y;
  		adj[x].push_back(y);
  		adj[y].push_back(x);
	        }
  		memset(visited, false, sizeof(visited));
  	} 
  	 
  	 
  	//BFS
  	
  	void bfs(int u){
  		queue<int> q;
  		q.push(u);
	   visited[u] = true;
  	 // cout<<u<<" ";
  	  while(!q.empty()){
  	  	int v = q.front();  q.pop();
  	  	cout<<v<<" ";
  	  	for(int x : adj[v]){
  	  		if(!visited[x]){
  	  		q.push(x);
  	  		visited[x] = true ;
  	  		}
  	  	 }
  	  }
  	}
  	 
	 //DFS
  	void dfs(int u){
  		cout<<u<<" ";
  		visited[u] = true;
			 for(int v : adj[u]){
			  if(!visited[v]){
			     dfs(v) ;
				}
			 }
		 }                                                                                                                                                                                                                                                                                                                   
  		                                                                                                                                                                                                                                                                                                                                                     
  	 int main(){
  	 	input();
  	 	bfs(1);
  	 	}