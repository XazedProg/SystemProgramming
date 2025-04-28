#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <algorithm>

// Функция swap
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Функция минимального элемента массива
template <typename T>
T findMin(const T arr[], int size) {
    if (size <= 0) {
        std::cerr << "В массиве ничего нема" << std::endl;
        return T();
    }
    T minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

// Возвращение суммы элементов массива
template <typename T>
T arraySum(const T arr[], int size) {
    T sum = T();
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Копирование массива
template <typename T>
void copyArray(const T source[], T dest[], int size) {
    for (int i = 0; i < size; ++i) {
        dest[i] = source[i];
    }
}

// Проверка на схожесть
template <typename T>
bool areEqual(const T& a, const T& b) {
    return a == b;
}

// Перевернутый массив
template <typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        std::swap(arr[i], arr[size - i - 1]);
    }
}

// Поиск элемента массива
template <typename T>
int findElement(const T arr[], int size, const T& value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Объединение массивов
template <typename T>
std::vector<T> mergeArrays(const T arr1[], int size1, const T arr2[], int size2) {
    std::vector<T> result;
    for (int i = 0; i < size1; ++i) {
        result.push_back(arr1[i]);
    }
    for (int i = 0; i < size2; ++i) {
        result.push_back(arr2[i]);
    }
    return result;
}

// Среднее значение массива
template <typename T>
double arrayAverage(const T arr[], int size) {
    if (size <= 0) {
        std::cerr << "Массив пуст!" << std::endl;
        return 0.0;
    }
    T sum = arraySum(arr, size);
    return static_cast<double>(sum) / size;
}

// Фильтрация массива
template <typename T, typename Predicate>
std::vector<T> filterArray(const T arr[], int size, Predicate pred) {
    std::vector<T> result;
    for (int i = 0; i < size; ++i) {
        if (pred(arr[i])) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

// Нахождение второго максимального элемента
template <typename T>
T findSecondMax(const T arr[], int size) {
    if (size < 2) {
        std::cerr << "Массив слишком мал!" << std::endl;
        return T();
    }
    T max1 = std::max(arr[0], arr[1]);
    T max2 = std::min(arr[0], arr[1]);
    for (int i = 2; i < size; ++i) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }
    return max2;
}

// Из массива в вектор
template <typename T>
std::vector<T> arrayToVector(const T arr[], int size) {
    return std::vector<T>(arr, arr + size);
}

// Точка пересечения массивов
template <typename T>
std::vector<T> arrayIntersection(const T arr1[], int size1, const T arr2[], int size2) {
    std::vector<T> result;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (arr1[i] == arr2[j]) {
                result.push_back(arr1[i]);
                break;
            }
        }
    }
    return result;
}

// Сортировка пузырьком
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif // FUNCTIONS_H