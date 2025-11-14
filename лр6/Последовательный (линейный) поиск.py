def sequential_search(arr, target):
    """Осуществляет последовательный поиск элемента 'target' в списке 'arr'."""
    for idx, value in enumerate(arr):  # Просмотр каждого элемента массива
        if value == target:            # Если текущий элемент равен целевому
            return idx                 # Вернуть индекс найденного элемента
    return None                        # Если элемент не найден, вернуть None


# Пример использования
if __name__ == "__main__":
    my_list = [10, 20, 30, 40, 50]
    search_value = 30
    result = sequential_search(my_list, search_value)

    if result is not None:
        print(f"Значение {search_value} найдено на позиции {result}.")
    else:
        print(f"Значение {search_value} не найдено.")

Пример выполнения:
Значение 30 найдено на позиции 2.
