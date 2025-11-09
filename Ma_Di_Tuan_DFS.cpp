#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int n, m;
int a[1001][1001];
bool visited[1001][1001];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int kichthuoc = 8;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void xuat() {
    system("cls");

    // Hiển thị lưới với đường đi của mã

      cout << "    ";
    for (int i = 1; i <= kichthuoc; i++) {
        cout << "  " << i << "  ";
    }
    cout << endl;

    
    for (int i = 1; i <= kichthuoc; i++) {
        cout << "   ";
        for (int j = 1; j <= kichthuoc; j++) {
            cout << "+----";
        }
        cout << "+" << endl;

        cout << " " << i  << " ";
        for (int j = 1; j <=kichthuoc; j++) {
            cout << "| ";
            if (a[i][j] == 0) {
                setColor(8); // Màu xám cho các ô trống
                cout << "  ";
            } else {
                setColor(14); // màu vàng cho đường đi của mã
                cout << setw(2) << a[i][j];
            }
            setColor(7); // Đặt lại về màu mặc định
            cout << " ";
        }
        cout << "|" << endl;
    }

    // In viền dưới
    cout << "   ";
    for (int j = 1; j <=kichthuoc; j++) {
        cout << "+----";
    }
    cout << "+" << endl;
}


int dem(int n, int m) {
    int count = 0;
    for (int k = 0; k < 8; k++) {
        int i1 = n + dx[k];
        int j1 = m + dy[k];
        if (i1 >= 1 && i1 <= kichthuoc && j1 >= 1 && j1 <= kichthuoc && !visited[i1][j1]) {
            count++;
        }
    }
    return count;
}

bool dfs(int n, int m, int buoc) {

    a[n][m] = buoc;
    xuat();
    Sleep(110);
    Beep(600, 110);
    if (buoc == kichthuoc * kichthuoc) {
        xuat();
        return true;
    }


    vector<pair<int, int>> nuoctt;
    for (int k = 0; k < 8; k++) {
        int i1 = n + dx[k];
        int j1 = m + dy[k];
        if (i1 >= 1 && i1 <= kichthuoc && j1 >= 1 && j1 <= kichthuoc && !visited[i1][j1]) {
            nuoctt.push_back({dem(i1, j1), k});
        }
    }

    sort(nuoctt.begin(), nuoctt.end());


    for (auto dichuyen : nuoctt) {
        int k = dichuyen.second;
        int i1 = n + dx[k];
        int j1 = m + dy[k];
        visited[i1][j1] = true;
        if (dfs(i1, j1, buoc + 1)) {
            return true;
        }
        visited[i1][j1] = false;
    }
    a[n][m] = 0;
    xuat();
    Sleep(110);
    Beep(600, 110);
    return false;
}


void input() {

    MessageBox(NULL, "Nhap OK De Nhap Vi Tri Xuat Phat", "Thong Bao", MB_OK);
    cout << "Vi Tri Xuat Phat : " << endl;

    MessageBox(NULL, "Nhap OK De Nhap Dong", "Thong Bao", MB_OK);
    cin >> n;
    cout << endl;

    MessageBox(NULL, "Nhap OK De Nhap Cot", "Thong Bao", MB_OK);
    cin >> m;

    memset(visited, 0, sizeof(visited));
    memset(a, 0, sizeof(a));
    visited[n][m] = true;
    if (!dfs(n, m, 1))  cout << endl;
    }


int main() {
    input();
    return 0;
}