#include <iostream>
#include <vector>
#include "functions.h"
#include "classes.h"

using namespace std;

void displayMenu() {
    setlocale(LC_ALL, "RU");

    cout << "\nМеню:\n";
    cout << "1. Функция swap\n";
    cout << "2. Класс Pair\n";
    cout << "3. Функция findMin\n";
    cout << "4. Класс Point\n";
    cout << "5. Функция arraySum\n";
    cout << "6. Класс Stack\n";
    cout << "7. Функция copyArray\n";
    cout << "8. Класс Array\n";
    cout << "9. Функция areEqual\n";
    cout << "10. Класс Complex\n";
    cout << "11. Функция reverseArray\n";
    cout << "12. Класс Queue\n";
    cout << "13. Функция findElement\n";
    cout << "14. Класс DynamicArray\n";
    cout << "15. Функция mergeArrays\n";
    cout << "16. Класс Matrix\n";
    cout << "17. Функция arrayAverage\n";
    cout << "18. Класс List\n";
    cout << "19. Функция filterArray\n";
    cout << "20. Класс Triangle\n";
    cout << "21. Функция findSecondMax\n";
    cout << "22. Класс Cube\n";
    cout << "23. Класс Wrapper\n";
    cout << "24. Функция bubbleSort\n";
    cout << "0. Выход\n";
    cout << "Выберите задание: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int a = 5, b = 10;
            cout << "До swap: a = " << a << ", b = " << b << endl;
            swapValues(a, b);
            cout << "После swap: a = " << a << ", b = " << b << endl;
            break;
        }
        case 2: {
            Pair<int, string> pair(1, "Пример");
            cout << "Pair: first = " << pair.getFirst() << ", second = " << pair.getSecond() << endl;
            break;
        }
        case 3: {
            int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size = sizeof(arr) / sizeof(arr[0]);
            cout << "Минимальный элемент в массиве: " << findMin(arr, size) << endl;
            break;
        }
        case 4: {
            Point<int> p1(1, 2), p2(3, 4);
            Point<int> p3 = p1 + p2;
            cout << "Сумма точек: (" << p3.getX() << ", " << p3.getY() << ")" << endl;
            break;
        }
        case 5: {
            int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size = sizeof(arr) / sizeof(arr[0]);
            cout << "Сумма элементов массива: " << arraySum(arr, size) << endl;
            break;
        }
        case 6: {
            Stack<int> stack;
            stack.push(1);
            stack.push(2);
            cout << "Верхний элемент стека: " << stack.top() << endl;
            stack.pop();
            cout << "Верхний элемент после pop: " << stack.top() << endl;
            break;
        }
        case 7: {
            int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size = sizeof(arr) / sizeof(arr[0]);
            int arr2[8];
            copyArray(arr, arr2, size);
            cout << "Скопированный массив: ";
            for (int i = 0; i < size; ++i) {
                cout << arr2[i] << " ";
            }
            cout << endl;
            break;
        }
        case 8: {
            Array<int> array(5);
            for (int i = 0; i < 5; ++i) {
                array[i] = i * i;
            }
            cout << "Элемент с индексом 2 в Array: " << array[2] << endl;
            break;
        }
        case 9: {
            cout << "Равны ли 5 и 5? " << (areEqual(5, 5) ? "Да" : "Нет") << endl;
            break;
        }
        case 10: {
            Complex<double> c1(1.0, 2.0), c2(3.0, 4.0);
            Complex<double> c3 = c1 + c2;
            cout << "Сумма комплексных чисел: " << c3.getReal() << " + " << c3.getImag() << "i" << endl;
            break;
        }
        case 11: {
            int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size = sizeof(arr) / sizeof(arr[0]);
            reverseArray(arr, size);
            cout << "Реверсированный массив: ";
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        case 12: {
            Queue<int> q;
            q.enqueue(1);
            q.enqueue(2);
            cout << "Первый элемент очереди: " << q.front() << endl;
            q.dequeue();
            cout << "Первый элемент после dequeue: " << q.front() << endl;
            break;
        }
        case 13: {
            int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size = sizeof(arr) / sizeof(arr[0]);
            cout << "Индекс элемента 5 в массиве: " << findElement(arr, size, 5) << endl;
            break;
        }
        case 14: {
            DynamicArray<int> dynArray;
            dynArray.add(1);
            dynArray.add(2);
            cout << "Элемент с индексом 0 в DynamicArray: " << dynArray[0] << endl;
            break;
        }
        case 15: {
            int arr1[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size1 = sizeof(arr1) / sizeof(arr1[0]);
            int arr2[] = { 7, 8, 9 };
            int size2 = sizeof(arr2) / sizeof(arr2[0]);
            vector<int> merged = mergeArrays(arr1, size1, arr2, size2);
            cout << "Объединенный массив: ";
            for (int num : merged) {
                cout << num << " ";
            }
            cout << endl;
            break;
        }
        case 16: {
            Matrix<int> mat1(2, 2, 1), mat2(2, 2, 2);
            Matrix<int> mat3 = mat1 + mat2;
            cout << "Сумма матриц:" << endl;
            mat3.print();
            break;
        }
        case 17: {
            int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size = sizeof(arr) / sizeof(arr[0]);
            cout << "Среднее значение массива: " << arrayAverage(arr, size) << endl;
            break;
        }
        case 18: {
            List<int> lst;
            lst.pushBack(1);
            lst.pushFront(0);
            cout << "Первый элемент списка: " << lst.front() << endl;
            break;
        }
        case 19: {
            int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size = sizeof(arr) / sizeof(arr[0]);
            vector<int> filtered = filterArray(arr, size, [](int x) { return x % 2 == 0; });
            cout << "Отфильтрованный массив (четные): ";
            for (int num : filtered) {
                cout << num << " ";
            }
            cout << endl;
            break;
        }
        case 20: {
            Point<int> tp1(0, 0), tp2(1, 0), tp3(0, 1);
            Triangle<int> triangle(tp1, tp2, tp3);
            cout << "Площадь треугольника: " << triangle.area() << endl;
            break;
        }
        case 21: {
            int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size = sizeof(arr) / sizeof(arr[0]);
            cout << "Второй максимальный элемент в массиве: " << findSecondMax(arr, size) << endl;
            break;
        }
        case 22: {
            Cube<double> cube(3.0);
            cout << "Объем куба: " << cube.volume() << ", площадь поверхности: " << cube.surfaceArea() << endl;
            break;
        }
        case 23: {
            Wrapper<string> wrapper("Обертка");
            cout << "Значение в обертке: " << wrapper.getValue() << endl;
            break;
        }
        case 24: {
            int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
            int size = sizeof(arr) / sizeof(arr[0]);
            bubbleSort(arr, size);
            cout << "Отсортированный массив: ";
            for (int i = 0; i < size; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}