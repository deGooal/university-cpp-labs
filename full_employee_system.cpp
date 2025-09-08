// пятое
#include <iostream>
#include <string>
using namespace std;

// Предварительное объявление класса date (задание 3)
class date {
private:
    int month;
    int day;
    int year;
public:
    void getdate() {
        char slash;
        cout << "Введите дату в формате MM/DD/YY: ";
        cin >> month >> slash >> day >> slash >> year;
    }
    void showdate() const {
        cout << (month < 10 ? "0" : "") << month << '/'
             << (day < 10 ? "0" : "") << day << '/'
             << (year < 10 ? "0" : "") << year;
    }
};

// Объявление перечисления etype
enum etype { laborer, secretary, manager, accountant, executive, researcher };

class employee {
private:
    int number;
    float salary;
    date hireDate; // Объект класса date для хранения даты приема
    etype empType; // Переменная перечислимого типа для хранения должности

public:
    // Метод для ввода всех данных о сотруднике
    void getemploy() {
        char typeChar; // Для ввода первой буквы должности

        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите оклад сотрудника: ";
        cin >> salary;
        cout << "Введите дату приема на работу ";
        hireDate.getdate();
        cout << "Введите первую букву должности (l, s, m, a, e, r): ";
        cin >> typeChar;

        // Используем switch для преобразования буквы в значение etype
        switch (typeChar) {
            case 'l': empType = laborer; break;
            case 's': empType = secretary; break;
            case 'm': empType = manager; break;
            case 'a': empType = accountant; break;
            case 'e': empType = executive; break;
            case 'r': empType = researcher; break;
            default:  empType = laborer; // Значение по умолчанию
        }
    }

    // Метод для отображения всех данных о сотруднике
    void putemploy() const {
        string typeName; // Строковое представление должности

        // Используем switch для преобразования etype в строку
        switch (empType) {
            case laborer:    typeName = "лаборант"; break;
            case secretary:  typeName = "секретарь"; break;
            case manager:    typeName = "менеджер"; break;
            case accountant: typeName = "бухгалтер"; break;
            case executive:  typeName = "директор"; break;
            case researcher: typeName = "исследователь"; break;
        }

        cout << "Сотрудник №" << number;
        cout << ", Оклад: " << salary;
        cout << ", Дата приема: "; hireDate.showdate();
        cout << ", Должность: " << typeName << endl;
    }
};

int main() {
    employee staff[3];

    cout << "Введите данные о трех сотрудниках:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\n--- Сотрудник " << i + 1 << " ---" << endl;
        staff[i].getemploy();
    }

    cout << "\n=== Информация о всех сотрудниках ===" << endl;
    for (int i = 0; i < 3; i++) {
        staff[i].putemploy();
    }

    return 0;
}