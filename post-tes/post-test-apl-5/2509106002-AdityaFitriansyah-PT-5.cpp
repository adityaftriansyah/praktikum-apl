#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

#define MAX 100

struct Aspirasi {
    string nama;
    string isi;
    string lokasi;
    string status;
};

// LOGIN
bool login() {
    string user, pass;
    cout << "Login\nNama: "; cin >> user;
    cout << "NIM : "; cin >> pass;
    return (user == "aditya" && pass == "002");
}

// TAMBAH (POINTER *)
void tambah(Aspirasi *a, int *jumlah) {

    if (*jumlah < MAX) {

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nama : ";
        getline(cin, (a + *jumlah)->nama);

        cout << "Isi : ";
        getline(cin, (a + *jumlah)->isi);

        cout << "Lokasi : ";
        getline(cin, (a + *jumlah)->lokasi);

        (a + *jumlah)->status = "diajukan";

        (*jumlah)++;

        cout << "Data berhasil ditambah!\n";
    } else {
        cout << "Data penuh!\n";
    }
}

// TAMPIL
void tampil(Aspirasi *a, int jumlah) {

    if (jumlah == 0) {
        cout << "Data kosong\n";
        return;
    }

    cout << "\n=== DATA ASPIRASI ===\n";

    for (int i = 0; i < jumlah; i++) {
        cout << i+1 << ". "
             << (a+i)->nama << " | "
             << (a+i)->lokasi << " | "
             << (a+i)->status << endl;
    }
}

// UBAH (KONFIRMASI + POINTER)
void ubah(Aspirasi *a, int jumlah) {

    int no;
    cout << "Nomor: "; cin >> no;

    if (no > 0 && no <= jumlah) {

        char y;
        cout << "Yakin ubah data? (y/t): ";
        cin >> y;

        if (y == 'y' || y == 'Y') {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Isi baru: ";
            getline(cin, (a+no-1)->isi);

            cout << "Status (1.diajukan 2.diproses 3.selesai): ";
            int s; cin >> s;

            if (s == 1) (a+no-1)->status = "diajukan";
            else if (s == 2) (a+no-1)->status = "diproses";
            else if (s == 3) (a+no-1)->status = "selesai";

            cout << "Data berhasil diubah\n";
        } else {
            cout << "Batal ubah\n";
        }

    } else {
        cout << "Nomor tidak valid\n";
    }
}

// HAPUS (POINTER + KONFIRMASI)
void hapus(Aspirasi *a, int *jumlah) {

    int no;
    cout << "Nomor: "; cin >> no;

    if (no > 0 && no <= *jumlah) {

        char y;
        cout << "Yakin hapus data? (y/t): ";
        cin >> y;

        if (y == 'y' || y == 'Y') {

            for (int i = no-1; i < *jumlah-1; i++) {
                *(a+i) = *(a+i+1);
            }

            (*jumlah)--;

            cout << "Data berhasil dihapus\n";
        } else {
            cout << "Batal hapus\n";
        }

    } else {
        cout << "Nomor tidak valid\n";
    }
}

// CARI
int cari(Aspirasi *a, int jumlah, string nama) {
    for (int i = 0; i < jumlah; i++) {
        if ((a+i)->nama == nama) return i;
    }
    return -1;
}

void menuCari(Aspirasi *a, int jumlah) {

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string nama;
    cout << "Cari nama: ";
    getline(cin, nama);

    int index = cari(a, jumlah, nama);

    if (index != -1) {
        cout << "Ditemukan: " << (a+index)->isi << endl;
    } else {
        cout << "Data tidak ditemukan\n";
    }
}

// STATISTIK
void statistik(Aspirasi *a, int jumlah) {

    int a1=0, a2=0, a3=0;

    for (int i = 0; i < jumlah; i++) {
        if ((a+i)->status == "diajukan") a1++;
        else if ((a+i)->status == "diproses") a2++;
        else if ((a+i)->status == "selesai") a3++;
    }

    cout << "\nSTATISTIK\n";
    cout << "Diajukan: " << a1 << endl;
    cout << "Diproses: " << a2 << endl;
    cout << "Selesai : " << a3 << endl;
    cout << "Total   : " << jumlah << endl;
}

// RESET (&)
void resetData(int &jumlah) {

    char y;
    cout << "Yakin kah mau reset semua data? (y/t): ";
    cin >> y;

    if (y == 'y' || y == 'Y') {
        jumlah = 0;
        cout << "Semua data berhasil direset\n";
    } else {
        cout << "Batal reset\n";
    }
}

// MAIN
int main() {

    Aspirasi data[MAX]; // tanpa global
    int jumlah = 0;

    if (!login()) {
        cout << "Login gagal, coba lagi\n";
        return 0;
    }

    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah\n2. Tampil\n3. Ubah\n4. Hapus\n";
        cout << "5. Cari\n6. Statistik\n7. Reset\n8. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tambah(data, &jumlah); break;
            case 2: tampil(data, jumlah); break;
            case 3: ubah(data, jumlah); break;
            case 4: hapus(data, &jumlah); break;
            case 5: menuCari(data, jumlah); break;
            case 6: statistik(data, jumlah); break;
            case 7: resetData(jumlah); break;
            case 8: cout << "Program selesai terimaksih\n"; break;
            default: cout << "Menu tidak ada\n";
        }

    } while (pilih != 8);

    return 0;
}