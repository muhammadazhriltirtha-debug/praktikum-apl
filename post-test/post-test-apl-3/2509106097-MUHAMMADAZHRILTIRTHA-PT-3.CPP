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

void tampilData(Toko dataToko[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "Data kosong!\n";
        return; 
    }

    for (int i = 0; i < jumlahData; i++) {
        cout << i+1 << ". "
             << dataToko[i].data.namaSayur
             << " | Harga: " << dataToko[i].data.harga
             << " | Stok: " << dataToko[i].data.stok << endl;
    }
}

int tambahData(Toko dataToko[], int jumlahData) {
    cout << "Nama Sayur: ";
    cin >> dataToko[jumlahData].data.namaSayur;

    cout << "Harga: ";
    cin >> dataToko[jumlahData].data.harga;

    cout << "Stok: ";
    cin >> dataToko[jumlahData].data.stok;

    cout << "Data berhasil ditambah!\n";

    return jumlahData + 1; 
}

void ubahData(Toko dataToko[], int jumlahData) {
    int nomorDipilih;

    tampilData(dataToko, jumlahData);

    cout << "Pilih nomor: ";
    cin >> nomorDipilih;

    if (nomorDipilih > 0 && nomorDipilih <= jumlahData) {
        cout << "Nama baru: ";
        cin >> dataToko[nomorDipilih-1].data.namaSayur;

        cout << "Harga baru: ";
        cin >> dataToko[nomorDipilih-1].data.harga;

        cout << "Stok baru: ";
        cin >> dataToko[nomorDipilih-1].data.stok;

        cout << "Data berhasil diubah!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

int hapusData(Toko dataToko[], int jumlahData) {
    int nomorDipilih;

    tampilData(dataToko, jumlahData);

    cout << "Pilih nomor: ";
    cin >> nomorDipilih;

    if (nomorDipilih > 0 && nomorDipilih <= jumlahData) {
        for (int i = nomorDipilih-1; i < jumlahData-1; i++) {
            dataToko[i] = dataToko[i+1];
        }

        cout << "Data berhasil dihapus!\n";
        return jumlahData - 1;
    } else {
        cout << "Nomor tidak valid!\n";
        return jumlahData;
    }
}

bool login(User dataUser[], int jumlahUser) {
    string namaInput, nimInput;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "Nama: ";
        cin >> namaInput;

        cout << "NIM: ";
        cin >> nimInput;

        for (int i = 0; i < jumlahUser; i++) {
            if (namaInput == dataUser[i].nama && nimInput == dataUser[i].nim) {
                return true; 
            }
        }

        percobaan++;
        cout << "Login gagal!\n";
    }

    return false;
}

void registerUser(User dataUser[], int &jumlahUser) {
    cout << "Nama: ";
    cin >> dataUser[jumlahUser].nama;

    cout << "NIM: ";
    cin >> dataUser[jumlahUser].nim;

    jumlahUser++; 
    cout << "Register berhasil!\n";
}

int main() {

    User dataUser[MAX_USER];
    Toko dataToko[MAX];

    int jumlahUser = 0;
    int jumlahData = 0;

    int pilihanAwal, pilihanMenu;

    do {
        cout << "\n=== MENU AWAL ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihanAwal;

        if (pilihanAwal == 1) {
            registerUser(dataUser, jumlahUser); 
        }

        else if (pilihanAwal == 2) {
            if (login(dataUser, jumlahUser)) {

                do {
                    cout << "\n=== TOKO SAYUR ===\n";
                    cout << "1. Tambah\n";
                    cout << "2. Lihat\n";
                    cout << "3. Ubah\n";
                    cout << "4. Hapus\n";
                    cout << "5. Keluar\n";
                    cout << "Pilih: ";
                    cin >> pilihanMenu;

                    switch (pilihanMenu) {
                        case 1:
                            jumlahData = tambahData(dataToko, jumlahData);
                            break;
                        case 2:
                            tampilData(dataToko, jumlahData);
                            break;
                        case 3:
                            ubahData(dataToko, jumlahData);
                            break;
                        case 4:
                            jumlahData = hapusData(dataToko, jumlahData);
                            break;
                    }

                } while (pilihanMenu != 5);

            } else {
                cout << "Login gagal 3x!\n";
            }
        }

    } while (pilihanAwal != 3);

    return 0;
}