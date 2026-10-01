// =============================================================================
// student.cpp — Implementasi Mahasiswa
// Pertemuan 1: Dasar-Dasar Struktur Data C++
// =============================================================================
// INSTRUKSI:
//   - Hanya file ini yang Anda edit untuk mengerjakan praktikum.
//   - Jangan menghapus #include "student.h" di baris pertama.
//   - Jangan mengubah nama atau signature fungsi (itu kontrak dengan checker).
//   - Anda BOLEH menambah fungsi helper sendiri bila memudahkan.
//   - JANGAN menambahkan fungsi main() di file ini — main() sudah ada di
//     src/main.cpp, dan menambahkannya di sini membuat penilaian gagal.
//
// MENCOBA SENDIRI:
//   Gunakan runner di src/main.cpp untuk menjalankan implementasi Anda:
//     g++ -std=c++17 src/student.cpp src/main.cpp -o latihan && ./latihan
//   File itu tidak ikut dinilai dan bebas Anda ubah.
//
// FILE YANG BOLEH DIEDIT     : src/student.cpp  ← HANYA FILE INI
// FILE YANG TIDAK BOLEH DIEDIT: src/student.h, tests/checker.cpp, tests/report.h
//
// Baca src/student.h untuk spesifikasi lengkap tiap fungsi (termasuk perilaku
// saat array kosong). Baca README.md untuk daftar soal dan contohnya.
//
// CATATAN: sebelum diisi, compiler akan memunculkan peringatan
// "unused parameter". Itu wajar — peringatan hilang setelah parameter
// benar-benar Anda pakai. Peringatan tidak mengurangi nilai.
// =============================================================================

#include "student.h"

using namespace std;

// =============================================================================
// BAGIAN A — Operasi Baca
// =============================================================================

// SOAL 1: Jumlahkan semua elemen data[0] .. data[n-1]. Bila n == 0, hasil 0.
int hitungTotal(const int data[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
    return total;
}

// SOAL 2: Rata-rata seluruh elemen (hasil pecahan). Bila n == 0, hasil 0.0.
double hitungRataRata(const int data[], int n) {
    if (n == 0) {
        return 0.0;
    }
    return static_cast<double>(hitungTotal(data, n)) / n;
}

// SOAL 3: Nilai terbesar di dalam array. Bila n == 0, hasil 0.
int cariMax(const int data[], int n) {
    if (n == 0) {
        return 0;
    }
    int max = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

// SOAL 4: Indeks kemunculan PERTAMA dari target, atau -1 bila tidak ada.
int cariIndeks(const int data[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}

// =============================================================================
// BAGIAN B — Operasi Ubah (in-place)
// =============================================================================

// SOAL 5: Balik urutan isi array di tempat. Tidak mengembalikan nilai.
void balikArray(int data[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = data[i];
        data[i] = data[n - 1 - i];
        data[n - 1 - i] = temp;
    }
}

// SOAL 6: Hapus semua elemen bernilai target, rapatkan sisanya,
//         kembalikan ukuran baru array.
int hapusNilai(int data[], int n, int target) {
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < n; readIndex++) {
        if (data[readIndex] != target) {
            data[writeIndex] = data[readIndex];
            writeIndex++;
        }
    }
    return writeIndex;
}

// =============================================================================
// BAGIAN C — Operasi pada kumpulan data bertipe struct
// =============================================================================

// SOAL 7: Rata-rata field `nilai` dari n mahasiswa. Bila n == 0, hasil 0.0.
double rataRataNilai(const Mahasiswa data[], int n) {
    if (n == 0) {
        return 0.0;
    }
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += data[i].nilai;
    }
    return total / n;
}

// SOAL 8: Indeks mahasiswa dengan nilai tertinggi (yang paling awal bila seri),
//         atau -1 bila n == 0.
int indeksNilaiTertinggi(const Mahasiswa data[], int n) {
    if (n == 0) {
        return -1;
    }
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (data[i].nilai > data[maxIndex].nilai) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// SOAL 9: Banyaknya mahasiswa dengan nilai >= kkm.
int hitungLulus(const Mahasiswa data[], int n, double kkm) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].nilai >= kkm) {
            count++;
        }
    }
    return count;
}
