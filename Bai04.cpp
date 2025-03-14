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
        PhanSo(){}
        PhanSo(int x, int y) : TuSo(x), MauSo(y){}
        int getTuSo(){
            return TuSo;
        }
        int getMauSo(){
            return MauSo;
        }
        float SoThapPhan(){
            return (1.0 * TuSo/MauSo);
        }
        void SetPhanSo(int x, int y){
            TuSo = x;
            MauSo = y;
        }
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
                cout << TuSo / MauSo << " ";
            }
            else{
                cout << TuSo << "/" << MauSo << " ";
            }
        }
};

int main(){
    int n;
    cout << "Nhap So Luong Phan So: ";
    cin >> n;
    PhanSo Max(0,1);
    vector<PhanSo> v;
    for(int i = 0; i<n; i++){
        PhanSo Temp;
        Temp.NhapPhanSo();
        Temp.RutGon();
        if(Max.SoThapPhan() < Temp.SoThapPhan()){
            Max.SetPhanSo(Temp.getTuSo(), Temp.getMauSo());
        }
        v.push_back(Temp);
    }
    Max.RutGon();
    Max.XuatPhanSo();
    cout << endl;
    sort(v.begin(), v.end(), [](PhanSo x, PhanSo y){
        return x.SoThapPhan() < y.SoThapPhan();
    });
    for(int i = 0; i<n; i++){
        v[i].XuatPhanSo();
    }
    cout << endl;
    sort(v.begin(), v.end(), [](PhanSo x, PhanSo y){
        return x.SoThapPhan() > y.SoThapPhan();
    });
    for(int i = 0; i<n; i++){
        v[i].XuatPhanSo();
    }
}