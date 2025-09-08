// вторая
#include <iostream>
using namespace std;

class employee {
private:
    int number;   // Номер сотрудника
    float salary; // Величина оклада

public:
    // Метод для ввода данных
    void getemploy() {
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите оклад сотрудника: ";
        cin >> salary;
    }

    // Метод для отображения данных
    void putemploy() const { // const, так метод не меняет объект
        cout << "Сотрудник №" << number;
        cout << ", Оклад: " << salary << endl;
    }
};

int main() {
    // Создаем массив из трех сотрудников
    employee emp[3];

    // Запрашиваем ввод данных для каждого сотрудника
    cout << "Введите данные о трех сотрудниках:\n";
    for (int i = 0; i < 3; i++) {
        cout << "--- Сотрудник " << i+1 << " ---" << endl;
        emp[i].getemploy();
    }

    // Выводим полученную информацию на экран
    cout << "\nИнформация о сотрудниках:\n";
    for (int i = 0; i < 3; i++) {
        emp[i].putemploy();
    }

    return 0;
}