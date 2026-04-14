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

// ================= BUBBLE SORT (NAMA SAYUR ASCENDING) =================
void bubbleSortNama(Toko *dataToko, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((dataToko+j)->data.namaSayur > (dataToko+j+1)->data.namaSayur) {
                swap(*(dataToko+j), *(dataToko+j+1));
            }
        }
    }
}

// ================= SELECTION SORT (HARGA DESCENDING) =================
void selectionSortHarga(Toko *dataToko, int n) {
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if ((dataToko+j)->data.harga > (dataToko+max)->data.harga) {
                max = j;
            }
        }
        swap(*(dataToko+i), *(dataToko+max));
    }
}

// ================= INSERTION SORT (STOK ASCENDING) =================
void insertionSortStok(Toko *dataToko, int n) {
    for (int i = 1; i < n; i++) {
        Toko key = *(dataToko+i);
        int j = i - 1;

        while (j >= 0 && (dataToko+j)->data.stok > key.data.stok) {
            *(dataToko+j+1) = *(dataToko+j);
            j--;
        }
        *(dataToko+j+1) = key;
    }
}

// ================= TAMPIL DATA =================
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

// ================= TAMBAH =================
void tambahData(Toko *dataToko, int *jumlahData) {
    cout << "Nama Sayur: ";
    cin >> (dataToko + *jumlahData)->data.namaSayur;

    cout << "Harga: ";
    cin >> (dataToko + *jumlahData)->data.harga;

    cout << "Stok: ";
    cin >> (dataToko + *jumlahData)->data.stok;

    (*jumlahData)++;
}

// ================= HAPUS =================
void hapusData(Toko *dataToko, int *jumlahData) {
    int nomor;

    tampilData(dataToko, *jumlahData);
    cout << "Pilih nomor: ";
    cin >> nomor;

    if (nomor > 0 && nomor <= *jumlahData) {
        for (int i = nomor-1; i < *jumlahData-1; i++) {
            *(dataToko+i) = *(dataToko+i+1);
        }
        (*jumlahData)--;
    }
}

// ================= LOGIN =================
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

// ================= MAIN =================
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
                    cout << "\n1. Tambah\n2. Lihat\n3. Hapus\n4. Sort Nama (ASC)\n5. Sort Harga (DESC)\n6. Sort Stok (ASC)\n7. Keluar\nPilih: ";
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
                        case 4:
                            bubbleSortNama(dataToko, jumlahData);
                            cout << "Data berhasil diurutkan (Nama ASC)\n";
                            break;
                        case 5:
                            selectionSortHarga(dataToko, jumlahData);
                            cout << "Data berhasil diurutkan (Harga DESC)\n";
                            break;
                        case 6:
                            insertionSortStok(dataToko, jumlahData);
                            cout << "Data berhasil diurutkan (Stok ASC)\n";
                            break;
                    }

                } while (menu != 7);
            }
        }

    } while (menuAwal != 3);

    return 0;
}