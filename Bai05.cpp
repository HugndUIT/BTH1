#include <bits/stdc++.h>
using namespace std;

class HocSinh{
    private:
        string HoTen;
        float DiemToan, DiemVan;
    public:
        void Nhap(){
            cout << "Nhap Ho Ten: ";
            getline(cin, HoTen);
            cout << "Nhap Diem Toan: ";
            cin >> DiemToan;
            cout << "Nhap Diem Van: ";
            cin >> DiemVan;
        }
        float DTB(){
            return (DiemToan + DiemVan)/2.0;
        }
        void Xuat(){
            cout << HoTen << " " << DTB();
        }
};

int main(){
    HocSinh x;
    x.Nhap();
    x.Xuat();
}
