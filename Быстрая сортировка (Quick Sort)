#include <iostream>
using namespace std;

// Вспомогательная функция для обмена значений двух элементов
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Функция для разделения массива вокруг опорного элемента
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Выбор последнего элемента в качестве опорного
    int i = (low - 1);     // Индекс для размещения меньших элементов

    // Проходим по массиву, оставляя слева от i элементы, меньшие либо равные pivot
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;           // Увеличиваем индекс для мелких элементов
            swap(&arr[i], &arr[j]);  // Поменять местами текущий и мелкий элемент
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Поместить pivot на своё место
    return (i + 1);                 // Возвращаем индекс опорного элемента
}

// Основная функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Разделение массива на две части и получение индекса опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем левую и правую части
        quickSort(arr, low, pi - 1);  // Левая часть
        quickSort(arr, pi + 1, high); // Правая часть
    }
}

// Тестовая программа
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

Пример выполнения:
Исходный массив: 10 7 8 9 1 5 
Отсортированный массив: 1 5 7 8 9 10
