#include <iostream>
#include <set>
#include <map>
#include <ctime>
using namespace std;

int inputPositiveInt(const string& message) {
    int value;
    while (true) {
        cout << message;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка: введите целое число!" << endl;
            continue;
        }

        if (value <= 0) {
            cout << "Ошибка: число должно быть положительным!" << endl;
            continue;
        }

        return value;
    }
}

void task2() {
    setlocale(LC_ALL, "russian");
    int M = inputPositiveInt("Введите длину первой последовательности: ");
    int N = inputPositiveInt("Введите длину второй последовательности: ");

    int* a = new int[M];
    int* b = new int[N];

    srand(time(nullptr));

    cout << "A: ";
    for (int i = 0; i < M; i++) {
        a[i] = rand() % 100 + 1;
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "B: ";
    for (int i = 0; i < N; i++) {
        b[i] = rand() % 100 + 1;
        cout << b[i] << " ";
    }
    cout << endl;

    map<int, int> cntA, cntB;
    for (int i = 0; i < M; i++) cntA[a[i]]++;
    for (int i = 0; i < N; i++) cntB[b[i]]++;

    set<int> result;
    for (map<int, int>::iterator it = cntA.begin(); it != cntA.end(); ++it) {
        if (it->second > 1 && cntB[it->first] > 1) {
            result.insert(it->first);
        }
    }

    cout << "Результат: ";
    if (result.empty()) {
        cout << "нет таких чисел";
    }
    else {
        for (set<int>::iterator it = result.begin(); it != result.end(); ++it) {
            cout << *it << " ";
        }
    }
    cout << endl;

    delete[] a;
    delete[] b;
}

int main() {
    task2();
    return 0;
}