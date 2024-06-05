#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string name, string type, double price) : name(name), type(type), price(price) {}
};

class Menu {
private:
    vector<MenuItem> items;

public:
    void addMenuItem(const MenuItem& item) {
        items.push_back(item);
    }

    void removeMenuItem(const string& name) {
        items.erase(remove_if(items.begin(), items.end(), [&](MenuItem& item) {
            return item.name == name;
        }), items.end());
    }

    void updateMenuItemPrice(const string& name, double newPrice) {
        for (auto& item : items) {
            if (item.name == name) {
                item.price = newPrice;
                break;
            }
        }
    }

    void displayMenu() const {
        cout << "Menu:" << endl;
        for (const auto& item : items) {
            cout << item.type << ": " << item.name << " - Rp. " << item.price << endl;
        }
    }

    void searchMenuItem(const string& name) const {
        bool found = false;
        for (const auto& item : items) {
            if (item.name.find(name) != string::npos) {
                cout << item.type << ": " << item.name << " - Rp. " << item.price << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Item '" << name << "' tidak ditemukan dalam menu." << endl;
        }
    }
};

class RestaurantManagementSystem {
private:
    Menu menu;

public:
    void viewMenu() const {
        menu.displayMenu();
    }

    void addMenuItem(const string& name, const string& type, double price) {
        MenuItem item(name, type, price);
        menu.addMenuItem(item);
    }

    void updateMenuItem(const string& name, double newPrice) {
        menu.updateMenuItemPrice(name, newPrice);
    }

    void deleteMenuItem(const string& name) {
        menu.removeMenuItem(name);
    }

    void searchMenuItem(const string& name) const {
        menu.searchMenuItem(name);
    }
};

void displayMenuOptions() {
    cout << "\nMenu Program Restoran:\n";
    cout << "1. Tampilkan Menu\n";
    cout << "2. Tambah Item Menu\n";
    cout << "3. Perbarui Harga Item Menu\n";
    cout << "4. Hapus Item Menu\n";
    cout << "5. Cari Item Menu\n";
    cout << "6. Keluar\n";
    cout << "Pilih opsi (1-6): ";
}

int main() {
    RestaurantManagementSystem rms;
    int choice;
    string name, type;
    double price;

    do {
        displayMenuOptions();
        cin >> choice;

        switch (choice) {
            case 1:
                rms.viewMenu();
                break;
            case 2:
                cout << "Masukkan nama item: ";
                cin.ignore();
                getline(cin, name);
                cout << "Masukkan jenis (Makanan/Minuman): ";
                getline(cin, type);
                cout << "Masukkan harga: ";
                cin >> price;
                rms.addMenuItem(name, type, price);
                break;
            case 3:
                cout << "Masukkan nama item yang ingin diperbarui: ";
                cin.ignore();
                getline(cin, name);
                cout << "Masukkan harga baru: ";
                cin >> price;
                rms.updateMenuItem(name, price);
                break;
            case 4:
                cout << "Masukkan nama item yang ingin dihapus: ";
                cin.ignore();
                getline(cin, name);
                rms.deleteMenuItem(name);
                break;
            case 5:
                cout << "Masukkan nama item yang ingin dicari: ";
                cin.ignore();
                getline(cin, name);
                rms.searchMenuItem(name);
                break;
            case 6:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}