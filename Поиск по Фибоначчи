def fibonacci_search(arr, x):
    # Генерируем последовательность чисел Фибоначчи до длины массива
    def generate_fib_sequence(length):
        fib_seq = [0, 1]
        while fib_seq[-1] < length:
            fib_seq.append(fib_seq[-1] + fib_seq[-2])
        return fib_seq[:-1]

    # Граничные условия для начальной позиции
    fib_numbers = generate_fib_sequence(len(arr))
    k = len(fib_numbers) - 1  # Максимальный индекс в последовательности Фибоначчи
    offset = -1               # Начало интервала поиска

    # Начинаем поиск
    while k > 0:
        i = min(offset + fib_numbers[k-1], len(arr)-1)  # Расчет возможной позиции
        if arr[i] < x:       # Если искомое больше текущего элемента
            k -= 1           # Используем предыдущее число Фибоначчи
            offset = i       # Обновляем начало интервала
        elif arr[i] > x:     # Если искомое меньше текущего элемента
            k -= 2           # Используем позапрошлое число Фибоначчи
        else:                # Совпадение найдено
            return i         # Возвращаем индекс элемента

    # Если элемент не найден
    return -1

# Пример использования
if __name__ == "__main__":
    arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
    x = 85
    result = fibonacci_search(arr, x)
    if result != -1:
        print(f"Элемент {x} найден на позиции {result}")
    else:
        print(f"Элемент {x} не найден в массиве")

Пример выполнения:
Элемент 85 найден на позиции 8
