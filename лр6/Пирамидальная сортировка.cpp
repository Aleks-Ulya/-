#include <iostream>
using namespace std;

// Вспомогательная функция для восстановления свойства кучи (heapify)
void heapify(int arr[], int n, int root) {
    int largest = root;     // Предполагаемый наибольший элемент (корень)
    int leftChild = 2 * root + 1;  // Левый потомок
    int rightChild = 2 * root + 2; // Правый потомок

    // Если левый потомок существует и больше корневого элемента
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // Если правый потомок существует и больше текущего наибольшего
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // Если наибольший элемент изменился
    if (largest != root) {
        swap(arr[root], arr[largest]);  // Меняем корень с наибольшим элементом
        heapify(arr, n, largest);      // Рекурсивно восстанавливаем кучу снизу вверх
    }
}

// Основная функция пирамидальной сортировки
void heapSort(int arr[], int n) {
    // Строим max-кучу (преобразование массива в кучу)
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);  // Поменять текущий максимум с последним элементом
        heapify(arr, i, 0);    // Восстанавливаем кучу после удаления максимума
    }
}

// Тестовая программа
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

Пример выполнения:
Исходный массив: 12 11 13 5 6 7 
Отсортированный массив: 5 6 7 11 12 13
