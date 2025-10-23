#include <iostream>

// Функция интерполирующего поиска
int interpolationSearch(int arr[], int n, int x) {
    int low = 0;                       // Нижняя граница интервала поиска
    int high = n - 1;                  // Верхняя граница интервала поиска

    // Пока интервал поиска не пуст и искомое значение лежит в диапазоне границ
    while ((low <= high) && (x >= arr[low]) && (x <= arr[high])) {
        // Рассчитываем возможную позицию искомого элемента
        int pos = low + (((double)(high - low) /
                         (arr[high] - arr[low])) *
                        (x - arr[low]));

        // Если нашли точное совпадение
        if (arr[pos] == x)
            return pos;                // Возвращаем индекс найденного элемента

        // Если элемент меньше ожидаемого, смещаем верхнюю границу
        if (arr[pos] < x)
            low = pos + 1;

        // Если элемент больше ожидаемого, смещаем нижнюю границу
        else
            high = pos - 1;
    }

    return -1;                        // Элемент не найден
}

// Точка входа программы
int main() {
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18;                      // Искомое значение

    int index = interpolationSearch(arr, n, x);

    if (index != -1)
        std::cout << "Элемент найден на позиции " << index << std::endl;
    else
        std::cout << "Элемент не найден." << std::endl;

    return 0;
}

Пример выполнения:
Элемент найден на позиции 4
