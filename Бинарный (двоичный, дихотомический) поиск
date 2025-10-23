def binary_search(arr, target):
    """Реализует бинарный поиск в отсортированном массиве"""
    low = 0                     # Нижняя граница поиска
    high = len(arr) - 1         # Верхняя граница поиска

    while low <= high:          # Пока границы пересекаются
        mid = (low + high) // 2 # Находим средний индекс
        guess = arr[mid]        # Средний элемент массива

        if guess == target:     # Нашли искомое значение
            return mid          # Возвращаем индекс
        elif guess > target:    # Значение больше цели
            high = mid - 1      # Сокращаем верхнюю границу
        else:                   # Значение меньше цели
            low = mid + 1       # Увеличим нижнюю границу

    return None                 # Элемент не найден


# Пример использования
if __name__ == "__main__":
    sorted_array = [1, 3, 5, 7, 9, 11, 13, 15]
    target_value = 7
    result = binary_search(sorted_array, target_value)

    if result is not None:
        print(f"Значение {target_value} найдено на позиции {result}")
    else:
        print(f"Значение {target_value} не найдено в массиве")

Пример выполнения:
Значение 7 найдено на позиции 3
