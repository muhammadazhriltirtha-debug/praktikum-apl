#include <iostream>
using namespace std;

#define MAX 100
#define MAX_USER 10

struct User {
    string nama;
    string nim;
};


struct Sayur {
    string namaSayur;
    int harga;
    int stok;
};

struct Toko {
    Sayur data;
};

int main() {

    
    User user[MAX_USER];
    Toko toko[MAX];

    int jumlahUser = 0;
    int jumlahData = 0;

    int pilihanAwal, pilihanMenu;
    int i, index;

    
    do {
        cout << "\n=== MENU AWAL ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihanAwal;

        
        if (pilihanAwal == 1) {
            cout << "Nama: ";
            cin >> user[jumlahUser].nama;
            cout << "NIM: ";
            cin >> user[jumlahUser].nim;

            jumlahUser++;
            cout << "Register berhasil!\n";
        }

        
        else if (pilihanAwal == 2) {
            string nama, nim;
            int percobaan = 0;
            bool berhasil = false;

            while (percobaan < 3 && berhasil == false) {
                cout << "\n=== LOGIN ===\n";
                cout << "Nama: ";
                cin >> nama;
                cout << "NIM: ";
                cin >> nim;

                for (i = 0; i < jumlahUser; i++) {
                    if (nama == user[i].nama && nim == user[i].nim) {
                        berhasil = true;
                    }
                }

                if (berhasil == false) {
                    percobaan++;
                    cout << "Login gagal!\n";
                }
            }

            if (berhasil == false) {
                cout << "Gagal login 3x, program berhenti!\n";
                return 0;
            }

            
            do {
                cout << "\n=== TOKO SAYUR ===\n";
                cout << "1. Tambah Data\n";
                cout << "2. Lihat Data\n";
                cout << "3. Ubah Data\n";
                cout << "4. Hapus Data\n";
                cout << "5. Keluar\n";
                cout << "Pilih: ";
                cin >> pilihanMenu;

                switch (pilihanMenu) {

                
                case 1:
                    if (jumlahData < MAX) {
                        cout << "Nama Sayur: ";
                        cin >> toko[jumlahData].data.namaSayur;
                        cout << "Harga: ";
                        cin >> toko[jumlahData].data.harga;
                        cout << "Stok: ";
                        cin >> toko[jumlahData].data.stok;

                        jumlahData++;
                        cout << "Data berhasil ditambah!\n";
                    } else {
                        cout << "Data penuh!\n";
                    }
                    break;

                
                case 2:
                    if (jumlahData == 0) {
                        cout << "Data kosong!\n";
                    } else {
                        cout << "\n=== DATA SAYUR ===\n";
                        for (i = 0; i < jumlahData; i++) {
                            cout << "No " << i+1 << endl;
                            cout << "Nama  : " << toko[i].data.namaSayur << endl;
                            cout << "Harga : " << toko[i].data.harga << endl;
                            cout << "Stok  : " << toko[i].data.stok << endl;
                            cout << "---------------------\n";
                        }
                    }
                    break;

                
                case 3:
                    if (jumlahData == 0) {
                        cout << "Data kosong!\n";
                    } else {
                        for (i = 0; i < jumlahData; i++) {
                            cout << i+1 << ". " << toko[i].data.namaSayur << endl;
                        }

                        cout << "Pilih nomor: ";
                        cin >> index;

                        if (index > 0 && index <= jumlahData) {
                            cout << "Nama baru: ";
                            cin >> toko[index-1].data.namaSayur;
                            cout << "Harga baru: ";
                            cin >> toko[index-1].data.harga;
                            cout << "Stok baru: ";
                            cin >> toko[index-1].data.stok;

                            cout << "Data berhasil diubah!\n";
                        } else {
                            cout << "Nomor tidak valid!\n";
                        }
                    }
                    break;

                
                case 4:
                    if (jumlahData == 0) {
                        cout << "Data kosong!\n";
                    } else {
                        for (i = 0; i < jumlahData; i++) {
                            cout << i+1 << ". " << toko[i].data.namaSayur << endl;
                        }

                        cout << "Pilih nomor: ";
                        cin >> index;

                        if (index > 0 && index <= jumlahData) {
                            for (i = index-1; i < jumlahData-1; i++) {
                                toko[i] = toko[i+1];
                            }
                            jumlahData--;
                            cout << "Data berhasil dihapus!\n";
                        } else {
                            cout << "Nomor tidak valid!\n";
                        }
                    }
                    break;

                case 5:
                    cout << "Keluar menu.\n";
                    break;

                default:
                    cout << "Pilihan tidak valid!\n";
                }

            } while (pilihanMenu != 5);
        }

    } while (pilihanAwal != 3);

    cout << "Program selesai.\n";
    return 0;
}