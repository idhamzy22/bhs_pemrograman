#include <stdio.h>

void menu() {
    printf("MENU PROGRAM:\n");
    printf("1. Tambah\n");
    printf("2. Kurang\n");
    printf("3. Kali\n");
    printf("4. Bagi\n");
    printf("0. Keluar\n");
}

void tambah() {
    int a, b;
    printf("Masukkan angka pertama: ");
    scanf("%d", &a);
    printf("Masukkan angka kedua: ");
    scanf("%d", &b);
    printf("Hasil dari %d + %d = %d\n", a, b, a + b);
}

void kurang() {
    int a, b;
    printf("Masukkan angka pertama: ");
    scanf("%d", &a);
    printf("Masukkan angka kedua: ");
    scanf("%d", &b);
    printf("Hasil dari %d - %d = %d\n", a, b, a - b);
}

void kali() {
    int a, b;
    printf("Masukkan angka pertama: ");
    scanf("%d", &a);
    printf("Masukkan angka kedua: ");
    scanf("%d", &b);
    printf("Hasil dari %d * %d = %d\n", a, b, a * b);
}

void bagi() {
    int a, b;
    printf("Masukkan angka pertama: ");
    scanf("%d", &a);
    printf("Masukkan angka kedua: ");
    scanf("%d", &b);
    if (b != 0) {
        printf("Hasil dari %d / %d = %.2f\n", a, b, (float)a / b);
    } else {
        printf("Pembagian dengan nol tidak diperbolehkan.\n");
    }
}

int main() {
    int pilihan;
    char lanjut;

    do {
        menu();
        printf("Pilih operasi (1-4, 0 untuk keluar): ");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                tambah();
                break;
            case 2:
                kurang();
                break;
            case 3:
                kali();
                break;
            case 4:
                bagi();
                break;
            case 0:
                printf("Keluar dari program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
        printf("Apakah Anda ingin melakukan operasi lain? (y/n): ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}