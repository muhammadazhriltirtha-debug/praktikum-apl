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

void tampilData(Toko *dataToko, int jumlahData) {
    if (jumlahData == 0) {
        cout << "Data kosong!\n";
    } else {
        for (int i = 0; i < jumlahData; i++) {
            cout << i+1 << ". "
                 << (dataToko+i)->data.namaSayur
                 << " | Harga: " << (dataToko+i)->data.harga
                 << " | Stok: " << (dataToko+i)->data.stok << endl;
        }
    }
}

void tambahData(Toko *dataToko, int *jumlahData) {
    cout << "Nama Sayur: ";
    cin >> (dataToko + *jumlahData)->data.namaSayur;

    cout << "Harga: ";
    cin >> (dataToko + *jumlahData)->data.harga;

    cout << "Stok: ";
    cin >> (dataToko + *jumlahData)->data.stok;

    *jumlahData = *jumlahData + 1; 
}

void hapusData(Toko *dataToko, int *jumlahData) {
    int nomor;

    tampilData(dataToko, *jumlahData);

    cout << "Pilih nomor: ";
    cin >> nomor;

    if (nomor > 0 && nomor <= *jumlahData) {
        for (int i = nomor-1; i < *jumlahData-1; i++) {
            *(dataToko+i) = *(dataToko+i+1);
        }

        *jumlahData = *jumlahData - 1; 
    }
}

bool login(User *dataUser, int jumlahUser) {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "Nama: ";
        cin >> nama;
        cout << "NIM: ";
        cin >> nim;

        for (int i = 0; i < jumlahUser; i++) {
            if (nama == (dataUser+i)->nama &&
                nim == (dataUser+i)->nim) {
                return true;
            }
        }

        percobaan++;
        cout << "Login gagal\n";
    }

    return false;
}

int main() {

    User dataUser[MAX_USER];
    Toko dataToko[MAX];

    int jumlahUser = 0;
    int jumlahData = 0;

    int menuAwal, menu;

    do {
        cout << "\n1. Register\n2. Login\n3. Keluar\nPilih: ";
        cin >> menuAwal;

        if (menuAwal == 1) {
            cout << "Nama: ";
            cin >> dataUser[jumlahUser].nama;
            cout << "NIM: ";
            cin >> dataUser[jumlahUser].nim;

            jumlahUser++;
        }

        else if (menuAwal == 2) {
            if (login(dataUser, jumlahUser)) {

                do {
                    cout << "\n1. Tambah\n2. Lihat\n3. Hapus\n4. Keluar\nPilih: ";
                    cin >> menu;

                    switch (menu) {
                        case 1:
                            tambahData(dataToko, &jumlahData); 
                            break;

                        case 2:
                            tampilData(dataToko, jumlahData);
                            break;

                        case 3:
                            hapusData(dataToko, &jumlahData); 
                            break;
                    }

                } while (menu != 4);
            }
        }

    } while (menuAwal != 3);

    return 0;
}