#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    double x, eps;
    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите точность eps (например, 1e-9): ";
    cin >> eps;
    if (eps >= 1 || eps <= 0) {
        cout << "Значение eps не должно быть в промежутке от 0 до 1!";
        return 1;

    }
    double a = x;         
    double sum = a;        
    int n = 0;

    cout << "Рекуррентное соотношение: a(n) = a(n-1) * (-x^2) / ((2n)(2n+1))\n";
    cout << "a0 = " << a << "\n\n";

    while ((a >= eps) || (a <= -eps)) {
        n++;
        a = a * (-x * x) / ((2.0 * n) * (2.0 * n + 1.0));
        sum += a;

        cout << "a" << n << " = " << a << "\t(сумма = " << sum << ")\n";
    }

    cout << "sin(" << x << ") ≈ " << sum << endl;
    cout << "Количество использованных членов ряда: " << n + 1 << endl;
    cout << "Последний учтенный член: " << a << endl;
}