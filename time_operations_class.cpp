// четвертое
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Конструктор, инициализирующий поля нулевыми значениями
    Time() : hours(0), minutes(0), seconds(0) {}

    // Конструктор, инициализирующий поля заданными значениями
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Метод для вывода времени в формате HH:MM:SS
    void showtime() const { // const, так метод не меняет объект
        cout << (hours < 10 ? "0" : "") << hours << ":";
        cout << (minutes < 10 ? "0" : "") << minutes << ":";
        cout << (seconds < 10 ? "0" : "") << seconds;
    }

    // Метод для сложения двух объектов Time
    Time add(const Time& t) const { // исправил time -> Time
        Time result;
        result.seconds = this->seconds + t.seconds;
        result.minutes = this->minutes + t.minutes;
        result.hours = this->hours + t.hours;

        // Обрабатываем переполнение
        if (result.seconds >= 60) {
            result.seconds -= 60;
            result.minutes++;
        }
        if (result.minutes >= 60) {
            result.minutes -= 60;
            result.hours++;
        }
        if (result.hours >= 24) { // переносим проверку сюда
            result.hours -= 24;
        }
        return result;
    }
};

int main() {
    // Создаем два инициализированных объекта
    // Метод add объявлен const, поэтому может работать и с константными объектами
    Time time1(5, 59, 59); // 5 часов, 59 минут, 59 секунд
    Time time2(1, 30, 2);  // 1 час, 30 минут, 2 секунды

    // Создаем один неинициализированный объект (инициализирован нулями)
    Time time3;

    // Складываем два инициализированных объекта, результат присваиваем третьему
    time3 = time1.add(time2); // исправил Time3 -> time3

    // Выводим значение третьего объекта на экран
    cout << "Time1: "; time1.showtime(); cout << endl;
    cout << "Time2: "; time2.showtime(); cout << endl;
    cout << "Time1 + Time2: "; time3.showtime(); cout << endl;

    return 0;
}
