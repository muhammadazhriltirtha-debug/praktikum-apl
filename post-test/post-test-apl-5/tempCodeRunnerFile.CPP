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
