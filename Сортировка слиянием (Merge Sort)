#include <iostream>
#include <vector>

// Вспомогательная функция для объединения двух отсортированных частей массива
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int const subArrayOneSize = mid - left + 1;   // Размер первой половины
    int const subArrayTwoSize = right - mid;      // Размер второй половины

    // Создание временных массивов для хранения обеих половин
    std::vector<int> leftSubarray(subArrayOneSize);
    std::vector<int> rightSubarray(subArrayTwoSize);

    // Копирование данных в обе половины
    for (int i = 0; i < subArrayOneSize; i++) {
        leftSubarray[i] = arr[left + i];
    }
    for (int j = 0; j < subArrayTwoSize; j++) {
        rightSubarray[j] = arr[mid + 1 + j];  // Обратите внимание на смещение (+1)
    }

    // Индексы для левой и правой половин, а также общего массива
    int indexLeft = 0, indexRight = 0, mergedIndex = left;

    // Объединение обоих временных массивов обратно в общий массив
    while (indexLeft < subArrayOneSize && indexRight < subArrayTwoSize) {
        if (leftSubarray[indexLeft] <= rightSubarray[indexRight]) {
            arr[mergedIndex++] = leftSubarray[indexLeft++];
        } else {
            arr[mergedIndex++] = rightSubarray[indexRight++];
        }
    }

    // Добавляем оставшиеся элементы из левой половины (если остались)
    while (indexLeft < subArrayOneSize) {
        arr[mergedIndex++] = leftSubarray[indexLeft++];
    }

    // Добавляем оставшиеся элементы из правой половины (если остались)
    while (indexRight < subArrayTwoSize) {
        arr[mergedIndex++] = rightSubarray[indexRight++];
    }
}

// Рекурсивная функция сортировки слиянием
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;  // Базовый случай рекурсии: если диапазон состоит из одного элемента
    }

    // Найти середину диапазона
    int mid = left + (right - left) / 2;

    // Рекурсивно разделяем левую половину
    mergeSort(arr, left, mid);

    // Рекурсивно разделяем правую половину
    mergeSort(arr, mid + 1, right);

    // Соединяем обе половины
    merge(arr, left, mid, right);
}

// Тестовая программа
int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    std::cout << "Исходный массив: ";
    for (auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Запускаем сортировку слиянием
    mergeSort(arr, 0, n - 1);

    std::cout << "Отсортированный массив: ";
    for (auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

Пример выполнения:
Исходный массив: 38 27 43 3 9 82 10 
Отсортированный массив: 3 9 10 27 38 43 82
