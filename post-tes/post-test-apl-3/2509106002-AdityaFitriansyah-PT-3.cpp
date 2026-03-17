#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_ASPIRASI 100

struct User {
    string nama;
    string nim;
};

struct Aspirasi {
    string namaPengirim;
    string isiAspirasi;
    string lokasi;
    string status;
};


User admin = {"aditya", "002"};
Aspirasi aspirasi[MAX_ASPIRASI];
int jumlah = 0;


bool cekLogin(string username, string password) {
    if (username == admin.nama && password == admin.nim) {
        return true;
    } else {
        return false;
    }
}


int hitungTotal(int data) {
    return data;
}


int cariIndex(string nama) {
    for (int i = 0; i < jumlah; i++) {
        if (aspirasi[i].namaPengirim == nama) {
            return i;
        }
    }
    return -1;
}


bool dataKosong(int jumlahData) {
    if (jumlahData == 0) {
        return true;
    } else {
        return false;
    }
}



void garis() {
    cout << "====================================================================" << endl;
}

void header() {
    cout << "\n===== SISTEM ASPIRASI DPRD Prov KALTIM =====" << endl;
}

void menu() {
    cout << "\n1. Tambah Aspirasi" << endl;
    cout << "2. Lihat Aspirasi" << endl;
    cout << "3. Ubah Aspirasi" << endl;
    cout << "4. Hapus Aspirasi" << endl;
    cout << "5. Cari Data Aspirasi" << endl;
    cout << "6. Statistik Data Aspirasi" << endl;
    cout << "7. Reset Semua Data" << endl;
    cout << "8. Keluar" << endl;
    cout << "Pilih : ";
}


void tambah() {

    if (jumlah < MAX_ASPIRASI) {

        cin.ignore();

        cout << "Nama : ";
        getline(cin, aspirasi[jumlah].namaPengirim);

        cout << "Isi Aspirasi : ";
        getline(cin, aspirasi[jumlah].isiAspirasi);

        cout << "Lokasi : ";
        getline(cin, aspirasi[jumlah].lokasi);

        aspirasi[jumlah].status = "Diajukan";

        jumlah++;

        cout << "data aspirasi berhasil ditambah!\n";

    } else {
        cout << "Data aspirasi penuh bro\n";
    }
}


void tampil() {

    if (dataKosong(jumlah)) {
        cout << "Data aspirasi kosong.\n";
        return;
    }

    garis();

    cout << left << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(15) << "Lokasi"
         << setw(12) << "Status"
         << "Isi" << endl;

    garis();

    for (int i = 0; i < jumlah; i++) {

        cout << left << setw(5) << i + 1
             << setw(20) << aspirasi[i].namaPengirim
             << setw(15) << aspirasi[i].lokasi
             << setw(12) << aspirasi[i].status
             << aspirasi[i].isiAspirasi << endl;
    }

    garis();
}

void tampilStatus() {
    cout << "\nDaftar Status Aspirasi:" << endl;
    cout << "1. diajukan" << endl;
    cout << "2. diproses" << endl;
    cout << "3. selesai" << endl;
}

void ubah() {

    int nomor;
    int pilihStatus;

    cout << "Nomor yang diubah: ";
    cin >> nomor;

    if (nomor > 0 && nomor <= jumlah) {

        cin.ignore();

        cout << "Isi aspirasi baru: ";
        getline(cin, aspirasi[nomor - 1].isiAspirasi);

        tampilStatus();

        cout << "Pilih status (1/2/3): ";
        cin >> pilihStatus;

        if (pilihStatus == 1) {
            aspirasi[nomor - 1].status = "diajukan";
        }
        else if (pilihStatus == 2) {
            aspirasi[nomor - 1].status = "diproses";
        }
        else if (pilihStatus == 3) {
            aspirasi[nomor - 1].status = "selesai";
        }
        else {
            cout << "Status tidak valid, default ke Diajukan.\n";
            aspirasi[nomor - 1].status = "Diajukan";
        }

        cout << "Data berhasil diubah\n";

    } else {
        cout << "data tidak valid cobalgi\n";
    }
}

void hapus() {

    int nomor;

    cout << "Nomor dihapus: ";
    cin >> nomor;

    if (nomor > 0 && nomor <= jumlah) {

        for (int i = nomor - 1; i < jumlah - 1; i++) {
            aspirasi[i] = aspirasi[i + 1];
        }

        jumlah--;

        cout << "Data aspirasi terhapus\n";

    } else {
        cout << "Gagal hapus aspirasi cbalagi\n";
    }
}

void cari() {

    cin.ignore();

    string nama;

    cout << "Cari nama: ";
    getline(cin, nama);

    int index = cariIndex(nama);

    if (index != -1) {
        cout << "Aspirasi ketemu: " << aspirasi[index].isiAspirasi << endl;
    } else {
        cout << "Aspirasi tidak ketemu cobalgi\n";
    }
}

void statistik() {

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < jumlah; i++) {

        if (aspirasi[i].status == "diajukan") a++;
        else if (aspirasi[i].status == "diproses") b++;
        else if (aspirasi[i].status == "selesai") c++;
    }

    cout << "\nSTATISTIK\n";
    cout << "diajukan : " << a << endl;
    cout << "diproses : " << b << endl;
    cout << "selesai  : " << c << endl;
    cout << "Total    : " << hitungTotal(jumlah) << endl;
}

void resetData() {

    char konfirmasi;

    cout << "Yakin reset semua data? (y/t): ";
    cin >> konfirmasi;

    if (konfirmasi == 'y') {

        jumlah = 0;

        cout << "Semua data dihapus\n";

    } else {
        cout << "Batal reset\n";
    }
}


void prosesLogin() {

    string username, password;
    int percobaan = 0;
    bool login = false;

    while (percobaan < 3 && login == false) {

        cout << "\nLOGIN SISTEM\n";
        cout << "Nama : ";
        cin >> username;
        cout << "NIM  : ";
        cin >> password;

        login = cekLogin(username, password);

        if (login) {
            cout << "Berhasil masuk!\n";
        } else {
            percobaan++;
            cout << "Salah, coba lagi!!!\n";
        }
    }

    if (!login) {
        cout << "Akses login ditolak\n";
        exit(0);
    }
}


int main() {

    prosesLogin();

    int pilih;

    do {

        header();
        menu();
        cin >> pilih;

        if (pilih == 1) {
            tambah();
        }
        else if (pilih == 2) {
            tampil();
        }
        else if (pilih == 3) {
            ubah();
        }
        else if (pilih == 4) {
            hapus();
        }
        else if (pilih == 5) {
            cari();
        }
        else if (pilih == 6) {
            statistik();
        }
        else if (pilih == 7) {
            resetData();
        }
        else if (pilih == 8) {
            cout << "program selesai, sampai jumpa kembali\n";
        }
        else {
            cout << "Menu tidak ada\n";
        }

    } while (pilih != 8);

    return 0;
}