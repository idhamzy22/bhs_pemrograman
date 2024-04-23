#include <iostream>
using namespace std;

int main() {
    char op;
    float num1, num2;

    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;

    cout << "Masukkan dua angka: ";
    cin >> num1 >> num2;

    switch(op) {
        case '+':
            cout << "Hasil penambahan: " << num1 + num2;
            break;
        case '-':
            cout << "Hasil pengurangan: " << num1 - num2;
            break;
        case '*':
            cout << "Hasil perkalian: " << num1 * num2;
            break;
        case '/':
            if(num2 != 0)
                cout << "Hasil pembagian: " << num1 / num2;
            else
                cout << "Tidak bisa melakukan pembagian dengan nol";
            break;
        default:
            // Operator yang dimasukkan tidak valid
            cout << "Operator yang dimasukkan tidak valid";
            break;
    }

    return 0;
}