def set_cover(universe, subsets):
    covered = set()
    result = []
    
    while len(covered) < len(universe):
        best = None
        max_new_elements = 0
        
        # Ищем подмножество с максимальным числом непокрытых элементов
        for subset in subsets:
            # Количество новых (непокрытых) элементов в подмножестве
            new_elements = len(subset - covered)
            if new_elements > max_new_elements:
                max_new_elements = new_elements
                best = subset
        
        # Если не нашли полезное подмножество — завершаем
        if best is None:
            break
            
        result.append(best)
        covered.update(best)
    
    return result



def main():
    print("=== Задача о покрытии множества ===\n")
    
    # Ввод вселенной (основного множества)
    print("Шаг 1. Введите элементы вселенной (все возможные элементы).")
    print("5 4 2 7 3")
    universe_input = input("Вселенная: ")
    universe = set(universe_input.strip().split())
    
    if not universe:
        print("Ошибка: вселенная не может быть пустой!")
        return
    
    print(f"Вселенная: {universe}\n")
    
    # Ввод подмножеств
    print("Шаг 2. Введите подмножества (каждое на новой строке).")
    print("Для завершения ввода оставьте строку пустой.")
    print("x y")
    
    subsets = []
    subset_count = 1
    
    while True:
        subset_input = input(f"Подмножество {subset_count}: ").strip()
        if not subset_input:  # Пустая строка — завершение ввода
            break
        
        subset = set(subset_input.split())
        if subset:  # Проверяем, что подмножество не пустое
            subsets.append(subset)
            subset_count += 1
        else:
            print("Подмножество не может быть пустым!")
    
    if not subsets:
        print("Ошибка: нужно ввести хотя бы одно подмножество!")
        return
    
    print(f"\nВведённые подмножества: {subsets}")
    
    # Запуск алгоритма
    result = set_cover(universe, subsets)
    
    # Вывод результата
    print("\n=== Результат ===")
    if len(covered := set().union(*result)) == len(universe):
        print("Покрытие найдено!")
        print(f"Выбранные подмножества ({len(result)} шт.):")
        for i, subset in enumerate(result, 1):
            print(f"{i}. {subset}")
        print(f"Покрыто элементов: {covered}")
    else:
        print("Не удалось полностью покрыть вселенную!")
        print(f"Покрыто: {covered}")
        print(f"Не покрыто: {universe - covered}")



if __name__ == "__main__":
    main()

РЕЗУЛЬТАТ ВЫПОЛНЕНИЯ:
=== Задача о покрытии множества ===

Шаг 1. Введите элементы вселенной (все возможные элементы).
5 4 2 7 3
Вселенная: 5 4 2 7 3
Вселенная: {'2', '4', '5', '3', '7'}

Шаг 2. Введите подмножества (каждое на новой строке).
Для завершения ввода оставьте строку пустой.
x y
Подмножество 1: x
Подмножество 2: y
Подмножество 3:

Введённые подмножества: [{'x'}, {'y'}]

=== Результат ===
Не удалось полностью покрыть вселенную!
Покрыто: {'x', 'y'}
Не покрыто: {'2', '4', '5', '3', '7'}
