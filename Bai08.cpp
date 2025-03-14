#include <iostream>
using namespace std;

class NTN {
private:
    int day, month, year;
public:
    void nhap();
    void xuatThu();
    int tinhThu();
};

void NTN::nhap() {
    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> day >> month >> year;
}

int NTN::tinhThu() {
    int d = day;
    int m = month;
    int y = year;
    if (m == 1 || m == 2) {
        m += 12;
        y -= 1;
    }
    int K = y % 100;
    int J = y / 100;
    int h = (d + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;
    return h;
}

void NTN::xuatThu() {
    string thu[] = {"Thu Bay", "Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau"};
    cout << "Ngay nay la: " << thu[tinhThu()] << endl;
}

int main() {
    NTN ngay;
    ngay.nhap();
    ngay.xuatThu();
    return 0;
}
