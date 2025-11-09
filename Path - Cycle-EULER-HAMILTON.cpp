#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
set<int> adj[1001];
int degree[1001];
bool visited[1001];
set<int> original_adj[1001]; // Danh sách kề ban đầu
vector<int> cycle(1002);
bool found_path = false;
bool found_cycle = false;

void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                adj[i].insert(j);
                adj[j].insert(i);
                original_adj[i].insert(j);
                original_adj[j].insert(i);
                degree[i]++;
                degree[j]++;
            }
        }
    }
}

// Khôi phục danh sách kề về trạng thái ban đầu.
void resertbando() {
    for (int i = 1; i <= n; i++) {
        adj[i] = original_adj[i];
    }
    memset(visited, false, sizeof(visited));
    found_path = false;
    found_cycle = false;
}

// Kiểm tra đồ thị có liên thông hay không
bool check1() {
    memset(visited, false, sizeof(visited));
    stack<int> st;
    st.push(1);
    visited[1] = true;
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                st.push(u);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && degree[i] > 0) return false;
    }
    return true;
}

// Kiểm tra điều kiện chu trình Euler
bool check2() {
    if (!check1()) return false;
    for (int i = 1; i <= n; i++)
        if (adj[i].size() & 1) return false;
    return true;
}

// Kiểm tra điều kiện đường đi Euler
int check3() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            count++;
        }
    }
    if (count == 2) return 1;
    else if (count == 0) return 2;
    return 0;
}

//Tìm các đỉnh có bậc lẻ
vector<int> bacle() {
    vector<int> dinhle;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            dinhle.push_back(i);
        }
    }
    return dinhle;
}

// Euler
void euler(int n) {
    stack<int> st;
    vector<int> EC;
    st.push(n);
    while (!st.empty()) {
        int x = st.top();
        if (!adj[x].empty()) {
            int y = *adj[x].begin();
            st.push(y);
            // Xóa cạnh x, y
            adj[x].erase(y);
            adj[y].erase(x);
        } else {
            st.pop();
            EC.push_back(x);
        }
    }

    reverse(begin(EC), end(EC));
    for (int x : EC) cout << x << " ";
}

// Kiểm tra chu trình, đường đi Hamilton
bool check4() {
    for (int i = 1; i <= n; i++) {
        if (degree[i] < n / 2) {
            for (int u = 1; u <= n; u++) {
                for (int v = u + 1; v <= n; v++) {
                    if (adj[u].find(v) == adj[u].end() && (degree[u] + degree[v] < n)) {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    return true;
}

// Hamilton
void hamilton(int u, int pos, bool find_cycle) {
    if (find_cycle && found_cycle) return;
    if (!find_cycle && found_path) return;
    
    visited[u] = true;
    cycle[pos] = u;
    
    if (pos == n) {               // Nếu đã thăm tất cả các đỉnh
        if (find_cycle) {
            if (adj[u].find(cycle[1]) != adj[u].end()) {
                cycle[pos + 1] = cycle[1];             // chu trình đỉnh đầu và cuối trùng nhau
                for (int k = 1; k <= pos + 1; k++) cout << cycle[k] << " ";
                cout << endl;
                found_cycle = true;
            }
        } else {
            for (int k = 1; k <= pos; k++) cout << cycle[k] << " ";
            cout << endl;
            found_path = true;
        }
        visited[u] = false;
        return;
    }
    
    for (int v : adj[u]) {                  //DFS
        if (!visited[v]) {
            hamilton(v, pos + 1, find_cycle);
        }
    }
    
    visited[u] = false;        //quay lui
}

int main() {
    nhap();
    int start;
    cout << "Nhap dinh bat dau : ";
    cin >> start;
    
    resertbando();
    if (check2()) {
        cout << "Chu trinh Euler: "<<endl;
        euler(start);
        cout << endl;
    } else {
        cout << "Khong co chu trinh Euler" << endl;
    }

    cout << endl;
    
    if (check3() == 1) {
        cout << "Duong di Euler\n";
        vector<int> dinhle = bacle();
        resertbando();
        euler(dinhle[0]);
        cout << endl;
    } else if (check3() == 2) {
        resertbando();
        cout << "Duong di Euler\n";
        euler(start);
        cout << endl;
    } else {
        cout << "Khong co duong di Euler\n";
    }

    resertbando();
    if (check4()) {
        cout << "Duong di Hamilton:" << endl;
        hamilton(start, 1, false);
        cout << endl;
    } else {
        cout << "Khong co duong di Hamilton" << endl;
    }

    resertbando();
    found_path = false;

    if (check4()) {
        cout << "Chu trinh Hamilton:" << endl;
        hamilton(start, 1, true);
        cout << endl;
    } else {
        cout << "Khong co chu trinh Hamilton" << endl;
    }
}

