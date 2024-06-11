#include <iostream>
using namespace std;

struct DriverBus
{
    string nama;
    string rute;
    int poin;
    DriverBus *next;
};

DriverBus *head = NULL, *tail = NULL, *cur = NULL, *newNode = NULL, *del = NULL;

void sisipDepan(string nama, string rute, int poin)
{
    newNode = new DriverBus();
    newNode->nama = nama;
    newNode->rute = rute;
    newNode->poin = poin;
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
    {
        tail = newNode;
    }
}

void sisipTengah(string nama, string rute, int poin, int jam_keberangkatan)
{
    if (head == NULL)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        newNode = new DriverBus();
        newNode->nama = nama;
        newNode->rute = rute;
        newNode->poin = poin;

        cur = head;
        int nomor = 1;
        while (nomor < jam_keberangkatan - 1 && cur->next != NULL)
        {
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void sisipBelakang(string nama, string rute, int poin)
{
    newNode = new DriverBus();
    newNode->nama = nama;
    newNode->rute = rute;
    newNode->poin = poin;
    newNode->next = NULL;
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void hapusDepan()
{
    if (head == NULL)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        del = head;
        head = head->next;
        delete del;
        if (head == NULL)
        {
            tail = NULL;
        }
    }
}

void hapusTengah(int jam_keberangkatan)
{
    if (head == NULL)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        cur = head;
        int nomor = 1;
        while (nomor < jam_keberangkatan - 1 && cur->next != NULL)
        {
            cur = cur->next;
            nomor++;
        }
        if (cur->next != NULL)
        {
            del = cur->next;
            cur->next = del->next;
            delete del;
            if (cur->next == NULL)
            {
                tail = cur;
            }
        }
    }
}

void hapusBelakang()
{
    if (head == NULL)
    {
        cout << "List belum diisi" << endl;
    }
    else if (head->next == NULL)
    {
        del = head;
        head = NULL;
        tail = NULL;
        delete del;
    }
    else
    {
        del = tail;
        cur = head;
        while (cur->next != tail)
        {
            cur = cur->next;
        }
        tail = cur;
        tail->next = NULL;
        delete del;
    }
}

void tampilkanData()
{
    if (head == NULL)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        cur = head;
        cout << "Data Driver Bus:" << endl;
        while (cur != NULL)
        {
            cout << "Nama: " << cur->nama << endl;
            cout << "Rute: " << cur->rute << endl;
            cout << "Poin: " << cur->poin << "\n" << endl;
            cur = cur->next;
        }
    }
}

int main()
{
    int pilih;
    string nama, rute;
    int poin, jam_keberangkatan;

    do
    {
        cout << "Menu:" << endl;
        cout << "a. Sisip depan" << endl;
        cout << "b. Sisip tengah" << endl;
        cout << "c. Sisip belakang" << endl;
        cout << "d. Hapus depan" << endl;
        cout << "e. Hapus tengah" << endl;
        cout << "f. Hapus belakang" << endl;
        cout << "g. Tampilkan data" << endl;
        cout << "h. Keluar" << endl;
        cout << "Pilih (a-h): ";
        char pilihan;
        cin >> pilihan;

        switch (pilihan)
        {
        case 'a':
            cout << "Masukkan nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan rute: ";
            getline(cin, rute);
            cout << "Masukkan poin: ";
            cin >> poin;
            sisipDepan(nama, rute, poin);
            break;
        case 'b':
            cout << "Masukkan nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan rute: ";
            getline(cin, rute);
            cout << "Masukkan poin: ";
            cin >> poin;
            cout << "Masukkan jam keberangkatan: ";
            cin >> jam_keberangkatan;
            sisipTengah(nama, rute, poin, jam_keberangkatan);
            break;
        case 'c':
            cout << "Masukkan nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan rute: ";
            getline(cin, rute);
            cout << "Masukkan poin: ";
            cin >> poin;
            sisipBelakang(nama, rute, poin);
            break;
        case 'd':
            hapusDepan();
            break;
        case 'e':
            cout << "Masukkan jam keberangkatan: ";
            cin >> jam_keberangkatan;
            hapusTengah(jam_keberangkatan);
            break;
        case 'f':
            hapusBelakang();
            break;
        case 'g':
            tampilkanData();
            break;
        case 'h':
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilih != 'h');

    return 0;
}