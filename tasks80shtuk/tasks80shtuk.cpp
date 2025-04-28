#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

//-------------task1------------------
class Shape1 {
public:
    virtual double area() const = 0;
    virtual ~Shape1() {}
};

class Circle1 : public Shape1 {
    double radius;
public:
    Circle1(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус не может быть отрицательным или 0");
    }
    double area() const override { return 3.14 * radius * radius; }
};

class Rectangle1 : public Shape1 {
    double width, height;
public:
    Rectangle1(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) throw invalid_argument("Стороны не могут быть отрицательными или 0");
    }
    double area() const override { return width * height; }
};

void task1() {
    try {
        Circle1 c(5);
        cout << "Circle area: " << c.area() << endl;

        Rectangle1 r(3, 4);
        cout << "Rectangle area: " << r.area() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task2------------------

class Animal2 {
public:
    virtual void speak() const = 0;
    virtual ~Animal2() {}
};

class Dog2 : public Animal2 {
    string name;
public:
    Dog2(const string& n) : name(n) {
        if (name.empty()) throw invalid_argument("Задайте имя");
    }
    void speak() const override { cout << name << "*гавкает*\n"; }
};

class Cat2 : public Animal2 {
    string name;
public:
    Cat2(const string& n) : name(n) {
        if (name.empty()) throw invalid_argument("Задайте имя");
    }
    void speak() const override { cout << name << "*мяукает*\n"; }
};

void task2() {
    try {
        Dog2 d("Rex");
        d.speak();

        Cat2 c("Fluffy");
        c.speak();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task3------------------
class BankAccount3 {
protected:
    double balance;
public:
    BankAccount3(double initial) : balance(initial) {}
    virtual void withdraw(double amount) {
        if (amount > balance) throw runtime_error("Недостаточный баланс");
        balance -= amount;
    }
    virtual ~BankAccount3() {}
    double getBalance() const { return balance; }
};

class SavingsAccount3 : public BankAccount3 {
    double minBalance;
public:
    SavingsAccount3(double initial, double min) : BankAccount3(initial), minBalance(min) {}
    void withdraw(double amount) override {
        if (balance - amount < minBalance) throw runtime_error("Баланс ниже минимального");
        BankAccount3::withdraw(amount);
    }
};

class CheckingAccount3 : public BankAccount3 {
public:
    CheckingAccount3(double initial) : BankAccount3(initial) {}
    void withdraw(double amount) override {
        if (amount > 1000) throw runtime_error("Превышает лимит на вывод средств");
        BankAccount3::withdraw(amount);
    }
};

void task3() {
    try {
        SavingsAccount3 sa(1000, 100);
        sa.withdraw(800);
        cout << "Сберегательный баланс: " << sa.getBalance() << endl;

        CheckingAccount3 ca(500);
        ca.withdraw(200);
        cout << "Проверка баланса: " << ca.getBalance() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task4------------------
class FileHandler4 {
public:
    virtual void open(const string& filename) = 0;
    virtual ~FileHandler4() {}
};

class TextFileHandler4 : public FileHandler4 {
public:
    void open(const string& filename) override {
        ifstream file(filename);
        if (!file) throw runtime_error("Файла нема");
        cout << "Откытый файл: " << filename << endl;
    }
};

class BinaryFileHandler4 : public FileHandler4 {
public:
    void open(const string& filename) override {
        ifstream file(filename, ios::binary);
        if (!file) throw runtime_error("Двоичный файл не найден");
        cout << "Открытый двоичный файл: " << filename << endl;
    }
};

void task4() {
    try {
        TextFileHandler4 tfh;
        tfh.open("file.txt");

        BinaryFileHandler4 bfh;
        bfh.open("file.bin");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task5------------------
class Shape5 {
public:
    virtual void draw() const = 0;
    virtual ~Shape5() {}
};

class Triangle5 : public Shape5 {
    double a, b, c;
public:
    Triangle5(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("неправильные стороны");
    }
    void draw() const override {
        cout << "Рисуется треугольник со сторонами: " << a << ", " << b << ", " << c << endl;
    }
};

class Square5 : public Shape5 {
    double side;
public:
    Square5(double s) : side(s) {
        if (side <= 0) throw invalid_argument("Стороны должны быть больше 0");
    }
    void draw() const override {
        cout << "рисую квадрат со сторонами: " << side << endl;
    }
};

void task5() {
    try {
        Triangle5 t(3, 4, 5);
        t.draw();

        Square5 s(10);
        s.draw();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task6------------------
class Person6 {
protected:
    string name;
    int age;
public:
    Person6(const string& n, int a) : name(n), age(a) {
        if (name.empty()) throw invalid_argument("Задайте имя");
        if (age <= 0) throw invalid_argument("Возраст не может быть 0 или меньше");
    }
    virtual void display() const {
        cout << "Имя: " << name << ", " << age << " лет" << endl;
    }
    virtual ~Person6() {}
};

class Student6 : public Person6 {
    string major;
public:
    Student6(const string& n, int a, const string& m) : Person6(n, a), major(m) {}
    void display() const override {
        cout << "Студент: " << name << ", " << age << " лет, Специальность: " << major << endl;
    }
};

class Teacher6 : public Person6 {
    string subject;
public:
    Teacher6(const string& n, int a, const string& s) : Person6(n, a), subject(s) {}
    void display() const override {
        cout << "Учитель: " << name << ", " << age << " лет, Предмет: " << subject << endl;
    }
};

void task6() {
    try {
        Student6 s("тимофей", 20, "Программист");
        s.display();

        Teacher6 t("Володя", 45, "Математика");
        t.display();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task7------------------
class Calculator7 {
public:
    virtual double calculate(double a, double b) const = 0;
    virtual ~Calculator7() {}
};

class Addition7 : public Calculator7 {
public:
    double calculate(double a, double b) const override {
        return a + b;
    }
};

class Division7 : public Calculator7 {
public:
    double calculate(double a, double b) const override {
        if (b == 0) throw runtime_error("На ноль нельзя делить, в школе не учили?");
        return a / b;
    }
};

void task7() {
    try {
        Addition7 add;
        cout << "5 + 3 = " << add.calculate(5, 3) << endl;

        Division7 div;
        cout << "10 / 2 = " << div.calculate(10, 2) << endl;
        cout << "10 / 0 = " << div.calculate(10, 0) << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task8------------------
class Game8 {
protected:
    bool isStarted;
public:
    Game8() : isStarted(false) {}
    virtual void start() {
        if (isStarted) throw runtime_error("Игра уже началась");
        isStarted = true;
    }
    virtual ~Game8() {}
};

class Chess8 : public Game8 {
public:
    void start() override {
        Game8::start();
        cout << "Шахматы начались\n";
    }
};

class Tennis8 : public Game8 {
public:
    void start() override {
        Game8::start();
        cout << "Тенис начался\n";
    }
};

void task8() {
    try {
        Chess8 chess;
        chess.start();

        Tennis8 tennis;
        tennis.start();
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task9------------------
class Document9 {
public:
    virtual void save(const string& filename) const = 0;
    virtual ~Document9() {}
};

class PDFDocument9 : public Document9 {
public:
    void save(const string& filename) const override {
        if (filename.empty()) throw invalid_argument("Задайте имя файал");
        if (filename.find(".pdf") == string::npos) throw invalid_argument("Недопустимое расширение");
        cout << "Сохраняем: " << filename << endl;
    }
};

class WordDocument9 : public Document9 {
public:
    void save(const string& filename) const override {
        if (filename.empty()) throw invalid_argument("Задайте имя файал");
        if (filename.find(".doc") == string::npos) throw invalid_argument("Недопустимое расширение");
        cout << "Сохраняем: " << filename << endl;
    }
};

void task9() {
    try {
        PDFDocument9 pdf;
        pdf.save("file.pdf");

        WordDocument9 doc;
        doc.save("file.doc");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task10------------------
class Matrix10 {
protected:
    int rows, cols;
    vector<vector<double>> data;
public:
    Matrix10(int r, int c) : rows(r), cols(c), data(r, vector<double>(c)) {}
    virtual double getElement(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            throw out_of_range("Индекс матрицы выходит за пределы допустимого диапазона");
        return data[row][col];
    }
    virtual ~Matrix10() {}
};

class IntMatrix10 : public Matrix10 {
public:
    IntMatrix10(int r, int c) : Matrix10(r, c) {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                data[i][j] = i + j;
    }
};

class FloatMatrix10 : public Matrix10 {
public:
    FloatMatrix10(int r, int c) : Matrix10(r, c) {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                data[i][j] = 0.5 * (i + j);
    }
};

void task10() {
    try {
        IntMatrix10 imat(3, 3);
        cout << "IntMatrix[1][1] = " << imat.getElement(1, 1) << endl;

        FloatMatrix10 fmat(2, 2);
        cout << "FloatMatrix[0][1] = " << fmat.getElement(0, 1) << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task11------------------
class Vehicle11 {
public:
    virtual double fuelEfficiency() const = 0;
    virtual ~Vehicle11() {}
};

class Car11 : public Vehicle11 {
    double kpl; // километры на литр
public:
    Car11(double efficiency) : kpl(efficiency) {
        if (kpl <= 0) throw invalid_argument("Эффективность должна быть положительной");
    }
    double fuelEfficiency() const override {
        return kpl;
    }
};

class Truck11 : public Vehicle11 {
    double kpl;
    double load;
public:
    Truck11(double efficiency, double l) : kpl(efficiency), load(l) {
        if (kpl <= 0) throw invalid_argument("Эффективность должна быть положительной");
        if (load < 0) throw invalid_argument("закгруженность не может быть отрицательной");
    }
    double fuelEfficiency() const override {
        return kpl * (1.0 - 0.1 * load);
    }
};

void task11() {
    try {
        Car11 car(25.5);
        cout << "Эффективность машины: " << car.fuelEfficiency() << " киломерты на литр" << endl;

        Truck11 truck(18.0, 2.5);
        cout << "Эффективность грузовика: " << truck.fuelEfficiency() << " киломерты на литр" << endl;


    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task12------------------
class User12 {
protected:
    string username;
    string password;
public:
    User12(const string& uname, const string& pwd) : username(uname), password(pwd) {}
    virtual void login(const string& pwd) const {
        if (pwd != password) throw invalid_argument("Неправильный пароль");
        cout << "Пользователь " << username << " успешный вход" << endl;
    }
    virtual ~User12() {}
};

class AdminUser12 : public User12 {
public:
    AdminUser12(const string& uname, const string& pwd) : User12(uname, pwd) {}
    void login(const string& pwd) const override {
        User12::login(pwd);
        cout << "Вы админ" << endl;
    }
};

class RegularUser12 : public User12 {
public:
    RegularUser12(const string& uname, const string& pwd) : User12(uname, pwd) {}
    void login(const string& pwd) const override {
        User12::login(pwd);
        cout << "Вы обычный чел" << endl;
    }
};

void task12() {
    try {
        AdminUser12 admin("admin", "secret123");
        admin.login("secret123");

        RegularUser12 user("timofey", "qwerty");
        user.login("qwerty");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task13------------------
class Shape13 {
public:
    virtual void scale(double factor) = 0;
    virtual ~Shape13() {}
};

class Circle13 : public Shape13 {
    double radius;
public:
    Circle13(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("радиус должен быть положительным");
    }
    void scale(double factor) override {
        if (factor <= 0) throw invalid_argument("Масштабный коэффициент должен быть положительным");
        radius *= factor;
        cout << "Окружность, масштабируемая по радиусу: " << radius << endl;
    }
};

class Square13 : public Shape13 {
    double side;
public:
    Square13(double s) : side(s) {
        if (side <= 0) throw invalid_argument("Стороны должны быть положительными");
    }
    void scale(double factor) override {
        if (factor <= 0) throw invalid_argument("Масштабный коэффициент должен быть положительным");
        side *= factor;
        cout << "Окружность, масштабируемая по сторнам: " << side << endl;
    }
};

void task13() {
    try {
        Circle13 circle(5.0);
        circle.scale(1.5);

        Square13 square(10.0);
        square.scale(0.8);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task14------------------
class Library14 {
protected:
    vector<string> availableBooks;
public:
    Library14(const vector<string>& books) : availableBooks(books) {}
    virtual void borrowBook(const string& title) {
        auto it = find(availableBooks.begin(), availableBooks.end(), title);
        if (it == availableBooks.end()) throw runtime_error("Книга не найдена");
        availableBooks.erase(it);
        cout << "Книга напрокат: " << title << endl;
    }
    virtual ~Library14() {}
};

class FictionLibrary14 : public Library14 {
public:
    FictionLibrary14() : Library14({ "2222", "3333", "4444" }) {}
    void borrowBook(const string& title) override {
        Library14::borrowBook(title);
        cout << "Приятного чтения" << endl;
    }
};

class NonFictionLibrary14 : public Library14 {
public:
    NonFictionLibrary14() : Library14({ "5555", "6666", "7777" }) {}
    void borrowBook(const string& title) override {
        Library14::borrowBook(title);
        cout << "У меня уже нет идей, что можно написать" << endl;
    }
};

void task14() {
    try {
        FictionLibrary14 fictionLib;
        fictionLib.borrowBook("1111");

        NonFictionLibrary14 nonFictionLib;
        nonFictionLib.borrowBook("5555");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task15-----------------
class Order15 {
protected:
    string orderId;
    double amount;
public:
    Order15(const string& id, double amt) : orderId(id), amount(amt) {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
    }
    virtual void process() const {
        cout << "В обработке #" << orderId << " за $" << amount << endl;
    }
    virtual ~Order15() {}
};

class OnlineOrder15 : public Order15 {
    string email;
public:
    OnlineOrder15(const string& id, double amt, const string& em)
        : Order15(id, amt), email(em) {
        if (email.empty() || email.find('@') == string::npos)
            throw invalid_argument("Некорректная почта");
    }
    void process() const override {
        Order15::process();
        cout << "Отправка подтверждения по адресу: " << email << endl;
    }
};

class InStoreOrder15 : public Order15 {
    int storeId;
public:
    InStoreOrder15(const string& id, double amt, int store)
        : Order15(id, amt), storeId(store) {
        if (storeId <= 0) throw invalid_argument("Некорректный айди магазина");
    }
    void process() const override {
        Order15::process();
        cout << "Готов к отправке в магазин #" << storeId << endl;
    }
};

void task15() {
    try {
        OnlineOrder15 online("ON123", 99.99, "customer@example.com");
        online.process();

        InStoreOrder15 instore("IS456", 49.99, 5);
        instore.process();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task16------------------
class Shape16 {
public:
    virtual void rotate(double angle) = 0;
    virtual ~Shape16() {}
};

class Triangle16 : public Shape16 {
    double angle;
public:
    Triangle16() : angle(0) {}
    void rotate(double newAngle) override {
        if (newAngle < 0 || newAngle >= 360)
            throw invalid_argument("угол должен быть от 0 до 360 градусов");
        angle = newAngle;
        cout << "Треугольник повернут на " << angle << " градусов" << endl;
    }
};

class Rectangle16 : public Shape16 {
    double angle;
public:
    Rectangle16() : angle(0) {}
    void rotate(double newAngle) override {
        if (newAngle < 0 || newAngle >= 360)
            throw invalid_argument("угол должен быть от 0 до 360 градусов");
        angle = newAngle;
        cout << "Прямоугольник повернут на " << angle << " градусов" << endl;
    }
};

void task16() {
    try {
        Triangle16 tri;
        tri.rotate(45);

        Rectangle16 rect;
        rect.rotate(90);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task17------------------
class Payment17 {
protected:
    double amount;
public:
    Payment17(double amt) : amount(amt) {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
    }
    virtual void processPayment() const = 0;
    virtual ~Payment17() {}
};

class CreditCardPayment17 : public Payment17 {
    string cardNumber;
public:
    CreditCardPayment17(double amt, const string& num)
        : Payment17(amt), cardNumber(num) {
        if (cardNumber.length() != 16)
            throw invalid_argument("Номер карты должен состоять из 16 цифр");
    }
    void processPayment() const override {
        cout << "Обработка платежей по кредитным картам в размере $" << amount
            << " карта: " << cardNumber.substr(12) << endl;
    }
};

class PayPalPayment17 : public Payment17 {
    string email;
public:
    PayPalPayment17(double amt, const string& em)
        : Payment17(amt), email(em) {
        if (email.empty() || email.find('@') == string::npos)
            throw invalid_argument("Некорректная почта");
    }
    void processPayment() const override {
        cout << "Обработка платежа PayPal по $" << amount
            << " на " << email << endl;
    }
};

void task17() {
    try {
        CreditCardPayment17 cc(100.0, "1234567812345678");
        cc.processPayment();

        PayPalPayment17 pp(50.0, "user@example.com");
        pp.processPayment();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task18------------------
class ExceptionHandler18 {
public:
    virtual void handle(const exception& e) const = 0;
    virtual ~ExceptionHandler18() {}
};

class FileExceptionHandler18 : public ExceptionHandler18 {
public:
    void handle(const exception& e) const override {
        cerr << "Ошибка файла: " << e.what() << " (logging to file)" << endl;
    }
};

class NetworkExceptionHandler18 : public ExceptionHandler18 {
public:
    void handle(const exception& e) const override {
        cerr << "Ошибка соединения: " << e.what() << " (retrying connection)" << endl;
    }
};

void task18() {
    try {
        FileExceptionHandler18 feh;
        feh.handle(runtime_error("Файл не найден"));

        NetworkExceptionHandler18 neh;
        neh.handle(runtime_error("Подключение истекло"));
    }
    catch (...) {
        cerr << "Непредвиденная ошибка в обработчиках исключений" << endl;
    }
}
//-------------task19------------------
class Course19 {
protected:
    string name;
    int capacity;
    int enrolled;
public:
    Course19(const string& n, int cap) : name(n), capacity(cap), enrolled(0) {}
    virtual void enroll() {
        if (enrolled >= capacity)
            throw runtime_error("Курс полный");
        enrolled++;
        cout << "Зачислен в " << name << " (" << enrolled << "/" << capacity << ")" << endl;
    }
    virtual ~Course19() {}
};

class OnlineCourse19 : public Course19 {
public:
    OnlineCourse19(const string& n, int cap) : Course19(n, cap) {}
    void enroll() override {
        Course19::enroll();
        cout << "Доступ к онлайн-материалам предоставлен" << endl;
    }
};

class OfflineCourse19 : public Course19 {
    string location;
public:
    OfflineCourse19(const string& n, int cap, const string& loc)
        : Course19(n, cap), location(loc) {}
    void enroll() override {
        Course19::enroll();
        cout << "Местоположение класса: " << location << endl;
    }
};

void task19() {
    try {
        OnlineCourse19 oc("C++ Programming", 30);
        oc.enroll();

        OfflineCourse19 fc("Data Structures", 20, "УПК2");
        fc.enroll();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task20------------------
class ShoppingCart20 {
protected:
    vector<string> items;
public:
    virtual void checkout() const {
        if (items.empty()) throw runtime_error("");
        cout << "Checking out " << items.size() << " items:" << endl;
        for (const auto& item : items) {
            cout << "- " << item << endl;
        }
    }
    void addItem(const string& item) {
        items.push_back(item);
    }
    virtual ~ShoppingCart20() {}
};

class RegularCart20 : public ShoppingCart20 {
public:
    void checkout() const override {
        ShoppingCart20::checkout();
        cout << "Итого: $" << items.size() * 10 << endl;
    }
};

class DiscountedCart20 : public ShoppingCart20 {
    double discount;
public:
    DiscountedCart20(double disc) : discount(disc) {
        if (discount <= 0 || discount >= 1)
            throw invalid_argument("Размер скидки должен составлять от 0 до 1");
    }
    void checkout() const override {
        ShoppingCart20::checkout();
        double total = items.size() * 10 * (1 - discount);
        cout << "итог после " << discount * 100 << "% скидки: $" << total << endl;
    }
};

void task20() {
    try {
        RegularCart20 regCart;
        regCart.addItem("Книга");
        regCart.addItem("Ручка");
        regCart.checkout();

        DiscountedCart20 discCart(0.2); // 20% discount
        discCart.addItem("Блокнот");
        discCart.addItem("Карандаш");
        discCart.addItem("Стерка");
        discCart.checkout();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task21------------------
class Shape21 {
public:
    virtual void translate(double x, double y) = 0;
    virtual ~Shape21() {}
};

class Circle21 : public Shape21 {
    double centerX, centerY, radius;
public:
    Circle21(double x, double y, double r) : centerX(x), centerY(y), radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    void translate(double x, double y) override {
        if (isinf(x) || isinf(y) || isnan(x) || isnan(y))
            throw invalid_argument("Недопустимые координаты перемещения");
        centerX += x;
        centerY += y;
        cout << "Круг перемещен в (" << centerX << ", " << centerY << ")" << endl;
    }
};

class Rectangle21 : public Shape21 {
    double x1, y1, x2, y2;
public:
    Rectangle21(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
        if (x1 >= x2 || y1 >= y2) throw invalid_argument("Недопустимые координаты прямоугольника");
    }
    void translate(double x, double y) override {
        if (isinf(x) || isinf(y) || isnan(x) || isnan(y))
            throw invalid_argument("Недопустимые координаты перемещения");
        x1 += x; y1 += y;
        x2 += x; y2 += y;
        cout << "Прямоугольник перемещен в (" << x1 << ", " << y1 << ")-(" << x2 << ", " << y2 << ")" << endl;
    }
};

void task21() {
    try {
        Circle21 circle(0, 0, 5);
        circle.translate(2, 3);

        Rectangle21 rect(1, 1, 3, 4);
        rect.translate(-1, 2);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task22------------------
class Database22 {
public:
    virtual void connect(const string& connectionString) = 0;
    virtual ~Database22() {}
};

class MySQLDatabase22 : public Database22 {
public:
    void connect(const string& connectionString) override {
        if (connectionString.empty() || connectionString.find("mysql://") == string::npos)
            throw runtime_error("Неверная строка подключения MySQL");
        cout << "Подключено к MySQL: " << connectionString << endl;
    }
};

class SQLiteDatabase22 : public Database22 {
public:
    void connect(const string& connectionString) override {
        if (connectionString.empty() || connectionString.find(".db") == string::npos)
            throw runtime_error("Неверная строка подключения SQLite");
        cout << "Подключено к SQLite: " << connectionString << endl;
    }
};

void task22() {
    try {
        MySQLDatabase22 mysql;
        mysql.connect("mysql://localhost:3306/mydb");

        SQLiteDatabase22 sqlite;
        sqlite.connect("data.db");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task23------------------
class Task23 {
public:
    virtual void execute() = 0;
    virtual ~Task23() {}
};

class PrintTask23 : public Task23 {
    string message;
public:
    PrintTask23(const string& msg) : message(msg) {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
    }
    void execute() override {
        cout << "Печать: " << message << endl;
    }
};

class EmailTask23 : public Task23 {
    string recipient, subject, body;
public:
    EmailTask23(const string& rec, const string& subj, const string& bd)
        : recipient(rec), subject(subj), body(bd) {
        if (recipient.empty() || recipient.find('@') == string::npos)
            throw invalid_argument("Некорректный получатель");
    }
    void execute() override {
        cout << "Отправка email '" << subject << "' to " << recipient << endl;
    }
};

void task23() {
    try {
        PrintTask23 print("Hello World");
        print.execute();

        EmailTask23 email("user@example.com", "Test", "This is a test email");
        email.execute();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task24------------------
class Shape24 {
public:
    virtual double getPerimeter() const = 0;
    virtual ~Shape24() {}
};

class Triangle24 : public Shape24 {
    double a, b, c;
public:
    Triangle24(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Недопустимые стороны треугольника");
    }
    double getPerimeter() const override { return a + b + c; }
};

class Square24 : public Shape24 {
    double side;
public:
    Square24(double s) : side(s) {
        if (side <= 0) throw invalid_argument("Сторона должна быть положительной");
    }
    double getPerimeter() const override { return 4 * side; }
};

void task24() {
    try {
        Triangle24 tri(3, 4, 5);
        cout << "Периметр треугольника: " << tri.getPerimeter() << endl;

        Square24 sq(10);
        cout << "Периметр квадрата: " << sq.getPerimeter() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task25------------------
class WeatherService25 {
public:
    virtual string getForecast(const string& location) const = 0;
    virtual ~WeatherService25() {}
};

class LocalWeatherService25 : public WeatherService25 {
public:
    string getForecast(const string& location) const override {
        if (location.empty()) throw runtime_error("Местоположение не указано");
        return "Местный прогноз для " + location + ": Солнечно, 25°C";
    }
};

class RemoteWeatherService25 : public WeatherService25 {
public:
    string getForecast(const string& location) const override {
        if (location.empty()) throw runtime_error("Местоположение не указано");
        if (location == "Антарктида") throw runtime_error("Нет данных для удаленного местоположения");
        return "Удаленный прогноз для " + location + ": Облачно, 18°C";
    }
};

void task25() {
    try {
        LocalWeatherService25 local;
        cout << local.getForecast("Москва") << endl;

        RemoteWeatherService25 remote;
        cout << remote.getForecast("Лондон") << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task26------------------
class Transaction26 {
public:
    virtual void commit() = 0;
    virtual ~Transaction26() {}
};

class BankTransaction26 : public Transaction26 {
    double amount;
public:
    BankTransaction26(double amt) : amount(amt) {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
    }
    void commit() override {
        if (amount > 10000) throw runtime_error("Превышен лимит банковской транзакции");
        cout << "Банковская транзакция на $" << amount << " выполнена" << endl;
    }
};

class CryptoTransaction26 : public Transaction26 {
    double amount;
    string wallet;
public:
    CryptoTransaction26(double amt, const string& w) : amount(amt), wallet(w) {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        if (wallet.length() != 42) throw invalid_argument("Некорректный кошелек");
    }
    void commit() override {
        cout << "Крипто транзакция " << amount << " ETH на кошелек "
            << wallet.substr(0, 6) << "..." << wallet.substr(38) << endl;
    }
};

void task26() {
    try {
        BankTransaction26 bank(5000);
        bank.commit();

        CryptoTransaction26 crypto(1.5, "0x71C7656EC7ab88b098defB751B7401B5f6d8976F");
        crypto.commit();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task27------------------
class Notification27 {
public:
    virtual void send(const string& message) = 0;
    virtual ~Notification27() {}
};

class EmailNotification27 : public Notification27 {
    string email;
public:
    EmailNotification27(const string& em) : email(em) {
        if (email.empty() || email.find('@') == string::npos)
            throw invalid_argument("Некорректный email");
    }
    void send(const string& message) override {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "Email отправлен на " << email << ": " << message.substr(0, 20)
            << (message.length() > 20 ? "..." : "") << endl;
    }
};

class SMSNotification27 : public Notification27 {
    string phone;
public:
    SMSNotification27(const string& ph) : phone(ph) {
        if (phone.length() < 10) throw invalid_argument("Некорректный номер телефона");
    }
    void send(const string& message) override {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "SMS отправлен на " << phone << ": " << message.substr(0, 20)
            << (message.length() > 20 ? "..." : "") << endl;
    }
};

void task27() {
    try {
        EmailNotification27 email("user@example.com");
        email.send("Это тестовое сообщение по электронной почте");

        SMSNotification27 sms("+79123456789");
        sms.send("Это тестовое SMS сообщение");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task28------------------
class Shape28 {
public:
    virtual void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const = 0;
    virtual ~Shape28() {}
};

class Circle28 : public Shape28 {
    double centerX, centerY, radius;
public:
    Circle28(double x, double y, double r) : centerX(x), centerY(y), radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const override {
        x1 = centerX - radius;
        y1 = centerY - radius;
        x2 = centerX + radius;
        y2 = centerY + radius;
    }
};

class Polygon28 : public Shape28 {
    vector<pair<double, double>> points;
public:
    Polygon28(const vector<pair<double, double>>& pts) : points(pts) {
        if (points.size() < 3) throw invalid_argument("Полигон должен иметь хотя бы 3 точки");
    }
    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const override {
        if (points.empty()) throw runtime_error("Нет точек для вычисления ограничительной рамки");
        x1 = x2 = points[0].first;
        y1 = y2 = points[0].second;
        for (const auto& p : points) {
            x1 = min(x1, p.first);
            y1 = min(y1, p.second);
            x2 = max(x2, p.first);
            y2 = max(y2, p.second);
        }
    }
};

void task28() {
    try {
        Circle28 circle(5, 5, 3);
        double x1, y1, x2, y2;
        circle.getBoundingBox(x1, y1, x2, y2);
        cout << "Ограничительная рамка круга: (" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ")" << endl;

        Polygon28 poly({ {1,1}, {3,5}, {6,2} });
        poly.getBoundingBox(x1, y1, x2, y2);
        cout << "Ограничительная рамка полигона: (" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ")" << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task29------------------
class UserProfile29 {
public:
    virtual void updateProfile( const string& name, int age) = 0;
    virtual ~UserProfile29() {}
};

class AdminProfile29 : public UserProfile29 {
public:
    void updateProfile(const string& name, int age) override {
        if (name.empty()) throw invalid_argument("Имя не может быть пустым");
        if (age < 18) throw invalid_argument("Админ должен быть старше 18 лет");
        cout << "Профиль админа обновлен: " << name << ", " << age << " лет" << endl;
    }
};

class GuestProfile29 : public UserProfile29 {
public:
    void updateProfile(const string& name, int age) override {
        string newName = name;
        int newAge = age;

        if (newName.empty()) newName = "Гость";
        if (newAge <= 0) newAge = 18;

        cout << "Гостевой профиль обновлен: " << newName << ", " << newAge << " лет" << endl;
    }
};

void task29() {
    try {
        AdminProfile29 admin;
        admin.updateProfile("Админ", 30);

        GuestProfile29 guest;
        guest.updateProfile("", 0);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task30------------------
class PaymentProcessor30 {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentProcessor30() {}
};

class CreditCardProcessor30 : public PaymentProcessor30 {
    string cardNumber;
    double balance;
public:
    CreditCardProcessor30(const string& num, double bal) : cardNumber(num), balance(bal) {
        if (cardNumber.length() != 16) throw invalid_argument("Некорректный номер карты");
    }
    void processPayment(double amount) override {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        if (amount > balance) throw runtime_error("Недостаточно средств на карте");
        balance -= amount;
        cout << "Оплачено $" << amount << " с карты " << cardNumber.substr(12)
            << ". Остаток: $" << balance << endl;
    }
};

class DebitCardProcessor30 : public PaymentProcessor30 {
    string cardNumber;
    double balance;
public:
    DebitCardProcessor30(const string& num, double bal) : cardNumber(num), balance(bal) {
        if (cardNumber.length() != 16) throw invalid_argument("Некорректный номер карты");
    }
    void processPayment(double amount) override {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        if (amount > 1000) throw runtime_error("Превышен дневной лимит дебетовой карты");
        if (amount > balance) throw runtime_error("Недостаточно средств на карте");
        balance -= amount;
        cout << "Оплачено $" << amount << " с дебетовой карты " << cardNumber.substr(12)
            << ". Остаток: $" << balance << endl;
    }
};

void task30() {
    try {
        CreditCardProcessor30 credit("1234567812345678", 5000);
        credit.processPayment(1000);

        DebitCardProcessor30 debit("8765432187654321", 2000);
        debit.processPayment(500);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task31------------------
class Shape31 {
public:
    virtual void reflect(bool horizontal, bool vertical) = 0;
    virtual ~Shape31() {}
};

class Circle31 : public Shape31 {
    double centerX, centerY, radius;
public:
    Circle31(double x, double y, double r) : centerX(x), centerY(y), radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    void reflect(bool horizontal, bool vertical) override {
        if (!horizontal && !vertical) throw invalid_argument("Должно быть хотя бы одно направление отражения");
        if (horizontal) centerY = -centerY;
        if (vertical) centerX = -centerX;
        cout << "Круг отражен в (" << centerX << "," << centerY << ")" << endl;
    }
};

class Rectangle31 : public Shape31 {
    double x1, y1, x2, y2;
public:
    Rectangle31(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
        if (x1 >= x2 || y1 >= y2) throw invalid_argument("Недопустимые координаты прямоугольника");
    }
    void reflect(bool horizontal, bool vertical) override {
        if (!horizontal && !vertical) throw invalid_argument("Должно быть хотя бы одно направление отражения");
        if (horizontal) { y1 = -y1; y2 = -y2; }
        if (vertical) { x1 = -x1; x2 = -x2; }
        cout << "Прямоугольник отражен в (" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ")" << endl;
    }
};

void task31() {
    try {
        Circle31 circle(2, 3, 5);
        circle.reflect(true, false);

        Rectangle31 rect(1, 1, 3, 4);
        rect.reflect(false, true);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task32------------------
class FileReader32 {
public:
    virtual string read(const string& filename) = 0;
    virtual ~FileReader32() {}
};

class TextFileReader32 : public FileReader32 {
public:
    string read(const string& filename) override {
        ifstream file(filename);
        if (!file) throw runtime_error("Не удалось открыть файл");
        string content((istreambuf_iterator<char>(file)),
            istreambuf_iterator<char>());
        if (content.empty()) throw runtime_error("Файл пуст");
        return content.substr(0, 100) + (content.length() > 100 ? "..." : "");
    }
};

class BinaryFileReader32 : public FileReader32 {
public:
    string read(const string& filename) override {
        ifstream file(filename, ios::binary);
        if (!file) throw runtime_error("Не удалось открыть файл");
        file.seekg(0, ios::end);
        size_t size = file.tellg();
        if (size == 0) throw runtime_error("Файл пуст");
        return "Двоичные данные размером " + to_string(size) + " байт";
    }
};

void task32() {
    try {
        TextFileReader32 textReader;
        cout << "Текст: " << textReader.read("file.txt") << endl;

        BinaryFileReader32 binReader;
        cout << "Данные: " << binReader.read("file.bin") << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task33------------------
class Shape33 {
public:
    virtual double getArea() const = 0;
    virtual ~Shape33() {}
};

class Ellipse33 : public Shape33 {
    double a, b;
public:
    Ellipse33(double major, double minor) : a(major), b(minor) {
        if (a <= 0 || b <= 0) throw invalid_argument("Оси должны быть положительными");
    }
    double getArea() const override { return 3.14 * a * b; }
};

class Square33 : public Shape33 {
    double side;
public:
    Square33(double s) : side(s) {
        if (side <= 0) throw invalid_argument("Сторона должна быть положительной");
    }
    double getArea() const override { return side * side; }
};

void task33() {
    try {
        Ellipse33 ellipse(5, 3);
        cout << "Площадь эллипса: " << ellipse.getArea() << endl;

        Square33 square(4);
        cout << "Площадь квадрата: " << square.getArea() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task34------------------
class EmailService34 {
public:
    virtual void sendEmail(const string& to, const string& subject, const string& body) = 0;
    virtual ~EmailService34() {}
};

class SMTPService34 : public EmailService34 {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        if (to.empty() || to.find('@') == string::npos)
            throw invalid_argument("Некорректный email получателя");
        if (subject.empty()) throw invalid_argument("Тема не может быть пустой");
        cout << "SMTP: Отправка '" << subject << "' to " << to << endl;
    }
};

class APIService34 : public EmailService34 {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        if (to.empty() || to.find('@') == string::npos)
            throw invalid_argument("Некорректный email получателя");
        if (body.empty()) throw invalid_argument("Тело сообщения не может быть пустым");
        cout << "API: Отправка письма (" << subject << ") to " << to << endl;
    }
};

void task34() {
    try {
        SMTPService34 smtp;
        smtp.sendEmail("user@example.com", "Важное письмо", "Привет!");

        APIService34 api;
        api.sendEmail("client@domain.com", "Уведомление", "Ваш заказ готов");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task35------------------
class Game35 {
protected:
    bool isActive;
public:
    Game35() : isActive(false) {}
    virtual void endGame() {
        if (!isActive) throw runtime_error("Игра не активна");
        isActive = false;
        cout << "Игра завершена" << endl;
    }
    virtual ~Game35() {}
};

class ChessGame35 : public Game35 {
public:
    void endGame() override {
        Game35::endGame();
        cout << "Шахматная игра завершена" << endl;
    }
};

class FootballGame35 : public Game35 {
public:
    void endGame() override {
        Game35::endGame();
        cout << "Футбольный матч завершен" << endl;
    }
};

void task35() {
    try {
        ChessGame35 chess;
        chess.endGame(); // Это вызовет исключение

        FootballGame35 football;
        football.endGame();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task36------------------
class Shape36 {
public:
    virtual vector<pair<double, double>> getVertices() const = 0;
    virtual ~Shape36() {}
};

class Triangle36 : public Shape36 {
    double x1, y1, x2, y2, x3, y3;
public:
    Triangle36(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
        // Проверка на вырожденный треугольник
        double area = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2;
        if (area < 0.0001) throw invalid_argument("Точки образуют вырожденный треугольник");
    }
    vector<pair<double, double>> getVertices() const override {
        return { {x1,y1}, {x2,y2}, {x3,y3} };
    }
};

class Pentagon36 : public Shape36 {
    vector<pair<double, double>> vertices;
public:
    Pentagon36(const vector<pair<double, double>>& pts) : vertices(pts) {
        if (pts.size() != 5) throw invalid_argument("Пентагон должен иметь 5 вершин");
        // Простая проверка на самопересечения
        for (size_t i = 0; i < pts.size(); ++i) {
            for (size_t j = i + 2; j < pts.size(); ++j) {
                if (i == 0 && j == pts.size() - 1) continue;
                // Проверка пересечения отрезков (i,i+1) и (j,j+1)
                // Упрощенная проверка - в реальном коде нужен полный алгоритм
                if (abs(pts[i].first - pts[j].first) < 0.0001 &&
                    abs(pts[i].second - pts[j].second) < 0.0001)
                    throw invalid_argument("Вершины пентагона не должны совпадать");
            }
        }
    }
    vector<pair<double, double>> getVertices() const override {
        return vertices;
    }
};

void task36() {
    try {
        Triangle36 tri(0, 0, 1, 0, 0, 1);
        auto triVertices = tri.getVertices();
        cout << "Вершины треугольника:\n";
        for (const auto& v : triVertices)
            cout << "(" << v.first << "," << v.second << ") ";
        cout << endl;

        Pentagon36 pent({ {0,0}, {1,0}, {1.5,1}, {0.5,1.5}, {-0.5,1} });
        auto pentVertices = pent.getVertices();
        cout << "Вершины пентагона:\n";
        for (const auto& v : pentVertices)
            cout << "(" << v.first << "," << v.second << ") ";
        cout << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task37------------------
class Session37 {
protected:
    bool isActive;
public:
    Session37() : isActive(false) {}
    virtual void startSession() {
        if (isActive) throw runtime_error("Сессия уже активна");
        isActive = true;
        cout << "Сессия начата\n";
    }
    virtual ~Session37() {}
};

class UserSession37 : public Session37 {
    string username;
public:
    UserSession37(const string& name) : username(name) {
        if (name.empty()) throw invalid_argument("Имя пользователя не может быть пустым");
    }
    void startSession() override {
        Session37::startSession();
        cout << "Пользовательская сессия для " << username << endl;
    }
};

class AdminSession37 : public Session37 {
    string username;
    int accessLevel;
public:
    AdminSession37(const string& name, int level) : username(name), accessLevel(level) {
        if (name.empty()) throw invalid_argument("Имя администратора не может быть пустым");
        if (level < 1 || level > 5) throw invalid_argument("Уровень доступа должен быть от 1 до 5");
    }
    void startSession() override {
        Session37::startSession();
        cout << "Админ сессия для " << username << " (уровень " << accessLevel << ")\n";
    }
};

void task37() {
    try {
        UserSession37 user("Иван");
        user.startSession();

        AdminSession37 admin("Админ", 3);
        admin.startSession();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task38------------------
class Shape38 {
public:
    virtual string getColor() const = 0;
    virtual ~Shape38() {}
};

class Circle38 : public Shape38 {
    string color;
public:
    Circle38(const string& col) : color(col) {
        if (color.empty()) throw invalid_argument("Цвет не может быть пустым");
        if (color != "красный" && color != "синий" && color != "зеленый")
            throw invalid_argument("Недопустимый цвет круга");
    }
    string getColor() const override {
        return color;
    }
};

class Square38 : public Shape38 {
    string color;
public:
    Square38(const string& col) : color(col) {
        if (color.empty()) throw invalid_argument("Цвет не может быть пустым");
        if (color != "черный" && color != "белый" && color != "серый")
            throw invalid_argument("Недопустимый цвет квадрата");
    }
    string getColor() const override {
        return color;
    }
};

void task38() {
    try {
        Circle38 circle("красный");
        cout << "Цвет круга: " << circle.getColor() << endl;

        Square38 square("белый");
        cout << "Цвет квадрата: " << square.getColor() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task39------------------
class Logger39 {
public:
    virtual void log(const string& message) = 0;
    virtual ~Logger39() {}
};

class FileLogger39 : public Logger39 {
    string filename;
public:
    FileLogger39(const string& fname) : filename(fname) {
        if (filename.empty()) throw invalid_argument("Имя файла не может быть пустым");
        if (filename.find('/') != string::npos || filename.find('\\') != string::npos)
            throw invalid_argument("Недопустимые символы в имени файла");
    }
    void log(const string& message) override {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        ofstream file(filename, ios::app);
        if (!file) throw runtime_error("Не удалось открыть файл для записи");
        file << message << endl;
        cout << "Сообщение записано в файл " << filename << endl;
    }
};

class ConsoleLogger39 : public Logger39 {
public:
    void log(const string& message) override {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "Лог: " << message << endl;
    }
};

void task39() {
    try {
        FileLogger39 fileLog("app.log");
        fileLog.log("Тестовое сообщение в файл");

        ConsoleLogger39 consoleLog;
        consoleLog.log("Тестовое сообщение в консоль");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task40------------------
class DataProcessor40 {
public:
    virtual void processData(const string& data) = 0;
    virtual ~DataProcessor40() {}
};

class CSVProcessor40 : public DataProcessor40 {
public:
    void processData(const string& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.find(',') == string::npos)
            throw runtime_error("CSV данные должны содержать разделители ','");

        size_t rows = count(data.begin(), data.end(), '\n') + 1;
        cout << "Обработка CSV: " << rows << " строк" << endl;
    }
};

class JSONProcessor40 : public DataProcessor40 {
public:
    void processData(const string& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.front() != '{' || data.back() != '}')
            throw runtime_error("Невалидный JSON: должен начинаться с { и заканчиваться }");

        size_t fields = count(data.begin(), data.end(), ':');
        cout << "Обработка JSON: " << fields << " полей" << endl;
    }
};

void task40() {
    try {
        CSVProcessor40 csv;
        csv.processData("id,name,age\n1,Иван,25\n2,Петр,30");

        JSONProcessor40 json;
        json.processData("{\"name\":\"Иван\",\"age\":25}");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task41------------------
class Shape41 {
public:
    virtual double area() const = 0;
    virtual ~Shape41() {}
};

class Circle41 : public Shape41 {
    double radius;
public:
    Circle41(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle41 : public Shape41 {
    double width, height;
public:
    Rectangle41(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) throw invalid_argument("Стороны должны быть положительными");
    }
    double area() const override { return width * height; }
};

class Triangle41 : public Shape41 {
    double a, b, c;
public:
    Triangle41(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Недопустимые стороны треугольника");
    }
    double area() const override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

void task41() {
    try {
        Circle41 c(5);
        cout << "Площадь круга: " << c.area() << endl;

        Rectangle41 r(3, 4);
        cout << "Площадь прямоугольника: " << r.area() << endl;

        Triangle41 t(3, 4, 5);
        cout << "Площадь треугольника: " << t.area() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task42------------------
class Employee42 {
public:
    virtual double calculateSalary(double hours) const = 0;
    virtual ~Employee42() {}
};

class FullTimeEmployee42 : public Employee42 {
    double hourlyRate;
public:
    FullTimeEmployee42(double rate) : hourlyRate(rate) {
        if (hourlyRate <= 0) throw invalid_argument("Ставка должна быть положительной");
    }
    double calculateSalary(double hours) const override {
        if (hours < 0) throw invalid_argument("Часы работы не могут быть отрицательными");
        return hourlyRate * min(hours, 40.0) + 1.5 * hourlyRate * max(0.0, hours - 40);
    }
};

class PartTimeEmployee42 : public Employee42 {
    double hourlyRate;
public:
    PartTimeEmployee42(double rate) : hourlyRate(rate) {
        if (hourlyRate <= 0) throw invalid_argument("Ставка должна быть положительной");
    }
    double calculateSalary(double hours) const override {
        if (hours < 0) throw invalid_argument("Часы работы не могут быть отрицательными");
        return hourlyRate * hours;
    }
};

void task42() {
    try {
        FullTimeEmployee42 ft(20);
        cout << "Зарплата (45 часов): " << ft.calculateSalary(45) << endl;

        PartTimeEmployee42 pt(15);
        cout << "Зарплата (30 часов): " << pt.calculateSalary(30) << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task43------------------
class DataReader43 {
public:
    virtual vector<string> readData(const string& filename) = 0;
    virtual ~DataReader43() {}
};

class CSVReader43 : public DataReader43 {
public:
    vector<string> readData(const string& filename) override {
        ifstream file(filename);
        if (!file) throw runtime_error("Файл не найден");

        vector<string> data;
        string line;
        while (getline(file, line)) {
            if (line.find(',') == string::npos)
                throw runtime_error("Неверный формат CSV");
            data.push_back(line);
        }
        return data;
    }
};

class XMLReader43 : public DataReader43 {
public:
    vector<string> readData(const string& filename) override {
        ifstream file(filename);
        if (!file) throw runtime_error("Файл не найден");

        vector<string> data;
        string line;
        while (getline(file, line)) {
            if (line.find('<') == string::npos || line.find('>') == string::npos)
                throw runtime_error("Неверный формат XML");
            data.push_back(line);
        }
        return data;
    }
};

void task43() {
    try {
        CSVReader43 csv;
        auto csvData = csv.readData("data.csv");
        cout << "Прочитано CSV строк: " << csvData.size() << endl;

        XMLReader43 xml;
        auto xmlData = xml.readData("data.xml");
        cout << "Прочитано XML строк: " << xmlData.size() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task44------------------
class Shape44 {
public:
    virtual void scale(double factor) = 0;
    virtual ~Shape44() {}
};

class Circle44 : public Shape44 {
    double radius;
public:
    Circle44(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    void scale(double factor) override {
        if (factor <= 0) throw invalid_argument("Масштаб должен быть положительным");
        radius *= factor;
        cout << "Круг масштабирован. Новый радиус: " << radius << endl;
    }
};

class Square44 : public Shape44 {
    double side;
public:
    Square44(double s) : side(s) {
        if (side <= 0) throw invalid_argument("Сторона должна быть положительной");
    }
    void scale(double factor) override {
        if (factor <= 0) throw invalid_argument("Масштаб должен быть положительным");
        side *= factor;
        cout << "Квадрат масштабирован. Новая сторона: " << side << endl;
    }
};

class Polygon44 : public Shape44 {
    vector<pair<double, double>> points;
public:
    Polygon44(const vector<pair<double, double>>& pts) : points(pts) {
        if (points.size() < 3) throw invalid_argument("Полигон должен иметь хотя бы 3 точки");
    }
    void scale(double factor) override {
        if (factor <= 0) throw invalid_argument("Масштаб должен быть положительным");
        for (auto& p : points) {
            p.first *= factor;
            p.second *= factor;
        }
        cout << "Полигон масштабирован. Новые точки: ";
        for (const auto& p : points) cout << "(" << p.first << "," << p.second << ") ";
        cout << endl;
    }
};

void task44() {
    try {
        Circle44 c(5);
        c.scale(2);

        Square44 s(10);
        s.scale(0.5);

        Polygon44 p({ {0,0}, {1,0}, {1,1} });
        p.scale(3);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task45------------------
class BankAccount45 {
protected:
    double balance;
public:
    BankAccount45(double initial) : balance(initial) {}
    virtual void transfer(double amount, BankAccount45& to) {
        if (amount <= 0) throw invalid_argument("Сумма перевода должна быть положительной");
        if (amount > balance) throw runtime_error("Недостаточно средств");
        balance -= amount;
        to.balance += amount;
        cout << "Переведено " << amount << ". Новый баланс: " << balance << endl;
    }
    virtual ~BankAccount45() {}
};

class SavingsAccount45 : public BankAccount45 {
    double minBalance;
public:
    SavingsAccount45(double initial, double min) : BankAccount45(initial), minBalance(min) {}
    void transfer(double amount, BankAccount45& to) override {
        if (balance - amount < minBalance)
            throw runtime_error("Перевод невозможен: баланс ниже минимального");
        BankAccount45::transfer(amount, to);
    }
};

class CheckingAccount45 : public BankAccount45 {
public:
    CheckingAccount45(double initial) : BankAccount45(initial) {}
    void transfer(double amount, BankAccount45& to) override {
        if (amount > 10000) throw runtime_error("Превышен лимит перевода для текущего счета");
        BankAccount45::transfer(amount, to);
    }
};

void task45() {
    try {
        SavingsAccount45 sa(5000, 1000);
        CheckingAccount45 ca(2000);
        sa.transfer(1000, ca);

        CheckingAccount45 ca2(1000);
        ca.transfer(500, ca2);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task46------------------
class NetworkRequest46 {
public:
    virtual void send(const string& url) = 0;
    virtual ~NetworkRequest46() {}
};

class HttpRequest46 : public NetworkRequest46 {
public:
    void send(const string& url) override {
        if (url.empty()) throw invalid_argument("URL не может быть пустым");
        if (url.find("http://") != 0 && url.find("https://") != 0)
            throw runtime_error("Неверный протокол HTTP");
        cout << "HTTP запрос отправлен: " << url << endl;
    }
};

class FtpRequest46 : public NetworkRequest46 {
public:
    void send(const string& url) override {
        if (url.empty()) throw invalid_argument("URL не может быть пустым");
        if (url.find("ftp://") != 0)
            throw runtime_error("Неверный протокол FTP");
        cout << "FTP запрос отправлен: " << url << endl;
    }
};

void task46() {
    try {
        HttpRequest46 http;
        http.send("https://example.com");

        FtpRequest46 ftp;
        ftp.send("ftp://example.com");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task47------------------
class Shape47 {
public:
    virtual void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const = 0;
    virtual ~Shape47() {}
};

class Circle47 : public Shape47 {
    double centerX, centerY, radius;
public:
    Circle47(double x, double y, double r) : centerX(x), centerY(y), radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const override {
        x1 = centerX - radius;
        y1 = centerY - radius;
        x2 = centerX + radius;
        y2 = centerY + radius;
    }
};

class Rectangle47 : public Shape47 {
    double x1, y1, x2, y2;
public:
    Rectangle47(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
        if (x1 >= x2 || y1 >= y2) throw invalid_argument("Недопустимые координаты прямоугольника");
    }
    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const override {
        x1 = this->x1;
        y1 = this->y1;
        x2 = this->x2;
        y2 = this->y2;
    }
};

class Polygon47 : public Shape47 {
    vector<pair<double, double>> points;
public:
    Polygon47(const vector<pair<double, double>>& pts) : points(pts) {
        if (points.size() < 3) throw invalid_argument("Полигон должен иметь хотя бы 3 точки");
    }
    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const override {
        if (points.empty()) throw runtime_error("Нет точек для вычисления границ");
        x1 = x2 = points[0].first;
        y1 = y2 = points[0].second;
        for (const auto& p : points) {
            x1 = min(x1, p.first);
            y1 = min(y1, p.second);
            x2 = max(x2, p.first);
            y2 = max(y2, p.second);
        }
    }
};

void task47() {
    try {
        Circle47 c(5, 5, 3);
        double x1, y1, x2, y2;
        c.getBoundingBox(x1, y1, x2, y2);
        cout << "Границы круга: (" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ")" << endl;

        Rectangle47 r(1, 1, 4, 3);
        r.getBoundingBox(x1, y1, x2, y2);
        cout << "Границы прямоугольника: (" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ")" << endl;

        Polygon47 p({ {0,0}, {2,0}, {1,2} });
        p.getBoundingBox(x1, y1, x2, y2);
        cout << "Границы полигона: (" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ")" << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task48------------------
class Exception48 {
public:
    virtual const char* what() const noexcept = 0;
    virtual ~Exception48() {}
};

class FileNotFoundException48 : public Exception48 {
public:
    const char* what() const noexcept override {
        return "Файл не найден";
    }
};

class InvalidInputException48 : public Exception48 {
public:
    const char* what() const noexcept override {
        return "Некорректный ввод";
    }
};

class NetworkException48 : public Exception48 {
public:
    const char* what() const noexcept override {
        return "Ошибка сети";
    }
};

void task48() {
    try {
        throw FileNotFoundException48();
    }
    catch (const Exception48& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task49------------------
class Task49 {
public:
    virtual void execute() = 0;
    virtual ~Task49() {}
};

class PrintTask49 : public Task49 {
    string message;
public:
    PrintTask49(const string& msg) : message(msg) {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
    }
    void execute() override {
        cout << "Печать: " << message << endl;
    }
};

class EmailTask49 : public Task49 {
    string to, subject, body;
public:
    EmailTask49(const string& t, const string& s, const string& b) : to(t), subject(s), body(b) {
        if (to.empty() || to.find('@') == string::npos) throw invalid_argument("Некорректный email");
    }
    void execute() override {
        cout << "Отправка email '" << subject << "' to " << to << endl;
    }
};

class DatabaseTask49 : public Task49 {
    string query;
public:
    DatabaseTask49(const string& q) : query(q) {
        if (query.empty()) throw invalid_argument("Запрос не может быть пустым");
    }
    void execute() override {
        cout << "Выполнение запроса: " << query << endl;
    }
};

void task49() {
    try {
        PrintTask49 print("Hello World");
        print.execute();

        EmailTask49 email("user@example.com", "Test", "Message");
        email.execute();

        DatabaseTask49 db("SELECT * FROM users");
        db.execute();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task50------------------
class Shape50 {
public:
    virtual void rotate(double angle) = 0;
    virtual ~Shape50() {}
};

class Circle50 : public Shape50 {
public:
    void rotate(double angle) override {
        cout << "Круг вращается на " << angle << " градусов" << endl;
    }
};

class Square50 : public Shape50 {
    double angle;
public:
    Square50() : angle(0) {}
    void rotate(double newAngle) override {
        if (newAngle < 0 || newAngle >= 360)
            throw invalid_argument("Угол должен быть от 0 до 360 градусов");
        angle = newAngle;
        cout << "Квадрат повернут на " << angle << " градусов" << endl;
    }
};

class Triangle50 : public Shape50 {
    double angle;
public:
    Triangle50() : angle(0) {}
    void rotate(double newAngle) override {
        if (newAngle < 0 || newAngle >= 360)
            throw invalid_argument("Угол должен быть от 0 до 360 градусов");
        angle = newAngle;
        cout << "Треугольник повернут на " << angle << " градусов" << endl;
    }
};

void task50() {
    try {
        Circle50 c;
        c.rotate(45);

        Square50 s;
        s.rotate(90);

        Triangle50 t;
        t.rotate(180);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task51------------------
class User51 {
protected:
    string username;
    string password;
public:
    User51(const string& uname, const string& pwd) : username(uname), password(pwd) {}
    virtual void login(const string& pwd) const {
        if (pwd != password) throw invalid_argument("Неверный пароль");
        cout << "Пользователь " << username << " вошел в систему" << endl;
    }
    virtual ~User51() {}
};

class AdminUser51 : public User51 {
public:
    AdminUser51(const string& uname, const string& pwd) : User51(uname, pwd) {}
    void login(const string& pwd) const override {
        User51::login(pwd);
        cout << "Доступ к админ панели предоставлен" << endl;
    }
};

class RegularUser51 : public User51 {
public:
    RegularUser51(const string& uname, const string& pwd) : User51(uname, pwd) {}
    void login(const string& pwd) const override {
        User51::login(pwd);
        cout << "Доступ к пользовательским функциям предоставлен" << endl;
    }
};

void task51() {
    try {
        AdminUser51 admin("admin", "secret");
        admin.login("secret");

        RegularUser51 user("user", "12345");
        user.login("12345");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task52------------------
class Payment52 {
public:
    virtual void process(double amount) = 0;
    virtual ~Payment52() {}
};

class CreditCardPayment52 : public Payment52 {
    string cardNumber;
    double balance;
public:
    CreditCardPayment52(const string& num, double bal) : cardNumber(num), balance(bal) {
        if (cardNumber.length() != 16) throw invalid_argument("Некорректный номер карты");
    }
    void process(double amount) override {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        if (amount > balance) throw runtime_error("Недостаточно средств");
        balance -= amount;
        cout << "Оплачено " << amount << " с кредитной карты. Остаток: " << balance << endl;
    }
};

class PayPalPayment52 : public Payment52 {
    string email;
public:
    PayPalPayment52(const string& em) : email(em) {
        if (email.empty() || email.find('@') == string::npos)
            throw invalid_argument("Некорректный email");
    }
    void process(double amount) override {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        cout << "Оплачено " << amount << " через PayPal (" << email << ")" << endl;
    }
};

class BankTransfer52 : public Payment52 {
    string accountNumber;
public:
    BankTransfer52(const string& acc) : accountNumber(acc) {
        if (accountNumber.length() < 10) throw invalid_argument("Некорректный номер счета");
    }
    void process(double amount) override {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        cout << "Переведено " << amount << " на счет " << accountNumber << endl;
    }
};

void task52() {
    try {
        CreditCardPayment52 cc("1234567812345678", 5000);
        cc.process(1000);

        PayPalPayment52 pp("user@example.com");
        pp.process(500);

        BankTransfer52 bt("1234567890");
        bt.process(2000);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task53------------------
class Shape53 {
public:
    virtual double getArea() const = 0;
    virtual ~Shape53() {}
};

class Circle53 : public Shape53 {
    double radius;
public:
    Circle53(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    double getArea() const override { return 3.14159 * radius * radius; }
};

class Rectangle53 : public Shape53 {
    double width, height;
public:
    Rectangle53(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) throw invalid_argument("Стороны должны быть положительными");
    }
    double getArea() const override { return width * height; }
};

class Triangle53 : public Shape53 {
    double a, b, c;
public:
    Triangle53(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Недопустимые стороны треугольника");
    }
    double getArea() const override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

void task53() {
    try {
        Circle53 c(5);
        cout << "Площадь круга: " << c.getArea() << endl;

        Rectangle53 r(3, 4);
        cout << "Площадь прямоугольника: " << r.getArea() << endl;

        Triangle53 t(3, 4, 5);
        cout << "Площадь треугольника: " << t.getArea() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task54------------------
class FileHandler54 {
public:
    virtual void open(const string& filename) = 0;
    virtual ~FileHandler54() {}
};

class TextFileHandler54 : public FileHandler54 {
public:
    void open(const string& filename) override {
        ifstream file(filename);
        if (!file) throw runtime_error("Не удалось открыть текстовый файл");
        cout << "Текстовый файл " << filename << " открыт" << endl;
    }
};

class BinaryFileHandler54 : public FileHandler54 {
public:
    void open(const string& filename) override {
        ifstream file(filename, ios::binary);
        if (!file) throw runtime_error("Не удалось открыть бинарный файл");
        cout << "Бинарный файл " << filename << " открыт" << endl;
    }
};

void task54() {
    try {
        TextFileHandler54 text;
        text.open("file.txt");

        BinaryFileHandler54 bin;
        bin.open("file.bin");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task55------------------
class Database55 {
public:
    virtual void query(const string& sql) = 0;
    virtual ~Database55() {}
};

class MySQLDatabase55 : public Database55 {
public:
    void query(const string& sql) override {
        if (sql.empty()) throw invalid_argument("SQL запрос не может быть пустым");
        if (sql.find(";") != string::npos)
            throw runtime_error("MySQL не поддерживает множественные запросы");
        cout << "MySQL: выполнен запрос - " << sql << endl;
    }
};

class SQLiteDatabase55 : public Database55 {
public:
    void query(const string& sql) override {
        if (sql.empty()) throw invalid_argument("SQL запрос не может быть пустым");
        cout << "SQLite: выполнен запрос - " << sql << endl;
    }
};

void task55() {
    try {
        MySQLDatabase55 mysql;
        mysql.query("SELECT * FROM users");

        SQLiteDatabase55 sqlite;
        sqlite.query("SELECT * FROM products");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task56------------------
class Shape56 {
public:
    virtual vector<pair<double, double>> getVertices() const = 0;
    virtual ~Shape56() {}
};

class Triangle56 : public Shape56 {
    double x1, y1, x2, y2, x3, y3;
public:
    Triangle56(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
        double area = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2;
        if (area < 0.0001) throw invalid_argument("Точки образуют вырожденный треугольник");
    }
    vector<pair<double, double>> getVertices() const override {
        return { {x1,y1}, {x2,y2}, {x3,y3} };
    }
};

class Square56 : public Shape56 {
    double x, y, side;
public:
    Square56(double x, double y, double s) : x(x), y(y), side(s) {
        if (side <= 0) throw invalid_argument("Сторона должна быть положительной");
    }
    vector<pair<double, double>> getVertices() const override {
        return { {x,y}, {x + side,y}, {x + side,y + side}, {x,y + side} };
    }
};

class Pentagon56 : public Shape56 {
    vector<pair<double, double>> points;
public:
    Pentagon56(const vector<pair<double, double>>& pts) : points(pts) {
        if (pts.size() != 5) throw invalid_argument("Пентагон должен иметь 5 вершин");
    }
    vector<pair<double, double>> getVertices() const override {
        return points;
    }
};

void task56() {
    try {
        Triangle56 tri(0, 0, 1, 0, 0, 1);
        auto triVerts = tri.getVertices();
        cout << "Вершины треугольника: ";
        for (const auto& v : triVerts) cout << "(" << v.first << "," << v.second << ") ";
        cout << endl;

        Square56 sq(0, 0, 2);
        auto sqVerts = sq.getVertices();
        cout << "Вершины квадрата: ";
        for (const auto& v : sqVerts) cout << "(" << v.first << "," << v.second << ") ";
        cout << endl;

        Pentagon56 pent({ {0,0}, {1,0}, {1.5,1}, {0.5,1.5}, {-0.5,1} });
        auto pentVerts = pent.getVertices();
        cout << "Вершины пентагона: ";
        for (const auto& v : pentVerts) cout << "(" << v.first << "," << v.second << ") ";
        cout << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task57------------------
class Logger57 {
public:
    virtual void log(const string& message) = 0;
    virtual ~Logger57() {}
};

class FileLogger57 : public Logger57 {
    string filename;
public:
    FileLogger57(const string& fname) : filename(fname) {
        if (filename.empty()) throw invalid_argument("Имя файла не может быть пустым");
    }
    void log(const string& message) override {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        ofstream file(filename, ios::app);
        if (!file) throw runtime_error("Не удалось открыть файл для записи");
        file << message << endl;
        cout << "Сообщение записано в файл " << filename << endl;
    }
};

class ConsoleLogger57 : public Logger57 {
public:
    void log(const string& message) override {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "Лог: " << message << endl;
    }
};

void task57() {
    try {
        FileLogger57 fileLog("app.log");
        fileLog.log("Тестовое сообщение в файл");

        ConsoleLogger57 consoleLog;
        consoleLog.log("Тестовое сообщение в консоль");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task58------------------
class Notification58 {
public:
    virtual void send(const string& message) = 0;
    virtual ~Notification58() {}
};

class EmailNotification58 : public Notification58 {
    string email;
public:
    EmailNotification58(const string& em) : email(em) {
        if (email.empty() || email.find('@') == string::npos)
            throw invalid_argument("Некорректный email");
    }
    void send(const string& message) override {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "Email отправлен на " << email << ": " << message << endl;
    }
};

class SMSNotification58 : public Notification58 {
    string phone;
public:
    SMSNotification58(const string& ph) : phone(ph) {
        if (phone.length() < 10) throw invalid_argument("Некорректный номер телефона");
    }
    void send(const string& message) override {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "SMS отправлен на " << phone << ": " << message << endl;
    }
};

class PushNotification58 : public Notification58 {
    string deviceId;
public:
    PushNotification58(const string& id) : deviceId(id) {
        if (deviceId.empty()) throw invalid_argument("ID устройства не может быть пустым");
    }
    void send(const string& message) override {
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "Push уведомление отправлено на устройство " << deviceId << ": " << message << endl;
    }
};

void task58() {
    try {
        EmailNotification58 email("user@example.com");
        email.send("Ваш заказ готов");

        SMSNotification58 sms("+79123456789");
        sms.send("Ваш код подтверждения: 1234");

        PushNotification58 push("device123");
        push.send("Новое сообщение");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task59------------------
class Shape59 {
public:
    virtual double getPerimeter() const = 0;
    virtual ~Shape59() {}
};

class Circle59 : public Shape59 {
    double radius;
public:
    Circle59(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle59 : public Shape59 {
    double width, height;
public:
    Rectangle59(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) throw invalid_argument("Стороны должны быть положительными");
    }
    double getPerimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle59 : public Shape59 {
    double a, b, c;
public:
    Triangle59(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Недопустимые стороны треугольника");
    }
    double getPerimeter() const override {
        return a + b + c;
    }
};

void task59() {
    try {
        Circle59 c(5);
        cout << "Периметр круга: " << c.getPerimeter() << endl;

        Rectangle59 r(3, 4);
        cout << "Периметр прямоугольника: " << r.getPerimeter() << endl;

        Triangle59 t(3, 4, 5);
        cout << "Периметр треугольника: " << t.getPerimeter() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task60------------------
class Session60 {
protected:
    bool isActive;
public:
    Session60() : isActive(false) {}
    virtual void start() {
        if (isActive) throw runtime_error("Сессия уже активна");
        isActive = true;
    }
    virtual ~Session60() {}
};

class UserSession60 : public Session60 {
    string username;
public:
    UserSession60(const string& name) : username(name) {
        if (name.empty()) throw invalid_argument("Имя пользователя не может быть пустым");
    }
    void start() override {
        Session60::start();
        cout << "Пользовательская сессия начата для " << username << endl;
    }
};

class AdminSession60 : public Session60 {
    string username;
    int accessLevel;
public:
    AdminSession60(const string& name, int level) : username(name), accessLevel(level) {
        if (name.empty()) throw invalid_argument("Имя администратора не может быть пустым");
        if (level < 1 || level > 5) throw invalid_argument("Уровень доступа должен быть от 1 до 5");
    }
    void start() override {
        Session60::start();
        cout << "Админ сессия начата для " << username << " (уровень " << accessLevel << ")\n";
    }
};

void task60() {
    try {
        UserSession60 user("Иван");
        user.start();

        AdminSession60 admin("Админ", 3);
        admin.start();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task61------------------
class DataProcessor61 {
public:
    virtual void process(const string& data) = 0;
    virtual ~DataProcessor61() {}
};

class CSVProcessor61 : public DataProcessor61 {
public:
    void process(const string& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.find(',') == string::npos)
            throw runtime_error("CSV данные должны содержать разделители ','");
        cout << "Обработка CSV данных: " << data.substr(0, 20) << "..." << endl;
    }
};

class JSONProcessor61 : public DataProcessor61 {
public:
    void process(const string& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.front() != '{' || data.back() != '}')
            throw runtime_error("Невалидный JSON: должен начинаться с { и заканчиваться }");
        cout << "Обработка JSON данных: " << data.substr(0, 20) << "..." << endl;
    }
};

class XMLProcessor61 : public DataProcessor61 {
public:
    void process(const string& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.find("<") == string::npos || data.find(">") == string::npos)
            throw runtime_error("Невалидный XML: должен содержать теги");
        cout << "Обработка XML данных: " << data.substr(0, 20) << "..." << endl;
    }
};

void task61() {
    try {
        CSVProcessor61 csv;
        csv.process("id,name,age\n1,John,30");

        JSONProcessor61 json;
        json.process("{\"name\":\"John\",\"age\":30}");

        XMLProcessor61 xml;
        xml.process("<user><name>John</name><age>30</age></user>");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task62------------------
class Shape62 {
public:
    virtual void transform(double x, double y, double scale) = 0;
    virtual ~Shape62() {}
};

class Circle62 : public Shape62 {
    double centerX, centerY, radius;
public:
    Circle62(double x, double y, double r) : centerX(x), centerY(y), radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    void transform(double x, double y, double scale) override {
        if (scale <= 0) throw invalid_argument("Масштаб должен быть положительным");
        centerX += x;
        centerY += y;
        radius *= scale;
        cout << "Круг трансформирован: (" << centerX << "," << centerY << "), r=" << radius << endl;
    }
};

class Square62 : public Shape62 {
    double x, y, side;
public:
    Square62(double x, double y, double s) : x(x), y(y), side(s) {
        if (side <= 0) throw invalid_argument("Сторона должна быть положительной");
    }
    void transform(double x, double y, double scale) override {
        if (scale <= 0) throw invalid_argument("Масштаб должен быть положительным");
        this->x += x;
        this->y += y;
        side *= scale;
        cout << "Квадрат трансформирован: (" << this->x << "," << this->y << "), side=" << side << endl;
    }
};

class Polygon62 : public Shape62 {
    vector<pair<double, double>> points;
public:
    Polygon62(const vector<pair<double, double>>& pts) : points(pts) {
        if (points.size() < 3) throw invalid_argument("Полигон должен иметь хотя бы 3 точки");
    }
    void transform(double x, double y, double scale) override {
        if (scale <= 0) throw invalid_argument("Масштаб должен быть положительным");
        for (auto& p : points) {
            p.first = p.first * scale + x;
            p.second = p.second * scale + y;
        }
        cout << "Полигон трансформирован. Новые точки: ";
        for (const auto& p : points) cout << "(" << p.first << "," << p.second << ") ";
        cout << endl;
    }
};

void task62() {
    try {
        Circle62 c(0, 0, 5);
        c.transform(2, 3, 1.5);

        Square62 s(1, 1, 4);
        s.transform(-1, 2, 0.8);

        Polygon62 p({ {0,0}, {1,0}, {0.5,1} });
        p.transform(3, -2, 2.0);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task63------------------
class User63 {
public:
    virtual void updateProfile(const map<string, string>& data) = 0;
    virtual ~User63() {}
};

class AdminUser63 : public User63 {
public:
    void updateProfile(const map<string, string>& data) override {
        if (data.empty()) throw invalid_argument("Данные профиля не могут быть пустыми");
        if (data.find("accessLevel") == data.end())
            throw runtime_error("Админ профиль должен содержать accessLevel");
        cout << "Админ профиль обновлен: ";
        for (const auto& item : data) cout << item.first << "=" << item.second << " ";
        cout << endl;
    }
};

class RegularUser63 : public User63 {
public:
    void updateProfile(const map<string, string>& data) override {
        if (data.empty()) throw invalid_argument("Данные профиля не могут быть пустыми");
        if (data.find("email") == data.end())
            throw runtime_error("Обычный профиль должен содержать email");
        cout << "Обычный профиль обновлен: ";
        for (const auto& item : data) cout << item.first << "=" << item.second << " ";
        cout << endl;
    }
};

void task63() {
    try {
        AdminUser63 admin;
        admin.updateProfile({ {"name", "Admin"}, {"accessLevel", "3"} });

        RegularUser63 user;
        user.updateProfile({ {"name", "User"}, {"email", "user@example.com"} });

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task64------------------
class TaskManager64 {
public:
    virtual void runTask(const string& taskName) = 0;
    virtual ~TaskManager64() {}
};

class ScheduledTask64 : public TaskManager64 {
public:
    void runTask(const string& taskName) override {
        if (taskName.empty()) throw invalid_argument("Имя задачи не может быть пустым");
        cout << "Запланированная задача '" << taskName << "' запущена" << endl;
    }
};

class ImmediateTask64 : public TaskManager64 {
public:
    void runTask(const string& taskName) override {
        if (taskName.empty()) throw invalid_argument("Имя задачи не может быть пустым");
        cout << "Немедленная задача '" << taskName << "' запущена" << endl;
    }
};

void task64() {
    try {
        ScheduledTask64 scheduled;
        scheduled.runTask("Backup");

        ImmediateTask64 immediate;
        immediate.runTask("Cleanup");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task65------------------
class Shape65 {
public:
    virtual string getColor() const = 0;
    virtual ~Shape65() {}
};

class Circle65 : public Shape65 {
    string color;
public:
    Circle65(const string& col) : color(col) {
        if (color.empty()) throw invalid_argument("Цвет не может быть пустым");
        if (color != "red" && color != "green" && color != "blue")
            throw invalid_argument("Недопустимый цвет круга");
    }
    string getColor() const override { return color; }
};

class Square65 : public Shape65 {
    string color;
public:
    Square65(const string& col) : color(col) {
        if (color.empty()) throw invalid_argument("Цвет не может быть пустым");
        if (color != "black" && color != "white" && color != "gray")
            throw invalid_argument("Недопустимый цвет квадрата");
    }
    string getColor() const override { return color; }
};

class Triangle65 : public Shape65 {
    string color;
public:
    Triangle65(const string& col) : color(col) {
        if (color.empty()) throw invalid_argument("Цвет не может быть пустым");
        if (color != "yellow" && color != "orange" && color != "purple")
            throw invalid_argument("Недопустимый цвет треугольника");
    }
    string getColor() const override { return color; }
};

void task65() {
    try {
        Circle65 c("red");
        cout << "Цвет круга: " << c.getColor() << endl;

        Square65 s("black");
        cout << "Цвет квадрата: " << s.getColor() << endl;

        Triangle65 t("yellow");
        cout << "Цвет треугольника: " << t.getColor() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task66------------------
class PaymentGateway66 {
public:
    virtual void processPayment(double amount, const string& currency) = 0;
    virtual ~PaymentGateway66() {}
};

class StripeGateway66 : public PaymentGateway66 {
public:
    void processPayment(double amount, const string& currency) override {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        if (currency != "USD" && currency != "EUR")
            throw runtime_error("Stripe поддерживает только USD и EUR");
        cout << "Stripe: платеж " << amount << " " << currency << " обработан" << endl;
    }
};

class PayPalGateway66 : public PaymentGateway66 {
public:
    void processPayment(double amount, const string& currency) override {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        if (amount < 1.0) throw runtime_error("Минимальная сумма платежа PayPal - 1.0");
        cout << "PayPal: платеж " << amount << " " << currency << " обработан" << endl;
    }
};

class SquareGateway66 : public PaymentGateway66 {
public:
    void processPayment(double amount, const string& currency) override {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        if (amount > 10000.0) throw runtime_error("Максимальная сумма платежа Square - 10000.0");
        cout << "Square: платеж " << amount << " " << currency << " обработан" << endl;
    }
};

void task66() {
    try {
        StripeGateway66 stripe;
        stripe.processPayment(100.0, "USD");

        PayPalGateway66 paypal;
        paypal.processPayment(50.0, "EUR");

        SquareGateway66 square;
        square.processPayment(5000.0, "USD");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task67------------------
class FileReader67 {
public:
    virtual string read(const string& filename) = 0;
    virtual ~FileReader67() {}
};

class TextFileReader67 : public FileReader67 {
public:
    string read(const string& filename) override {
        ifstream file(filename);
        if (!file) throw runtime_error("Не удалось открыть текстовый файл");
        string content((istreambuf_iterator<char>(file)),
            istreambuf_iterator<char>());
        if (content.empty()) throw runtime_error("Файл пуст");
        return content.substr(0, 100) + (content.length() > 100 ? "..." : "");
    }
};

class BinaryFileReader67 : public FileReader67 {
public:
    string read(const string& filename) override {
        ifstream file(filename, ios::binary);
        if (!file) throw runtime_error("Не удалось открыть бинарный файл");
        file.seekg(0, ios::end);
        size_t size = file.tellg();
        if (size == 0) throw runtime_error("Файл пуст");
        return "Бинарные данные размером " + to_string(size) + " байт";
    }
};

class JsonFileReader67 : public FileReader67 {
public:
    string read(const string& filename) override {
        ifstream file(filename);
        if (!file) throw runtime_error("Не удалось открыть JSON файл");
        string content((istreambuf_iterator<char>(file)),
            istreambuf_iterator<char>());
        if (content.empty()) throw runtime_error("Файл пуст");
        if (content.front() != '{' || content.back() != '}')
            throw runtime_error("Невалидный JSON формат");
        return content.substr(0, 100) + (content.length() > 100 ? "..." : "");
    }
};

void task67() {
    try {
        TextFileReader67 text;
        cout << "Текст: " << text.read("file.txt") << endl;

        BinaryFileReader67 bin;
        cout << "Данные: " << bin.read("file.bin") << endl;

        JsonFileReader67 json;
        cout << "JSON: " << json.read("file.json") << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task68------------------
class Shape68 {
public:
    virtual double getArea() const = 0;
    virtual ~Shape68() {}
};

class Circle68 : public Shape68 {
    double radius;
public:
    Circle68(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle68 : public Shape68 {
    double width, height;
public:
    Rectangle68(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) throw invalid_argument("Стороны должны быть положительными");
    }
    double getArea() const override {
        return width * height;
    }
};

class Triangle68 : public Shape68 {
    double a, b, c;
public:
    Triangle68(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Недопустимые стороны треугольника");
    }
    double getArea() const override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

void task68() {
    try {
        Circle68 c(5);
        cout << "Площадь круга: " << c.getArea() << endl;

        Rectangle68 r(3, 4);
        cout << "Площадь прямоугольника: " << r.getArea() << endl;

        Triangle68 t(3, 4, 5);
        cout << "Площадь треугольника: " << t.getArea() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task69------------------
class ExceptionHandler69 {
public:
    virtual void handle(const exception& e) const = 0;
    virtual ~ExceptionHandler69() {}
};

class FileExceptionHandler69 : public ExceptionHandler69 {
public:
    void handle(const exception& e) const override {
        cerr << "Ошибка файла: " << e.what() << " (записано в файл логов)" << endl;
    }
};

class NetworkExceptionHandler69 : public ExceptionHandler69 {
public:
    void handle(const exception& e) const override {
        cerr << "Ошибка сети: " << e.what() << " (повторная попытка)" << endl;
    }
};

class InputExceptionHandler69 : public ExceptionHandler69 {
public:
    void handle(const exception& e) const override {
        cerr << "Ошибка ввода: " << e.what() << " (проверьте данные)" << endl;
    }
};

void task69() {
    try {
        FileExceptionHandler69 fileHandler;
        fileHandler.handle(runtime_error("Файл не найден"));

        NetworkExceptionHandler69 netHandler;
        netHandler.handle(runtime_error("Таймаут соединения"));

        InputExceptionHandler69 inputHandler;
        inputHandler.handle(invalid_argument("Некорректный формат"));

    }
    catch (...) {
        cerr << "Неизвестная ошибка в обработчике исключений" << endl;
    }
}

//-------------task70------------------
class UserProfile70 {
public:
    virtual void save(const map<string, string>& data) = 0;
    virtual ~UserProfile70() {}
};

class AdminProfile70 : public UserProfile70 {
public:
    void save(const map<string, string>& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.find("password") == data.end())
            throw runtime_error("Админ профиль должен содержать пароль");
        cout << "Админ профиль сохранен (зашифрован)" << endl;
    }
};

class RegularProfile70 : public UserProfile70 {
public:
    void save(const map<string, string>& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.find("email") == data.end())
            throw runtime_error("Обычный профиль должен содержать email");
        cout << "Обычный профиль сохранен" << endl;
    }
};

void task70() {
    try {
        AdminProfile70 admin;
        admin.save({ {"name", "Admin"}, {"password", "secret"} });

        RegularProfile70 user;
        user.save({ {"name", "User"}, {"email", "user@example.com"} });

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task71------------------
class Shape71 {
public:
    virtual string getDescription() const = 0;
    virtual ~Shape71() {}
};

class Circle71 : public Shape71 {
    double radius;
public:
    Circle71(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    string getDescription() const override {
        return "Круг с радиусом " + to_string(radius);
    }
};

class Square71 : public Shape71 {
    double side;
public:
    Square71(double s) : side(s) {
        if (side <= 0) throw invalid_argument("Сторона должна быть положительной");
    }
    string getDescription() const override {
        return "Квадрат со стороной " + to_string(side);
    }
};

class Triangle71 : public Shape71 {
    double a, b, c;
public:
    Triangle71(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Недопустимые стороны треугольника");
    }
    string getDescription() const override {
        return "Треугольник со сторонами " + to_string(a) + ", " + to_string(b) + ", " + to_string(c);
    }
};

void task71() {
    try {
        Circle71 c(5);
        cout << c.getDescription() << endl;

        Square71 s(4);
        cout << s.getDescription() << endl;

        Triangle71 t(3, 4, 5);
        cout << t.getDescription() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task72------------------
class EmailService72 {
public:
    virtual void sendEmail(const string& to, const string& subject, const string& body) = 0;
    virtual ~EmailService72() {}
};

class SMTPService72 : public EmailService72 {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        if (to.empty() || to.find('@') == string::npos)
            throw invalid_argument("Некорректный email получателя");
        if (subject.empty()) throw invalid_argument("Тема не может быть пустой");
        cout << "SMTP: отправка '" << subject << "' to " << to << endl;
    }
};

class APIService72 : public EmailService72 {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        if (to.empty() || to.find('@') == string::npos)
            throw invalid_argument("Некорректный email получателя");
        if (body.empty()) throw invalid_argument("Тело сообщения не может быть пустым");
        cout << "API: отправка письма (" << subject << ") to " << to << endl;
    }
};

class MockEmailService72 : public EmailService72 {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        if (to.empty()) throw invalid_argument("Получатель не может быть пустым");
        cout << "MOCK: письмо '" << subject << "' to " << to << " (не отправлено)" << endl;
    }
};

void task72() {
    try {
        SMTPService72 smtp;
        smtp.sendEmail("user@example.com", "Важное письмо", "Привет!");

        APIService72 api;
        api.sendEmail("client@domain.com", "Уведомление", "Ваш заказ готов");

        MockEmailService72 mock;
        mock.sendEmail("test@test.com", "Тест", "Тестовое сообщение");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task73------------------
class DataValidator73 {
public:
    virtual bool validate(const string& data) const = 0;
    virtual ~DataValidator73() {}
};

class EmailValidator73 : public DataValidator73 {
public:
    bool validate(const string& data) const override {
        if (data.empty()) throw invalid_argument("Email не может быть пустым");
        size_t at = data.find('@');
        if (at == string::npos || at == 0 || at == data.length() - 1)
            throw invalid_argument("Некорректный формат email");
        return true;
    }
};

class PhoneValidator73 : public DataValidator73 {
public:
    bool validate(const string& data) const override {
        if (data.empty()) throw invalid_argument("Телефон не может быть пустым");
        if (data.length() < 10)
            throw invalid_argument("Телефон должен содержать минимум 10 цифр");
        return true;
    }
};

class AgeValidator73 : public DataValidator73 {
public:
    bool validate(const string& data) const override {
        if (data.empty()) throw invalid_argument("Возраст не может быть пустым");
        int age = stoi(data);
        if (age < 0 || age > 120)
            throw invalid_argument("Возраст должен быть от 0 до 120");
        return true;
    }
};

void task73() {
    try {
        EmailValidator73 email;
        cout << "Email valid: " << email.validate("user@example.com") << endl;

        PhoneValidator73 phone;
        cout << "Phone valid: " << phone.validate("+79123456789") << endl;

        AgeValidator73 age;
        cout << "Age valid: " << age.validate("30") << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task74------------------
class Shape74 {
public:
    virtual vector<double> getDimensions() const = 0;
    virtual ~Shape74() {}
};

class Circle74 : public Shape74 {
    double radius;
public:
    Circle74(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    vector<double> getDimensions() const override {
        return { radius };
    }
};

class Rectangle74 : public Shape74 {
    double width, height;
public:
    Rectangle74(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) throw invalid_argument("Стороны должны быть положительными");
    }
    vector<double> getDimensions() const override {
        return { width, height };
    }
};

class Triangle74 : public Shape74 {
    double a, b, c;
public:
    Triangle74(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Недопустимые стороны треугольника");
    }
    vector<double> getDimensions() const override {
        return { a, b, c };
    }
};

void task74() {
    try {
        Circle74 c(5);
        auto cDims = c.getDimensions();
        cout << "Размеры круга: ";
        for (double d : cDims) cout << d << " ";
        cout << endl;

        Rectangle74 r(3, 4);
        auto rDims = r.getDimensions();
        cout << "Размеры прямоугольника: ";
        for (double d : rDims) cout << d << " ";
        cout << endl;

        Triangle74 t(3, 4, 5);
        auto tDims = t.getDimensions();
        cout << "Размеры треугольника: ";
        for (double d : tDims) cout << d << " ";
        cout << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
//-------------task75------------------
class Transaction75 {
protected:
    double amount;
    string accountNumber;
public:
    Transaction75(double amt, const string& acc) : amount(amt), accountNumber(acc) {
        if (amount <= 0) throw invalid_argument("Сумма должна быть положительной");
        if (accountNumber.empty()) throw invalid_argument("Номер счета не может быть пустым");
    }
    virtual void execute(double& balance) = 0;
    virtual ~Transaction75() {}
};

class DepositTransaction75 : public Transaction75 {
public:
    DepositTransaction75(double amt, const string& acc) : Transaction75(amt, acc) {}
    void execute(double& balance) override {
        if (amount > 100000) throw runtime_error("Превышен лимит депозита");
        balance += amount;
        cout << "Депозит " << amount << " на счет " << accountNumber
            << ". Новый баланс: " << balance << endl;
    }
};

class WithdrawalTransaction75 : public Transaction75 {
public:
    WithdrawalTransaction75(double amt, const string& acc) : Transaction75(amt, acc) {}
    void execute(double& balance) override {
        if (amount > balance) throw runtime_error("Недостаточно средств");
        if (amount > 50000) throw runtime_error("Превышен лимит снятия");
        balance -= amount;
        cout << "Снятие " << amount << " со счета " << accountNumber
            << ". Новый баланс: " << balance << endl;
    }
};

void task75() {
    try {
        double balance = 10000;
        DepositTransaction75 deposit(5000, "ACC123");
        deposit.execute(balance);

        WithdrawalTransaction75 withdraw(3000, "ACC123");
        withdraw.execute(balance);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task76------------------
class Shape76 {
public:
    virtual bool getIntersection(const Shape76& other) const = 0;
    virtual ~Shape76() {}
};

class Circle76 : public Shape76 {
    double x, y, radius;
public:
    Circle76(double x, double y, double r) : x(x), y(y), radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    bool getIntersection(const Shape76& other) const override {
        const Circle76* circle = dynamic_cast<const Circle76*>(&other);
        if (circle) {
            double dx = x - circle->x;
            double dy = y - circle->y;
            double distance = sqrt(dx * dx + dy * dy);
            return distance <= (radius + circle->radius);
        }
        throw runtime_error("Пересечение с неподдерживаемым типом фигуры");
    }
};

class Rectangle76 : public Shape76 {
    double x1, y1, x2, y2;
public:
    Rectangle76(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
        if (x1 >= x2 || y1 >= y2) throw invalid_argument("Недопустимые координаты прямоугольника");
    }
    bool getIntersection(const Shape76& other) const override {
        const Rectangle76* rect = dynamic_cast<const Rectangle76*>(&other);
        if (rect) {
            return !(x2 < rect->x1 || rect->x2 < x1 || y2 < rect->y1 || rect->y2 < y1);
        }
        throw runtime_error("Пересечение с неподдерживаемым типом фигуры");
    }
};

class Polygon76 : public Shape76 {
    vector<pair<double, double>> points;
public:
    Polygon76(const vector<pair<double, double>>& pts) : points(pts) {
        if (points.size() < 3) throw invalid_argument("Полигон должен иметь хотя бы 3 точки");
    }
    bool getIntersection(const Shape76& other) const override {
        throw runtime_error("Пересечение полигонов не реализовано");
    }
};

void task76() {
    try {
        Circle76 c1(0, 0, 5);
        Circle76 c2(3, 4, 3);
        cout << "Круги пересекаются: " << c1.getIntersection(c2) << endl;

        Rectangle76 r1(0, 0, 2, 2);
        Rectangle76 r2(1, 1, 3, 3);
        cout << "Прямоугольники пересекаются: " << r1.getIntersection(r2) << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task77------------------
class User77 {
protected:
    string username;
    string password;
public:
    User77(const string& uname, const string& pwd) : username(uname), password(pwd) {
        if (username.empty()) throw invalid_argument("Имя пользователя не может быть пустым");
    }
    virtual void authenticate(const string& pwd) const = 0;
    virtual ~User77() {}
};

class AdminUser77 : public User77 {
    string adminToken;
public:
    AdminUser77(const string& uname, const string& pwd, const string& token)
        : User77(uname, pwd), adminToken(token) {}
    void authenticate(const string& pwd) const override {
        if (pwd != password) throw runtime_error("Неверный пароль администратора");
        if (adminToken != "SECRET_ADMIN_TOKEN") throw runtime_error("Неверный токен администратора");
        cout << "Администратор " << username << " аутентифицирован" << endl;
    }
};

class RegularUser77 : public User77 {
public:
    RegularUser77(const string& uname, const string& pwd) : User77(uname, pwd) {}
    void authenticate(const string& pwd) const override {
        if (pwd != password) throw runtime_error("Неверный пароль пользователя");
        cout << "Пользователь " << username << " аутентифицирован" << endl;
    }
};

void task77() {
    try {
        AdminUser77 admin("admin", "admin123", "SECRET_ADMIN_TOKEN");
        admin.authenticate("admin123");

        RegularUser77 user("user", "password");
        user.authenticate("password");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task78------------------
class DataProcessor78 {
public:
    virtual void processData(const string& data) = 0;
    virtual ~DataProcessor78() {}
};

class CSVDataProcessor78 : public DataProcessor78 {
public:
    void processData(const string& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.find(',') == string::npos)
            throw runtime_error("CSV данные должны содержать разделители ','");
        cout << "Обработка CSV данных: " << data.substr(0, 20) << "..." << endl;
    }
};

class XMLDataProcessor78 : public DataProcessor78 {
public:
    void processData(const string& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.find("<") == string::npos || data.find(">") == string::npos)
            throw runtime_error("XML данные должны содержать теги");
        cout << "Обработка XML данных: " << data.substr(0, 20) << "..." << endl;
    }
};

class JSONDataProcessor78 : public DataProcessor78 {
public:
    void processData(const string& data) override {
        if (data.empty()) throw invalid_argument("Данные не могут быть пустыми");
        if (data.front() != '{' || data.back() != '}')
            throw runtime_error("JSON данные должны быть в фигурных скобках");
        cout << "Обработка JSON данных: " << data.substr(0, 20) << "..." << endl;
    }
};

void task78() {
    try {
        CSVDataProcessor78 csv;
        csv.processData("id,name,age\n1,John,30");

        XMLDataProcessor78 xml;
        xml.processData("<user><name>John</name><age>30</age></user>");

        JSONDataProcessor78 json;
        json.processData("{\"name\":\"John\",\"age\":30}");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task79------------------
class Shape79 {
public:
    virtual double getArea() const = 0;
    virtual ~Shape79() {}
};

class Circle79 : public Shape79 {
    double radius;
public:
    Circle79(double r) : radius(r) {
        if (radius <= 0) throw invalid_argument("Радиус должен быть положительным");
    }
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle79 : public Shape79 {
    double width, height;
public:
    Rectangle79(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) throw invalid_argument("Стороны должны быть положительными");
    }
    double getArea() const override {
        return width * height;
    }
};

class Triangle79 : public Shape79 {
    double a, b, c;
public:
    Triangle79(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Недопустимые стороны треугольника");
    }
    double getArea() const override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

void task79() {
    try {
        Circle79 c(5);
        cout << "Площадь круга: " << c.getArea() << endl;

        Rectangle79 r(3, 4);
        cout << "Площадь прямоугольника: " << r.getArea() << endl;

        Triangle79 t(3, 4, 5);
        cout << "Площадь треугольника: " << t.getArea() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//-------------task80------------------
class NotificationService80 {
public:
    virtual void sendNotification(const string& recipient, const string& message) = 0;
    virtual ~NotificationService80() {}
};

class EmailNotificationService80 : public NotificationService80 {
public:
    void sendNotification(const string& recipient, const string& message) override {
        if (recipient.empty() || recipient.find('@') == string::npos)
            throw invalid_argument("Некорректный email получателя");
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "Email отправлен на " << recipient << ": " << message << endl;
    }
};

class SMSNotificationService80 : public NotificationService80 {
public:
    void sendNotification(const string& recipient, const string& message) override {
        if (recipient.length() < 10) throw invalid_argument("Некорректный номер телефона");
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "SMS отправлен на " << recipient << ": " << message << endl;
    }
};

class PushNotificationService80 : public NotificationService80 {
public:
    void sendNotification(const string& recipient, const string& message) override {
        if (recipient.empty()) throw invalid_argument("ID устройства не может быть пустым");
        if (message.empty()) throw invalid_argument("Сообщение не может быть пустым");
        cout << "Push уведомление отправлено на устройство " << recipient << ": " << message << endl;
    }
};

void task80() {
    try {
        EmailNotificationService80 email;
        email.sendNotification("user@example.com", "Ваш заказ готов");

        SMSNotificationService80 sms;
        sms.sendNotification("+79123456789", "Ваш код подтверждения: 1234");

        PushNotificationService80 push;
        push.sendNotification("device123", "Новое сообщение");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//---------------MENU---------------------
void showMenu() {
    cout << "\n=== Главное меню ===\n";
    cout << "1. Фигуры с площадью\n";
    cout << "2. Говорящие животные\n";
    cout << "3. Банковские аккаунты с выводом\n";
    cout << "4. Файловые помощник с открытием\n";
    cout << "5. Фигуры с рисованием\n";
    cout << "6. Люди с отображением\n";
    cout << "7. Калькулятор с вычислением\n";
    cout << "8. Игра с запуском\n";
    cout << "9. Документ с сохранением\n";
    cout << "10. Матрица с получением элемента\n";
    cout << "11. Транспорт с эффективностью топлива\n";
    cout << "12. Пользователь со входом\n";
    cout << "13. Фигура с масштабированием\n";
    cout << "14. Библиотека с книгами напрокат\n";
    cout << "15. Заказ с процессом\n";
    cout << "16. Фигура с поворотом\n";
    cout << "17. Платеж с обработкой\n";
    cout << "18. Обработчик исключений\n";
    cout << "19. Курс с зачислением\n";
    cout << "20. Корзина с оформлением\n";
    cout << "21. Фигура с перемещением\n";
    cout << "22. База данных с подключением\n";
    cout << "23. Задача с выполнением\n";
    cout << "24. Фигура с периметром\n";
    cout << "25. Сервис погоды с прогнозом\n";
    cout << "26. Транзакция с подтверждением\n";
    cout << "27. Уведомление с отправкой\n";
    cout << "28. Фигура с ограничительной рамкой\n";
    cout << "29. Профиль пользователя с обновлением\n";
    cout << "30. Процессор платежей с обработкой\n";
    cout << "31. Фигура с отражением\n";
    cout << "32. Читатель файлов с чтением\n";
    cout << "33. Фигура с площадью\n";
    cout << "34. Сервис email с отправкой\n";
    cout << "35. Игра с завершением\n";
    cout << "36. Фигура с вершинами\n";
    cout << "37. Сессия с началом\n";
    cout << "38. Фигура с цветом\n";
    cout << "39. Логгер с записью\n";
    cout << "40. Процессор данных с обработкой\n";
    cout << "41. Фигуры с площадью\n";
    cout << "42. Сотрудники с зарплатой\n";
    cout << "43. Читатели данных\n";
    cout << "44. Фигуры с масштабированием\n";
    cout << "45. Банковские счета с переводом\n";
    cout << "46. Сетевые запросы\n";
    cout << "47. Фигуры с границами\n";
    cout << "48. Исключения с сообщениями\n";
    cout << "49. Задачи с выполнением\n";
    cout << "50. Фигуры с вращением\n";
    cout << "51. Пользователи с входом\n";
    cout << "52. Платежи с обработкой\n";
    cout << "53. Фигуры с площадью\n";
    cout << "54. Обработчики файлов\n";
    cout << "55. Базы данных с запросами\n";
    cout << "56. Фигуры с вершинами\n";
    cout << "57. Логгеры с записью\n";
    cout << "58. Уведомления с отправкой\n";
    cout << "59. Фигуры с периметром\n";
    cout << "60. Сессии с началом\n";
    cout << "61. Процессоры данных\n";
    cout << "62. Фигуры с трансформацией\n";
    cout << "63. Пользователи с обновлением профиля\n";
    cout << "64. Менеджер задач с выполнением\n";
    cout << "65. Фигуры с цветом\n";
    cout << "66. Платежные шлюзы\n";
    cout << "67. Читатели файлов\n";
    cout << "68. Фигуры с площадью\n";
    cout << "69. Обработчики исключений\n";
    cout << "70. Профили пользователей с сохранением\n";
    cout << "71. Фигуры с описанием\n";
    cout << "72. Сервисы email\n";
    cout << "73. Валидаторы данных\n";
    cout << "74. Фигуры с размерами\n";
    cout << "75. Транзакции с выполнением\n";
    cout << "76. Фигуры с пересечением\n";
    cout << "77. Пользователи с аутентификацией\n";
    cout << "78. Процессоры данных\n";
    cout << "79. Фигуры с площадью\n";
    cout << "80. Сервисы уведомлений\n";
    cout << "0. Выход\n";
    cout << "Ваш выбор: ";
}


int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    do {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Пожалуйста, введите число.\n";
            continue;
        }

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        case 8: task8(); break;
        case 9: task9(); break;
        case 10: task10(); break;
        case 11: task11(); break;
        case 12: task12(); break;
        case 13: task13(); break;
        case 14: task14(); break;
        case 15: task15(); break;
        case 16: task16(); break;
        case 17: task17(); break;
        case 18: task18(); break;
        case 19: task19(); break;
        case 20: task20(); break;
        case 21: task21(); break;
        case 22: task22(); break;
        case 23: task23(); break;
        case 24: task24(); break;
        case 25: task25(); break;
        case 26: task26(); break;
        case 27: task27(); break;
        case 28: task28(); break;
        case 29: task29(); break;
        case 30: task30(); break;
        case 31: task31(); break;
        case 32: task32(); break;
        case 33: task33(); break;
        case 34: task34(); break;
        case 35: task35(); break;
        case 36: task36(); break;
        case 37: task37(); break;
        case 38: task38(); break;
        case 39: task39(); break;
        case 40: task40(); break;
        case 41: task41(); break;
        case 42: task42(); break;
        case 43: task43(); break;
        case 44: task44(); break;
        case 45: task45(); break;
        case 46: task46(); break;
        case 47: task47(); break;
        case 48: task48(); break;
        case 49: task49(); break;
        case 50: task50(); break;
        case 51: task51(); break;
        case 52: task52(); break;
        case 53: task53(); break;
        case 54: task54(); break;
        case 55: task55(); break;
        case 56: task56(); break;
        case 57: task57(); break;
        case 58: task58(); break;
        case 59: task59(); break;
        case 60: task60(); break;
        case 61: task61(); break;
        case 62: task62(); break;
        case 63: task63(); break;
        case 64: task64(); break;
        case 65: task65(); break;
        case 66: task66(); break;
        case 67: task67(); break;
        case 68: task68(); break;
        case 69: task69(); break;
        case 70: task70(); break;
        case 71: task71(); break;
        case 72: task72(); break;
        case 73: task73(); break;
        case 74: task74(); break;
        case 75: task75(); break;
        case 76: task76(); break;
        case 77: task77(); break;
        case 78: task78(); break;
        case 79: task79(); break;
        case 80: task80(); break;
        case 0: cout << "Выход...\n"; break;
        default: cout << "Некорректный ввод. Попробуйте еще раз.\n";
        }
    } while (choice != 0);

    return 0;
}