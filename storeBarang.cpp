#include <iostream>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

struct Barang {
    string nama;
    int jumlah;
};

bool isNumber(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void hapusBarang(queue<Barang>& daftarBarang, const string& namaBarang) {
    cout << "Daftar Barang sebelum dihapus:" << endl;
    if (daftarBarang.empty()) {
        cout << "Tidak ada barang dalam daftar." << endl;
        return;
    }

    int index = 1;
    queue<Barang> tempQueue = daftarBarang;
    while (!tempQueue.empty()) {
        Barang barang = tempQueue.front();
        cout << index << ". Nama: " << barang.nama << ", Jumlah: " << barang.jumlah << endl;
        tempQueue.pop();
        index++;
    }
    cout << endl;

    bool found = false;
    queue<Barang> tempQueue2;

    while (!daftarBarang.empty()) {
        Barang barang = daftarBarang.front();
        daftarBarang.pop();

        if (barang.nama == namaBarang) {
            cout << "Barang dengan nama " << barang.nama << " dan jumlah " << barang.jumlah << " telah dihapus." << endl;
            found = true;
        } else {
            tempQueue2.push(barang);
        }
    }

    if (!found) {
        cout << "Barang dengan nama " << namaBarang << " tidak ditemukan dalam daftar." << endl;
    }

    daftarBarang = tempQueue2;
}

void cariBarang(const queue<Barang>& daftarBarang, const string& namaBarang) {
    cout << "Mencari barang dengan nama " << namaBarang << "..." << endl;

    if (daftarBarang.empty()) {
        cout << "Tidak ada barang dalam daftar." << endl;
        return;
    }

    int index = 1;
    queue<Barang> tempQueue = daftarBarang;
    while (!tempQueue.empty()) {
        Barang barang = tempQueue.front();
        if (barang.nama == namaBarang) {
            cout << "Barang dengan nama " << namaBarang << " ditemukan pada letak penyimpanan " << index << "." << endl;
            return;
        }
        tempQueue.pop();
        index++;
    }

    cout << "Barang dengan nama " << namaBarang << " tidak ditemukan dalam daftar." << endl;
}

int main() {
    queue<Barang> daftarBarang;
    char pilihan;

    do {
        cout << "==== Manajemen Penyimpanan Barang ====" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Barang" << endl;
        cout << "3. Hapus Barang" << endl;
        cout << "4. Cari Barang" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                {
                    char tambahLagi;
                    do {
                        Barang barang;
                        cout << "Nama barang: ";
                        cin >> barang.nama;

                        string jumlahInput;
                        cout << "Jumlah barang: ";
                        cin >> jumlahInput;

                        if (isNumber(jumlahInput)) {
                            barang.jumlah = stoi(jumlahInput);
                            daftarBarang.push(barang);
                            cout << "Barang berhasil ditambahkan!" << endl;
                        } else {
                            cout << "Inputan salah. Jumlah barang harus berupa angka." << endl;
                        }

                        cout << "Tambah barang lagi? (y/n): ";
                        cin >> tambahLagi;

                    } while (tolower(tambahLagi) == 'y');

                    cout << endl;
                    break;
                }
            case '2':
                {
                    cout << "Daftar Barang:" << endl;
                    if (daftarBarang.empty()) {
                        cout << "Tidak ada barang dalam daftar." << endl;
                    } else {
                        int index = 1;
                        queue<Barang> tempQueue = daftarBarang;
                        while (!tempQueue.empty()) {
                            Barang barang = tempQueue.front();
                            cout << index << ". Nama: " << barang.nama << ", Jumlah: " << barang.jumlah << endl;
                            tempQueue.pop();
                            index++;
                        }
                    }

                    cout << endl;
                    break;
                }
            case '3':
                {
                    string namaBarang;
                    cout << "Nama barang yang akan dihapus: ";
                    cin >> namaBarang;
                    cout << endl;

                    hapusBarang(daftarBarang, namaBarang);
                    cout << endl;
                    break;
                }
            case '4':
                {
                    string namaBarang;
                    cout << "Nama barang yang akan dicari: ";
                    cin >> namaBarang;
                    cout << endl;

                    cariBarang(daftarBarang, namaBarang);
                    cout << endl;
                    break;
                }
            case '5':
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

    } while (pilihan != '5');

    return 0;
}
