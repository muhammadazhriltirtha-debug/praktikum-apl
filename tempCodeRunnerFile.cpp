    #include <iostream>
    using namespace std;

    int main() {
    string nama, inputNama;
        string password, inputPassword;
        int kesempatan = 0;

        nama = "Azhril";
        password = "097"; 

        while (kesempatan < 3) {
            cout << "=== LOGIN ===" << endl;
            cout << "Masukkan Nama: ";
            cin >> inputNama;
            cout << "Masukkan Password: ";
            cin >> inputPassword;

            if (inputNama == nama && inputPassword == password) {
                cout << "Login Berhasil!" << endl;
                break;
            } else {
                kesempatan++;
                cout << "Login Salah! Kesempatan ke-" << kesempatan << endl;
            }
        }

        if (kesempatan == 3) {
            cout << "Anda gagal login 3 kali. Program berhenti." << endl;
            return 0;
        }

        int pilihan;
        do {
            cout << "\n=== MENU UTAMA ===" << endl;
            cout << "1. Hitung Luas Persegi" << endl;
            cout << "2. Hitung Luas Lingkaran" << endl;
            cout << "3. Hitung Luas Segitiga" << endl;
            cout << "4. Keluar" << endl;
            cout << "Pilih menu: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1: {
                    int sisi, luas;
                    cout << "Masukkan sisi: ";
                    cin >> sisi;
                    luas = sisi * sisi;
                    cout << "Luas Persegi = " << luas << endl;
                    break;
                }

                case 2: {
                    float r, luas;
                    cout << "Masukkan jari-jari: ";
                    cin >> r;
                    luas = 3.14 * r * r;
                    cout << "Luas Lingkaran = " << luas << endl;
                    break;
                }

                case 3: {
                    float alas, tinggi, luas;
                    cout << "Masukkan alas: ";
                    cin >> alas;
                    cout << "Masukkan tinggi: ";
                    cin >> tinggi;
                    luas = 0.5 * alas * tinggi;
                    cout << "Luas Segitiga = " << luas << endl;
                    break;
                }

                case 4:
                    cout << "Terima kasih!" << endl;
                    break;

                default:
                    cout << "Pilihan tidak valid!" << endl;
            }

        } while (pilihan != 4);

        return 0;
    }