#include <iostream>
using namespace std;

class PhanSo {
private:
    int TuSo, MauSo;
public:
    int getTuso() {
        return this->TuSo;
    }
    int getMauso() {
        return this->MauSo;
    }
    void nhap();
    void xuat();
    void rutgon();
    PhanSo cong(PhanSo);
    PhanSo tru(PhanSo);
    PhanSo nhan(PhanSo);
    PhanSo chia(PhanSo);
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void PhanSo::rutgon() {
    int ucln = gcd(abs(TuSo), abs(MauSo));
    TuSo /= ucln;
    MauSo /= ucln;
    if (MauSo < 0) {
        TuSo = -TuSo;
        MauSo = -MauSo;
    }
}

void PhanSo::nhap() {
    cin >> TuSo >> MauSo;
    while (MauSo == 0) {
        cout << "Error! Mau so phai khac 0, nhap lai: ";
        cin >> MauSo;
    }
}

void PhanSo::xuat() {
    rutgon();
    if (TuSo % MauSo == 0)
        cout << TuSo / MauSo;
    else
        cout << TuSo << "/" << MauSo << " ";
}

PhanSo PhanSo::cong(PhanSo x) {
    PhanSo result;
    result.TuSo = TuSo * x.MauSo + x.TuSo * MauSo;
    result.MauSo = MauSo * x.MauSo;
    result.rutgon();
    return result;
}

PhanSo PhanSo::tru(PhanSo x) {
    PhanSo result;
    result.TuSo = TuSo * x.MauSo - x.TuSo * MauSo;
    result.MauSo = MauSo * x.MauSo;
    result.rutgon();
    return result;
}

PhanSo PhanSo::nhan(PhanSo x) {
    PhanSo result;
    result.TuSo = TuSo * x.TuSo;
    result.MauSo = MauSo * x.MauSo;
    result.rutgon();
    return result;
}

PhanSo PhanSo::chia(PhanSo x) {
    if (x.TuSo == 0) {
        cout << "Error! Khong the chia cho 0." << endl;
        exit(1);
    }
    PhanSo result;
    result.TuSo = TuSo * x.MauSo;
    result.MauSo = MauSo * x.TuSo;
    result.rutgon();
    return result;
}

int main() {
    PhanSo a, b;
    cout << "Phan so thu nhat: ";
    a.nhap();
    cout << "Phan so thu hai: ";
    b.nhap();
    cout << "Tong: ";
    a.cong(b).xuat();
    cout << endl;
    cout << "Hieu: ";
    a.tru(b).xuat();
    cout << endl;
    cout << "Tich: ";
    a.nhan(b).xuat();
    cout << endl;
    cout << "Thuong: ";
    a.chia(b).xuat();
    cout << endl;
    return 0;
}
