#include <iostream>
#include <cstdlib> // Untuk menggunakan system("clear")
using namespace std;

int main() {
    char op;
    float angka1, angka2;

    while(true) {
        cout << "Pilih operasi yang diinginkan:" << endl;
        cout << "1. Pertambahan (+)" << endl;
        cout << "2. Pengurangan (-)" << endl;
        cout << "3. Perkalian (*)" << endl;
        cout << "4. Pembagian (/)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> op;

        if(op == '5') {
            cout << "Terima kasih telah menggunakan kalkulator ini. Sampai jumpa!";
            break;
        }

        cout << "Masukkan dua angka: ";
        cin >> angka1 >> angka2;

        switch(op) {
            case '1':
                cout << "Hasil pertambahan: " << angka1 + angka2 << endl;
                break;
            case '2':
                cout << "Hasil pengurangan: " << angka1 - angka2 << endl;
                break;
            case '3':
                cout << "Hasil perkalian: " << angka1 * angka2 << endl;
                break;
            case '4':
                if(angka2 != 0)
                    cout << "Hasil pembagian: " << angka1 / angka2 << endl;
                else
                    cout << "Tidak bisa melakukan pembagian dengan nol" << endl;
                break;
            default:
                // Operator yang dimasukkan tidak valid
                cout << "Operasi yang dimasukkan tidak valid" << endl;
                break;
        }

        // Membersihkan layar
        system("clear");
    }

    return 0;
}