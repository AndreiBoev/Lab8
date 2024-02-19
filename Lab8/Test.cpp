#include <iostream> //потоковый ввод и вывод
using namespace std;

// используем прототип функции перестановки
bool sort(int len, int a[]);

int main()
{
    int a[50], len, i;

    cout << "Введите 0<len<=50 len = ";
    cin >> len;

    cout << "Введите элементы массива\n";
    for (i = 0; i < len; i++) cin >> *(a + i);

    if (sort(len, a)) // вызов функции сортировки
    {
        cout << "Преобразованный массив:\n";
        for (i = 0; i < len; i++)
            cout << "  " << *(a + i);
        cout << " \n";
    }
    else
        cout << "Без изменений\n";
    return 0; // признак успешного завершения программы
}

bool sort(int len, int a[]) // функция сортировки
{
    int b, * i, nc = -1, * j; // описание переменных

    for (i = a; i < a + len; i++)
        if (*i >= 0)
        {
            if (nc != -1) /* сдвиг вправо, начиная с последнего */
            {
                for (b = *i, j = i; j >= a + nc + 1; j--)
                    *j = *(j - 1);
                *(a + nc++) = b;
            }
        }
        else if (nc == -1)
            nc = i - a;
    if (nc != -1) return true;
    else return false;
}
