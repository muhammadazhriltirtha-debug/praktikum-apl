#include <iostream>
#include "validasi.h"
using namespace std;

#define MAX 100

struct Sayur {
    int id;
    string nama;
    int harga;
    int stok;
};

void tampilData(Sayur *data, int jumlah) {
    if (jumlah == 0) throw runtime_error("Data kosong!");

    for (int i = 0; i < jumlah; i++) {
        cout << i+1 << ". "
             << (data+i)->id << " | "
             << (data+i)->nama << " | "
             << (data+i)->harga << " | "
             << (data+i)->stok << endl;
    }
}

void tambahData(Sayur *data, int *jumlah) {
    if (*jumlah >= MAX) throw runtime_error("Data penuh!");

    cout << "ID: "; cin >> (data+*jumlah)->id;
    cout << "Nama: "; cin >> (data+*jumlah)->nama;

    cout << "Harga: "; cin >> (data+*jumlah)->harga;
    if (cin.fail()) throw invalid_argument("Harga harus angka!");
    cekAngka((data+*jumlah)->harga);

    cout << "Stok: "; cin >> (data+*jumlah)->stok;
    cekAngka((data+*jumlah)->stok);

    (*jumlah)++;
}

void hapusData(Sayur *data, int *jumlah) {
    if (*jumlah == 0) throw runtime_error("Data kosong!");

    int idx;
    cout << "Pilih nomor: "; cin >> idx;

    cekIndex(idx-1, *jumlah);

    for (int i = idx-1; i < *jumlah-1; i++) {
        *(data+i) = *(data+i+1);
    }
    (*jumlah)--;
}

void bubbleSortNama(Sayur *data, int n) {
    for (int i=0;i<n-1;i++)
        for (int j=0;j<n-i-1;j++)
            if ((data+j)->nama > (data+j+1)->nama)
                swap(*(data+j), *(data+j+1));
}

void selectionSortHarga(Sayur *data, int n) {
    for (int i=0;i<n-1;i++) {
        int max=i;
        for (int j=i+1;j<n;j++)
            if ((data+j)->harga > (data+max)->harga)
                max=j;
        swap(*(data+i), *(data+max));
    }
}

void insertionSortStok(Sayur *data, int n) {
    for (int i=1;i<n;i++) {
        Sayur key = *(data+i);
        int j=i-1;
        while (j>=0 && (data+j)->stok > key.stok) {
            *(data+j+1)=*(data+j);
            j--;
        }
        *(data+j+1)=key;
    }
}

int linearSearchNama(Sayur *data, int n, string cari) {
    for (int i=0;i<n;i++)
        if ((data+i)->nama == cari) return i;
    return -1;
}

void bubbleSortID(Sayur *data, int n) {
    for (int i=0;i<n-1;i++)
        for (int j=0;j<n-i-1;j++)
            if ((data+j)->id > (data+j+1)->id)
                swap(*(data+j), *(data+j+1));
}

int binarySearchID(Sayur *data, int n, int cari) {
    int low=0, high=n-1;
    while (low<=high) {
        int mid=(low+high)/2;
        if ((data+mid)->id == cari) return mid;
        else if ((data+mid)->id < cari) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main() {

    Sayur data[MAX];
    int jumlah=0, menu;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah\n2. Tampil\n3. Hapus\n";
        cout << "4. Sort Nama (ASC)\n5. Sort Harga (DESC)\n6. Sort Stok (ASC)\n";
        cout << "7. Cari ID (Binary)\n8. Cari Nama (Linear)\n9. Keluar\n";
        cout << "Pilih: "; cin >> menu;

        try {
            switch(menu) {
                case 1: tambahData(data,&jumlah); break;
                case 2: tampilData(data,jumlah); break;
                case 3: hapusData(data,&jumlah); break;

                case 4: bubbleSortNama(data,jumlah); break;
                case 5: selectionSortHarga(data,jumlah); break;
                case 6: insertionSortStok(data,jumlah); break;

                case 7: {
                    int id; cout<<"Cari ID: "; cin>>id;
                    bubbleSortID(data,jumlah);
                    int hasil=binarySearchID(data,jumlah,id);
                    if (hasil!=-1)
                        cout<<"Ditemukan: "<<(data+hasil)->nama<<endl;
                    else cout<<"Tidak ditemukan\n";
                    break;
                }

                case 8: {
                    string nama; cout<<"Cari Nama: "; cin>>nama;
                    int hasil=linearSearchNama(data,jumlah,nama);
                    if (hasil!=-1)
                        cout<<"Ditemukan ID: "<<(data+hasil)->id<<endl;
                    else cout<<"Tidak ditemukan\n";
                    break;
                }
            }
        }
        catch (const invalid_argument& e) {
            cout<<"Error: "<<e.what()<<endl;
            cin.clear(); cin.ignore(1000,'\n');
        }
        catch (const out_of_range& e) {
            cout<<"Error: "<<e.what()<<endl;
        }
        catch (const runtime_error& e) {
            cout<<"Error: "<<e.what()<<endl;
        }

    } while(menu!=9);

    return 0;
}