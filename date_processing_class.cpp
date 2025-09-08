// третья
#include <iostream>
using namespace std;

class date {
private:
    int month;
    int day;
    int year;

public:
    // Метод для ввода даты
    void getdate() {
        char slash; // Для хранения символа '/'
        cout << "Введите дату в формате MM/DD/YY: ";
        cin >> month >> slash >> day >> slash >> year;
    }

    // Метод для вывода даты
    void showdate() const { // const, так метод не меняет объект
        // Форматируем вывод: добавляем ведущий ноль, если нужно
        cout << (month < 10 ? "0" : "") << month << '/';
        cout << (day < 10 ? "0" : "") << day << '/';
        cout << (year < 10 ? "0" : "") << year;
    }
};

// Простой пример main для проверки
// Точка входа
int main() {
    date today;
    today.getdate();
    cout << "Введенная дата: ";
    today.showdate();
    return 0;
}