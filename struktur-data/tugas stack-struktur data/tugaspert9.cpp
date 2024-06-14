#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void typewriter(const string& text, int delay = 50) {
    for (char ch : text) {
        cout << ch;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

void displayHeader(const string& header) {
    cout << "\n\033[1;34m=========================\n";
    cout << header << "\n";
    cout << "=========================\033[0m\n";
}

void displayBanner() {
    cout << "\n\033[1;35m======================================\n";
    cout << "        IDHAM KHOLID NUR AZIZI       \n";
    cout << "======================================\033[0m\n";
}

void displayMenu() {
    cout << "\n\033[1;32mSTACK - STRUKTUR DATA:\033[0m\n";
    cout << "1. \033[1;36mpush\033[0m\n";
    cout << "2. \033[1;36mpop\033[0m\n";
    cout << "3. \033[1;36mpeek\033[0m\n";
    cout << "4. \033[1;36misEmpty\033[0m\n";
    cout << "5. \033[1;36msize\033[0m\n";
    cout << "6. \033[1;36mhistori\033[0m\n";
    cout << "7. \033[1;36mbantuan\033[0m\n";
    cout << "8. \033[1;31mexit\033[0m\n";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void loadingAnimation() {
    cout << "\n\033[1;33mSABAR YA";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500)); // 500 ms
    }
    cout << "\033[0m\n";
}

void errorMessage(const string& message) {
    cout << "\033[1;31mError: " << message << "\033[0m" << endl;
}

void push(stack<string>& films, vector<string>& history) {
    string film;
    displayHeader("MENAMBAHKAN FILM / PUSH");
    typewriter("Masukkan judul film yang akan ditambahkan: ");
    cin.ignore();
    getline(cin, film);
    films.push(film);
    history.push_back("Menambahkan film: " + film);
    loadingAnimation();
    cout << "\033[1;32mFilm \"" << film << "\" telah ditambahkan ke tumpukan.\033[0m" << endl;
}

void pop(stack<string>& films, vector<string>& history) {
    displayHeader("MENGHAPUS FILM / POP");
    if (films.empty()) {
        errorMessage("Tumpukan film kosong. Tidak ada film yang bisa dihapus.");
    } else {
        cout << "Film \"" << films.top() << "\" akan dihapus dari tumpukan. Lanjutkan? (y/n): ";
        char confirm;
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            history.push_back("Menghapus film: " + films.top());
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
        errorMessage("Tumpukan film kosong.");
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

void showHistory(const vector<string>& history) {
    displayHeader("HISTORI OPERASI");
    if (history.empty()) {
        cout << "\033[1;31mBelum ada operasi yang dilakukan.\033[0m" << endl;
    } else {
        for (const auto& entry : history) {
            cout << "\033[1;32m" << entry << "\033[0m\n";
        }
    }
}

void displayStackVisual(const stack<string>& films) {
    stack<string> temp = films;
    vector<string> displayStack;

    while (!temp.empty()) {
        displayStack.push_back(temp.top());
        temp.pop();
    }

    if (displayStack.empty()) {
        cout << "\033[1;31mTumpukan film kosong.\033[0m" << endl;
    } else {
        cout << "\033[1;34m\nVisualisasi Tumpukan Film:\033[0m" << endl;
        for (auto it = displayStack.rbegin(); it != displayStack.rend(); ++it) {
            cout << "|\033[1;32m " << *it << " \033[0m|\n";
        }
        cout << "=================\n";
    }
}

void showHelp() {
    displayHeader("BANTUAN");
    cout << "\033[1;36m1. push:\033[0m Menambahkan film ke tumpukan.\n";
    cout << "\033[1;36m2. pop:\033[0m Menghapus film teratas dari tumpukan.\n";
    cout << "\033[1;36m3. peek:\033[0m Melihat film teratas di tumpukan.\n";
    cout << "\033[1;36m4. isEmpty:\033[0m Mengecek apakah tumpukan kosong.\n";
    cout << "\033[1;36m5. size:\033[0m Melihat jumlah film di tumpukan.\n";
    cout << "\033[1;36m6. histori:\033[0m Melihat histori operasi.\n";
    cout << "\033[1;36m7. exit:\033[0m Keluar dari program.\n";
}

int main() {
    stack<string> films;
    vector<string> history;
    unordered_map<string, string> commands = {
        {"1", "push"}, {"2", "pop"}, {"3", "peek"},
        {"4", "isEmpty"}, {"5", "size"}, {"6", "histori"},
        {"7", "bantuan"}, {"8", "exit"},
        {"push", "push"}, {"pop", "pop"}, {"peek", "peek"},
        {"isEmpty", "isEmpty"}, {"size", "size"}, {"histori", "histori"},
        {"bantuan", "bantuan"}, {"exit", "exit"}
    };

    string command;
    
    displayBanner();
    while (true) {
        displayStackVisual(films);
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

        try {
            if (operation == "push") {
                push(films, history);
            } else if (operation == "pop") {
                pop(films, history);
            } else if (operation == "peek") {
                peek(films);
            } else if (operation == "isEmpty") {
                isEmpty(films);
            } else if (operation == "size") {
                size(films);
            } else if (operation == "histori") {
                showHistory(history);
            } else if (operation == "bantuan") {
                showHelp();
            } else if (operation == "exit") {
                displayHeader("TERIMA KASIH");
                cout << "\033[1;32mProgram berakhir.\033[0m" << endl;
                break;
            }
        } catch (const exception& e) {
            errorMessage(e.what());
        }
    }

    return 0;
}