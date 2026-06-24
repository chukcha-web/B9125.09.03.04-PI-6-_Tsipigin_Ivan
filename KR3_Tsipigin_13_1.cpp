#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Ticket
{
    string flightName;  
    string destination; 
    Date date;           
};

bool isLeapYear(int year)
{
    return (year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0);
}

bool isValidDate(const Date& d)
{
    if (d.month < 1 || d.month > 12)
        return false;

    int daysInMonth[] =
    {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (isLeapYear(d.year))
        daysInMonth[1] = 29;

    return d.day >= 1 &&
        d.day <= daysInMonth[d.month - 1];
}

int main(){
    setlocale(LC_ALL, "russian");
    ifstream fin("input.txt");

    if (!fin)
    {
        cout << "Ошибка: файл input.txt не найден или недоступен для чтения."
            << endl;
        return 1;
    }

    int n;

    if (!(fin >> n) || n <= 0)
    {
        cout << "Ошибка: некорректное количество записей в файле."
            << endl;
        return 1;
    }

    map<string, map<int, int> > stat;

    for (int i = 0; i < n; i++)
    {
        Ticket t;
        char dot1, dot2;

        if (!(fin >> t.flightName
            >> t.destination
            >> t.date.day
            >> dot1
            >> t.date.month
            >> dot2
            >> t.date.year))
        {
            cout << "Ошибка: неверный формат данных в записи №"
                << i + 1 << "." << endl;
            return 1;
        }

        if (!isValidDate(t.date))
        {
            cout << "Ошибка: некорректная дата "
                << t.date.day << "."
                << t.date.month << "."
                << t.date.year
                << " в записи №"
                << i + 1 << "." << endl;

            return 1;
        }

        stat[t.destination][t.date.month]++;
    }

    fin.close();

    cout << "Обработка данных завершена успешно." << endl;
    cout << "Сформирована статистика продаж авиабилетов по направлениям и месяцам."
        << endl << endl;

    map<string, map<int, int> >::iterator dir;

    for (dir = stat.begin(); dir != stat.end(); ++dir)
    {
        cout << "Направление: "
            << dir->first << endl;

        map<int, int>::iterator month;

        for (month = dir->second.begin();
            month != dir->second.end();
            ++month)
        {
            cout << "  Месяц "
                << month->first
                << " - "
                << month->second
                << " билетов"
                << endl;
        }

        cout << endl;
    }

    cout << "Работа программы завершена успешно."
        << endl;
}