#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a % b);
}

class PhanSo {
    private:
        int TuSo, MauSo;
    public:
        void RutGon(){
            int UCLN = GCD(abs(TuSo), abs(MauSo));
            TuSo /= UCLN;
            MauSo /= UCLN;
            if(MauSo < 0){
                TuSo = -TuSo;
                MauSo = -MauSo;
            }
        }
        void NhapPhanSo(){
            cout << "Nhap Tu So: ";
            cin >> TuSo;
            cout << "Nhap Mau So: ";
            cin >> MauSo;
            while (MauSo == 0) {
                cout << "Mau So Khong Hop Le!" << endl;
                cin >> MauSo;
            }
        }
        void XuatPhanSo(){
            if(TuSo % MauSo == 0){
                cout << TuSo / MauSo << endl;
            }
            else{
                cout << TuSo << "/" << MauSo << endl;
            }
        }
};

int main(){
    PhanSo x;
    x.NhapPhanSo();
    x.RutGon();
    x.XuatPhanSo();
}