#include <bits/stdc++.h>
using namespace std;

class NTN {
private:
    long long day, month, year;
public:
    NTN() : day(1), month(1), year(1) {}
    NTN(long long d, long long m, long long y) : day(d), month(m), year(y) {}
    void nhap();
    void xuat();
    bool isLeapYear();
    bool isValidDate();
    NTN getNextDate();
};

void NTN::nhap() {
    cin >> day >> month >> year;
}

void NTN::xuat() {
    cout << day << '/' << month << '/' << year;
}

bool NTN::isValidDate() {
    if (year < 1 || day < 1)
        return false;
    if (month < 1 || month > 12)
        return false;
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31))
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
        return false;
    if ((isLeapYear() && month == 2 && day > 29) || (!isLeapYear() && month == 2 && day > 28))
        return false;
    return true;
}

bool NTN::isLeapYear(){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

NTN NTN::getNextDate() {
    NTN tempDate(day + 1, month, year);
    if (tempDate.day > 31) {
        tempDate.day = 1;
        tempDate.month++;
        if (tempDate.month > 12) {
            tempDate.month = 1;
            tempDate.year++;
        }
    }
    else if (tempDate.day > 30) {
        if (tempDate.month == 4 || tempDate.month == 6 || tempDate.month == 9 || tempDate.month == 11)
        {
            tempDate.day = 1;
            tempDate.month++;
        }
    }
    else if (tempDate.month == 2) {
        if (isLeapYear()) {
            if (tempDate.day > 29)
            {
                tempDate.day = 1;
                tempDate.month++;
            }
        }
        else {
            if (tempDate.day > 28)
            {
                tempDate.day = 1;
                tempDate.month++;
            }
        }
    }
    return tempDate;
}

int main() {
    NTN x;
    x.nhap();
    NTN nextDay = x.getNextDate();
    nextDay.xuat();
    return 0;
}
