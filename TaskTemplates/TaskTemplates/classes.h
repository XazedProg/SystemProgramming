#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

// Класс Pair
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
};

// Класс Point
template <typename T>
class Point {
private:
    T x;
    T y;
public:
    Point(T xVal = 0, T yVal = 0) : x(xVal), y(yVal) {}
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    T getX() const { return x; }
    T getY() const { return y; }
};

// Класс Stack
template <typename T>
class Stack {
private:
    std::stack<T> stk;
public:
    void push(const T& value) {
        stk.push(value);
    }
    void pop() {
        if (!stk.empty()) {
            stk.pop();
        }
        else {
            std::cerr << "Стек пуст!" << std::endl;
        }
    }
    T top() const {
        if (!stk.empty()) {
            return stk.top();
        }
        else {
            std::cerr << "Стек пуст!" << std::endl;
            return T();
        }
    }
    bool empty() const {
        return stk.empty();
    }
};

// Класс Array
template <typename T>
class Array {
private:
    T* data;
    int size;
public:
    Array(int size) : size(size) {
        data = new T[size];
    }
    ~Array() {
        delete[] data;
    }
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Не знаем такого индекса" << std::endl;
            exit(1);
        }
        return data[index];
    }
    int getSize() const { return size; }
};

// Класс Complex
template <typename T>
class Complex {
private:
    T real;
    T imag;
public:
    Complex(T r = 0, T i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    T getReal() const { return real; }
    T getImag() const { return imag; }
};

// Класс Queue
template <typename T>
class Queue {
private:
    std::queue<T> q;
public:
    void enqueue(const T& value) {
        q.push(value);
    }
    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
        else {
            std::cerr << "Очередь пуста!" << std::endl;
        }
    }
    T front() const {
        if (!q.empty()) {
            return q.front();
        }
        else {
            std::cerr << "Очередь пуста!" << std::endl;
            return T();
        }
    }
    bool empty() const {
        return q.empty();
    }
};

// Класс DynamicArray
template <typename T>
class DynamicArray {
private:
    std::vector<T> data;
public:
    void add(const T& value) {
        data.push_back(value);
    }
    void remove(int index) {
        if (index >= 0 && index < data.size()) {
            data.erase(data.begin() + index);
        }
        else {
            std::cerr << "Индекс вне диапазона!" << std::endl;
        }
    }
    T& operator[](int index) {
        if (index < 0 || index >= data.size()) {
            std::cerr << "Индекс вне диапазона!" << std::endl;
            exit(1);
        }
        return data[index];
    }
    int size() const { return data.size(); }
};

// Класс Matrix
template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int rows;
    int cols;
public:
    Matrix(int r, int c, T init = T()) : rows(r), cols(c) {
        data.resize(rows, std::vector<T>(cols, init));
    }
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Размеры матриц не совпадают!" << std::endl;
            return *this;
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Размеры матриц не совпадают!" << std::endl;
            return *this;
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Класс List
template <typename T>
class List {
private:
    std::list<T> lst;
public:
    void pushFront(const T& value) {
        lst.push_front(value);
    }
    void pushBack(const T& value) {
        lst.push_back(value);
    }
    void popFront() {
        if (!lst.empty()) {
            lst.pop_front();
        }
        else {
            std::cerr << "Список пуст!" << std::endl;
        }
    }
    void popBack() {
        if (!lst.empty()) {
            lst.pop_back();
        }
        else {
            std::cerr << "Список пуст!" << std::endl;
        }
    }
    T front() const {
        if (!lst.empty()) {
            return lst.front();
        }
        else {
            std::cerr << "Список пуст!" << std::endl;
            return T();
        }
    }
    T back() const {
        if (!lst.empty()) {
            return lst.back();
        }
        else {
            std::cerr << "Список пуст!" << std::endl;
            return T();
        }
    }
    bool empty() const {
        return lst.empty();
    }
};

// Класс Triangle
template <typename T>
class Triangle {
private:
    Point<T> p1, p2, p3;
public:
    Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c) : p1(a), p2(b), p3(c) {}
    double area() const {
        T x1 = p1.getX(), y1 = p1.getY();
        T x2 = p2.getX(), y2 = p2.getY();
        T x3 = p3.getX(), y3 = p3.getY();
        return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    }
};

// Класс Graph
template <typename T>
class Graph {
private:
    std::vector<std::vector<T>> adjList;
    int vertices;
public:
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }
    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else {
            std::cerr << "Неверные вершины" << std::endl;
        }
    }
    void removeEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjList[u].erase(std::remove(adjList[u].begin(), adjList[u].end(), v), adjList[u].end());
            adjList[v].erase(std::remove(adjList[v].begin(), adjList[v].end(), u), adjList[v].end());
        }
        else {
            std::cerr << "Неверные вершины" << std::endl;
        }
    }
};

// Класс Cube
template <typename T>
class Cube {
private:
    T edgeLength;
public:
    Cube(T edge) : edgeLength(edge) {}
    T volume() const {
        return edgeLength * edgeLength * edgeLength;
    }
    T surfaceArea() const {
        return 6 * edgeLength * edgeLength;
    }
};

// Класс Wrapper
template <typename T>
class Wrapper {
private:
    T value;
public:
    Wrapper(T val = T()) : value(val) {}
    T getValue() const { return value; }
    void setValue(T val) { value = val; }
};

#endif // CLASSES_H