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
            cin.ignore();
        }
        float DTB(){
            return (DiemToan + DiemVan)/2.0;
        }
        void Xuat(){
            cout << HoTen << " " << DTB() << endl;
        }
};

int main(){
    int n;
    cout << "Nhap So Luong Hoc Sinh: ";
    cin >> n;
    cin.ignore();
    vector<HocSinh> v;
    for(int i = 0; i<n; i++){
        HocSinh Temp;
        Temp.Nhap();
        v.push_back(Temp);
    }
    float Max = INT_MIN;
    float Min = INT_MAX;
    for(HocSinh x : v){
        if(x.DTB() > Max) Max = x.DTB();
        if(x.DTB() < Min) Min = x.DTB();
    }
    cout << "Hoc Sinh Co Diem Trung Binh Cao Nhat:" << endl;
    for(HocSinh x : v){
        if(x.DTB() == Max) x.Xuat();
    }
    cout << "Hoc Sinh Co Diem Trung Binh Thap Nhat:" << endl;
    for(HocSinh x : v){
        if(x.DTB() == Min) x.Xuat(); 
    }
}