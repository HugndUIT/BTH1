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
        int getTuSo(){
            return TuSo;
        }
        int getMauSo(){
            return MauSo;
        }
        void RutGon(){
            int TempTuSo, TempMauSo;
            TempTuSo = TuSo/GCD(TuSo, MauSo);
            TempMauSo = MauSo/GCD(TuSo, MauSo);
            TuSo = TempTuSo;
            MauSo = TempMauSo;
            if(MauSo < 0){
                TuSo = -TuSo;
                MauSo = -MauSo;
            }
        }
        void NhapPhanSo(){
            do{
                cout << "Nhap Tu So: ";
                cin >> TuSo;
                cout << "Nhap Mau So: ";
                cin >> MauSo;
            }while(MauSo == 0);
        }
        void XuatPhanSo(){
            if(MauSo == 0){
                cout << "Mau So Khong Hop Le";
                return;
            }
            if(MauSo == 1){
                cout << TuSo;
                return;
            }
            cout << TuSo << "/" << MauSo << endl;
        }
};

void SoSanh(PhanSo x, PhanSo y){
    int Temp1 = x.getTuSo() * y.getMauSo();
    int Temp2 = x.getMauSo() * y.getTuSo();
    if(Temp1 > Temp2){
        x.RutGon();
        x.XuatPhanSo();
    }
    else if(Temp1 < Temp2){
        y.RutGon();
        y.XuatPhanSo();
    }
    else{
        cout << "Hai Phan So Bang Nhau!";
    }
}

int main(){
    PhanSo x, y;
    x.NhapPhanSo();
    y.NhapPhanSo();
    SoSanh(x, y);
}