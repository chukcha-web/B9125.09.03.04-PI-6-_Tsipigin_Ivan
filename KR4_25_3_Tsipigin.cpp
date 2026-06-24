#include <iostream>
using namespace std;

void printBinary(unsigned short num) {
    const int bits = sizeof(unsigned short) * 8;
    for (int i = 0; i < bits; ++i) {
        cout << ((num >> i) & 1);
    }
}

int main() {
    setlocale(LC_ALL, "russian");
    unsigned short X;
    int x;
    cout << "Введите безнаковое короткое целое число X в границах (от 0 до 65535): ";
    cin >> x;
    if (x <= 0 || x > 65535) {
        cout << "Граниыц от 0 до 65535!";
        return 0;
    }
    X = x;
    const int bits = sizeof(unsigned short) * 8;

    unsigned short mask = 0;
    for (int i = 0; i < bits; ++i) {
        if ((i + 1) % 4 != 0){
            mask |= (1u << i);
        }
    }

    unsigned short result = X & mask;
    cout << "Исходное число: " << X << " " << endl;
    cout << "Исходное число: " << endl;
    printBinary(X);
    cout << "\n";
    cout << "Результат:" << result << endl;
    cout << "Результат:" << endl;
    printBinary(result);

}