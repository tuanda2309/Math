#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

void inNgauNhienTim(int soLuong, int maxLech = 3) {
    for (int i = 0; i < soLuong; i++) {
        if (rand() % 3 == 0) cout << (char)3; 
        else cout << ' ';
        if (maxLech > 0) cout << string(rand() % maxLech, ' ');
    }
}

void inHangCoTim(char h, int chieuRongTong, int chieuRongBenTrong) {
    int dem = (chieuRongTong - chieuRongBenTrong) / 2;
    for (int i = 0; i < dem; i++) {
        if (rand() % 3 == 0) cout << h;
        else cout << ' ';
    }
    for (int i = 0; i < chieuRongBenTrong; i++) {
        cout << ' ';
    }
    for (int i = 0; i < dem; i++) {
        if (rand() % 3 == 0) cout << h;
        else cout << ' ';
    }
    cout << endl;
}

void inHangBienCoTim(int chieuRong) {
    inNgauNhienTim(chieuRong);
    cout << endl;
}

void inHangCoTimBen(char h, int chieuRongTong, int chieuRongBenTrong) {
    int timBen = (chieuRongTong - chieuRongBenTrong - 2) / 2;
    cout << h << h;
    inNgauNhienTim(timBen, 2);
    for (int i = 0; i < chieuRongBenTrong; i++) {
        cout << ' ';
    }
    inNgauNhienTim(timBen, 2);
    cout << h << h;
    cout << endl;
}

int main() {
    int i;
    char h = 3; 
    MessageBox(NULL, "HAPPY BIRDTHAY NAME ", "HAPPY", MB_OK);
    system("cls");
    system("color f5");
    cout << "\t\t\tFrom: your name\n";
    Sleep(500);
    Beep(523, 500);
    cout << "\t\t\tTo  : Person's name\n\n";
    Sleep(500);
    Beep(523, 500);
    cout << "\t\t";
    for (i = 0; i < 42; i++)
        cout << "_";
    cout << "\n\n";
    system("color f9");

    int tongSoTim = 0;

    Sleep(500);
    Beep(523, 500);
    inHangBienCoTim(60);
    tongSoTim += 60;

    Sleep(500);
    Beep(523, 500);
    inHangCoTimBen(h, 60, 42);
    tongSoTim += 60;

    Sleep(500);
    Beep(523, 500);
    cout << string(3, h) << string(19, ' ') <<" "<<" "<<" "<<" "<<" "<< h << " HAPPY BIRTHDAY " << h <<" "<< string(2, h) << endl;
    tongSoTim += 3 + 19 + 16 + 3 + 3;

    Sleep(500);
    Beep(523, 500);
    inHangCoTimBen(h, 60, 42);
    tongSoTim += 60;

    Sleep(500);
    Beep(523, 500);
    inHangCoTimBen(h, 60, 42);
    tongSoTim += 60;

    Sleep(500);
    Beep(523, 500);
    cout << string(3, h) <<" "<<h<< "\t\t\t\ti i i i i\t\t\t" << string(5, h) << endl;
    tongSoTim += 5 + 5;

    Sleep(500);
    Beep(523, 500);
    cout << string(2, h) <<" "<< h << " "<< "\t\t\t\ti i i i i\t\t\t" << string(5, h) << endl;
    tongSoTim += 5 + 5;

    Sleep(500);
    Beep(523, 500);
    cout << string(1, h) <<" " <<h<<" " <<h<< "\t\t\t      __i_i_i_i_i__\n";
    cout << string(2, h) << " "<<h<<h<< "\t\t\t     |" << h << "           " << h << "|\n";
    tongSoTim += 5 + 5 + 2;

    Sleep(500);
    Beep(523, 500);
    cout << string(1, h) <<" " <<h << h <<" "<< "\t\t\t   __| " << h << "  dd/mm  " << h << " |__\n";
    tongSoTim += 5 + 2;

    Sleep(500);
    Beep(523, 500);
    cout << string(3, h) <<" "<<h<< "\t\t\t  | " << h << "   " << h << "       " << h << "   " << h << " |\n";
    tongSoTim += 5 + 4;

    Sleep(500);
    Beep(523, 500);
    cout << string(1, h) <<" " <<h<<" "<<h<< "\t\t\t__|" << h << "   HAPPY     " << h << "   " << h << "|__\n";
    tongSoTim += 5 + 4;

    Sleep(500);
    Beep(523, 500);
    cout << string(3, h) <<" "<<h<< "\t\t       | " << h << "   " << h << "     BIRTHDAY    " << h << " |\n";
    tongSoTim += 5 + 3;

    Sleep(500);
    Beep(523, 500);
    cout << string(2, h) <<" "<<h<<h<< "\t\t       |" << h << "  " << h << "     " << h << "    " << h << "     " << h << "   " << h << "|\n";
    tongSoTim += 5 + 6;

    Sleep(500);
    Beep(523, 500);
    cout << string(3, h) <<" "<<h<< "\t\t       | " << h << " " << h << " " << h << " " << h << " N A M E " << h << " " << h << " " << h << " " << h << " |\n";
    tongSoTim += 5 + 8;

    Sleep(500);
    Beep(523, 500);
    cout << string(1, h) <<" " <<h<<h<<" "<< "\t\t       |_________________________|\n";
    tongSoTim += 5;

    Sleep(500);
    Beep(523, 500);
    inHangBienCoTim(60);
    tongSoTim += 60;

    Sleep(500);
    Beep(523, 500);
    inHangCoTimBen(h, 60, 42);
    tongSoTim += 60;

    Sleep(500);
    Beep(523, 500);
    inHangCoTimBen(h, 60, 42);
    tongSoTim += 60;

    cout << "\n\n\n\n\n";
    system("pause");
    return 0;
}