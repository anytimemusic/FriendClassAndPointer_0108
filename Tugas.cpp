#include <iostream>
using namespace std;

class BelahKetupat; // forward declaration

class LayangLayang {
private:
    double d1, d2;
    double sisi1, sisi2;

public:
    void inputData() {
        cout << "=== Input Layang-Layang ===\n";
        cout << "Diagonal 1 : "; cin >> d1;
        cout << "Diagonal 2 : "; cin >> d2;
        cout << "Sisi 1     : "; cin >> sisi1;
        cout << "Sisi 2     : "; cin >> sisi2;
    }

    double hitungLuas() const {
        return 0.5 * d1 * d2;
    }

    void tampilLuas() const {
        cout << "Luas Layang-Layang : " << hitungLuas() << endl;
    }

    // friend function
    friend void tampilkanKeliling(const LayangLayang&, const BelahKetupat&);
};

class BelahKetupat {
private:
    double d1, d2;
    double sisi;

public:
    void inputData() {
        cout << "\n=== Input Belah Ketupat ===\n";
        cout << "Diagonal 1 : "; cin >> d1;
        cout << "Diagonal 2 : "; cin >> d2;
        cout << "Sisi       : "; cin >> sisi;
    }

    double hitungLuas() const {
        return 0.5 * d1 * d2;
    }

    double hitungKeliling() const {
        return 4 * sisi;
    }

    void tampilLuas() const {
        cout << "Luas Belah Ketupat : " << hitungLuas() << endl;
    }

    friend void tampilkanKeliling(const LayangLayang&, const BelahKetupat&);
};

// friend function
void tampilkanKeliling(const LayangLayang& l, const BelahKetupat& b) {
    double kelLayang = 2 * (l.sisi1 + l.sisi2);
    double kelBelah  = 4 * b.sisi;

    cout << "\n=== DATA KELILING ===\n";
    cout << "Keliling Layang-Layang : " << kelLayang << endl;
    cout << "Keliling Belah Ketupat : " << kelBelah << endl;
}

int main() {
    LayangLayang LL;
    BelahKetupat BK;

    LL.inputData();
    BK.inputData();

    cout << "\n=== DATA LUAS ===\n";
    LL.tampilLuas();
    BK.tampilLuas();

    tampilkanKeliling(LL, BK);

    return 0;
}