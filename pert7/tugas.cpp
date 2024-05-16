#include <iostream>
using namespace std;

int main() {
    int choice1, choice2, choice3, quantity;
    double total = 0.0;
    double harga_makanan = 0.0; // Menyimpan harga makanan yang dipilih

    do {
        cout << "Menu:\n";
        cout << "1. Makanan\n";
        cout << "2. Minuman\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice1;

        switch (choice1) {
            case 1:
                cout << "Makanan:\n";
                cout << "1. Pecel Lele (Rp. 10.000)\n";
                cout << "2. Nasi Goreng (Rp. 15.000)\n";
                cout << "3. Kembali\n";
                cout << "Pilih makanan: ";
                cin >> choice2;
                if (choice2 == 1 || choice2 == 2) {
                    cout << "Masukkan jumlah yang ingin dipesan: ";
                    cin >> quantity;
                    if (choice2 == 1) {
                        harga_makanan = quantity * 10000.0;
                        cout << "Jumlah harga: Rp" << harga_makanan << endl; // Menampilkan jumlah harga makanan
                        total += harga_makanan; // Menambahkan harga makanan ke total
                    } else {
                        harga_makanan = quantity * 15000.0;
                        cout << "Jumlah harga: Rp" << harga_makanan << endl; // Menampilkan jumlah harga makanan
                        total += harga_makanan; // Menambahkan harga makanan ke total
                    }
                }
                break;
            case 2:
                cout << "Minuman:\n";
                cout << "1. Es Teh (Rp. 5.000)\n";
                cout << "2. Air Mineral (Rp. 3.000)\n";
                cout << "3. Kembali\n";
                cout << "Pilih minuman: ";
                cin >> choice2;
                if (choice2 == 1 || choice2 == 2) {
                    cout << "Quantity: ";
                    cin >> quantity;
                    if (choice2 == 1) total += quantity * 5000.0; // Harga Es Teh per gelas
                    else total += quantity * 3000.0; // Harga Air Mineral per gelas
                }
                break;
            case 3:
                cout << "Total harga: Rp" << total << endl; // Menampilkan total harga sebelum keluar
                cout << "Terima kasih telah menggunakan layanan kami.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }

        cout << endl;
    } while (choice1 != 3);

    return 0;
}