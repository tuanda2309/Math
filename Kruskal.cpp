#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

int n,m;
int parent[1001],size[1001];
vector<edge> canh;

// Disjoint set Union (DSU)  Cấu trúc dữ liệu các tập hợp rời nhau
void make_set(){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        size[i] = 1;
    }
}
int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}
bool Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(size[a] < size[b]) swap(a,b);      //swap(a, b) : hoán đổi 2 biến a , b
    parent[b] = a;
    size[a] + size[b];
    return true;
}

// Nhập
void inp(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,w; cin >> x >> y >> w;
        edge e; e.u = x; e.v = y; e.w = w;
        canh.push_back(e);
    }
}

bool cmp(edge a,edge b){
    return a.w < b.w;
}

void kruskal(){
    // tạo cây khung cực tiểu rỗng
    vector<edge> MST;
    int d = 0;
    sort(canh.begin(),canh.end(),cmp);
    //lặp
    for(int i=0;i<m;i++){
        if(MST.size() == n-1) break;
        edge e = canh[i];    // chọn cạnh nhỏ nhất
        if(Union(e.u,e.v)){
            MST.push_back(e);
            d+=e.w;
        }
    }
    if(MST.size() != n-1) cout << "do thi khong lien thong" << endl;
    else {
        cout << "MST: " << d << endl;
        for(auto it : MST){
            cout << it.u << " " << it.v << " " << it.w << endl;
        }
    }
}

int main(){

    inp();
    make_set();
    kruskal();

    return 0;
}