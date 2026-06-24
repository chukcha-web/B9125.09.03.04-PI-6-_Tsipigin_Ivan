#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void printEven(Node* P) {
    if (!P) {
        cout << "Список пуст" << endl;
        return;
    }

    int num = 1;
    Node* cur = P;
    bool found = false;

    while (cur) {
        if (num % 2 == 0) {
            cout << cur->data << " ";
            found = true;
        }
        cur = cur->next;
        num++;
    }

    if (!found) cout << "нет";
    cout << endl;
}

Node* createList(int n) {
    if (n <= 0) return nullptr;

    cout << "Введите " << n << " символов через пробел: ";
    char c;
    cin >> c;

    Node* head = new Node;
    head->data = c;
    head->next = nullptr;

    Node* cur = head;
    for (int i = 1; i < n; i++) {
        cin >> c;
        Node* newNode = new Node;
        newNode->data = c;
        newNode->next = nullptr;
        cur->next = newNode;
        cur = newNode;
    }

    return head;
}

void printList(Node* P) {
    if (!P) {
        cout << "Список пуст" << endl;
        return;
    }

    Node* cur = P;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void deleteList(Node*& P) {
    while (P) {
        Node* temp = P;
        P = P->next;
        delete temp;
    }
}

int main() {
    setlocale(LC_ALL, "russian");
    int n;

    cout << "Введите количество элементов списка: ";
    cin >> n;
    while (n <= 0) {
        cout << "Ошибка: количество должно быть > 0. Введите снова: ";
        cin >> n;
    }

    Node* P = createList(n);

    cout << "Список: ";
    printList(P);

    cout << "Четные: ";
    printEven(P);

    deleteList(P);

    return 0;
}