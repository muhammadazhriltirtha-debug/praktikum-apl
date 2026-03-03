#include <iostream>
using namespace std;

int main() {
    string nama, password;
    int kesempatan = 3;
    bool login = false;

    // LOGIN
    while (kesempatan > 0) {
        cout << "Masukkan Nama     : ";
        cin >> nama;
        cout << "Masukkan Password : ";
        cin >> password;

        if (nama == "user" && password == "097") {
            login = true;
            break;
        } else {
            kesempatan--;
            cout << "Login salah. Sisa kesempatan: "
                 << kesempatan << endl;
        }
    }

    if (login == false) {
        cout << "Anda gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    // MENU
    int pilihan;
    do {
        cout << "\nMENU KONVERSI WAKTU" << endl;
        cout << "1. Jam ke Menit dan Detik" << endl;
        cout << "2. Menit ke Jam dan Detik" << endl;
        cout << "3. Detik ke Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int jam;
            cout << "Masukkan Jam: ";
            cin >> jam;
            cout << "Hasil: "
                 << jam * 60 << " menit dan "
                 << jam * 3600 << " detik" << endl;
        }
        else if (pilihan == 2) {
            int menit;
            cout << "Masukkan Menit: ";
            cin >> menit;
            cout << "Hasil: "
                 << menit / 60 << " jam dan "
                 << menit * 60 << " detik" << endl;
        }
        else if (pilihan == 3) {
            int detik;
            cout << "Masukkan Detik: ";
            cin >> detik;
            cout << "Hasil: "
                 << detik / 3600 << " jam dan "
                 << (detik % 3600) / 60 << " menit" << endl;
        }
        else if (pilihan == 4) {
            cout << "Program selesai." << endl;
        }
        else {
            cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 4);

    return 0;
}