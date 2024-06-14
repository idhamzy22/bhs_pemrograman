#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void displayHeader(const string& header) {
    cout << "\n\033[1;34m=========================\n";
    cout << header << "\n";
    cout << "=========================\033[0m\n";
}

void displayMenu() {
    cout << "\n\033[1;32mSTACK - STRUKTUR DATA:\033[0m\n";
    cout << "1. \033[1;36mpush\033[0m\n";
    cout << "2. \033[1;36mpop\033[0m\n";
    cout << "3. \033[1;36mpeek\033[0m\n";
    cout << "4. \033[1;36misEmpty\033[0m\n";
    cout << "5. \033[1;36msize\033[0m\n";
    cout << "6. \033[1;31mexit\033[0m\n";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void loadingAnimation() {
    cout << "SABAR YA";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        cout.flush();
        usleep(500000); // 500 ms
    }
    cout << "\n";
}

void push(stack<string>& films) {
    string film;
    displayHeader("MENAMBAHKAN FILM / PUSH");
    cout << "Masukkan judul film yang akan ditambahkan: ";
    cin.ignore();
    getline(cin, film);
    films.push(film);
    loadingAnimation();
    cout << "\033[1;32mFilm \"" << film << "\" telah ditambahkan ke tumpukan.\033[0m" << endl;
}

void pop(stack<string>& films) {
    displayHeader("MENGHAPUS FILM / POP");
    if (films.empty()) {
        cout << "\033[1;31mTumpukan film kosong. Tidak ada film yang bisa dihapus.\033[0m" << endl;
    } else {
        cout << "Film \"" << films.top() << "\" akan dihapus dari tumpukan. Lanjutkan? (y/n): ";
        char confirm;
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            loadingAnimation();
            cout << "\033[1;32mFilm \"" << films.top() << "\" telah dihapus dari tumpukan.\033[0m" << endl;
            films.pop();
        } else {
            cout << "\033[1;33mPenghapusan film dibatalkan.\033[0m" << endl;
        }
    }
}

void peek(const stack<string>& films) {
    displayHeader("FILM TERATAS / PEEK");
    if (films.empty()) {
        cout << "\033[1;31mTumpukan film kosong.\033[0m" << endl;
    } else {
        loadingAnimation();
        cout << "Film teratas di tumpukan: \033[1;32m\"" << films.top() << "\"\033[0m" << endl;
    }
}

void isEmpty(const stack<string>& films) {
    displayHeader("STATUS TUMPUKAN / ISEMPTY");
    loadingAnimation();
    if (films.empty()) {
        cout << "\033[1;31mTumpukan film kosong.\033[0m" << endl;
    } else {
        cout << "\033[1;32mTumpukan film tidak kosong.\033[0m" << endl;
    }
}

void size(const stack<string>& films) {
    displayHeader("JUMLAH FILM / SIZE");
    loadingAnimation();
    cout << "Jumlah film di tumpukan: \033[1;32m" << films.size() << "\033[0m" << endl;
    if (films.empty()) {
        cout << "\033[1;31mTumpukan film kosong.\033[0m" << endl;
    } else {
        stack<string> temp = films;
        cout << "Film dalam tumpukan:\n";
        while (!temp.empty()) {
            cout << "- \033[1;32m" << temp.top() << "\033[0m\n";
            temp.pop();
        }
    }
}

int main() {
    stack<string> films;
    unordered_map<string, string> commands = {
        {"1", "push"}, {"2", "pop"}, {"3", "peek"},
        {"4", "isEmpty"}, {"5", "size"}, {"6", "exit"},
        {"push", "push"}, {"pop", "pop"}, {"peek", "peek"},
        {"isEmpty", "isEmpty"}, {"size", "size"}, {"exit", "exit"}
    };

    string command;
    
    while (true) {
        displayMenu();
        cout << "\nMasukkan Pilihan: ";
        cin >> command;

        if (commands.find(command) == commands.end()) {
            displayHeader("yah gabisaaa");
            cout << "\033[1;31mgabisa nih... dicoba lagi yaa!!!.\033[0m" << endl;
            continue;
        }

        string operation = commands[command];

        clearScreen();

        if (operation == "push") {
            push(films);
        } else if (operation == "pop") {
            pop(films);
        } else if (operation == "peek") {
            peek(films);
        } else if (operation == "isEmpty") {
            isEmpty(films);
        } else if (operation == "size") {
            size(films);
        } else if (operation == "exit") {
            displayHeader("TERIMA KASIH");
            cout << "\033[1;32mProgram berakhir.\033[0m" << endl;
            break;
        }
    }

    return 0;
}