#include <iostream>
using namespace std;
struct Alamat {
string jalan;
int nomor;
string kota;
};
struct Mahasiswa {
string nama;
int umur;
string jurusan;
Alamat alamat;
};
#define MAX_MAHASISWA 100
int panjang = 0;
Mahasiswa mhs[MAX_MAHASISWA];
int main() {
int pilihan, index;
do {
cout <<" Menu Manajemen Mahasiswa " < endl;
cout << "==============================" < endl;
cout << "1. Tampilkan Data Mahasiswa" << endl;
cout << "2. Tambah Data Mahasiswa" << endl;
cout << "3. Ubah Data Mahasiswa" << endl;
cout << "4. Hapus Data Mahasiswa" << endl;
cout << "5. Keluar" << endl;
cout << "Pilihan: ";
cin >> pilihan;
switch (pilihan) {
case 1: * . READ . / break;
case 2: * . CREATE . / break;
case 3: * . UPDATE . / break;
case 4: * . DELETE . / break;
case 5: cout < "Sampai jumpa!" < endl; break;
default: cout < "Pilihan tidak valid!" < endl; break;
}
} while (pilihan = 5);
return 0;
}