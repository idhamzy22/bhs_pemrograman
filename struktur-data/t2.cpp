#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }

    // Insert node at the beginning
    void insertFront(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert node in the middle after a given node
    void insertMiddle(int value, int afterValue) {
        Node* newNode = new Node;
        newNode->data = value;
        Node* current = head;
        while (current != NULL && current->data != afterValue) {
            current = current->next;
        }
        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            cout << "Node with value " << afterValue << " not found!" << endl;
        }
    }

    // Insert node at the end
    void insertEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Delete node from the beginning
    void deleteFront() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "List is empty!" << endl;
        }
    }

    // Delete node from the middle
    void deleteMiddle(int value) {
        if (head != NULL) {
            Node* current = head;
            Node* prev = NULL;
            while (current != NULL && current->data != value) {
                prev = current;
                current = current->next;
            }
            if (current != NULL) {
                prev->next = current->next;
                delete current;
            } else {
                cout << "Node with value " << value << " not found!" << endl;
            }
        } else {
            cout << "List is empty!" << endl;
        }
    }

    // Delete node from the end
    void deleteEnd() {
        if (head != NULL) {
            if (head->next == NULL) {
                delete head;
                head = NULL;
            } else {
                Node* current = head;
                Node* prev = NULL;
                while (current->next != NULL) {
                    prev = current;
                    current = current->next;
                }
                prev->next = NULL;
                delete current;
            }
        } else {
            cout << "List is empty!" << endl;
        }
    }

    // Display the linked list
    void display() {
        Node* current = head;
        if (current == NULL) {
            cout << "List is empty!" << endl;
        } else {
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList list;
    char choice;
    int value, afterValue;

    do {
        cout << "Menu:" << endl;
        cout << "a. Insert depan" << endl;
        cout << "b. Insert tengah" << endl;
        cout << "c. Insert belakang" << endl;
        cout << "d. Delete depan" << endl;
        cout << "e. Delete tengah" << endl;
        cout << "f. Delete belakang" << endl;
        cout << "g. Tampilkan data" << endl;
        cout << "h. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Masukkan nilai: ";
                cin >> value;
                list.insertFront(value);
                break;
            case 'b':
                cout << "Masukkan nilai: ";
                cin >> value;
                cout << "Setelah nilai: ";
                cin >> afterValue;
                list.insertMiddle(value, afterValue);
                break;
            case 'c':
                cout << "Masukkan nilai: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 'd':
                list.deleteFront();
                break;
            case 'e':
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> value;
                list.deleteMiddle(value);
                break;
            case 'f':
                list.deleteEnd();
                break;
            case 'g':
                cout << "Data linked list: ";
                list.display();
                break;
            case 'h':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 'h');

    return 0;
}