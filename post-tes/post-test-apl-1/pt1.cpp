#include <iostream>
using namespace std;

int main() {
    string nama, password;
    int batas = 0;

    while (batas < 3) {
        cout << "\nlogin dulu cess\n";
        cout << "Nama : ";
        cin >> nama;
        cout << "Password (3 digit NIM terakhir) : ";
        cin >> password;

        if (nama == "aditya" && password == "002") {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Salah!\n";
            batas++;
        }
    }

    if (batas == 3) {
        cout << "terlalu banyak kesalahan, silahkan coba lagi sod\n";
        return 0;
    }

    int pilih;

    do {
        cout << "\n----------------------\n";
        cout << "1. Jam to Menit & Detik\n";
        cout << "2. Menit to Jam & Detik\n";
        cout << "3. Detik to Jam & Menit\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilih;

        if (pilih == 1) {
            int j;
            cout << "Masukkan jam : ";
            cin >> j;
            cout << j << " jam = "
                 << j*60 << " menit dan "
                 << j*3600 << " detik\n";
        }
        else if (pilih == 2) {
            int m;
            cout << "Masukkan menit : ";
            cin >> m;
            cout << m << " menit = "
                 << m/60 << " jam "
                 << m%60 << " menit dan "
                 << m*60 << " detik\n";
        }
        else if (pilih == 3) {
            int d;
            cout << "Masukkan detik : ";
            cin >> d;
            cout << d << " detik = "
                 << d/3600 << " jam "
                 << (d%3600)/60 << " menit\n";
        }

    } while (pilih != 4);

    cout << "\nProgram selesai, Thank you\n";
    return 0;
}