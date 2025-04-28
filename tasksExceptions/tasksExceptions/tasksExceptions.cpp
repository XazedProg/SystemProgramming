#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;

class MyException : public exception {
private:
    string message;
public:
    MyException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

//Функция деления с обработкой деления на ноль
double divideNumbers(double a, double b) {
    if (b == 0) {
        throw runtime_error("Ошибка: деление на ноль!");
    }
    return a / b;
}

//Функция проверки возраста
void checkAge(int age) {
    if (age < 0 || age > 120) {
        throw out_of_range("Ошибка: возраст должен быть от 0 до 120 лет!");
    }
}

//Функция суммы элементов массива
int sumArray(const int arr[], int size) {
    if (size < 0) {
        throw invalid_argument("Ошибка: размер массива не может быть отрицательным!");
    }
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

//Функция вычисления квадратного корня
double calculateSquareRoot(double num) {
    if (num < 0) {
        throw domain_error("Ошибка: нельзя извлечь квадратный корень из отрицательного числа!");
    }
    return sqrt(num);
}

//Функция поиска элемента в массиве
int findElement(const int arr[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            return i;
        }
    }
    throw MyException("Ошибка: элемент не найден в массиве!");
}


class Divider {
public:
    static double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Ошибка Divider: деление на ноль!");
        }
        return a / b;
    }
};

class Age {
private:
    int age;
public:
    Age(int a) : age(a) {
        if (a < 0 || a > 120) {
            throw out_of_range("Ошибка Age: недопустимый возраст!");
        }
    }
    int getAge() const { return age; }
};

class MyArray {
private:
    vector<int> arr;
public:
    MyArray(const vector<int>& a) : arr(a) {}
    int getElement(int index) const {
        if (index < 0 || index >= arr.size()) {
            throw out_of_range("Ошибка MyArray: индекс за пределами массива!");
        }
        return arr[index];
    }
};

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (den == 0) {
            throw runtime_error("Ошибка Fraction: знаменатель не может быть нулем!");
        }
    }
    string toString() const {
        return to_string(numerator) + "/" + to_string(denominator);
    }
};

class SquareRoot {
public:
    static double calculate(double num) {
        if (num < 0) {
            throw domain_error("Ошибка SquareRoot: нельзя извлечь корень из отрицательного числа!");
        }
        return sqrt(num);
    }
};

class Calculator {
public:
    static double add(double a, double b) { return a + b; }
    static double subtract(double a, double b) { return a - b; }
    static double multiply(double a, double b) { return a * b; }
    static double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Ошибка Calculator: деление на ноль!");
        }
        return a / b;
    }
};

class Stack {
private:
    vector<int> elements;
public:
    void push(int element) {
        elements.push_back(element);
    }
    int pop() {
        if (elements.empty()) {
            throw runtime_error("Ошибка Stack: стек пуст!");
        }
        int element = elements.back();
        elements.pop_back();
        return element;
    }
};

class Point {
private:
    double x, y;
public:
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {
        if (x < -100 || x > 100 || y < -100 || y > 100) {
            throw out_of_range("Ошибка Point: координаты должны быть в диапазоне [-100, 100]!");
        }
    }
    string toString() const {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

class StringArray {
private:
    vector<string> arr;
public:
    StringArray(const vector<string>& a) : arr(a) {}
    string getString(int index) const {
        if (index < 0 || index >= arr.size()) {
            throw out_of_range("Ошибка StringArray: индекс за пределами массива!");
        }
        return arr[index];
    }
};

class Square {
private:
    double side;
public:
    Square(double s) : side(s) {
        if (s < 0) {
            throw invalid_argument("Ошибка Square: сторона не может быть отрицательной!");
        }
    }
    double getArea() const { return side * side; }
};


int stringToInt(const string& str) {
    try {
        return stoi(str);
    }
    catch (const invalid_argument&) {
        throw invalid_argument("Ошибка: строка не может быть преобразована в число!");
    }
    catch (const out_of_range&) {
        throw out_of_range("Ошибка: число слишком большое!");
    }
}

// Функция для чтения файла
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Ошибка: не удалось открыть файл!");
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}

void logError(const string& error) {
    ofstream logfile("error_log.txt", ios::app);
    if (logfile.is_open()) {
        logfile << error << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    cout << "Выберите задание (1-20): ";
    cin >> choice;

    try {
        switch (choice) {

        case 1: {
            double a, b;
            cout << "Введите два числа: ";
            cin >> a >> b;
            cout << "Результат: " << divideNumbers(a, b) << endl;
            break;
        }

        case 2: {
            int age;
            cout << "Введите возраст: ";
            cin >> age;
            checkAge(age);
            cout << "Возраст корректен!" << endl;
            break;
        }

        case 3: {
            int size;
            cout << "Введите размер массива: ";
            cin >> size;
            int* arr = new int[size];
            cout << "Введите элементы массива: ";
            for (int i = 0; i < size; ++i) cin >> arr[i];
            cout << "Сумма: " << sumArray(arr, size) << endl;
            delete[] arr;
            break;
        }

        case 4: {
            double num;
            cout << "Введите число: ";
            cin >> num;
            cout << "Квадратный корень: " << calculateSquareRoot(num) << endl;
            break;
        }

        case 5: {
            int size, element;
            cout << "Введите размер массива: ";
            cin >> size;
            int* arr = new int[size];
            cout << "Введите элементы массива: ";
            for (int i = 0; i < size; ++i) cin >> arr[i];
            cout << "Введите элемент для поиска: ";
            cin >> element;
            cout << "Индекс элемента: " << findElement(arr, size, element) << endl;
            delete[] arr;
            break;
        }

        case 6: {
            double a, b;
            cout << "Введите два числа: ";
            cin >> a >> b;
            cout << "Результат: " << Divider::divide(a, b) << endl;
            break;
        }

        case 7: {
            int age;
            cout << "Введите возраст: ";
            cin >> age;
            Age a(age);
            cout << "Создан объект Age с возрастом: " << a.getAge() << endl;
            break;
        }

        case 8: {
            vector<int> arr = { 1, 2, 3, 4, 5 };
            MyArray myArr(arr);
            int index;
            cout << "Введите индекс (0-4): ";
            cin >> index;
            cout << "Элемент: " << myArr.getElement(index) << endl;
            break;
        }

        case 9: {
            int num, den;
            cout << "Введите числитель и знаменатель: ";
            cin >> num >> den;
            Fraction f(num, den);
            cout << "Дробь: " << f.toString() << endl;
            break;
        }

        case 10: {
            double num;
            cout << "Введите число: ";
            cin >> num;
            cout << "Квадратный корень: " << SquareRoot::calculate(num) << endl;
            break;
        }

        case 11: {
            double a, b;
            char op;
            cout << "Введите два числа и оператор (+, -, *, /): ";
            cin >> a >> b >> op;
            double result;
            switch (op) {
            case '+': result = Calculator::add(a, b); break;
            case '-': result = Calculator::subtract(a, b); break;
            case '*': result = Calculator::multiply(a, b); break;
            case '/': result = Calculator::divide(a, b); break;
            default: throw invalid_argument("Неверный оператор!");
            }
            cout << "Результат: " << result << endl;
            break;
        }

        case 12: {
            string input;
            cout << "Введите число: ";
            cin >> input;
            cout << "Число: " << stringToInt(input) << endl;
            break;
        }

        case 13: {
            Stack s;
            s.push(10);
            cout << "Извлеченный элемент: " << s.pop() << endl;
            cout << "Извлеченный элемент: " << s.pop() << endl;
            break;
        }

        case 14: {
            double x, y;
            cout << "Введите координаты x и y (от -100 до 100): ";
            cin >> x >> y;
            Point p(x, y);
            cout << "Точка: " << p.toString() << endl;
            break;
        }

        case 15: {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            cout << "Содержимое файла:\n" << readFile(filename) << endl;
            break;
        }

        case 16: {
            vector<string> arr = { "one", "two", "three" };
            StringArray sa(arr);
            int index;
            cout << "Введите индекс (0-2): ";
            cin >> index;
            cout << "Строка: " << sa.getString(index) << endl;
            break;
        }

        case 17: {
            double side;
            cout << "Введите длину стороны: ";
            cin >> side;
            Square sq(side);
            cout << "Площадь квадрата: " << sq.getArea() << endl;
            break;
        }

        case 18: {
            string str;
            cout << "Введите строку с числом: ";
            cin >> str;
            cout << "Число: " << stringToInt(str) << endl;
            break;
        }

        case 19: {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            ifstream file(filename);
            if (!file.is_open()) {
                throw runtime_error("Не удалось открыть файл в main!");
            }
            cout << "Файл успешно открыт!" << endl;
            break;
        }

        case 20: {
            try {
                cout << "Результат деления: " << divideNumbers(10, 0) << endl;
            }
            catch (const exception& e) {
                cout << "Поймано исключение: " << e.what() << endl;
                logError(e.what());
            }

            try {
                checkAge(150);
            }
            catch (const exception& e) {
                cout << "Поймано исключение: " << e.what() << endl;
                logError(e.what());
            }

            try {
                int arr[] = { 1, 2, 3 };
                cout << "Сумма массива: " << sumArray(arr, -1) << endl;
            }
            catch (const exception& e) {
                cout << "Поймано исключение: " << e.what() << endl;
                logError(e.what());
            }
            break;
        }
        default:
            cout << "Неверный выбор!" << endl;
        }

    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        logError(e.what());
    }

    return 0;
}