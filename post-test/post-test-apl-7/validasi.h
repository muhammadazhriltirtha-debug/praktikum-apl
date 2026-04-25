#ifndef VALIDASI_H
#define VALIDASI_H

#include <stdexcept>
using namespace std;

void cekAngka(int x) {
    if (x < 0) {
        throw runtime_error("Nilai tidak boleh negatif!");
    }
}

void cekIndex(int index, int max) {
    if (index < 0 || index >= max) {
        throw out_of_range("Index di luar batas!");
    }
}

#endif