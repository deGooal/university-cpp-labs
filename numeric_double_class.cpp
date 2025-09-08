// первая
#include <iostream>
using namespace std;

class Double {
private:
    double value; // Единственное поле типа double

public:
    // Метод для установки значения равным нулю
    void setZero() {
        value = 0.0;
    }

    // Метод для инициализации целым значением
    void setInt(int intValue) {
        value = static_cast<double>(intValue);
    }

    // Метод для вывода значения на экран
    void display() const { // const, так метод не меняет объект
        cout << value;
    }

    // Метод для сложения двух объектов Double
    Double add(const Double& other) const { // const, так метод не меняет объекты
        Double result;
        result.value = this->value + other.value;
        return result;
    }

    // Метод для установки значения (пригодится для присваивания)
    void setValue(double val) {
        value = val;
    }
};

int main() {
    // Создаем три объекта класса Double
    Double num1, num2, num3;

    // Инициализируем два объекта
    num1.setInt(10);   // Инициализация целым числом 10
    num2.setInt(20);   // Инициализация целым числом 20

    // Складываем два инициализированных объекта, присваиваем результат третьему
    num3 = num1.add(num2); // Используем метод add

    // Выводим результат на экран
    cout << "Результат сложения: ";
    num3.display();
    cout << endl;

    return 0;
}