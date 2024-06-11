#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TamuUndangan {
public:
    string email;
    bool kehadiran;

    TamuUndangan(string email) : email(email), kehadiran(false) {}

    void konfirmasiKehadiran() {
        kehadiran = true;
        cout << "Tamu dengan email " << email << " telah mengkonfirmasi kehadiran." << endl;
    }
};

class Website {
public:
    vector<TamuUndangan> tamuUndangan;
    string undangan;

    void konfirmasiAkun(string nama) {
        cout << "Akun untuk " << nama << " telah dikonfirmasi." << endl;
    }

    void tampilkanTemplateUndangan() {
        cout << "Template undangan tersedia." << endl;
    }

    void previewUndangan(string infoAcara) {
        cout << "Preview undangan: " << infoAcara << endl;
    }

    void kirimUndangan() {
        for (TamuUndangan& tamu : tamuUndangan) {
            cout << "Undangan dikirim ke " << tamu.email << endl;
        }
    }

    void tampilkanDaftarTamu() {
        cout << "Daftar tamu undangan:" << endl;
        for (TamuUndangan& tamu : tamuUndangan) {
            cout << "- " << tamu.email;
            if (tamu.kehadiran) {
                cout << " (Hadir)";
            }
            cout << endl;
        }
    }

    void konfirmasiHapus() {
        cout << "Undangan telah dihapus." << endl;
    }
};

class Pengguna {
public:
    string nama;
    string email;
    Website* website;

    Pengguna(string nama, string email, Website* website) {
        this->nama = nama;
        this->email = email;
        this->website = website;
    }

    void buatAkun() {
        cout << nama << " membuat akun." << endl;
        website->konfirmasiAkun(nama);
    }

    void buatUndangan(string judul, string isi) {
        cout << nama << " membuat undangan." << endl;
        website->tampilkanTemplateUndangan();
        cout << "Informasi acara: " << isi << endl;
        website->previewUndangan(isi);
        website->undangan = isi;
    }

    void kirimUndangan(vector<string> emailTamu) {
        for (string email : emailTamu) {
            TamuUndangan tamu(email);
            website->tamuUndangan.push_back(tamu);
        }
        website->kirimUndangan();
    }

    void lihatDaftarTamu() {
        website->tampilkanDaftarTamu();
    }

    void editUndangan(string infoBaru) {
        cout << nama << " mengedit undangan." << endl;
        website->previewUndangan(infoBaru);
        website->undangan = infoBaru;
        cout << "Perubahan telah disimpan." << endl;
    }

    void hapusUndangan() {
        website->undangan = "";
        website->tamuUndangan.clear();
        website->konfirmasiHapus();
    }

    void konfirmasiKehadiranTamu(string email) {
        auto it = find_if(website->tamuUndangan.begin(), website->tamuUndangan.end(),
                          [email](TamuUndangan& tamu) { return tamu.email == email; });
        if (it != website->tamuUndangan.end()) {
            it->konfirmasiKehadiran();
        } else {
            cout << "Tamu dengan email " << email << " tidak ditemukan." << endl;
        }
    }
};

int main() {
    Website website;
    Pengguna pengguna("John Doe", "johndoe@example.com", &website);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Akun\n";
        cout << "2. Buat Undangan\n";
        cout << "3. Kirim Undangan\n";
        cout << "4. Lihat Daftar Tamu\n";
        cout << "5. Edit Undangan\n";
        cout << "6. Hapus Undangan\n";
        cout << "7. Konfirmasi Kehadiran Tamu\n";
        cout << "0. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                pengguna.buatAkun();
                break;
            }
            case 2: {
                string judul, isi;
                cout << "Masukkan judul undangan: ";
                getline(cin, judul);
                cout << "Masukkan isi undangan: ";
                getline(cin, isi);
                pengguna.buatUndangan(judul, isi);
                break;
            }
            case 3: {
                int n;
                cout << "Masukkan jumlah tamu: ";
                cin >> n;
                cin.ignore();
                vector<string> emailTamu(n);
                for (int i = 0; i < n; ++i) {
                    cout << "Masukkan email tamu " << i + 1 << ": ";
                    getline(cin, emailTamu[i]);
                }
                pengguna.kirimUndangan(emailTamu);
                break;
            }
            case 4: {
                pengguna.lihatDaftarTamu();
                break;
            }
            case 5: {
                string infoBaru;
                cout << "Masukkan informasi undangan baru: ";
                getline(cin, infoBaru);
                pengguna.editUndangan(infoBaru);
                break;
            }
            case 6: {
                pengguna.hapusUndangan();
                break;
            }
            case 7: {
                string email;
                cout << "Masukkan email tamu yang akan mengkonfirmasi kehadiran: ";
                getline(cin, email);
                pengguna.konfirmasiKehadiranTamu(email);
                break;
            }
            case 0: {
                cout << "Keluar dari program." << endl;
                break;
            }
            default: {
                cout << "Opsi tidak valid." << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}