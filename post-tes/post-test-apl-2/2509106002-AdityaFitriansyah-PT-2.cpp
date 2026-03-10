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

int main(){

    string username;
    string password;

    int percobaan = 0;
    bool login = false;

    while(percobaan < 3 && login == false){

        cout << "===== LOGIN SISTEM =====" << endl;
        cout << "Masukkan Nama : ";
        cin >> username;
        cout << "Masukkan NIM  : ";
        cin >> password;

        if(username == admin.nama && password == admin.nim){
            login = true;
            cout << "login berhasil" << endl;
        }else{
            percobaan++;
            cout << "login salah, silakan coba lagi sod" << endl;
        }
    }

    if(login == false){
        cout << "Kesempatan login lu dah habis" << endl;
        return 0;
    }

    int pilihan;

    do{

        cout << "\nSISTEM MANAJEMEN ASPIRASI DPRD PROV KALTIM" << endl;
        cout << "1. Tambah Aspirasi" << endl;
        cout << "2. Lihat Aspirasi" << endl;
        cout << "3. Ubah Aspirasi" << endl;
        cout << "4. Hapus Aspirasi" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch(pilihan){

        case 1:

            if(jumlah < MAX_ASPIRASI){

                cin.ignore();

                cout << "Nama Pengirim : ";
                getline(cin, aspirasi[jumlah].namaPengirim);

                cout << "Isi Aspirasi : ";
                getline(cin, aspirasi[jumlah].isiAspirasi);

                cout << "Lokasi : ";
                getline(cin, aspirasi[jumlah].lokasi);

                aspirasi[jumlah].status = "Diajukan";

                jumlah++;

                cout << "Aspirasi berhasil ditambahkan." << endl;

            }else{
                cout << "Data sudah penuh." << endl;
            }

            break;

        case 2: 

            if(jumlah == 0){

                cout << "Belum ada data aspirasi." << endl;

            }else{

                cout << "\n===========================================================================" << endl;

                cout << left << setw(5) << "NO"
                     << setw(20) << "Nama Pengirim"
                     << setw(15) << "Lokasi"
                     << setw(12) << "Status"
                     << "Isi Aspirasi" << endl;

                cout << "===========================================================================" << endl;

                for(int i = 0; i < jumlah; i++){

                    cout << left << setw(5) << i+1
                         << setw(20) << aspirasi[i].namaPengirim
                         << setw(15) << aspirasi[i].lokasi
                         << setw(12) << aspirasi[i].status
                         << aspirasi[i].isiAspirasi << endl;
                }

                cout << "===========================================================================" << endl;
            }

            break;

        case 3: 

            int nomor;

            cout << "Masukkan nomor aspirasi yang ingin diubah: ";
            cin >> nomor;

            if(nomor > 0 && nomor <= jumlah){

                cin.ignore();

                cout << "Isi aspirasi baru : ";
                getline(cin, aspirasi[nomor-1].isiAspirasi);

                cout << "Status (Diajukan/Diproses/Selesai) : ";
                getline(cin, aspirasi[nomor-1].status);

                cout << "Data berhasil diubah." << endl;

            }else{
                cout << "Nomor tidak diketahui." << endl;
            }

            break;

        case 4:

            int hapus;

            cout << "Masukkan nomor aspirasi yang ingin dihapus: ";
            cin >> hapus;

            if(hapus > 0 && hapus <= jumlah){

                for(int i = hapus-1; i < jumlah-1; i++){
                    aspirasi[i] = aspirasi[i+1];
                }

                jumlah--;

                cout << "Data berhasil dihapus." << endl;

            }else{
                cout << "Nomor tidak diketahuii." << endl;
            }

            break;

        case 5:
            cout << "Program selesai, Sampai Jumpa Lagi cess" << endl;
            break;

        default:
            cout << "Pilihan tidak ada." << endl;
        }

    }while(pilihan != 5);

}