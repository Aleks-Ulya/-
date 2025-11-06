public class PalindromeChecker {

    /**
     * Основной метод проверки строки на палиндром.
     * @param s входная строка
     * @return true, если строка — палиндром; false иначе
     */
    public static boolean isPalindrome(String s) {
        // Нормализация: нижний регистр и удаление пробелов
        s = s.toLowerCase().replace(" ", "");
        
        // Запуск рекурсивной проверки с границами [0, length-1]
        return isPalindromeRecursive(s, 0, s.length() - 1);
    }

    /**
     * Рекурсивный метод проверки подстроки на палиндром.
     * @param s строка для проверки
     * @param left левый индекс текущей подстроки
     * @param right правый индекс текущей подстроки
     * @return true, если подстрока — палиндром
     */
    private static boolean isPalindromeRecursive(String s, int left, int right) {
        // Базовый случай 1: индексы встретились или пересеклись — палиндром
        if (left >= right) {
            return true;
        }
        
        // Базовый случай 2: символы на границах не совпадают — не палиндром
        if (s.charAt(left) != s.charAt(right)) {
            return false;
        }
        
        // Рекурсивный вызов: сдвигаем границы внутрь
        return isPalindromeRecursive(s, left + 1, right - 1);
    }

    // Пример использования
    public static void main(String[] args) {
        String[] testStrings = {
            "шалаш",
            "А роза упала на лапу Азора",
            "привет",
            "abcba",
            "a"
        };

        for (String text : testStrings) {
            boolean result = isPalindrome(text);
            System.out.println("'" + text + "' -> " + result);
        }
    }
}

Результат выполнения:
'шалаш' -> true
'А роза упала на лапу Азора' -> true
'привет' -> false
'abcba' -> true
'a' -> true
