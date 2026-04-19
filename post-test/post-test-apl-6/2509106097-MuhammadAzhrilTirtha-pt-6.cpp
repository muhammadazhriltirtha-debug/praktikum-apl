#include <iostream>
using namespace std;

#define MAX 100

struct Sayur {
    int id;
    string nama;
    int harga;
};

int binarySearch(Sayur *data, int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if ((data+mid)->id == target)
            return mid;
        else if ((data+mid)->id < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int linearSearch(Sayur *data, int n, string target) {
    for (int i = 0; i < n; i++) {
        if ((data+i)->nama == target) {
            return i;
        }
    }
    return -1;
}

void tampilData(Sayur *data, int n) {
    for (int i = 0; i < n; i++) {
        cout << (data+i)->id << " | "
             << (data+i)->nama << " | "
             << (data+i)->harga << endl;
    }
}

void bubbleSort(Sayur *data, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((data+j)->id > (data+j+1)->id) {
                swap(*(data+j), *(data+j+1));
            }
        }
    }
}

int main() {
    Sayur data[MAX] = {
        {103, "Bayam", 5000},
        {101, "Wortel", 4000},
        {105, "Kangkung", 3000},
        {102, "Kubis", 6000},
        {104, "Tomat", 7000}
    };

    int n = 5;
    int pilih;

    do {
        cout << "\n=== MENU SEARCHING ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Cari ID (Binary Search)\n";
        cout << "3. Cari Nama (Linear Search)\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            tampilData(data, n);
        }

        else if (pilih == 2) {
            int cari;
            cout << "Masukkan ID: ";
            cin >> cari;

            bubbleSort(data, n);

            int hasil = binarySearch(data, n, cari);

            if (hasil != -1)
                cout << "Data ditemukan: " << (data+hasil)->nama << endl;
            else
                cout << "Data tidak ditemukan\n";
        }

        else if (pilih == 3) {
            string cari;
            cout << "Masukkan Nama: ";
            cin >> cari;

            int hasil = linearSearch(data, n, cari);

            if (hasil != -1)
                cout << "Data ditemukan: ID " << (data+hasil)->id << endl;
            else
                cout << "Data tidak ditemukan\n";
        }

    } while (pilih != 4);

    return 0;
}